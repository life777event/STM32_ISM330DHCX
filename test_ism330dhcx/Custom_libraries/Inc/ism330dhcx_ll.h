#include "ism330dhcx_regs.h"
#include <stdio.h>

/* Read function */
int32_t ism330dhcx_read(ISM330DHCX_HandleTypeDef *h_ism,
                        uint8_t reg,
                        uint8_t *data,
                        uint16_t len);
/* Write function */
int32_t ism330dhcx_write(ISM330DHCX_HandleTypeDef *h_ism,
                        uint8_t reg,
                        uint8_t *data,
                        uint16_t len);

/********** Initialization & Configuration Functions **********/

/* Read WHO_AM_I register */
int32_t ism330dhcx_who_am_i(ISM330DHCX_HandleTypeDef *h_ism, uint8_t *buff);
/* Restore default configuration */
int32_t ism330dhcx_reset_set(ISM330DHCX_HandleTypeDef *h_ism, uint8_t val);
/* Read the CTRL3_C register */
int32_t ism330dhcx_reset_get(ISM330DHCX_HandleTypeDef *h_ism, uint8_t *buff);
/* Enable Block Data Update */
int32_t ism330dhcx_block_data_update_set(ISM330DHCX_HandleTypeDef *h_ism, uint8_t val);
/* Set Output Data Update */
int32_t ism330dhcx_xl_data_rate_set(ISM330DHCX_HandleTypeDef *h_ism, ism330dhcx_odr_xl_t val);
int32_t ism330dhcx_gy_data_rate_set(ISM330DHCX_HandleTypeDef *h_ism, ism330dhcx_odr_g_t val);
/* Set Full Scale */
int32_t ism330dhcx_xl_full_scale_set(ISM330DHCX_HandleTypeDef *h_ism, ism330dhcx_fs_xl_t val);
int32_t ism330dhcx_gy_full_scale_set(ISM330DHCX_HandleTypeDef *h_ism, ism330dhcx_fs_g_t val);
/* Configure Filtering chain (no Aux interface)
    Accelerometer - LPF1 + LPF2 path            */
int32_t ism330dhcx_xl_hp_path_on_out_set(ISM330DHCX_HandleTypeDef *h_ism, ism330dhcx_hp_slope_xl_en_t val);
int32_t ism330dhcx_xl_filter_lp2_set(ISM330DHCX_HandleTypeDef *h_ism, uint8_t val);

/********** Reading samples on Polling mod (no int) **********/

/* Read Acceleration Data Ready Flag */
int32_t ism330dhcx_xl_flag_data_ready_get(ISM330DHCX_HandleTypeDef *h_ism, uint8_t *val);
/* Read Acceleration Field Data */
int32_t ism330dhcx_acceleration_raw_get(ISM330DHCX_HandleTypeDef *h_ism, int16_t *val);

/* Read Acceleration Data Ready Flag */
int32_t ism330dhcx_gy_flag_data_ready_get(ISM330DHCX_HandleTypeDef *h_ism, uint8_t *val);
/* Read Angular Rate Field Data */
int32_t ism330dhcx_angular_rate_raw_get(ISM330DHCX_HandleTypeDef *h_ism, int16_t *val);

/* Read Temperature Data Ready Flag */
int32_t ism330dhcx_temp_flag_data_ready_get(ISM330DHCX_HandleTypeDef *h_ism, uint8_t *val);
/* Read Temperature  Data */
int32_t ism330dhcx_temperature_raw_get(ISM330DHCX_HandleTypeDef *h_ism, int16_t *val);

int32_t ism330dhcx_fsm_enable_get(ISM330DHCX_HandleTypeDef *h_ism,
                                  ism330dhcx_emb_fsm_enable_t *val);

int32_t ism330dhcx_mem_bank_set(ISM330DHCX_HandleTypeDef *h_ism,
                                ism330dhcx_reg_access_t val);

int32_t ism330dhcx_fsm_data_rate_get(ISM330DHCX_HandleTypeDef *h_ism,
                                     ism330dhcx_fsm_odr_t *val);

int32_t ism330dhcx_mlc_get(ISM330DHCX_HandleTypeDef *h_ism, uint8_t *val);

int32_t ism330dhcx_mlc_data_rate_get(ISM330DHCX_HandleTypeDef *h_ism,
                                     ism330dhcx_mlc_odr_t *val);

/**********          Conversion Function            **********/
/* Extern functions */
extern float_t ism330dhcx_from_fs2g_to_mg(int16_t lsb);
extern float_t ism330dhcx_from_fs4g_to_mg(int16_t lsb);
extern float_t ism330dhcx_from_fs8g_to_mg(int16_t lsb);
extern float_t ism330dhcx_from_fs16g_to_mg(int16_t lsb);
extern float_t ism330dhcx_from_fs125dps_to_mdps(int16_t lsb);
extern float_t ism330dhcx_from_fs250dps_to_mdps(int16_t lsb);
extern float_t ism330dhcx_from_fs500dps_to_mdps(int16_t lsb);
extern float_t ism330dhcx_from_fs1000dps_to_mdps(int16_t lsb);
extern float_t ism330dhcx_from_fs2000dps_to_mdps(int16_t lsb);
extern float_t ism330dhcx_from_fs4000dps_to_mdps(int16_t lsb);
extern float_t ism330dhcx_from_lsb_to_celsius(int16_t lsb);
extern float_t ism330dhcx_from_lsb_to_nsec(int32_t lsb);
