#include "ism330dhcx_hal.h"
#include "stm32g4xx_hal.h"
#include <string.h> /* memset */
#include <unistd.h> /* close */

extern I2C_HandleTypeDef hi2c1;
extern ISM330DHCX_HandleTypeDef 	hism330;
uint8_t whoamI, rst;

static int16_t data_raw_acceleration[3];
static int16_t data_raw_angular_rate[3];
static int16_t data_raw_temperature;

extern void Error_Handler(void);

/**
  * @brief 		ISM330DHCX Write Function
  * @param1		Peripheral communication handler
  * @param2 	ISM330DHCX Adress's register
  * @param3 	Pointer to the buffer that contains the data to write
  * @param4		Length of the buffer of @param3
  * @retval 	HAL status
  */
int32_t HAL_ISM330DHCX_Write(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len)
{
	return HAL_I2C_Mem_Write(handle, ISM3320DHCX_I2C_ADD_L_W, reg, I2C_MEMADD_SIZE_8BIT, bufp, len, 1000);
}

/**
  * @brief 		ISM330DHCX Read Function
  * @param1		Peripheral communication handler
  * @param2 	ISM330DHCX Adress's register
  * @param3 	Pointer to the buffer that'll store the data
  * @param4		Expected length of data to be received
  * @retval 	HAL status
  */
int32_t HAL_ISM330DHCX_Read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len)
{
	return HAL_I2C_Mem_Read(handle, ISM3320DHCX_I2C_ADD_L_R, reg, I2C_MEMADD_SIZE_8BIT, bufp, len, 1000);
}

/**
  * @brief 		ISM330DHCX Initialization function
  * @param		None
  * @retval 	None
  */
void HAL_ISM330DHCX_Init(void)
{
	/* Fill the ISM330DHCX Handler */
	hism330.write 	= HAL_ISM330DHCX_Write;
	hism330.read 	= HAL_ISM330DHCX_Read;
	hism330.handle	= &hi2c1;

	/* Check device ID */
	ism330dhcx_who_am_i(&hism330, &whoamI);
	if (whoamI != ISM3320DHCX_WHO_AM_I)
	{
		Error_Handler();
	}

	/* Restore default configuration */
	ism330dhcx_reset_set(&hism330, PROPERTY_ENABLE);
	do
	{
	    ism330dhcx_reset_get(&hism330, &rst);
	} while (rst);

	/* Enable Block Data Update */
	ism330dhcx_block_data_update_set(&hism330, PROPERTY_ENABLE);
	/* Set Output Data Rate */
	ism330dhcx_xl_data_rate_set(&hism330, ISM330DHCX_XL_ODR_12Hz5);
	ism330dhcx_gy_data_rate_set(&hism330, ISM330DHCX_GY_ODR_12Hz5);
	/* Set full scale */
	ism330dhcx_xl_full_scale_set(&hism330, ISM330DHCX_2g);
	ism330dhcx_gy_full_scale_set(&hism330, ISM330DHCX_2000dps);
	/* Configure filtering chain(No aux interface)
	 *
	 * Accelerometer - LPF1 + LPF2 path
	 */
	ism330dhcx_xl_hp_path_on_out_set(&hism330, ISM330DHCX_LP_ODR_DIV_100);
	ism330dhcx_xl_filter_lp2_set(&hism330, PROPERTY_ENABLE);

}

void HAL_ISM330DHCX_getConf(ism_conf* ism_c)
{
	  ism330dhcx_ctrl1_xl_t ctrl1_xl;
	  ism330dhcx_ctrl2_g_t ctrl2_g;
	  ism330dhcx_ctrl3_ois_t ctrl3_ois;

	  //Contient XL_RATE_SET
	  ism330dhcx_read(&hism330, CTRL1_XL,
                            (uint8_t *)&ctrl1_xl, 1);
	  //Contient GY_RATE_SET et GY_FULL_SCALE
	  ism330dhcx_read(&hism330, CTRL2_G,
	                                (uint8_t *)&ctrl2_g, 1);
	  //Contient XL_FULL_SCALE
	  ism330dhcx_read(&hism330, CTRL3_OIS,
	                              (uint8_t *)&ctrl3_ois, 1);

	  ism_c->acc_data_rate 	= (uint8_t)ctrl1_xl.odr_xl;
	  ism_c->gyr_data_rate	= (uint8_t)ctrl2_g.odr_g;
	  ism_c->acc_full_scale	= (uint8_t)ctrl3_ois.fs_xl_ois;
	  ism_c->gyr_full_scale 	= (uint8_t)ctrl2_g.fs_g;
}

void HAL_ISM330DHCX_Poll(ism_data* ism_d)
{
	/* Read samples in polling mode (no int) */
	uint8_t reg;
	/* Read output only if new xl value is available */
	ism330dhcx_xl_flag_data_ready_get(&hism330, &reg);

	if (reg) {
		/* Read acceleration field data */
		memset(data_raw_acceleration, 0x00, 3 * sizeof(int16_t));
		ism330dhcx_acceleration_raw_get(&hism330, (int16_t*)data_raw_acceleration);
		ism_d->acceleration_mg[0] =
				ism330dhcx_from_fs2g_to_mg(data_raw_acceleration[0]);
		ism_d->acceleration_mg[1] =
				ism330dhcx_from_fs2g_to_mg(data_raw_acceleration[1]);
		ism_d->acceleration_mg[2] =
				ism330dhcx_from_fs2g_to_mg(data_raw_acceleration[2]);
	}

	ism330dhcx_gy_flag_data_ready_get(&hism330, &reg);

	if (reg) {
		/* Read angular rate field data */
		memset(data_raw_angular_rate, 0x00, 3 * sizeof(int16_t));
		ism330dhcx_angular_rate_raw_get(&hism330, (int16_t*)data_raw_angular_rate);
		ism_d->angular_rate_mdps[0] =
				ism330dhcx_from_fs2000dps_to_mdps(data_raw_angular_rate[0]);
		ism_d->angular_rate_mdps[1] =
				ism330dhcx_from_fs2000dps_to_mdps(data_raw_angular_rate[1]);
		ism_d->angular_rate_mdps[2] =
				ism330dhcx_from_fs2000dps_to_mdps(data_raw_angular_rate[2]);
	}

	ism330dhcx_temp_flag_data_ready_get(&hism330, &reg);

	if (reg) {
		/* Read temperature data */
		memset(&data_raw_temperature, 0x00, sizeof(int16_t));
		ism330dhcx_temperature_raw_get(&hism330, &data_raw_temperature);
		ism_d->temperature_degC = ism330dhcx_from_lsb_to_celsius(
				data_raw_temperature);
	}

}
