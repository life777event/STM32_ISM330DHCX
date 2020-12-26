#include "ism330dhcx_ll.h"

#define PROPERTY_DISABLE                (0U)
#define PROPERTY_ENABLE                 (1U)


/* Public struct */
typedef struct			//< Structure for ISM330DHCX data
{
	float_t acceleration_mg[3];		// 12 bytes
	float_t angular_rate_mdps[3];	// 12 bytes
	float_t temperature_degC;		// 4 bytes
} ism_data;							// = 28 bytes

typedef struct			//< Structure for ISM330DHCX config
{
	uint8_t		acc_data_rate;
	uint8_t		gyr_data_rate;
	uint8_t		acc_full_scale;
	uint8_t		gyr_full_scale;
	uint8_t		lpf1_path;
	uint8_t		lpf2_path;
} ism_conf;

/* Public functions */
int32_t HAL_ISM330DHCX_Write(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len);
int32_t HAL_ISM330DHCX_Read(void *handle, uint8_t reg, uint8_t *bufp, uint16_t len);
void HAL_ISM330DHCX_Init(void);
void HAL_ISM330DHCX_getConf(ism_conf* ism_c);
void HAL_ISM330DHCX_Poll(ism_data* ism_d);
