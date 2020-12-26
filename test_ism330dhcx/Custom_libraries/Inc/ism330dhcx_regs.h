#ifndef ISM330DHCX_REGS_H
#define ISM330DHCX_REGS_H

 /* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <math.h>

#define ISM3320DHCX_I2C_ADD_L   0x6AU
#define ISM3320DHCX_I2C_ADD_H   0x6BU

/* 7bytes-> Adress + 1byte -> R/W */
#define ISM3320DHCX_I2C_ADD_L_W	0xD4U
#define ISM3320DHCX_I2C_ADD_L_R	0xD5U

#define ISM3320DHCX_I2C_ADD_H_W	0xD6U
#define ISM3320DHCX_I2C_ADD_H_R	0xD7U



#define ISM3320DHCX_WHO_AM_I    0x6BU

#define PROPERTY_DISABLE                (0U)
#define PROPERTY_ENABLE                 (1U)

/* Pointers to the read/write functions */
typedef int32_t (*_write_ptr)(void*, uint8_t, uint8_t*, uint16_t);
typedef int32_t (*_read_ptr)(void*, uint8_t, uint8_t*, uint16_t);

/* ISM330DHCX Handler Structure */
typedef struct {
    _write_ptr  write;			//< Pointer to the Write function
    _read_ptr   read;			//< Pointer to the Read function

    void *handle;				//< Pointer to the communication peripheral handler
} ISM330DHCX_HandleTypeDef;

/* Register's Adress */
#define    FUNC_CFG_ACCESS				  0x01U  /*  1byte   /   RW  */
#define    PIN_CTRL						  0x02U  /*  1byte   /   RW  */
#define    RESERVED_0					  0x03U  /*  4byte   /   --  */
#define    FIFO_CTRL1       			  0x07U  /*  1byte   /   RW  */
#define    FIFO_CTRL2                     0x08U  /*  1byte   /   RW  */
#define    FIFO_CTRL3                     0x09U  /*  1byte   /   RW  */
#define    FIFO_CTRL4                     0x0AU  /*  1byte   /   RW  */
#define    COUNTER_BDR_REG1               0x0BU  /*  1byte   /   RW  */
#define    COUNTER_BDR_REG2               0x0CU  /*  1byte   /   RW  */
#define    INT1_CTRL                      0x0DU  /*  1byte   /   RW  */
#define    INT2_CTRL                      0x0EU  /*  1byte   /   RW  */
#define    WHO_AM_I                       0x0FU  /*  1byte   /   RO  */
#define    CTRL1_XL                       0x10U  /*  1byte   /   RW  */
#define    CTRL2_G                        0x11U  /*  1byte   /   RW  */
#define    CTRL3_C                        0x12U  /*  1byte   /   RW  */
#define    CTRL4_C                        0x13U  /*  1byte   /   RW  */
#define    CTRL5_C                        0x14U  /*  1byte   /   RW  */
#define    CTRL6_C                        0x15U  /*  1byte   /   RW  */
#define    CTRL7_G                        0x16U  /*  1byte   /   RW  */
#define    CTRL8_XL                       0x17U  /*  1byte   /   RW  */
#define    CTRL9_XL                       0x18U  /*  1byte   /   RW  */
#define    CTRL10_C                       0x19U  /*  1byte   /   RW  */
#define    ALL_INT_SRC                    0x1AU  /*  1byte   /   RO  */
#define    WAKE_UP_SRC                    0x1BU  /*  1byte   /   RO  */
#define    TAP_SRC                        0x1CU  /*  1byte   /   RO  */
#define    D6D_SRC                        0x1DU  /*  1byte   /   RO  */
#define    STATUS_SPIAUX                  0x1EU  /*  1byte   /   RO  */
#define    RESERVED_1                     0x1FU  /*  1byte   /   --  */
#define    OUT_TEMP_L                     0x20U  /*  1byte   /   RO  */
#define    OUT_TEMP_H                     0x21U  /*  1byte   /   RO  */
#define    OUTX_L_G                       0x22U  /*  1byte   /   RO  */
#define    OUTX_H_G                       0x23U  /*  1byte   /   RO  */
#define    OUTY_L_G                       0x24U  /*  1byte   /   RO  */
#define    OUTY_H_G                       0x25U  /*  1byte   /   RO  */
#define    OUTZ_L_G                       0x26U  /*  1byte   /   RO  */
#define    OUTZ_H_G                       0x27U  /*  1byte   /   RO  */
#define    OUTX_L_A                       0x28U  /*  1byte   /   RO  */
#define    OUTX_H_A                       0x29U  /*  1byte   /   RO  */
#define    OUTY_L_A                       0x2AU  /*  1byte   /   RO  */
#define    OUTY_H_A                       0x2BU  /*  1byte   /   RO  */
#define    OUTZ_L_A                       0x2CU  /*  1byte   /   RO  */
#define    OUTZ_H_A                       0x2DU  /*  1byte   /   RO  */
#define    RESERVED_2                     0x2EU  /*  7byte   /   --  */
#define    EMB_FUNC_STATUS_MAINPAGE       0x35U  /*  1byte   /   RO  */
#define    FSM_STATUS_A_MAINPAGE          0x36U  /*  1byte   /   RO  */
#define    FSM_STATUS_B_MAINPAGE          0x37U  /*  1byte   /   RO  */
#define    MLC_STATUS_MAINPAGE            0x38U  /*  1byte   /   RO  */
#define    STATUS_MASTER_MAINPAGE         0x39U  /*  1byte   /   RO  */
#define    FIFO_STATUS1                   0x3AU  /*  1byte   /   RO  */
#define    FIFO_STATUS2                   0x3BU  /*  4byte   /   --  */
#define    RESERVED_3                      0x3CU  /*  1byte   /   RO  */
#define    TIMESTAMP0                     0x40U  /*  1byte   /   RO  */
#define    TIMESTAMP1                     0x41U  /*  1byte   /   RO  */
#define    TIMESTAMP2                     0x42U  /*  1byte   /   RO  */
#define    TIMESTAMP3                     0x43U  /*  1byte   /   RO  */
#define    RESERVED_4                      0x44U  /*  13byte  /   --  */
#define    TAP_CFG0                       0x56U  /*  1byte   /   RW  */
#define    TAP_CFG1                       0x57U  /*  1byte   /   RW  */
#define    TAP_CFG2                       0x58U  /*  1byte   /   RW  */
#define    TAP_THS_6D                     0x59U  /*  1byte   /   RW  */
#define    INT_DUR2                       0x5AU  /*  1byte   /   RW  */
#define    WAKE_UP_THS                    0x5BU  /*  1byte   /   RW  */
#define    WAKE_UP_DUR                    0x5CU  /*  1byte   /   RW  */
#define    FREE_FALL                      0x5DU  /*  1byte   /   RW  */
#define    MD1_CFG                        0x5EU  /*  1byte   /   RW  */
#define    MD2_CFG                        0x5FU  /*  1byte   /   RW  */
#define    RESERVED_5                      0x60U  /*  3byte   /   --  */
#define    INTERNAL_FREQ_FINE             0x63U  /*  1byte   /   RO  */
#define    RESERVED_6                      0x64U  /*  11byte  /   --  */
#define    INT_OIS                        0x6FU  /*  1byte   /   RO  */
#define    CTRL1_OIS                      0x70U  /*  1byte   /   RO  */
#define    CTRL2_OIS                      0x71U  /*  1byte   /   RO  */
#define    CTRL3_OIS                      0x72U  /*  1byte   /   RO  */
#define    X_OFS_USR                      0x73U  /*  1byte   /   RW  */
#define    Y_OFS_USR                      0x74U  /*  1byte   /   RW  */
#define    Z_OFS_USR                      0x75U  /*  1byte   /   RW  */
#define    RESERVED_7                      0x76U  /*  2byte   /   --  */
#define    FIFO_DATA_OUT_TAG              0x78U  /*  1byte   /   RO  */
#define    FIFO_DATA_OUT_X_L              0x79U  /*  1byte   /   RO  */
#define    FIFO_DATA_OUT_X_H              0x7AU  /*  1byte   /   RO  */
#define    FIFO_DATA_OUT_Y_L              0x7BU  /*  1byte   /   RO  */
#define    FIFO_DATA_OUT_Y_H              0x7CU  /*  1byte   /   RO  */
#define    FIFO_DATA_OUT_Z_L              0x7DU  /*  1byte   /   RO  */
#define    FIFO_DATA_OUT_Z_H              0x7EU   /*  1byte   /   RO  */

/*
 *  @brief	Embedded Function Adress Register
 *
 *  @note	Actif only if FUNC_CFG_EN is set to '1' in FUNC_CFG_ACCESS (01h).
 */
typedef enum {
    PAGE_SEL                    =   0x02,
    RESERVED                    =   0x03,
    EMB_FUNC_EN_A               =   0x04,
    EMB_FUNC_EN_B               =   0x05,
    PAGE_ADDRESS                =   0x08,
    PAGE_VALUE                  =   0x09,
    EMB_FUNC_INT1               =   0x0A,
    FSM_INT1_A                  =   0x0B,
    FSM_INT1_B                  =   0x0C,
    MLC_INT1                    =   0x0D,
    EMB_FUNC_INT2               =   0x0E,
    FSM_INT2_A                  =   0x0F,
    FSM_INT2_B                  =   0x10,
    MLC_INT2                    =   0x11,
    EMB_FUNC_STATUS             =   0x12,
    FSM_STATUS_A                =   0x13,
    FSM_STATUS_B                =   0x14,
    MLC_STATUS                  =   0x15,
    PAGE_RW                     =   0x17,
            /*  RESERVED - 18-43 */
    EMB_FUNC_FIFO_CFG           =   0x44,
    FSM_ENABLE_A                =   0x46,
    FSM_ENABLE_B                =   0x47,
    FSM_LONG_COUNTER_L          =   0x48,
    FSM_LONG_COUNTER_H          =   0x49,
    FSM_LONG_COUNTER_CLEAR      =   0x4A,
    FSM_OUTS1                   =   0x4C,
    FSM_OUTS2                   =   0x4D,
    FSM_OUTS3                   =   0x4E,
    FSM_OUTS4                   =   0x4F,
    FSM_OUTS5                   =   0x50,
    FSM_OUTS6                   =   0x51,
	EMB_FUNC_ODR_CFG_B          =	0x5F,
	EMB_FUNC_ODR_CFG_C          =	0x60,
	ISM330DHCX_STEP_COUNTER_L   =	0x62,
	STEP_COUNTER_H              =	0x63,
	EMB_FUNC_SRC                =	0x64,
	EMB_FUNC_INIT_A             =	0x66,
	EMB_FUNC_INIT_B             =	0x67,
	MLC0_SRC                    =	0x70,
	MLC1_SRC                    =	0x71,
	MLC2_SRC                    =	0x72,
	MLC3_SRC                    =	0x73,
	MLC4_SRC                    =	0x74,
	MLC5_SRC                    =	0x75,
	MLC6_SRC                    =	0x76,
	MLC7_SRC                    =	0x77
} ism330_embfnc;

/*
 *  @brief	Embedded function page 0 Adress Register (External Magnetometer )
 *
 */
typedef enum {
    MAG_SENSITIVITY_L           =   0xBA,
    MAG_SENSITIVITY_H           =   0xBB,
    MAG_OFFX_L                  =   0xC0,
    MAG_OFFX_H                  =   0xC1,
    MAG_OFFY_L                  =   0xC2,
    MAG_OFFY_H                  =   0xC3,
    MAG_OFFZ_L                  =   0xC4,
    MAG_OFFZ_H                  =   0xC5,
    MAG_SI_XX_L                 =   0xC6,
    MAG_SI_XX_H                 =   0xC7,
    MAG_SI_XY_L                 =   0xC8,
    MAG_SI_XY_H                 =   0xC9,
    MAG_SI_XZ_L                 =   0xCA,
    MAG_SI_XZ_H                 =   0xCB,
    MAG_SI_YY_L                 =   0xCC,
    MAG_SI_YY_H                 =   0xCD,
    MAG_SI_YZ_L                 =   0xCE,
    MAG_SI_YZ_H                 =   0xCF,
    MAG_SI_ZZ_L                 =   0xD0,
    MAG_SI_ZZ_H                 =   0xD1,
    MAG_CFG_A                   =   0xD4,
    MAG_CFG_B                   =   0xD5,
    FSM_LC_TIMEOUT_L            =   0x7A,
    FSM_LC_TIMEOUT_H            =   0x7B,
    FSM_PROGRAMS                =   0x7C,
    FSM_START_ADD_L             =   0x7E,
    FSM_START_ADD_H             =   0x7F,
    PEDO_CMD_REG                =   0x83,
    PEDO_DEB_STEPS_CONF         =   0x84,
    PEDO_SC_DELTAT_L            =   0xD0,
    PEDO_SC_DELTAT_H            =   0xD1,
    MLC_MAG_SENSITIVITY_L       =   0xE8,
    MLC_MAG_SENSITIVITY_H       =   0xE9
} ism330_embfnc_page0;

/*
 *  @brief	Sensor Hub Adress Register
 *
 */
typedef enum {
    SENSOR_HUB_1 = 0x02,
    SENSOR_HUB_2 = 0x03,
    SENSOR_HUB_3 = 0x04,
    SENSOR_HUB_4 = 0x05,
    SENSOR_HUB_5 = 0x06,
    SENSOR_HUB_6 = 0x07,
    SENSOR_HUB_7 = 0x08,
    SENSOR_HUB_8 = 0x09,
    SENSOR_HUB_9 = 0x0A,
    SENSOR_HUB_10 = 0x0B,
    SENSOR_HUB_11 = 0x0C,
    SENSOR_HUB_12 = 0x0D,
    SENSOR_HUB_13 = 0x0E,
    SENSOR_HUB_14 = 0x0F,
    SENSOR_HUB_15 = 0x10,
    SENSOR_HUB_16 = 0x11,
    SENSOR_HUB_17 = 0x12,
    SENSOR_HUB_18 = 0x13,
    MASTER_CONFIG = 0x14,
    SLV0_ADD = 0x15,
    SLV0_SUBADD = 0x16,
    SLV0_CONFIG = 0x17,
    SLV1_ADD = 0x18,
    SLV1_SUBADD = 0x19,
    SLV1_CONFIG = 0x1A,
    SLV2_ADD = 0x1B,
    SLV2_SUBADD = 0x1C,
    SLV2_CONFIG = 0x1D,
    SLV3_ADD = 0x1E,
    SLV3_SUBADD = 0x1F,
    SLV3_CONFIG = 0x20,
    DATAWRITE_SLV0 = 0x21,
    STATUS_MASTER = 0x22
} ism330_sensor_hub;

/*  For all next registers:
 *  - Default value (if no notes), = 0x00
 *  - Format Little-Endian
 */

/* Enable embedded functions register */
typedef struct {
    uint8_t reserved0           : 6;
    /// Enable access to the embedded functions configuration registers.
    uint8_t reg_access		    : 2;
} ism330dhcx_func_cfg_access_t;

typedef enum {
  ISM330DHCX_USER_BANK           = 0,
  ISM330DHCX_SENSOR_HUB_BANK     = 1,
  ISM330DHCX_EMBEDDED_FUNC_BANK  = 2,
} ism330dhcx_reg_access_t;

/* Pins pull-up enable/disable register */
typedef struct {
    uint8_t reserved0           : 6;        // To '1'
    /// Enable pull-up on SDO pin.
    uint8_t ois_pu_en           : 1;
    /// Disable pull-up on both OCS_Aux and SDO_Aux pins.
    uint8_t ois_pu_dis          : 1;
} ism330dhcx_pin_ctrl_t;

typedef enum {
  ISM330DHCX_PULL_UP_DISC       = 0,
  ISM330DHCX_PULL_UP_CONNECT    = 1,
} ism330dhcx_sdo_pu_en_t;

typedef enum {
  ISM330DHCX_AUX_PULL_UP_DISC       = 0,
  ISM330DHCX_AUX_PULL_UP_CONNECT    = 1,
} ism330dhcx_ois_pu_dis_t;

/* FIFO Control register 1 */
typedef struct {
    /// FIFO watermark threshold, in conjunction withm WTM8 (fifo_ctrl2)
    uint8_t wtm                 : 8;
} ism330dhcx_fifo_ctrl1_t;

/* FIFO Control register 2 */
typedef struct {
    /// FIFO watermark threshold, in conjunction with WTM[7:0] in fifo_ctrl1
    uint8_t wtm8                : 1;
    /// This field configures the compression algorithm to write non-compressed data at each rate.
    uint8_t uncoptr_rate        : 2;
    uint8_t reserved0           : 1;
    /// Enables ODR CHANGE virtual sensor to be batched in FIFO
    uint8_t odrchg_en           : 1;
    uint8_t reserved1           : 1;
    /// Enables/Disables compression algorithm runtime
    uint8_t fifo_compr_rt_en    : 1;
    /// Sensing chain FIFO stop values memorization at threshold level
    uint8_t stop_on_wtm         : 1;
} ism330dhcx_ctrl2_t;

typedef enum {
  ISM330DHCX_CMP_DISABLE  = 0x00,
  ISM330DHCX_CMP_ALWAYS   = 0x04,
  ISM330DHCX_CMP_8_TO_1   = 0x05,
  ISM330DHCX_CMP_16_TO_1  = 0x06,
  ISM330DHCX_CMP_32_TO_1  = 0x07,
} ism330dhcx_uncoptr_rate_t;

/* FIFO Control register 3 */
typedef struct {
    /// Selects Batch Data Rate (write frequency in FIFO) for accelerometer data.
    uint8_t bdr_xl              : 4;
    /// Selects Batch Data Rate (write frequency in FIFO) for gyroscope data.
    uint8_t bdr_gy              : 4;
} ism330dhcx_fifo_ctrl3_t;

typedef enum {
  ISM330DHCX_XL_NOT_BATCHED       =  0,
  ISM330DHCX_XL_BATCHED_AT_12Hz5   =  1,
  ISM330DHCX_XL_BATCHED_AT_26Hz    =  2,
  ISM330DHCX_XL_BATCHED_AT_52Hz    =  3,
  ISM330DHCX_XL_BATCHED_AT_104Hz   =  4,
  ISM330DHCX_XL_BATCHED_AT_208Hz   =  5,
  ISM330DHCX_XL_BATCHED_AT_417Hz   =  6,
  ISM330DHCX_XL_BATCHED_AT_833Hz   =  7,
  ISM330DHCX_XL_BATCHED_AT_1667Hz  =  8,
  ISM330DHCX_XL_BATCHED_AT_3333Hz  =  9,
  ISM330DHCX_XL_BATCHED_AT_6667Hz  = 10,
  ISM330DHCX_XL_BATCHED_AT_6Hz5    = 11,
} ism330dhcx_bdr_xl_t;

typedef enum {
  ISM330DHCX_GY_NOT_BATCHED         = 0,
  ISM330DHCX_GY_BATCHED_AT_12Hz5    = 1,
  ISM330DHCX_GY_BATCHED_AT_26Hz     = 2,
  ISM330DHCX_GY_BATCHED_AT_52Hz     = 3,
  ISM330DHCX_GY_BATCHED_AT_104Hz    = 4,
  ISM330DHCX_GY_BATCHED_AT_208Hz    = 5,
  ISM330DHCX_GY_BATCHED_AT_417Hz    = 6,
  ISM330DHCX_GY_BATCHED_AT_833Hz    = 7,
  ISM330DHCX_GY_BATCHED_AT_1667Hz   = 8,
  ISM330DHCX_GY_BATCHED_AT_3333Hz   = 9,
  ISM330DHCX_GY_BATCHED_AT_6667Hz   = 10,
  ISM330DHCX_GY_BATCHED_6Hz5        = 11,
} ism330dhcx_bdr_gy_t;

/* FIFO Control register 4 */
typedef struct {
    /// FIFO mode selection
    uint8_t fifo_mode           : 3;
    uint8_t reserved0           : 1;
    /// Selects batch data rate (write frequency in FIFO) for temperature data
    uint8_t odr_t_batch         : 2;
    /// Selects decimation for timestamp batching in FIFO. Write rate will be the maximum rate between XL
    uint8_t dec_ts_batch        : 2;
} ism330dhcx_fifo_ctrl4_t;

typedef enum {
  ISM330DHCX_BYPASS_MODE             = 0,
  ISM330DHCX_FIFO_MODE               = 1,
  ISM330DHCX_STREAM_TO_FIFO_MODE     = 3,
  ISM330DHCX_BYPASS_TO_STREAM_MODE   = 4,
  ISM330DHCX_STREAM_MODE             = 6,
  ISM330DHCX_BYPASS_TO_FIFO_MODE     = 7,
} ism330dhcx_fifo_mode_t;

typedef enum {
  ISM330DHCX_NO_DECIMATION = 0,
  ISM330DHCX_DEC_1         = 1,
  ISM330DHCX_DEC_8         = 2,
  ISM330DHCX_DEC_32        = 3,
} ism330dhcx_dec_ts_batch_t;

typedef enum {
  ISM330DHCX_TEMP_NOT_BATCHED        = 0,
  ISM330DHCX_TEMP_BATCHED_AT_52Hz    = 1,
  ISM330DHCX_TEMP_BATCHED_AT_12Hz5   = 2,
  ISM330DHCX_TEMP_BATCHED_AT_1Hz6    = 3,
} ism330dhcx_odr_t_batch_t;

/* Counter batch data rate register 1 */
typedef struct {
    /// In conjunction with CNT_BDR_TH_[7:0] in COUNTER_BDR_REG2 (0Ch),
    uint8_t cnt_bdr_th          : 3;
    uint8_t reserved0           : 2;
    /// Selects the trigger for the internal counter of batch events between XL and gyro.
    uint8_t trig_counter_bdr    : 1;
    /// Resets the internal counter of batch events for a single sensor.
    uint8_t rst_counter_bdr     : 1;
    /// Enables pulsed data-ready mode
    uint8_t dataready_pulsed    : 1;
} ism330dhcx_counter_bdr_reg1_t;

typedef enum {
  ISM330DHCX_XL_BATCH_EVENT   = 0,
  ISM330DHCX_GYRO_BATCH_EVENT = 1,
} ism330dhcx_trig_counter_bdr_t;

typedef enum {
  ISM330DHCX_DRDY_LATCHED = 0,
  ISM330DHCX_DRDY_PULSED  = 1,
} ism330dhcx_dataready_pulsed_t;

/* Counter batch data rate register 2 */
typedef struct {
    /// In conjunction with CNT_BDR_TH_[8:10] in COUNTER_BDR_REG1
    uint8_t cnt_bdr_th          : 8;
} ism330dhcx_counter_bdr_reg2_t;

/* INT1 pin control register */
typedef struct {
    //  Enables accelerometer data-ready interrupt on INT1 pin.
    uint8_t int1_drdy_xl        : 1;
    //  Enables gyroscope data-ready interrupt on INT1 pin.
    uint8_t int1_drdx_g         : 1;
    //  Enables boot status on INT1 pin.
    uint8_t int1_boot           : 1;
    //  Enables FIFO threshold interrupt on INT1 pin.
    uint8_t int1_fifo_th        : 1;
    //  Enables FIFO overrun interrupt on INT1 pin.
    uint8_t int1_fifo_ovr       : 1;
    //  Enables FIFO full flag interrupt on INT1 pin.
    uint8_t int1_fifo_full      : 1;
    //  Enables COUNTER_BDR_IA interrupt on INT1.
    uint8_t int1_cnt_bdr        : 1;
    //  Sends DEN_DRDY (DEN stamped on Sensor Data flag) to INT1 pin.
    uint8_t den_drdy_flag       : 1;
} ism330dhcx_int1_ctrl_t;

/* INT2 pin control register */
typedef struct {
    //  Enables accelerometer data-ready interrupt on INT2 pin.
    uint8_t int2_drdy_xl        : 1;
    //  Enables gyroscope data-ready interrupt on INT2 pin.
    uint8_t int2_drdx_g         : 1;
    //  Enables boot status on INT2 pin.
    uint8_t int2_boot           : 1;
    //  Enables FIFO threshold interrupt on INT2 pin.
    uint8_t int2_fifo_th        : 1;
    //  Enables FIFO overrun interrupt on INT2 pin.
    uint8_t int2_fifo_ovr       : 1;
    //  Enables FIFO full flag interrupt on INT2 pin.
    uint8_t int2_fifo_full      : 1;
    //  Enables COUNTER_BDR_IA interrupt on INT2.
    uint8_t int2_cnt_bdr        : 1;
    uint8_t reserved0           : 1;
} ism330dhcx_int2_ctrl_t;

/* Who Am I register */
typedef struct {
    //  This is a read-only register.
    //  Its value is fixed at 6Bh.
    uint8_t who_am_i            : 8;
} ism330dhcx_who_am_i_t;

/* Accelerometer control register 1 */
typedef struct {
    uint8_t reserved0           : 1;
    //  Accelerometer high-resolution selection.
    uint8_t lpf2_xl_en          : 1;
    //  Accelerometer full-scale selection.
    uint8_t fs_xl               : 2;
    //  Accelerometer ODR selection.
    uint8_t odr_xl              : 4;
} ism330dhcx_ctrl1_xl_t;

typedef enum {
    ISM330DHCX_2g   = 0,
    ISM330DHCX_16g  = 1, /* if XL_FS_MODE = ‘1’ -> ISM330DHCX_2g */
    ISM330DHCX_4g   = 2,
    ISM330DHCX_8g   = 3,
} ism330dhcx_fs_xl_t;

typedef enum {
  ISM330DHCX_XL_ODR_OFF    = 0,
  ISM330DHCX_XL_ODR_12Hz5  = 1,
  ISM330DHCX_XL_ODR_26Hz   = 2,
  ISM330DHCX_XL_ODR_52Hz   = 3,
  ISM330DHCX_XL_ODR_104Hz  = 4,
  ISM330DHCX_XL_ODR_208Hz  = 5,
  ISM330DHCX_XL_ODR_417Hz  = 6,
  ISM330DHCX_XL_ODR_833Hz  = 7,
  ISM330DHCX_XL_ODR_1667Hz = 8,
  ISM330DHCX_XL_ODR_3333Hz = 9,
  ISM330DHCX_XL_ODR_6667Hz = 10,
  ISM330DHCX_XL_ODR_6Hz5   = 11, /* (low power only) */
} ism330dhcx_odr_xl_t;

/* Gyroscope control register 2 */
typedef struct {
    //  Selects gyro chain full-scale ±4000 dps.
    uint8_t fs_4000         : 1;
    //  Selects gyro chain full-scale ±125 dps
    uint8_t fs_125          : 1;
    //  Gyroscope chain full-scale selection
    uint8_t fs_g            : 2;
    //  Gyroscope output data rate selection.
    uint8_t odr_g           : 4;
} ism330dhcx_ctrl2_g_t;

typedef enum {
  ISM330DHCX_250dps = 0,
  ISM330DHCX_500dps = 1,
  ISM330DHCX_1000dps = 2,
  ISM330DHCX_2000dps = 3,
} ism330dhcx_fs_g_t;

typedef enum {
  ISM330DHCX_GY_ODR_OFF    = 0,
  ISM330DHCX_GY_ODR_12Hz5  = 1,
  ISM330DHCX_GY_ODR_26Hz   = 2,
  ISM330DHCX_GY_ODR_52Hz   = 3,
  ISM330DHCX_GY_ODR_104Hz  = 4,
  ISM330DHCX_GY_ODR_208Hz  = 5,
  ISM330DHCX_GY_ODR_417Hz  = 6,
  ISM330DHCX_GY_ODR_833Hz  = 7,
  ISM330DHCX_GY_ODR_1667Hz = 8,
  ISM330DHCX_GY_ODR_3333Hz = 9,
  ISM330DHCX_GY_ODR_6667Hz = 10,
} ism330dhcx_odr_g_t;

/* Control register 3 */
typedef struct {
    //  Software reset.
    uint8_t sw_reset            : 1;
    uint8_t reserved0           : 1;
    //  Register address automatically incremented during a multiple byte access with a serial interface (I²C or SPI).
    uint8_t if_inc              : 1;
    //  SPI Serial Interface Mode selection.
    uint8_t sim                 : 1;
    //  Push-pull/open-drain selection on INT1 and INT2 pins. This bit must be set to '0' when H_LACTIVE is set to '1'.
    uint8_t pp_od               : 1;
    //  Interrupt activation level.
    uint8_t h_lactive           : 1;
    //  Block Data Update.
    uint8_t bdu                 : 1;
    //  Reboots memory content.
    uint8_t boot                : 1;
} ism330dhcx_ctrl3_c_t;

typedef enum {
  ISM330DHCX_SPI_4_WIRE = 0,
  ISM330DHCX_SPI_3_WIRE = 1,
} ism330dhcx_sim_t;

typedef enum {
  ISM330DHCX_PUSH_PULL   = 0,
  ISM330DHCX_OPEN_DRAIN  = 1,
} ism330dhcx_pp_od_t;

typedef enum {
  ISM330DHCX_ACTIVE_HIGH = 0,
  ISM330DHCX_ACTIVE_LOW  = 1,
} ism330dhcx_h_lactive_t;

/* Control register 4 */
typedef struct {
    uint8_t reserved0           : 1;
    //  Enables gyroscope digital LPF1; the bandwidth can be selected through FTYPE[2:0] in CTRL6_C (15h).
    uint8_t lpf1_sel_g          : 1;
    //  Disables I²C interface. Default value: 0
    uint8_t i2c_disable         : 1;
    //  Enables data available
    uint8_t drdy_mask           : 1;
    uint8_t reserved1           : 1;
    //  All interrupt signals available on INT1 pin enable. Default value: 0
    uint8_t int2_on_int1        : 1;
    //  Enables gyroscope Sleep mode. Default value:0
    uint8_t sleep_g             : 1;
    uint8_t reserved2           : 1;
} ism330dhcx_ctrl4_c_t;

typedef enum {
  ISM330DHCX_I2C_ENABLE  = 0,
  ISM330DHCX_I2C_DISABLE = 1,
} ism330dhcx_i2c_disable_t;

/* Control register 5 */
typedef struct {
    //  Linear acceleration sensor self-test enable. Default value: 00
    uint8_t st_xl               : 2;
    //  Angular rate sensor self-test enable. Default value: 00
    uint8_t st_g                : 2;
    uint8_t reserved0           : 1;
    //  Circular burst-mode (rounding) read of the output registers. Default value: 00
    uint8_t rounding            : 2;
    uint8_t reserved1           : 1;
} ism330dhcx_ctrl5_c_t;

typedef enum {
  ISM330DHCX_XL_ST_DISABLE  = 0,
  ISM330DHCX_XL_ST_POSITIVE = 1,
  ISM330DHCX_XL_ST_NEGATIVE = 2,
} ism330dhcx_st_xl_t;

typedef enum {
  ISM330DHCX_GY_ST_DISABLE  = 0,
  ISM330DHCX_GY_ST_POSITIVE = 1,
  ISM330DHCX_GY_ST_NEGATIVE = 3,
} ism330dhcx_st_g_t;

typedef enum {
  ISM330DHCX_NO_ROUND      = 0,
  ISM330DHCX_ROUND_XL      = 1,
  ISM330DHCX_ROUND_GY      = 2,
  ISM330DHCX_ROUND_GY_XL   = 3,
} ism330dhcx_rounding_t;

/* Control register 6 */
typedef struct {
    //  Gyroscope low-pass filter (LPF1) bandwidth selection. Table 58 shows the selectable bandwidth values.
    uint8_t ftype               : 3;
    //  Weight of XL user offset bits of registers X_OFS_USR (73h), Y_OFS_USR (74h), Z_OFS_USR (75h)
    uint8_t usr_off_w           : 1;
    //  Disables high-performance operating mode for accelerometer. Default value: 0
    uint8_t xl_hm_mode          : 1;
    //  Enables DEN level-sensitive latched mode. Refer to Table 57.
    uint8_t lvl2_en             : 1;
    //  Enables DEN data level-sensitive trigger mode. Refer to Table 57.
    uint8_t lvl1_en             : 1;
    //  Enables DEN data edge-sensitive trigger mode. Refer to Table 57.
    uint8_t trig_en             : 1;
} ism330dhcx_ctrl6_c_t;

typedef enum {
  ISM330DHCX_ULTRA_LIGHT  = 0,
  ISM330DHCX_VERY_LIGHT   = 1,
  ISM330DHCX_LIGHT        = 2,
  ISM330DHCX_MEDIUM       = 3,
  ISM330DHCX_STRONG       = 4,
  ISM330DHCX_VERY_STRONG  = 5,
  ISM330DHCX_AGGRESSIVE   = 6,
  ISM330DHCX_XTREME       = 7,
} ism330dhcx_ftype_t;

typedef enum {
  ISM330DHCX_LSb_1mg  = 0,
  ISM330DHCX_LSb_16mg = 1,
} ism330dhcx_usr_off_w_t;

typedef enum {
  ISM330DHCX_HIGH_PERFORMANCE_MD  = 0,
  ISM330DHCX_LOW_NORMAL_POWER_MD  = 1,
} ism330dhcx_xl_hm_mode_t;

/* Control register 7 */
typedef struct {
    //  Enables/disables the OIS chain from primary interface when the OIS_ON_EN bit is '1'.
    uint8_t ois_on              : 1;
    //  Enables accelerometer user offset correction block; it's valid for the low-pass path
    uint8_t usr_off_on_out      : 1;
    //  Selects how to enable and disable the OIS chain, after first configuration and enabling through SPI2.
    uint8_t ois_on_en           : 1;
    uint8_t reserved0           : 1;
    //  Gyroscope digital HP filter cutoff selection
    uint8_t hpm_g               : 2;
    //  Enables gyroscope digital high-pass filter. The filter is enabled only if the gyro is in HP mode
    uint8_t hp_en_g             : 1;
    //  Disables high-performance operating mode for gyroscope.
    uint8_t g_hm_mode           : 1;
} ism330dhcx_ctrl7_c_t;

typedef enum {
  ISM330DHCX_AUX_ON                    = 1,
  ISM330DHCX_AUX_ON_BY_AUX_INTERFACE   = 0,
} ism330dhcx_ois_on_t;

typedef enum {
  ISM330DHCX_HP_FILTER_NONE     = 0x00,
  ISM330DHCX_HP_FILTER_16mHz    = 0x80,
  ISM330DHCX_HP_FILTER_65mHz    = 0x81,
  ISM330DHCX_HP_FILTER_260mHz   = 0x82,
  ISM330DHCX_HP_FILTER_1Hz04    = 0x83,
} ism330dhcx_hpm_g_t;

typedef enum {
  ISM330DHCX_GY_HIGH_PERFORMANCE  = 0,
  ISM330DHCX_GY_NORMAL            = 1,
} ism330dhcx_g_hm_mode_t;

/* Control register 8 */
typedef struct {
    //  LPF2 on 6D function selection
    uint8_t low_pass_on_6D      : 1;
    uint8_t reserved0           : 1;
    //  Accelerometer slope filter / high-pass filter selection.
    uint8_t hp_slope_xl_en      : 1;
    //  Enables accelerometer LPF2 and HPF fast-settling mode. The filter sets the second samples after
    //      writing this bit. Active only during device exit from power- down mode.
    uint8_t fastsettl_mode_xl   : 1;
    //  Enables accelerometer high-pass filter reference mode (valid for high-pass path -
    //      HP_SLOPE_XL_EN bit must be ‘1’)
    uint8_t hp_ref_mode_xl      : 1;
    //  Accelerometer LPF2 and HP filter configuration and cutoff setting.
    uint8_t hpcf_xl             : 3;
} ism330dhcx_ctrl8_xl_t;

typedef enum {
  ISM330DHCX_HP_PATH_DISABLE_ON_OUT    = 0x00,
  ISM330DHCX_SLOPE_ODR_DIV_4           = 0x10,
  ISM330DHCX_HP_ODR_DIV_10             = 0x11,
  ISM330DHCX_HP_ODR_DIV_20             = 0x12,
  ISM330DHCX_HP_ODR_DIV_45             = 0x13,
  ISM330DHCX_HP_ODR_DIV_100            = 0x14,
  ISM330DHCX_HP_ODR_DIV_200            = 0x15,
  ISM330DHCX_HP_ODR_DIV_400            = 0x16,
  ISM330DHCX_HP_ODR_DIV_800            = 0x17,
  ISM330DHCX_HP_REF_MD_ODR_DIV_10      = 0x31,
  ISM330DHCX_HP_REF_MD_ODR_DIV_20      = 0x32,
  ISM330DHCX_HP_REF_MD_ODR_DIV_45      = 0x33,
  ISM330DHCX_HP_REF_MD_ODR_DIV_100     = 0x34,
  ISM330DHCX_HP_REF_MD_ODR_DIV_200     = 0x35,
  ISM330DHCX_HP_REF_MD_ODR_DIV_400     = 0x36,
  ISM330DHCX_HP_REF_MD_ODR_DIV_800     = 0x37,
  ISM330DHCX_LP_ODR_DIV_10             = 0x01,
  ISM330DHCX_LP_ODR_DIV_20             = 0x02,
  ISM330DHCX_LP_ODR_DIV_45             = 0x03,
  ISM330DHCX_LP_ODR_DIV_100            = 0x04,
  ISM330DHCX_LP_ODR_DIV_200            = 0x05,
  ISM330DHCX_LP_ODR_DIV_400            = 0x06,
  ISM330DHCX_LP_ODR_DIV_800            = 0x07,
} ism330dhcx_hp_slope_xl_en_t;

/* Control register 9 */
typedef struct {
    uint8_t reserved0           : 1;
    //  Enables the proper device configuration.
    uint8_t device_conf         : 1;
    //  DEN active level configuration.
    uint8_t den_lh              : 1;
    //  Extends DEN functionality to accelerometer sensor.
    uint8_t den_xl_en           : 1;
    //  DEN stamping sensor selection.
    uint8_t den_xl_g            : 1;
    //  DEN value stored in LSB of Z-axis.
    uint8_t den_z               : 1;
    //  DEN value stored in LSB of Y-axis.
    uint8_t den_y               : 1;
    //  DEN value stored in LSB of X-axis.
    uint8_t den_x               : 1;
} ism330dhcx_ctrl9_xl_t;

typedef enum {
  ISM330DHCX_DEN_ACT_LOW  = 0,
  ISM330DHCX_DEN_ACT_HIGH = 1,
} ism330dhcx_den_lh_t;

typedef enum {
  ISM330DHCX_STAMP_IN_GY_DATA     = 0,
  ISM330DHCX_STAMP_IN_XL_DATA     = 1,
  ISM330DHCX_STAMP_IN_GY_XL_DATA  = 2,
} ism330dhcx_den_xl_g_t;

/* Control register 10 */
typedef struct {
    uint8_t reserved0           : 5;
    //  Enables timestamp counter.
    uint8_t timestamp_en        : 1;
    uint8_t RESERVED1           : 2;
} ism330dhcx_ctrl10_c_t;

/* Source register for all interrupts */
typedef struct {
    //  Free-fall event status.
    uint8_t ff_ia               : 1;
    //  Wake-up event status.
    uint8_t wu_ia               : 1;
    //  Single-tap event status.
    uint8_t single_tap          : 1;
    //  Double-tap event status
    uint8_t double_tap          : 1;
    //  Interrupt active for change in position of portrait, landscape, face-up, face-down.
    uint8_t d6d_ia              : 1;
    //  Detects change event in activity/inactivity status.
    uint8_t sleep_change_ia     : 1;
    uint8_t reserved0           : 1;
    //  Alerts timestamp overflow within 6.4 ms
    uint8_t timestamp_endcount  : 1;
} ism330dhcx_all_int_src_t;

/* Wake-up interrupt source register */
typedef struct {
    //  Wakeup event detection status on Z-axis.
    uint8_t z_wu                : 1;
    //  Wakeup event detection status on Y-axis.
    uint8_t y_wu                : 1;
    //  Wakeup event detection status on X-axis.
    uint8_t x_wu                : 1;
    //  Wakeup event detection status.
    uint8_t wu_ia               : 1;
    //  Sleep event status.
    uint8_t sleep_state         : 1;
    //  Free-fall event detection status.
    uint8_t ff_ia               : 1;
    //  Detects change event in activity/inactivity status.
    uint8_t sleep_change_ia     : 1;
    uint8_t reserved0           : 1;
} ism330dhcx_wake_up_src_t;

/* Tap source register */
typedef struct {
    //  Tap event detection status on Z-axis.
    uint8_t z_tap               : 1;
    //  Tap event detection status on Y-axis.
    uint8_t y_tap               : 1;
    //  Tap event detection status on X-axis.
    uint8_t x_tap               : 1;
    //  Sign of acceleration detected by tap event.
    uint8_t tap_sign            : 1;
    //  Double-tap event detection status.
    uint8_t double_tap          : 1;
    //  Single-tap event status.
    uint8_t single_tap          : 1;
    //  Tap event detection status.
    uint8_t tap_ia              : 1;
    uint8_t reserved0           : 1;
} ism330dhcx_tap_src_t;

/* Portrait, landscape, face-up and face-down source register */
typedef struct {
    //  X-axis low event (under threshold).
    uint8_t xl                  : 1;
    //  X-axis high event (under threshold).
    uint8_t xh                  : 1;
    //  Y-axis low event (under threshold).
    uint8_t yl                  : 1;
    //  Y-axis high event (under threshold).
    uint8_t yh                  : 1;
    //  Z-axis low event (under threshold).
    uint8_t zl                  : 1;
    //  Z-axis high event (under threshold).
    uint8_t zh                  : 1;
    //  Interrupt active for change position portrait, landscape, face-up, face-down.
    uint8_t d6d_ia              : 1;
    //  DEN data-ready signal. It is set high when data output is related to the data coming from a DEN active condition
    uint8_t den_drdy            : 1;
} ism330dhcx_drd_src_t;

/* STATUS_REG register (read by the primary interface I²C/SPI) */
typedef struct {
    //  Accelerometer new data available.
    uint8_t xlda                : 1;
    //  Gyroscope new data available.
    uint8_t gda                 : 1;
    //  Temperature new data available.
    uint8_t tda                 : 1;
    uint8_t reserved0           : 5;
} ism330dhcx_status_reg_t;

/* STATUS_SPIAux register (read by the auxiliary SPI) */
typedef struct {
    //  Accelerometer data available (reset when one of the high parts of the output data is read)
    uint8_t xlda                : 1;
    //  Gyroscope data available (reset when one of the high parts of the output data is read)
    uint8_t gda                 : 1;
    //  High when the gyroscope output is in the settling phase.
    uint8_t gyro_settling       : 1;
    uint8_t reserved0           : 5;
} ism330dhcx_spi_aux_t;

/*  Temp[15:0]
    Temperature sensor output data
    The value is expressed as two’s complement sign extended on the MSB.
*/
typedef struct {
    uint8_t temp                : 8;
} ism330dhcx_out_temp_l_t;
typedef struct {
    uint8_t temp                : 8;
} ism330dhcx_out_temp_h_t;

/*  OUTX_GYRO[15:0]
    Pitch axis (X) angular rate value
    D[15:0] expressed in two’s complement and its value depends on the interface used:
    SPI1/I²C: Gyro GP chain pitch axis output
    SPI2: Gyro OIS chain pitch axis output
*/
typedef struct {
    uint8_t d                   : 8;
} ism330dhcx_outx_l_g_t;
typedef struct {
    uint8_t d                   : 8;
} ism330dhcx_outx_h_g_t;

/*  OUTY_GYRO[15:0]
    Roll axis (Y) angular rate value
    D[15:0] expressed in two’s complement and its value depends on the interface used:
    SPI1/I²C: Gyro GP chain roll axis output
    SPI2: Gyro OIS chain roll axis output
*/
typedef struct {
    uint8_t d                   : 8;
} ism330dhcx_outy_l_g_t;
typedef struct {
    uint8_t d                   : 8;
} ism330dhcx_outy_h_g_t;

/*  OUTZ_GYRO[15:0]
    Yaw axis (Z) angular rate value
    D[15:0] expressed in two’s complement and its value depends on the interface used:
    SPI1/I²C: Gyro GP chain yaw axis output
    SPI2: Gyro OIS chain yaw axis output
*/
typedef struct {
    uint8_t d                   : 8;
} ism330dhcx_outz_l_g_t;
typedef struct {
    uint8_t d                   : 8;
} ism330dhcx_outz_h_g_t;

/*  OUTX_ACC[15:0]
    X-axis linear acceleration value.
    D[15:0] expressed in two’s complement and its value depends on the interface used:
    SPI1/I²C: Accelerometer GP chain X-axis output
    SPI2: Accelerometer OIS chain X-axis output
*/
typedef struct {
    uint8_t d                   : 8;
} ism330dhcx_outx_l_a_t;
typedef struct {
    uint8_t d                   : 8;
} ism330dhcx_outx_h_a_t;

/*  OUTY_ACC[15:0]
    Y-axis linear acceleration value
    D[15:0] expressed in two’s complement and its value depends on the interface used:
    SPI1/I²C: Accelerometer GP chain Y-axis output
    SPI2: Accelerometer OIS chain Y-axis output
*/
typedef struct {
    uint8_t d                   : 8;
} ism330dhcx_outy_l_a_t;
typedef struct {
    uint8_t d                   : 8;
} ism330dhcx_outy_h_a_t;

/*  OUTZ_ACC[15:0]
    Z-axis linear acceleration value
    D[15:0] expressed in two’s complement and its value depends on the interface used:
    SPI1/I²C: Accelerometer GP chain Z-axis output
    SPI2: Accelerometer OIS chain Z-axis output
*/
typedef struct {
    uint8_t d                   : 8;
} ism330dhcx_outz_l_a_t;
typedef struct {
    uint8_t d                   : 8;
} ism330dhcx_outz_h_a_t;

/*  Embedded function status register */
typedef struct {
    uint8_t reserved0           : 3;
    //  Interrupt status bit for step detection.
    uint8_t is_step_det         : 1;
    //  Interrupt status bit for tilt detection.
    uint8_t is_tilt             : 1;
    //  Interrupt status bit for significant motion detection
    uint8_t is_sigmot           : 1;
    uint8_t reserved1           : 1;
    //  Interrupt status bit for FSM long counter tiemout interrupt event.
    uint8_t is_fsm_lc           : 1;
} ism330dhcx_emb_func_status_mainpage_t;

/*  Finite State Machine status register */
typedef struct {
    uint8_t is_fsm1             : 1;
    uint8_t is_fsm2             : 1;
    uint8_t is_fsm3             : 1;
    uint8_t is_fsm4             : 1;
    uint8_t is_fsm5             : 1;
    uint8_t is_fsm6             : 1;
    uint8_t is_fsm7             : 1;
    uint8_t is_fsm8             : 1;
} ism330dhcx_fsm_status_a_mainpage_t;

/*  Finite State Machine status register */
typedef struct {
    uint8_t is_fsm9             : 1;
    uint8_t is_fsm10            : 1;
    uint8_t is_fsm11            : 1;
    uint8_t is_fsm12            : 1;
    uint8_t is_fsm13            : 1;
    uint8_t is_fsm14            : 1;
    uint8_t is_fsm15            : 1;
    uint8_t is_fsm16            : 1;
} ism330dhcx_fsm_status_b_mainpage_t;

/*  Machine Learning Core status register */
typedef struct {
    uint8_t is_mlc1             : 1;
    uint8_t is_mlc2             : 1;
    uint8_t is_mlc3             : 1;
    uint8_t is_mlc4             : 1;
    uint8_t is_mlc5             : 1;
    uint8_t is_mlc6             : 1;
    uint8_t is_mlc7             : 1;
    uint8_t is_mlc8             : 1;
} ism330dhcx_mlc_status_mainpage_t;

/*  Sensor hub source register */
typedef struct {
    //  Sensor hub communication status
    uint8_t sens_hub_endop      : 1;
    uint8_t reserved0           : 2;
    //  This bit is set to 1 if NACK on slave 0 communicaiton
    uint8_t slave0_nack         : 1;
    //  This bit is set to 1 if NACK on slave 1 communicaiton
    uint8_t slave1_nack         : 1;
    //  This bit is set to 1 if NACK on slave 2 communicaiton
    uint8_t slave2_nack         : 1;
    //  This bit is set to 1 if NACK on slave 3 communicaiton
    uint8_t slave3_nack         : 1;
    //  When the bit WRITE_ONCE in MASTER_CONFIG (14h) is configured as 1,
    //      this bit is set to 1 when the write operation on slave 0 has
    //      been performed and completed.
    uint8_t wr_once_done        : 1;
} ism330dhcx_status_master_mainpage_t;

/*  FIFO status register 1 */
typedef struct {
    // Number of unread sensor data (TAG + 6 bytes) stored in FIFO
    //  In conjunction with DIFF_FIFO[9:8] in FIFO_STATUS2
    uint8_t diff_fifo           : 8;
} ism330dhcx_fifo_status1_t;

/*  FIFO status register 2 */
typedef struct {
    // In conjunction with DIFF_FIFO[0:7] in FIFO_STATUS1
    uint8_t diff_fifo           : 2;
    uint8_t reserved0           : 1;
    // Latched FIFO overrun status.
    uint8_t fifo_ovr_latched    : 1;
    // Counter BDR reaches the CNT_BDR_TH[10:0] threshold set in
    //  COUNTER_BDR_REG1 and COUNTER_BDR_REG2.
    uint8_t counter_bdr_ia      : 1;
    // Smart FIFO full status
    uint8_t fifo_full_ia        : 1;
    // FIFO Overrun status
    uint8_t fifo_ovr_ia         : 1;
    // FIFO Watermark status
    uint8_t fifo_wtm_ia         : 1;
} ism330dhcx_fifo_status2_t;

/*
    Timestamp first data output register (r).
    The value is expressed as a 32-bit word and the bit resolution is 25 µs.
*/
//  D[0:7]
typedef struct {
    uint8_t d                   : 8;
} ism330dhcx_timestamp0_t;
//  D[8:15]
typedef struct {
    uint8_t d                   : 8;
} ism330dhcx_timestamp1_t;
//  D[16:23]
typedef struct {
    uint8_t d                   : 8;
} ism330dhcx_timestamp2_t;
//  D[24:32]
typedef struct {
    uint8_t d                   : 8;
} ism330dhcx_timestamp3;

/*  Activity/inactivity functions, configuration of filtering, and tap recognition functions */
typedef struct {
    // Latched interrupt
    uint8_t lir                 : 1;
    // Enable Z direction in tap recognition
    uint8_t tap_z_en            : 1;
    // Enable Y direction in tap recognition
    uint8_t tap_y_en            : 1;
    // Enable X direction in tap recognition
    uint8_t tap_x_en            : 1;
    // HPF or SLOPE filter selection on wake-up and Activity/Inactivity functions.
    uint8_t slope_fds           : 1;
    // Activity/inactivity interrupt mode configuration.
    //  If INT1_SLEEP_CHANGE or INT2_SLEEP_CHANGE bits are enabled, drives the sleep status or
    //  sleep change on the INT pins
    uint8_t sleep_status_on_int : 1;
    // This bit allows immediately clearing the latched interrupts of an event detection upon the read of
    //  the corresponding status register. It must be set to 1 together with LIR.
    uint8_t int_clr_on_read     : 1;
    uint8_t reserved0           : 1;
} ism330dhcx_tap_cfg0;

typedef enum {
  ISM330DHCX_ALL_INT_PULSED            = 0,
  ISM330DHCX_BASE_LATCHED_EMB_PULSED   = 1,
  ISM330DHCX_BASE_PULSED_EMB_LATCHED   = 2,
  ISM330DHCX_ALL_INT_LATCHED           = 3,
} ism330dhcx_lir_t;

typedef enum {
  ISM330DHCX_USE_SLOPE = 0,
  ISM330DHCX_USE_HPF   = 1,
} ism330dhcx_slope_fds_t;

typedef enum {
  ISM330DHCX_DRIVE_SLEEP_CHG_EVENT = 0,
  ISM330DHCX_DRIVE_SLEEP_STATUS    = 1,
} ism330dhcx_sleep_status_on_int_t;

/*  Tap configuration register */
typedef struct {
    // X-axis tap recognition threshold.
    uint8_t tap_ths_x           : 5;
    // Selection of axis priority for TAP detection.
    uint8_t tap_priority        : 3;
} ism330dhcx_tap_cfg1_t;

typedef enum {
  ISM330DHCX_XYZ = 0,
  ISM330DHCX_YXZ = 1,
  ISM330DHCX_XZY = 2,
  ISM330DHCX_ZYX = 3,
  ISM330DHCX_YZX = 5,
  ISM330DHCX_ZXY = 6,
} ism330dhcx_tap_priority_t;

/*  Enables interrupt and inactivity functions, and tap recognition functions */
typedef struct {
    // Y-axis tap recofnition threshold.
    uint8_t tap_ths_y           : 5;
    // Enable activity/inactivity (sleep function)
    uint8_t inact_en            : 2;
    // Enable basic interrupts (6D/4D, free-fall, wake-up, tap, inactivity)
    uint8_t interrupts_enable   : 1;
} ism330dhcx_tap_cfg2_t;

typedef enum {
  ISM330DHCX_XL_AND_GY_NOT_AFFECTED      = 0,
  ISM330DHCX_XL_12Hz5_GY_NOT_AFFECTED    = 1,
  ISM330DHCX_XL_12Hz5_GY_SLEEP           = 2,
  ISM330DHCX_XL_12Hz5_GY_PD              = 3,
} ism330dhcx_inact_en_t;

/*  Portrait/landscape position and tap function threshold register */
typedef struct {
    // Z-axis recognition threshold
    uint8_t tap_ths_z           : 5;
    // Threshold for 4D/6D function
    uint8_t sixd_ths            : 2;
    // Enables detection of 4D orientation, Z-axis position detection is disabled.
    uint8_t d4d_en              : 1;
} ism330dhcx_tap_ths_6D_t;

typedef enum {
  ISM330DHCX_DEG_80  = 0,
  ISM330DHCX_DEG_70  = 1,
  ISM330DHCX_DEG_60  = 2,
  ISM330DHCX_DEG_50  = 3,
} ism330dhcx_sixd_ths_t;

/*  Tap recognition function setting register */
typedef struct {
    // Maximum duration of overthreshold event
    uint8_t shock               : 2;
    // Expected quiet time after a tap detection
    uint8_t quiet               : 2;
    // Duration of maximum time gap for double-tap recognition
    uint8_t dur                 : 4;
} ism330dhcx_int_dur2_t;

/*  Single/double-tap selection and wake-up configuration */
typedef struct {
    // Threshold for wakeup (1LSB weight depends on WAKE_THS_W in WAKE_UP_DUR)
    uint8_t wk_ths              : 6;
    // Sends the low pass filtered data with user offset correction to the wake up funcion
    uint8_t usr_off_on_wu       : 1;
    // Single/double-tap event enable
    uint8_t single_double_tap   : 1;
} ism330dhcx_wake_up_ths_t;

typedef enum {
  ISM330DHCX_ONLY_SINGLE        = 0,
  ISM330DHCX_BOTH_SINGLE_DOUBLE = 1,
} ism330dhcx_single_double_tap_t;

/*  Free-fall, wakeup and sleep mode functions duration setting register */
typedef struct {
    // Duration to go in sleep mode
    uint8_t sleep_dur           : 4;
    // Weight of 1 LSB of wakeup threshold
    uint8_t wake_ths_w          : 1;
    // Wake up duration event
    uint8_t wake_dur            : 2;
    // Free fall duration event
    uint8_t ff_dur5             : 1;
} ism330dhcx_wake_up_dur_t;

typedef enum {
  ISM330DHCX_LSb_FS_DIV_64       = 0,
  ISM330DHCX_LSb_FS_DIV_256      = 1,
} ism330dhcx_wake_ths_w_t;

/*  Free-fall function duration setting register */
typedef struct {
    // Free-fall threshold setting
    uint8_t ff_ths              : 3;
    // Free-fall duration event
    //  For the complete configuration of the free fall duration, refer to FF_DUR5 in WAKE_UP_DUR (5Ch)
    //  configuration.
    uint8_t ff_dur              : 5;
} ism330dhcx_free_fall_t;

typedef enum {
  ISM330DHCX_FF_TSH_156mg = 0,
  ISM330DHCX_FF_TSH_219mg = 1,
  ISM330DHCX_FF_TSH_250mg = 2,
  ISM330DHCX_FF_TSH_312mg = 3,
  ISM330DHCX_FF_TSH_344mg = 4,
  ISM330DHCX_FF_TSH_406mg = 5,
  ISM330DHCX_FF_TSH_469mg = 6,
  ISM330DHCX_FF_TSH_500mg = 7,
} ism330dhcx_ff_ths_t;

/*  Functions routing on INT1 register */
typedef struct {
    //  Routing of sensor hub communication concluded event on INT1.
    uint8_t int1_shub           : 1;
    // Routing of embedded functions event on INT1
    uint8_t int1_emb_func       : 1;
    // Routing of 6D event on INT1
    uint8_t int1_6d;
    // Routing of tap event on INT1
    uint8_t int1_double_tap     : 1;
    // Routing of free-fall event on INT1
    uint8_t int1_ff             : 1;
    // Routing of wakeup event on INT1
    uint8_t int1_wu             : 1;
    // Routing of single-tap recognition event on INT1
    uint8_t int1_single_tap     : 1;
    // Routing of activity/inactivity recognition on INT1
    uint8_t int1_sleep_change   : 1;
} ism330dhcx_md1_cfg_t;

/*  Functions routing on INT2 register */
typedef struct {
    //  Enables routing on INT2 pin of the alert for timestamp overflow within 6.4 ms.
    uint8_t int2_timestamp      : 1;
    // Routing of embedded functions event on INT2
    uint8_t int2_emb_func       : 1;
    // Routing of 6D event on INT1
    uint8_t int2_6d;
    // Routing of tap event on INT1
    uint8_t int2_double_tap     : 1;
    // Routing of free-fall event on INT1
    uint8_t int2_ff             : 1;
    // Routing of wakeup event on INT1
    uint8_t int2_wu             : 1;
    // Routing of single-tap recognition event on INT1
    uint8_t int2_single_tap     : 1;
    // Routing of activity/inactivity recognition on INT1
    uint8_t int2_sleep_change   : 1;
} ism330dhcx_md2_cfg_t;

/*  Internal frequency register */
typedef struct {
    // Difference in percentage of the effective ODR (and timestamp rate)
    //  with respect to the typical step (0.15%).
    //  8-bit format, 2's complement.
    uint8_t freq_fine           : 8;
} ism330dhcx_internal_freq_fine_t;

/*  OIS interrupt configuration register and accelerometer self-test enable setting.
    Primary interface for read-only (r);
    only Aux SPI can write to this register
*/
typedef struct {
    // Selects accelerometer self-test
    //  effective only if XL OIS chain is enabled
    uint8_t st_xl_ois           : 2;
    uint8_t reserved0           : 3;
    // Indicates polarity of DEN signal on OIS chain.
    uint8_t den_lh_ois          : 1;
    // Enables level-sensitive latched mode on the OIS chain.
    uint8_t lvl2_ois            : 1;
    // Enables OIS chain DRDY on INT2 pin. This setting has priority over all other INT2 settings.
    uint8_t int2_drdy_ois       : 1;
} ism330dhcx_int_ois_t;

typedef enum {
  ISM330DHCX_AUX_XL_DISABLE = 0,
  ISM330DHCX_AUX_XL_POS     = 1,
  ISM330DHCX_AUX_XL_NEG     = 2,
} ism330dhcx_st_xl_ois_t;

typedef enum {
  ISM330DHCX_AUX_DEN_ACTIVE_LOW     = 0,
  ISM330DHCX_AUX_DEN_ACTIVE_HIGH    = 1,
} ism330dhcx_den_lh_ois_t;

typedef enum {
  ISM330DHCX_AUX_DEN_DISABLE         = 0,
  ISM330DHCX_AUX_DEN_LEVEL_TRIG      = 2,
  ISM330DHCX_AUX_DEN_LEVEL_LATCH     = 3,
} ism330dhcx_lvl2_ois_t;

/*
    OIS configuration register.
    Primary interface for read-only (r);
    only Aux SPI can write to this register (r/w).
*/
typedef struct {
    // Enables OIS chain data processing for gyro in Mode 3 and Mode 4 (mode4_en = 1) and accelerometer data in Mode 4 (mode4_en = 1).
    //  When the OIS chain is enabled, the OIS outputs are available through the SPI2 in registers OUTX_L_G
    //      (22h) and OUTX_H_G (23h) through OUTZ_L_A (2Ch) and OUTZ_H_A (2Dh) and STATUS_REG (1Eh) /
    //      STATUS_SPIAux (1Eh), and LPF1 is dedicated to this chain.
    uint8_t ois_en_spi2         : 1;
    // Selects gyroscope OIS chain full-scale +/- 125 dps.
    uint8_t fs_125_ois          : 1;
    // Selects gyroscope OIS chain full-sclae
    uint8_t fs_g_ois            : 2;
    // Enables accelerometer OIS chain. OIS outputs are available through SPI2
    //  in registers OUTX_L_A and OUTX_H_A or OUT_Z_L_A and OUT_Z_H_A
    uint8_t mode4_en            : 1;
    // Select SPI wire interface (3 or 4)
    uint8_t sim_ois             : 1;
    // Enables level-sensitive trigge mode on OIS chain
    uint8_t lvl1_ois            : 1;
    uint8_t reserved0           : 1;
} ism330dhcx_ctrl1_ois_t;

typedef enum {
  ISM330DHCX_AUX_DISABLE  = 0,
  ISM330DHCX_MODE_3_GY    = 1,
  ISM330DHCX_MODE_4_GY_XL = 3,
} ism330dhcx_ois_en_spi2_t;

typedef enum {
  ISM330DHCX_125dps_AUX  =  0x04,
  ISM330DHCX_250dps_AUX  =  0x00,
  ISM330DHCX_500dps_AUX  =  0x01,
  ISM330DHCX_1000dps_AUX =  0x02,
  ISM330DHCX_2000dps_AUX =  0x03,
} ism330dhcx_fs_g_ois_t;

typedef enum {
    ISM330DHCX_AUX_SPI_4_WIRE = 0,
    ISM330DHCX_AUX_SPI_3_WIRE = 1,
} ism330dhcx_sim_ois_t;

//< DEN mode selection can be done using the LVL1_OIS bit
//  of register CTRL1_OIS (70h) and the LVL2_OIS bit of
//  register INT_OIS (6Fh).
typedef enum {                          // LV1_OIS  LV2_OIS
  ISM330DHCX_DEN_DISABLE    = 0,        //      0    0
  ISM330DHCX_LEVEL_FIFO     = 6,        //      0
  ISM330DHCX_LEVEL_LETCHED  = 3,        //      1
  ISM330DHCX_LEVEL_TRIGGER  = 2,        //      0
  ISM330DHCX_EDGE_TRIGGER   = 4,        //      0
} ism330dhcx_den_mode_t;

/*
    OIS configuration register.
*/
typedef struct {
    // Enables gyroscope OIS chain digital high-pass filter
    uint8_t hp_en_ois           : 1;
    // Selects gyroscope digital LPFA filter bandwith.
    uint8_t ftype_ois           : 2;
    uint8_t reserved0           : 1;
    // Selects gyroscope OIS chain digital high-pass filter cutoff.
    uint8_t hpm_ois             : 2;
    uint8_t reserved1           : 2;
} ism330dhcx_ctrl2_ois_t;

typedef enum {
  ISM330DHCX_351Hz39 = 0,
  ISM330DHCX_236Hz63 = 1,
  ISM330DHCX_172Hz70 = 2,
  ISM330DHCX_937Hz91 = 3,
} ism330dhcx_ftype_ois_t;

typedef enum {
  ISM330DHCX_AUX_HP_DISABLE = 0x00,
  ISM330DHCX_AUX_HP_Hz016   = 0x10,
  ISM330DHCX_AUX_HP_Hz065   = 0x11,
  ISM330DHCX_AUX_HP_Hz260   = 0x12,
  ISM330DHCX_AUX_HP_1Hz040  = 0x13,
} ism330dhcx_hpm_ois_t;

/*
    OIS configuration register.
*/
typedef struct {
    // Disables OIS chain clamp
    uint8_t st_ois_clampdis     : 1;
    // Selects gyroscope OIS chain self-test
    uint8_t st_ois              : 2;
    // Selects accelerometer OIS channel bandwith
    uint8_t filter_xl_conf_ois  : 3;
    // Selects accelerometer OIS channel full-scale
    uint8_t fs_xl_ois           : 2;
} ism330dhcx_ctrl3_ois_t;

typedef enum {
  ISM330DHCX_ENABLE_CLAMP  = 0,
  ISM330DHCX_DISABLE_CLAMP = 1,
} ism330dhcx_st_ois_clampdis_t;

typedef enum {
  ISM330DHCX_AUX_GY_DISABLE = 0,
  ISM330DHCX_AUX_GY_POS     = 1,
  ISM330DHCX_AUX_GY_NEG     = 3,
} ism330dhcx_st_ois_t;

typedef enum {
  ISM330DHCX_631Hz = 0,
  ISM330DHCX_295Hz = 1,
  ISM330DHCX_140Hz = 2,
  ISM330DHCX_68Hz2 = 3,
  ISM330DHCX_33Hz6 = 4,
  ISM330DHCX_16Hz7 = 5,
  ISM330DHCX_8Hz3  = 6,
  ISM330DHCX_4Hz11 = 7,
} ism330dhcx_filter_xl_conf_ois_t;

typedef enum {
  ISM330DHCX_AUX_2g  = 0,
  ISM330DHCX_AUX_16g = 1,
  ISM330DHCX_AUX_4g  = 2,
  ISM330DHCX_AUX_8g  = 3,
} ism330dhcx_fs_xl_ois_t;

/*
    ²Accelerometer axis user offset correction (r/w).
    The offset value set in the OFS_USR offset register is
    internally subtracted from the acceleration value measured on the axis.

    Accelerometer axis user offset correction expressed in two’s complement, weight depends on
    USR_OFF_W in CTRL6_C (15h). The value must be in the range [-127 127].
*/
typedef struct {
    uint8_t x_ofs_usr           : 8;
} ism330dhcx_x_ofs_usr_t;
typedef struct {
    uint8_t y_ofs_usr           : 8;
} ism330dhcx_y_ofs_usr_t;
typedef struct {
    uint8_t z_ofs_usr           : 8;
} ism330dhcx_z_ofs_usr_t;

/*  FIFO Tag register */
typedef struct {
    // Parity check of TAG content
    uint8_t tag_parity          : 1;
    // 2-bit counter wich identifies sensor time slot
    uint8_t tag_cnt              : 2;
    // Identifies the sensor in all FIFO_DATA_OUT_ registers.
    // Voir table suivante
    uint8_t tag_sensor          : 5;
} ism330dhcx_fifo_data_out_tag_t;

typedef enum {
  ISM330DHCX_GYRO_NC_TAG    = 1,
  ISM330DHCX_XL_NC_TAG,
  ISM330DHCX_TEMPERATURE_TAG,
  ISM330DHCX_TIMESTAMP_TAG,
  ISM330DHCX_CFG_CHANGE_TAG,
  ISM330DHCX_XL_NC_T_2_TAG,
  ISM330DHCX_XL_NC_T_1_TAG,
  ISM330DHCX_XL_2XC_TAG,
  ISM330DHCX_XL_3XC_TAG,
  ISM330DHCX_GYRO_NC_T_2_TAG,
  ISM330DHCX_GYRO_NC_T_1_TAG,
  ISM330DHCX_GYRO_2XC_TAG,
  ISM330DHCX_GYRO_3XC_TAG,
  ISM330DHCX_SENSORHUB_SLAVE0_TAG,
  ISM330DHCX_SENSORHUB_SLAVE1_TAG,
  ISM330DHCX_SENSORHUB_SLAVE2_TAG,
  ISM330DHCX_SENSORHUB_SLAVE3_TAG,
  ISM330DHCX_STEP_CPUNTER_TAG,
  ISM330DHCX_GAME_ROTATION_TAG,
  ISM330DHCX_GEOMAG_ROTATION_TAG,
  ISM330DHCX_ROTATION_TAG,
  ISM330DHCX_SENSORHUB_NACK_TAG = 0x19,
} ism330dhcx_fifo_tag_t;

/*  FIFO data output X */
typedef struct {
    // [D0-D7]
    uint8_t d                   : 8;
} ism330dhcx_fifo_data_out_x_l_t;
typedef struct {
    // [D8-D15]
    uint8_t d                   : 8;
} ism330dhcx_fifo_data_out_x_h_t;

/*  FIFO data output Y */
typedef struct {
    // [D0-D7]
    uint8_t d                   : 8;
} ism330dhcx_fifo_data_out_y_l_t;
typedef struct {
    // [D8-D15]
    uint8_t d                   : 8;
} ism330dhcx_fifo_data_out_y_h_t;

/*  FIFO data output Z */
typedef struct {
    // [D0-D7]
    uint8_t d                   : 8;
} ism330dhcx_fifo_data_out_z_l_t;
typedef struct {
    // [D8-D15]
    uint8_t d                   : 8;
} ism330dhcx_fifo_data_out_z_h_t;

/***************** Embeded functions registers *************/

/*  Enable advanced features dedicated page */
typedef struct {
    uint8_t reserved0           : 1;        // Must be set to '1'
    uint8_t reserved1           : 3;
    // Select the advanced features dedicated page
    uint8_t page_sel            : 4;
} ism330dhcx_page_sel_t;

/* Embedded functions enable register */
typedef struct {
    uint8_t reserved0           : 3;
    // Enable pedometer algorithm.
    uint8_t pedo_en             : 1;
    // Enable tilt calculation.
    uint8_t tilt_en             : 1;
    // Enable significant motion detection function.
    uint8_t sign_motion_en      : 1;
    uint8_t reserved1           : 2;
} ism330dhcx_emb_func_en_a_t;

/* Embedded functions enable register */
typedef struct {
    // Enable Finite State Machine (FSM) feature.
    uint8_t fsm_en              : 1;
    uint8_t reserved0           : 2;
    // Enable FIFO compression feature.
    uint8_t fifo_compr_en       : 1;
    // Enable Machine Learning Core feature.
    uint8_t mlc_en              : 1;
    uint8_t reserved1           : 3;
} ism330dhcx_emb_func_en_b_t;

/* Page adress register */
typedef struct {
/*
    After setting the bit PAGE_WRITE / PAGE_READ in register PAGE_RW (17h),
    this register is used to set the address of the register to be written/read
    in the advanced features page selected through the bits PAGE_SEL[3:0]
    in register PAGE_SEL (02h).
*/
    uint8_t page_addr           : 8;
} ism330dhcx_page_adress_t;

/* Page value register */
typedef struct {
/*
    These bits are used to write
    (if the bit PAGE_WRITE = 1 in register PAGE_RW (17h))
    or read
    (if the bit PAGE_READ = 1 in register PAGE_RW (17h))
    the data at the address PAGE_ADDR[7:0] of the selected
    advanced features page.
*/
    uint8_t page_value          : 8;
} ism330dhcx_page_value_t;

/* INT1 pin control register */
typedef struct {
    uint8_t reserved0           : 3;
    // Routing of pedometer step recognition event on INT1.
    uint8_t int1_step_detector  : 1;
    // Routing of tilt event on INT1.
    uint8_t int1_tilt           : 1;
    // Routing of significant motion event on INT1.
    uint8_t int1_sig_mot        : 1;
    uint8_t reserved1           : 1;
    // Routing of FSM long counter timeout interrupt event on INT1.
    uint8_t int1_fsm_lc         : 1;
} ism330dhcx_emb_func_int1_t;

/*  INT1 pin control register
    Routing of FSMX interrupt event on INT1. */
typedef struct {
    uint8_t int1_fsm1           : 1;
    uint8_t int1_fsm2           : 1;
    uint8_t int1_fsm3           : 1;
    uint8_t int1_fsm4           : 1;
    uint8_t int1_fsm5           : 1;
    uint8_t int1_fsm6           : 1;
    uint8_t int1_fsm7           : 1;
    uint8_t int1_fsm8           : 1;
} ism330dhcx_fsm_int1_a_t;

/*  INT1 pin control register
    Routing of FSMX interrupt event on INT1. */
typedef struct {
    uint8_t int1_fsm9           : 1;
    uint8_t int1_fsm10          : 1;
    uint8_t int1_fsm11          : 1;
    uint8_t int1_fsm12          : 1;
    uint8_t int1_fsm13          : 1;
    uint8_t int1_fsm14          : 1;
    uint8_t int1_fsm15          : 1;
    uint8_t int1_fsm16          : 1;
} ism330dhcx_fsm_int1_b_t;

/*  INT1 pin control register
    Routing of MLCX interrupt event on INT1  */
typedef struct {
    uint8_t int1_mlc1           : 1;
    uint8_t int1_mlc2           : 1;
    uint8_t int1_mlc3           : 1;
    uint8_t int1_mlc4           : 1;
    uint8_t int1_mlc5           : 1;
    uint8_t int1_mlc6           : 1;
    uint8_t int1_mlc7           : 1;
    uint8_t int1_mlc8           : 1;
} ism330dhcx_mlc_int1_t;

/* INT2 pin control register */
typedef struct {
    uint8_t reserved0           : 3;
    // Routing of pedometer step recognition event on INT2.
    uint8_t int2_step_detector  : 1;
    // Routing of tilt event on INT2.
    uint8_t int2_tilt           : 1;
    // Routing of significant motion event on INT2.
    uint8_t int2_sig_mot        : 1;
    uint8_t reserved1           : 1;
    // Routing of FSM long counter timeout interrupt event on INT2.
    uint8_t int2_fsm_lc         : 1;
} ism330dhcx_emb_func_int2_t;

/*  INT2 pin control register
    Routing of FSMX interrupt event on INT2. */
typedef struct {
    uint8_t int2_fsm1           : 1;
    uint8_t int2_fsm2           : 1;
    uint8_t int2_fsm3           : 1;
    uint8_t int2_fsm4           : 1;
    uint8_t int2_fsm5           : 1;
    uint8_t int2_fsm6           : 1;
    uint8_t int2_fsm7           : 1;
    uint8_t int2_fsm8           : 1;
} ism330dhcx_fsm_int2_a_t;

/*  INT2 pin control register
    Routing of FSMX interrupt event on INT2. */
typedef struct {
    uint8_t int2_fsm9           : 1;
    uint8_t int2_fsm10          : 1;
    uint8_t int2_fsm11          : 1;
    uint8_t int2_fsm12          : 1;
    uint8_t int2_fsm13          : 1;
    uint8_t int2_fsm14          : 1;
    uint8_t int2_fsm15          : 1;
    uint8_t int2_fsm16          : 1;
} ism330dhcx_fsm_int2_b_t;

/*  INT2 pin control register
    Routing of MLCX interrupt event on INT2  */
typedef struct {
    uint8_t int2_mlc1           : 1;
    uint8_t int2_mlc2           : 1;
    uint8_t int2_mlc3           : 1;
    uint8_t int2_mlc4           : 1;
    uint8_t int2_mlc5           : 1;
    uint8_t int2_mlc6           : 1;
    uint8_t int2_mlc7           : 1;
    uint8_t int2_mlc8           : 1;
} ism330dhcx_mlc_int2_t;

/* Embedded function status register */
typedef struct {
    uint8_t reserved0           : 3;
    // Interrupt status bit for step detection
    uint8_t is_step_det         : 1;
    // Interrupt status bit for tilt detection
    uint8_t is_tilt             : 1;
    // Interrupt status bit for significant motion detection
    uint8_t is_sigmot           : 1;
    uint8_t reserved1           : 1;
    // Interrupt status bit for FSM long counter timeout interrupt event.
    uint8_t is_fsm_lc           : 1;
} ism330dhcx_emb_func_status_t;

/*  Finite State Machine status register
    Interrupt status bit for FSM interrupt event. */
typedef struct {
    uint8_t is_fsm1             : 1;
    uint8_t is_fsm2             : 1;
    uint8_t is_fsm3             : 1;
    uint8_t is_fsm4             : 1;
    uint8_t is_fsm5             : 1;
    uint8_t is_fsm6             : 1;
    uint8_t is_fsm7             : 1;
    uint8_t is_fsm8             : 1;
} ism330dhcx_fsm_status_a_t;
/*  Finite State Machine status register */
typedef struct {
    uint8_t is_fsm9             : 1;
    uint8_t is_fsm10            : 1;
    uint8_t is_fsm11            : 1;
    uint8_t is_fsm12            : 1;
    uint8_t is_fsm13            : 1;
    uint8_t is_fsm14            : 1;
    uint8_t is_fsm15            : 1;
    uint8_t is_fsm16            : 1;
} ism330dhcx_fsm_status_b_t;

/*  Machine Learning Core status register
    Interrupt status bit for MLC interrupt event. */
typedef struct {
    uint8_t is_mlc1             : 1;
    uint8_t is_mlc2             : 1;
    uint8_t is_mlc3             : 1;
    uint8_t is_mlc4             : 1;
    uint8_t is_mlc5             : 1;
    uint8_t is_mlc6             : 1;
    uint8_t is_mlc7             : 1;
    uint8_t is_mlc8             : 1;
} ism330dhcx_mlc_status_t;

/*  Enable read and write mode of advanced features dedicated page */
typedef struct {
    uint8_t reserved0           : 5;
    // Enable reads from the selected advanced features dedicated page.
    uint8_t page_read           : 1;
    // Enable writes to the selected advanced features dedicated page.
    uint8_t page_write          : 1;
    // Latched Interrupt mode for Embedded Functions.
    uint8_t emb_func_lir        : 1;
} ism330dhcx_page_rw_t;

/* Embedded functions batching configuration register */
typedef struct {
    uint8_t reserved0           : 6;
    // Enable FIFO batching of step counter values.
    uint8_t pedo_fifo_en        : 1;
    uint8_t reserved1           : 1;
} ism330dhcx_emb_func_fifo_cfg_t;

/* FSM enable register */
typedef struct {
    uint8_t fsm1_en             : 1;
    uint8_t fsm2_en             : 1;
    uint8_t fsm3_en             : 1;
    uint8_t fsm4_en             : 1;
    uint8_t fsm5_en             : 1;
    uint8_t fsm6_en             : 1;
    uint8_t fsm7_en             : 1;
    uint8_t fsm8_en             : 1;
} ism330dhcx_fsm_enable_a_t;
/* FSM enable register */
typedef struct {
    uint8_t fsm9_en             : 1;
    uint8_t fsm10_en            : 1;
    uint8_t fsm11_en            : 1;
    uint8_t fsm12_en            : 1;
    uint8_t fsm13_en            : 1;
    uint8_t fsm14_en            : 1;
    uint8_t fsm15_en            : 1;
    uint8_t fsm16_en            : 1;
} ism330dhcx_fsm_enable_b_t;

typedef struct {
	ism330dhcx_fsm_enable_a_t     fsm_enable_a;
	ism330dhcx_fsm_enable_b_t     fsm_enable_b;
} ism330dhcx_emb_fsm_enable_t;

/* FSM long counter status register
    Long counter value is an unsigned integer value (16-bit format);
    this value can be reset using the LC_CLEAR bit
    in FSM_LONG_COUNTER_CLEAR (4Ah) register.   */
typedef struct {
    uint8_t fsm_lc_0            : 1;
    uint8_t fsm_lc_1            : 1;
    uint8_t fsm_lc_2            : 1;
    uint8_t fsm_lc_3            : 1;
    uint8_t fsm_lc_4            : 1;
    uint8_t fsm_lc_5            : 1;
    uint8_t fsm_lc_6            : 1;
    uint8_t fsm_lc_7            : 1;
} ism330dhcx_fsm_long_counter_l_t;
typedef struct {
    uint8_t fsm_lc_8            : 1;
    uint8_t fsm_lc_9            : 1;
    uint8_t fsm_lc_10           : 1;
    uint8_t fsm_lc_11           : 1;
    uint8_t fsm_lc_12           : 1;
    uint8_t fsm_lc_13           : 1;
    uint8_t fsm_lc_14           : 1;
    uint8_t fsm_lc_15           : 1;
} ism330dhcx_fsm_long_counter_h_t;

/*  FSM long counter reset register */
typedef struct {
    // Clear FSM long counter value.
    uint8_t fsm_lc_clear        : 1;
    // This read-only bit is automatically set to 1 when the long counter reset is done.
    uint8_t fsm_lc_cleared      : 1;
} ism330dhcx_fsm_long_counter_clear_t;

/*  FSM1 output register */
typedef struct {
    // FSM1 output: negative event detected on the vector
    uint8_t n_v                 : 1;
    // FSM1 output: positive event detected on the vector
    uint8_t p_v                 : 1;
    // FSM1 output: negative event detected on the Z-axis
    uint8_t n_z                 : 1;
    // FSM1 output: positive event detected on the Z-axis
    uint8_t p_z                 : 1;
    // FSM1 output: negative event detected on the Y-axis
    uint8_t n_y                 : 1;
    // FSM1 output: positive event detected on the Y-axis
    uint8_t p_y                 : 1;
    // FSM1 output: negative event detected on the X-axis
    uint8_t n_x                 : 1;
    // FSM1 output: positive event detected on the X-axis
    uint8_t p_x                 : 1;
} ism330dhcx_fsm_outs1_t;

/* FSM2 output register */
typedef struct {
    // FSM2 output: negative event detected on the vector
    uint8_t n_v                 : 1;
    // FSM2 output: positive event detected on the vector
    uint8_t p_v                 : 1;
    // FSM2 output: negative event detected on the Z-axis
    uint8_t n_z                 : 1;
    // FSM2 output: positive event detected on the Z-axis
    uint8_t p_z                 : 1;
    // FSM2 output: negative event detected on the Y-axis
    uint8_t n_y                 : 1;
    // FSM2 output: positive event detected on the Y-axis
    uint8_t p_y                 : 1;
    // FSM2 output: negative event detected on the X-axis
    uint8_t n_x                 : 1;
    // FSM2 output: positive event detected on the X-axis
    uint8_t p_x                 : 1;
} ism330dhcx_fsm_outs2_t;

/* FSM3 output register */
typedef struct {
    // FSM3 output: negative event detected on the vector
    uint8_t n_v                 : 1;
    // FSM3 output: positive event detected on the vector
    uint8_t p_v                 : 1;
    // FSM3 output: negative event detected on the Z-axis
    uint8_t n_z                 : 1;
    // FSM3 output: positive event detected on the Z-axis
    uint8_t p_z                 : 1;
    // FSM3 output: negative event detected on the Y-axis
    uint8_t n_y                 : 1;
    // FSM3 output: positive event detected on the Y-axis
    uint8_t p_y                 : 1;
    // FSM3 output: negative event detected on the X-axis
    uint8_t n_x                 : 1;
    // FSM3 output: positive event detected on the X-axis
    uint8_t p_x                 : 1;
} ism330dhcx_fsm_outs3_t;

/* FSM4 output register */
typedef struct {
    // FSM4 output: negative event detected on the vector
    uint8_t n_v                 : 1;
    // FSM4 output: positive event detected on the vector
    uint8_t p_v                 : 1;
    // FSM4 output: negative event detected on the Z-axis
    uint8_t n_z                 : 1;
    // FSM4 output: positive event detected on the Z-axis
    uint8_t p_z                 : 1;
    // FSM4 output: negative event detected on the Y-axis
    uint8_t n_y                 : 1;
    // FSM4 output: positive event detected on the Y-axis
    uint8_t p_y                 : 1;
    // FSM4 output: negative event detected on the X-axis
    uint8_t n_x                 : 1;
    // FSM4 output: positive event detected on the X-axis
    uint8_t p_x                 : 1;
} ism330dhcx_fsm_outs4_t;

/* FSM5 output register */
typedef struct {
    // FSM5 output: negative event detected on the vector
    uint8_t n_v                 : 1;
    // FSM5 output: positive event detected on the vector
    uint8_t p_v                 : 1;
    // FSM5 output: negative event detected on the Z-axis
    uint8_t n_z                 : 1;
    // FSM5 output: positive event detected on the Z-axis
    uint8_t p_z                 : 1;
    // FSM5 output: negative event detected on the Y-axis
    uint8_t n_y                 : 1;
    // FSM5 output: positive event detected on the Y-axis
    uint8_t p_y                 : 1;
    // FSM5 output: negative event detected on the X-axis
    uint8_t n_x                 : 1;
    // FSM5 output: positive event detected on the X-axis
    uint8_t p_x                 : 1;
} ism330dhcx_fsm_outs5_t;

/* FSM6 output register */
typedef struct {
    // FSM6 output: negative event detected on the vector
    uint8_t n_v                 : 1;
    // FSM6 output: positive event detected on the vector
    uint8_t p_v                 : 1;
    // FSM6 output: negative event detected on the Z-axis
    uint8_t n_z                 : 1;
    // FSM6 output: positive event detected on the Z-axis
    uint8_t p_z                 : 1;
    // FSM6 output: negative event detected on the Y-axis
    uint8_t n_y                 : 1;
    // FSM6 output: positive event detected on the Y-axis
    uint8_t p_y                 : 1;
    // FSM6 output: negative event detected on the X-axis
    uint8_t n_x                 : 1;
    // FSM6 output: positive event detected on the X-axis
    uint8_t p_x                 : 1;
} ism330dhcx_fsm_outs6_t;

/* FSM7 output register */
typedef struct {
    // FSM7 output: negative event detected on the vector
    uint8_t n_v                 : 1;
    // FSM7 output: positive event detected on the vector
    uint8_t p_v                 : 1;
    // FSM7 output: negative event detected on the Z-axis
    uint8_t n_z                 : 1;
    // FSM7 output: positive event detected on the Z-axis
    uint8_t p_z                 : 1;
    // FSM7 output: negative event detected on the Y-axis
    uint8_t n_y                 : 1;
    // FSM7 output: positive event detected on the Y-axis
    uint8_t p_y                 : 1;
    // FSM7 output: negative event detected on the X-axis
    uint8_t n_x                 : 1;
    // FSM7 output: positive event detected on the X-axis
    uint8_t p_x                 : 1;
} ism330dhcx_fsm_outs7_t;

/* FSM8 output register */
typedef struct {
    // FSM8 output: negative event detected on the vector
    uint8_t n_v                 : 1;
    // FSM8 output: positive event detected on the vector
    uint8_t p_v                 : 1;
    // FSM8 output: negative event detected on the Z-axis
    uint8_t n_z                 : 1;
    // FSM8 output: positive event detected on the Z-axis
    uint8_t p_z                 : 1;
    // FSM8 output: negative event detected on the Y-axis
    uint8_t n_y                 : 1;
    // FSM8 output: positive event detected on the Y-axis
    uint8_t p_y                 : 1;
    // FSM8 output: negative event detected on the X-axis
    uint8_t n_x                 : 1;
    // FSM8 output: positive event detected on the X-axis
    uint8_t p_x                 : 1;
} ism330dhcx_fsm_outs8_t;

/* FSM9 output register */
typedef struct {
    // FSM9 output: negative event detected on the vector
    uint8_t n_v                 : 1;
    // FSM9 output: positive event detected on the vector
    uint8_t p_v                 : 1;
    // FSM9 output: negative event detected on the Z-axis
    uint8_t n_z                 : 1;
    // FSM9 output: positive event detected on the Z-axis
    uint8_t p_z                 : 1;
    // FSM9 output: negative event detected on the Y-axis
    uint8_t n_y                 : 1;
    // FSM9 output: positive event detected on the Y-axis
    uint8_t p_y                 : 1;
    // FSM9 output: negative event detected on the X-axis
    uint8_t n_x                 : 1;
    // FSM9 output: positive event detected on the X-axis
    uint8_t p_x                 : 1;
} ism330dhcx_fsm_outs9_t;

/* FSM10 output register */
typedef struct {
    // FSM10 output: negative event detected on the vector
    uint8_t n_v                 : 1;
    // FSM10 output: positive event detected on the vector
    uint8_t p_v                 : 1;
    // FSM10 output: negative event detected on the Z-axis
    uint8_t n_z                 : 1;
    // FSM10 output: positive event detected on the Z-axis
    uint8_t p_z                 : 1;
    // FSM10 output: negative event detected on the Y-axis
    uint8_t n_y                 : 1;
    // FSM10 output: positive event detected on the Y-axis
    uint8_t p_y                 : 1;
    // FSM10 output: negative event detected on the X-axis
    uint8_t n_x                 : 1;
    // FSM10 output: positive event detected on the X-axis
    uint8_t p_x                 : 1;
} ism330dhcx_fsm_outs10_t;

/* FSM11 output register */
typedef struct {
    // FSM11 output: negative event detected on the vector
    uint8_t n_v                 : 1;
    // FSM11 output: positive event detected on the vector
    uint8_t p_v                 : 1;
    // FSM11 output: negative event detected on the Z-axis
    uint8_t n_z                 : 1;
    // FSM11 output: positive event detected on the Z-axis
    uint8_t p_z                 : 1;
    // FSM11 output: negative event detected on the Y-axis
    uint8_t n_y                 : 1;
    // FSM11 output: positive event detected on the Y-axis
    uint8_t p_y                 : 1;
    // FSM11 output: negative event detected on the X-axis
    uint8_t n_x                 : 1;
    // FSM11 output: positive event detected on the X-axis
    uint8_t p_x                 : 1;
} ism330dhcx_fsm_outs11_t;

/* FSM12 output register */
typedef struct {
    // FSM12 output: negative event detected on the vector
    uint8_t n_v                 : 1;
    // FSM12 output: positive event detected on the vector
    uint8_t p_v                 : 1;
    // FSM12 output: negative event detected on the Z-axis
    uint8_t n_z                 : 1;
    // FSM12 output: positive event detected on the Z-axis
    uint8_t p_z                 : 1;
    // FSM12 output: negative event detected on the Y-axis
    uint8_t n_y                 : 1;
    // FSM12 output: positive event detected on the Y-axis
    uint8_t p_y                 : 1;
    // FSM12 output: negative event detected on the X-axis
    uint8_t n_x                 : 1;
    // FSM12 output: positive event detected on the X-axis
    uint8_t p_x                 : 1;
} ism330dhcx_fsm_outs12_t;

/* FSM13 output register */
typedef struct {
    // FSM13 output: negative event detected on the vector
    uint8_t n_v                 : 1;
    // FSM13 output: positive event detected on the vector
    uint8_t p_v                 : 1;
    // FSM13 output: negative event detected on the Z-axis
    uint8_t n_z                 : 1;
    // FSM13 output: positive event detected on the Z-axis
    uint8_t p_z                 : 1;
    // FSM13 output: negative event detected on the Y-axis
    uint8_t n_y                 : 1;
    // FSM13 output: positive event detected on the Y-axis
    uint8_t p_y                 : 1;
    // FSM13 output: negative event detected on the X-axis
    uint8_t n_x                 : 1;
    // FSM13 output: positive event detected on the X-axis
    uint8_t p_x                 : 1;
} ism330dhcx_fsm_outs13_t;

/* FSM14 output register */
typedef struct {
    // FSM14 output: negative event detected on the vector
    uint8_t n_v                 : 1;
    // FSM14 output: positive event detected on the vector
    uint8_t p_v                 : 1;
    // FSM14 output: negative event detected on the Z-axis
    uint8_t n_z                 : 1;
    // FSM14 output: positive event detected on the Z-axis
    uint8_t p_z                 : 1;
    // FSM14 output: negative event detected on the Y-axis
    uint8_t n_y                 : 1;
    // FSM14 output: positive event detected on the Y-axis
    uint8_t p_y                 : 1;
    // FSM14 output: negative event detected on the X-axis
    uint8_t n_x                 : 1;
    // FSM14 output: positive event detected on the X-axis
    uint8_t p_x                 : 1;
} ism330dhcx_fsm_outs14_t;

/* FSM15 output register */
typedef struct {
    // FSM15 output: negative event detected on the vector
    uint8_t n_v                 : 1;
    // FSM15 output: positive event detected on the vector
    uint8_t p_v                 : 1;
    // FSM15 output: negative event detected on the Z-axis
    uint8_t n_z                 : 1;
    // FSM15 output: positive event detected on the Z-axis
    uint8_t p_z                 : 1;
    // FSM15 output: negative event detected on the Y-axis
    uint8_t n_y                 : 1;
    // FSM15 output: positive event detected on the Y-axis
    uint8_t p_y                 : 1;
    // FSM15 output: negative event detected on the X-axis
    uint8_t n_x                 : 1;
    // FSM15 output: positive event detected on the X-axis
    uint8_t p_x                 : 1;
} ism330dhcx_fsm_outs15_t;

/* FSM16 output register */
typedef struct {
    // FSM16 output: negative event detected on the vector
    uint8_t n_v                 : 1;
    // FSM16 output: positive event detected on the vector
    uint8_t p_v                 : 1;
    // FSM16 output: negative event detected on the Z-axis
    uint8_t n_z                 : 1;
    // FSM16 output: positive event detected on the Z-axis
    uint8_t p_z                 : 1;
    // FSM16 output: negative event detected on the Y-axis
    uint8_t n_y                 : 1;
    // FSM16 output: positive event detected on the Y-axis
    uint8_t p_y                 : 1;
    // FSM16 output: negative event detected on the X-axis
    uint8_t n_x                 : 1;
    // FSM16 output: positive event detected on the X-axis
    uint8_t p_x                 : 1;
} ism330dhcx_fsm_outs16_t;

/*  Finite State Machine output data rate configuration register */
typedef struct {
    uint8_t reserved0           : 2;    // '1'
    uint8_t reserved1           : 1;
    // Finite State Machine ODR configuration (voir ism330dhcx_fsm_odr_t)
    uint8_t fsm_odr             : 2;
    uint8_t reserved2           : 2;
} ism330dhcx_emb_func_odr_cfg_b_t;

typedef enum {
  ISM330DHCX_ODR_FSM_12Hz5 = 0,
  ISM330DHCX_ODR_FSM_26Hz  = 1,
  ISM330DHCX_ODR_FSM_52Hz  = 2,
  ISM330DHCX_ODR_FSM_104Hz = 3,
} ism330dhcx_fsm_odr_t;

/*  Machine Learning Core output data rate configuration register */
typedef struct {
    uint8_t reserved0           : 1;    // '1'
    uint8_t reserved1           : 1;
    uint8_t reserved2           : 1;    // '1'
    uint8_t reserved3           : 1;
    // Machine Learning Core ODR configuration (voir ism330dhcx_mlc_odr_t)
    uint8_t mlc_odr             : 2;
    uint8_t reserved4           : 2;
} ism330dhcx_emb_func_odr_cfg_c_t;

typedef enum {
  ISM330DHCX_ODR_PRGS_12Hz5 = 0,
  ISM330DHCX_ODR_PRGS_26Hz  = 1,
  ISM330DHCX_ODR_PRGS_52Hz  = 2,
  ISM330DHCX_ODR_PRGS_104Hz = 3,
} ism330dhcx_mlc_odr_t;

/* Step counter output register
    Step counter output */
typedef struct {
    // STEP[0:7]
    uint8_t step0               : 1;
    uint8_t step1               : 1;
    uint8_t step2               : 1;
    uint8_t step3               : 1;
    uint8_t step4               : 1;
    uint8_t step5               : 1;
    uint8_t step6               : 1;
    uint8_t step7               : 1;
} ism330dhcx_step_counter_l_t;
typedef struct {
    // STEP[8:15]
    uint8_t step8               : 1;
    uint8_t step9               : 1;
    uint8_t step10              : 1;
    uint8_t step11              : 1;
    uint8_t step12              : 1;
    uint8_t step13              : 1;
    uint8_t step14              : 1;
    uint8_t step15              : 1;
} ism330dhcx_step_counter_h_t;

/* Embedded function source register */
typedef struct {
    uint8_t reserved0           : 1;
    // This bit is equal to 1 when the step count is increased. Read-only bit.
    uint8_t stepcounter_bit_set : 1;
    // Step counter overflow status. Read-only bit.
    uint8_t step_overflow       : 1;
    // Pedometer step recognition on delta time status. Read-only bit.
    uint8_t step_count_delta_ia : 1;
    // Step detector event detection status. Read-only bit.
    uint8_t step_detected       : 1;
    uint8_t reserved1           : 1;
    // Reset pedometer step counter. Read/write bit.
    uint8_t pedo_rst_step       : 1;
} ism330dhcx_emb_func_src_t;

/*  Embedded functions initialization register */
typedef struct {
    uint8_t reserved0           : 1;
    // Pedometer Step Counter/Detector algorithm initialization request.
    uint8_t step_det_init       : 1;
    // Tilt algorithm initialization request.
    uint8_t tilt_init           : 1;
    // Significant Motion Detection algorithm initialization request.
    uint8_t sig_mot_init        : 1;
    uint8_t reserved1           : 1;
} ism330dhcx_emb_func_init_a_t;

/*  Embedded functions initialization register */
typedef struct {
    // FSM initialization request
    uint8_t fsm_init            : 1;
    uint8_t reserved0           : 2;
    // FIFO compression feature initialization request
    uint8_t fifo_compr_init     : 1;
    // Machine learning core initialization request
    uint8_t mlc_init            : 1;
    uint8_t reserved1           : 3;
} ism330dhcx_emb_func_init_b_t;

/*  Machine Learning Core source register */
typedef struct {
    uint8_t mlc0_src_0          : 1;
    uint8_t mlc0_src_1          : 1;
    uint8_t mlc0_src_2          : 1;
    uint8_t mlc0_src_3          : 1;
    uint8_t mlc0_src_4          : 1;
    uint8_t mlc0_src_5          : 1;
    uint8_t mlc0_src_6          : 1;
    uint8_t mlc0_src_7          : 1;
} ism330dhcx_mlc0_src_t;
typedef struct {
    uint8_t mlc1_src_0          : 1;
    uint8_t mlc1_src_1          : 1;
    uint8_t mlc1_src_2          : 1;
    uint8_t mlc1_src_3          : 1;
    uint8_t mlc1_src_4          : 1;
    uint8_t mlc1_src_5          : 1;
    uint8_t mlc1_src_6          : 1;
    uint8_t mlc1_src_7          : 1;
} ism330dhcx_mlc1_src_t;
typedef struct {
    uint8_t mlc2_src_0          : 1;
    uint8_t mlc2_src_1          : 1;
    uint8_t mlc2_src_2          : 1;
    uint8_t mlc2_src_3          : 1;
    uint8_t mlc2_src_4          : 1;
    uint8_t mlc2_src_5          : 1;
    uint8_t mlc2_src_6          : 1;
    uint8_t mlc2_src_7          : 1;
} ism330dhcx_mlc2_src_t;
typedef struct {
    uint8_t mlc3_src_0          : 1;
    uint8_t mlc3_src_1          : 1;
    uint8_t mlc3_src_2          : 1;
    uint8_t mlc3_src_3          : 1;
    uint8_t mlc3_src_4          : 1;
    uint8_t mlc3_src_5          : 1;
    uint8_t mlc3_src_6          : 1;
    uint8_t mlc3_src_7          : 1;
} ism330dhcx_mlc3_src_t;
typedef struct {
    uint8_t mlc4_src_0          : 1;
    uint8_t mlc4_src_1          : 1;
    uint8_t mlc4_src_2          : 1;
    uint8_t mlc4_src_3          : 1;
    uint8_t mlc4_src_4          : 1;
    uint8_t mlc4_src_5          : 1;
    uint8_t mlc4_src_6          : 1;
    uint8_t mlc4_src_7          : 1;
} ism330dhcx_mlc4_src_t;
typedef struct {
    uint8_t mlc5_src_0          : 1;
    uint8_t mlc5_src_1          : 1;
    uint8_t mlc5_src_2          : 1;
    uint8_t mlc5_src_3          : 1;
    uint8_t mlc5_src_4          : 1;
    uint8_t mlc5_src_5          : 1;
    uint8_t mlc5_src_6          : 1;
    uint8_t mlc5_src_7          : 1;
} ism330dhcx_mlc5_src_t;
typedef struct {
    uint8_t mlc6_src_0          : 1;
    uint8_t mlc6_src_1          : 1;
    uint8_t mlc6_src_2          : 1;
    uint8_t mlc6_src_3          : 1;
    uint8_t mlc6_src_4          : 1;
    uint8_t mlc6_src_5          : 1;
    uint8_t mlc6_src_6          : 1;
    uint8_t mlc6_src_7          : 1;
} ism330dhcx_mlc6_src_t;
typedef struct {
    uint8_t mlc7_src_0          : 1;
    uint8_t mlc7_src_1          : 1;
    uint8_t mlc7_src_2          : 1;
    uint8_t mlc7_src_3          : 1;
    uint8_t mlc7_src_4          : 1;
    uint8_t mlc7_src_5          : 1;
    uint8_t mlc7_src_6          : 1;
    uint8_t mlc7_src_7          : 1;
} ism330dhcx_mlc7_src_t;

/***************** Embedded advanced features register description *******/
/*  External magnetometer sensitivity value register for the Finite State Machine (r/w).
    This register corresponds to the LSB-to-gauss conversion value of the external magnetometer sensor. The
    register value is expressed as half-precision floating-point format: SEEEEEFFFFFFFFFF
    (S: 1 sign bit; E: 5 exponent bits; F: 10 fraction bits).
    Default value of MAG_SENS[15:0] is 0x1624, corresponding to 0.0015 gauss/LSB.
*/
typedef struct {
    uint8_t mag_sens_0          : 1;
    uint8_t mag_sens_1          : 1;
    uint8_t mag_sens_2          : 1;
    uint8_t mag_sens_3          : 1;
    uint8_t mag_sens_4          : 1;
    uint8_t mag_sens_5          : 1;
    uint8_t mag_sens_6          : 1;
    uint8_t mag_sens_7          : 1;
} ism330dhcx_mag_sensitivity_l_t;
typedef struct {
    uint8_t mag_sens_8          : 1;
    uint8_t mag_sens_9          : 1;
    uint8_t mag_sens_10         : 1;
    uint8_t mag_sens_11         : 1;
    uint8_t mag_sens_12         : 1;
    uint8_t mag_sens_13         : 1;
    uint8_t mag_sens_14         : 1;
    uint8_t mag_sens_15         : 1;
} ism330dhcx_mag_sensitivity_h_t;

/*  Offset for X-axis hard-iron compensation register (r/w).
    The value is expressed as half-precision floating-point format: SEEEEEFFFFFFFFFF
    (S: 1 sign bit; E: 5 exponent bits; F: 10 fraction bits).
    **
    Offset for X-axis hard-iron compensation (MSbyte)
*/
typedef struct {
    uint8_t mag_offx_0          : 1;
    uint8_t mag_offx_1          : 1;
    uint8_t mag_offx_2          : 1;
    uint8_t mag_offx_3          : 1;
    uint8_t mag_offx_4          : 1;
    uint8_t mag_offx_5          : 1;
    uint8_t mag_offx_6          : 1;
    uint8_t mag_offx_7          : 1;
} ism330dhcx_mag_offx_l_t;
typedef struct {
    uint8_t mag_offx_8          : 1;
    uint8_t mag_offx_9          : 1;
    uint8_t mag_offx_10         : 1;
    uint8_t mag_offx_11         : 1;
    uint8_t mag_offx_12         : 1;
    uint8_t mag_offx_13         : 1;
    uint8_t mag_offx_14         : 1;
    uint8_t mag_offx_15         : 1;
} ism330dhcx_mag_offx_h_t;

/*  Offset for Y-axis hard-iron compensation register (r/w).
    The value is expressed as half-precision floating-point format: SEEEEEFFFFFFFFFF
    (S: 1 sign bit; E: 5 exponent bits; F: 10 fraction bits).
    **
    Offset for Y-axis hard-iron compensation (MSbyte)
*/
typedef struct {
    uint8_t mag_offy_0          : 1;
    uint8_t mag_offy_1          : 1;
    uint8_t mag_offy_2          : 1;
    uint8_t mag_offy_3          : 1;
    uint8_t mag_offy_4          : 1;
    uint8_t mag_offy_5          : 1;
    uint8_t mag_offy_6          : 1;
    uint8_t mag_offy_7          : 1;
} ism330dhcx_mag_offy_l_t;
typedef struct {
    uint8_t mag_offy_8          : 1;
    uint8_t mag_offy_9          : 1;
    uint8_t mag_offy_10         : 1;
    uint8_t mag_offy_11         : 1;
    uint8_t mag_offy_12         : 1;
    uint8_t mag_offy_13         : 1;
    uint8_t mag_offy_14         : 1;
    uint8_t mag_offy_15         : 1;
} ism330dhcx_mag_offy_h_t;

/*  Offset for Z-axis hard-iron compensation register (r/w).
    The value is expressed as half-precision floating-point format: SEEEEEFFFFFFFFFF
    (S: 1 sign bit; E: 5 exponent bits; F: 10 fraction bits).
    **
    Offset for Z-axis hard-iron compensation (MSbyte)
*/
typedef struct {
    uint8_t mag_offz_0          : 1;
    uint8_t mag_offz_1          : 1;
    uint8_t mag_offz_2          : 1;
    uint8_t mag_offz_3          : 1;
    uint8_t mag_offz_4          : 1;
    uint8_t mag_offz_5          : 1;
    uint8_t mag_offz_6          : 1;
    uint8_t mag_offz_7          : 1;
} ism330dhcx_mag_offz_l_t;
typedef struct {
    uint8_t mag_offz_8          : 1;
    uint8_t mag_offz_9          : 1;
    uint8_t mag_offz_10         : 1;
    uint8_t mag_offz_11         : 1;
    uint8_t mag_offz_12         : 1;
    uint8_t mag_offz_13         : 1;
    uint8_t mag_offz_14         : 1;
    uint8_t mag_offz_15         : 1;
} ism330dhcx_mag_offz_h_t;

/*  Soft-iron (3x3 symmetric) matrix correction register (r/w).
    The value is expressed as half-precision floating-point format: SEEEEEFFFFFFFFFF
    (S: 1 sign bit; E: 5 exponent bits; F: 10 fraction bits).
    **
    Soft-iron correction row1 col1 coefficient (LSbyte).
*/
typedef struct {
    uint8_t mag_si_xx_0         : 1;
    uint8_t mag_si_xx_1         : 1;
    uint8_t mag_si_xx_2         : 1;
    uint8_t mag_si_xx_3         : 1;
    uint8_t mag_si_xx_4         : 1;
    uint8_t mag_si_xx_5         : 1;
    uint8_t mag_si_xx_6         : 1;
    uint8_t mag_si_xx_7         : 1;
} ism330dhcx_mag_si_xx_l_t;
typedef struct {
    uint8_t mag_si_xx_8         : 1;
    uint8_t mag_si_xx_9         : 1;
    uint8_t mag_si_xx_10        : 1;
    uint8_t mag_si_xx_11        : 1;
    uint8_t mag_si_xx_12        : 1;
    uint8_t mag_si_xx_13        : 1;
    uint8_t mag_si_xx_14        : 1;
    uint8_t mag_si_xx_15        : 1;
} ism330dhcx_mag_si_xx_h_t;

/*  Soft-iron (3x3 symmetric) matrix correction register (r/w).
    The value is expressed as half-precision floating-point format: SEEEEEFFFFFFFFFF
    (S: 1 sign bit; E: 5 exponent bits; F: 10 fraction bits).
    **
    Soft-iron correction row1 col2 coefficient (LSbyte).
*/
typedef struct {
    uint8_t mag_si_xy_0         : 1;
    uint8_t mag_si_xy_1         : 1;
    uint8_t mag_si_xy_2         : 1;
    uint8_t mag_si_xy_3         : 1;
    uint8_t mag_si_xy_4         : 1;
    uint8_t mag_si_xy_5         : 1;
    uint8_t mag_si_xy_6         : 1;
    uint8_t mag_si_xy_7         : 1;
} ism330dhcx_mag_si_xy_l_t;
typedef struct {
    uint8_t mag_si_xy_8         : 1;
    uint8_t mag_si_xy_9         : 1;
    uint8_t mag_si_xy_10        : 1;
    uint8_t mag_si_xy_11        : 1;
    uint8_t mag_si_xy_12        : 1;
    uint8_t mag_si_xy_13        : 1;
    uint8_t mag_si_xy_14        : 1;
    uint8_t mag_si_xy_15        : 1;
} ism330dhcx_mag_si_xy_h_t;

/*  Soft-iron (3x3 symmetric) matrix correction register (r/w).
    The value is expressed as half-precision floating-point format: SEEEEEFFFFFFFFFF
    (S: 1 sign bit; E: 5 exponent bits; F: 10 fraction bits).
    **
    Soft-iron correction row1 col3 coefficient (LSbyte).
*/
typedef struct {
    uint8_t mag_si_xz_0         : 1;
    uint8_t mag_si_xz_1         : 1;
    uint8_t mag_si_xz_2         : 1;
    uint8_t mag_si_xz_3         : 1;
    uint8_t mag_si_xz_4         : 1;
    uint8_t mag_si_xz_5         : 1;
    uint8_t mag_si_xz_6         : 1;
    uint8_t mag_si_xz_7         : 1;
} ism330dhcx_mag_si_xz_l_t;
typedef struct {
    uint8_t mag_si_xz_8         : 1;
    uint8_t mag_si_xz_9         : 1;
    uint8_t mag_si_xz_10        : 1;
    uint8_t mag_si_xz_11        : 1;
    uint8_t mag_si_xz_12        : 1;
    uint8_t mag_si_xz_13        : 1;
    uint8_t mag_si_xz_14        : 1;
    uint8_t mag_si_xz_15        : 1;
} ism330dhcx_mag_si_xz_h_t;

/*  Soft-iron (3x3 symmetric) matrix correction register (r/w).
    The value is expressed as half-precision floating-point format: SEEEEEFFFFFFFFFF
    (S: 1 sign bit; E: 5 exponent bits; F: 10 fraction bits).
    **
    Soft-iron correction row2 col2 coefficient (LSbyte).
*/
typedef struct {
    uint8_t mag_si_yy_0         : 1;
    uint8_t mag_si_yy_1         : 1;
    uint8_t mag_si_yy_2         : 1;
    uint8_t mag_si_yy_3         : 1;
    uint8_t mag_si_yy_4         : 1;
    uint8_t mag_si_yy_5         : 1;
    uint8_t mag_si_yy_6         : 1;
    uint8_t mag_si_yy_7         : 1;
} ism330dhcx_mag_si_yy_l_t;
typedef struct {
    uint8_t mag_si_yy_8         : 1;
    uint8_t mag_si_yy_9         : 1;
    uint8_t mag_si_yy_10        : 1;
    uint8_t mag_si_yy_11        : 1;
    uint8_t mag_si_yy_12        : 1;
    uint8_t mag_si_yy_13        : 1;
    uint8_t mag_si_yy_14        : 1;
    uint8_t mag_si_yy_15        : 1;
} ism330dhcx_mag_si_yy_h_t;

/*  Soft-iron (3x3 symmetric) matrix correction register (r/w).
    The value is expressed as half-precision floating-point format: SEEEEEFFFFFFFFFF
    (S: 1 sign bit; E: 5 exponent bits; F: 10 fraction bits).
    **
    Soft-iron correction row2 col3 coefficient (LSbyte).
*/
typedef struct {
    uint8_t mag_si_yz_0         : 1;
    uint8_t mag_si_yz_1         : 1;
    uint8_t mag_si_yz_2         : 1;
    uint8_t mag_si_yz_3         : 1;
    uint8_t mag_si_yz_4         : 1;
    uint8_t mag_si_yz_5         : 1;
    uint8_t mag_si_yz_6         : 1;
    uint8_t mag_si_yz_7         : 1;
} ism330dhcx_mag_si_yz_l_t;
typedef struct {
    uint8_t mag_si_yz_8         : 1;
    uint8_t mag_si_yz_9         : 1;
    uint8_t mag_si_yz_10        : 1;
    uint8_t mag_si_yz_11        : 1;
    uint8_t mag_si_yz_12        : 1;
    uint8_t mag_si_yz_13        : 1;
    uint8_t mag_si_yz_14        : 1;
    uint8_t mag_si_yz_15        : 1;
} ism330dhcx_mag_si_yz_h_t;

/*  Soft-iron (3x3 symmetric) matrix correction register (r/w).
    The value is expressed as half-precision floating-point format: SEEEEEFFFFFFFFFF
    (S: 1 sign bit; E: 5 exponent bits; F: 10 fraction bits).
    **
    Soft-iron correction row3 col3 coefficient (LSbyte).
*/
typedef struct {
    uint8_t mag_si_zz_0         : 1;
    uint8_t mag_si_zz_1         : 1;
    uint8_t mag_si_zz_2         : 1;
    uint8_t mag_si_zz_3         : 1;
    uint8_t mag_si_zz_4         : 1;
    uint8_t mag_si_zz_5         : 1;
    uint8_t mag_si_zz_6         : 1;
    uint8_t mag_si_zz_7         : 1;
} ism330dhcx_mag_si_zz_l_t;
typedef struct {
    uint8_t mag_si_zz_8         : 1;
    uint8_t mag_si_zz_9         : 1;
    uint8_t mag_si_zz_10        : 1;
    uint8_t mag_si_zz_11        : 1;
    uint8_t mag_si_zz_12        : 1;
    uint8_t mag_si_zz_13        : 1;
    uint8_t mag_si_zz_14        : 1;
    uint8_t mag_si_zz_15        : 1;
} ism330dhcx_mag_si_zz_h_t;

/*  External magnetometer coordinates (Z and Y axes) rotation register */
typedef struct {
    // Magnetometer Z-axis coordinates rotation (to be aligned to accelerometer/gyroscope axes orientation)
    uint8_t mag_z_axis          : 3;
    uint8_t reserved0           : 1;
    // Magnetometer Y-axis coordinates rotation (to be aligned to accelerometer/gyroscope axes orientation)
    uint8_t mag_y_axis          : 3;
    uint8_t reserved1           : 1;
} ism330dhcx_mag_cfg_a_t;

/*  External magnetometer coordinates (X-axis) rotation register */
typedef struct {
    // Magnetometer X-axis coordinates rotation (to be aligned to accelerometer/gyroscope axes orientation)
    uint8_t mag_x_axis          : 3;
    uint8_t reserved0           : 5;
} ism330dhcx_mag_cfg_b_t;

/* FSM long counter timeout register */
typedef struct {
    uint8_t fsm_lc_timeout0     : 1;
    uint8_t fsm_lc_timeout1     : 1;
    uint8_t fsm_lc_timeout2     : 1;
    uint8_t fsm_lc_timeout3     : 1;
    uint8_t fsm_lc_timeout4     : 1;
    uint8_t fsm_lc_timeout5     : 1;
    uint8_t fsm_lc_timeout6     : 1;
    uint8_t fsm_lc_timeout7     : 1;
} ism330dhcx_fsm_lc_timeout_l_t;
typedef struct {
    uint8_t fsm_lc_timeout8     : 1;
    uint8_t fsm_lc_timeout9     : 1;
    uint8_t fsm_lc_timeout10    : 1;
    uint8_t fsm_lc_timeout11    : 1;
    uint8_t fsm_lc_timeout12    : 1;
    uint8_t fsm_lc_timeout13    : 1;
    uint8_t fsm_lc_timeout14    : 1;
    uint8_t fsm_lc_timeout15    : 1;
} ism330dhcx_fsm_lc_timeout_h_t;

/*  FSM number of programs register */
typedef struct {
    uint8_t fsm_n_prog0     : 1;
    uint8_t fsm_n_prog1     : 1;
    uint8_t fsm_n_prog2     : 1;
    uint8_t fsm_n_prog3     : 1;
    uint8_t fsm_n_prog4     : 1;
    uint8_t fsm_n_prog5     : 1;
    uint8_t fsm_n_prog6     : 1;
    uint8_t fsm_n_prog7     : 1;
} ism330dhcx_fsm_programs_t;

/*  FSM start address register (r/w).
    First available address is 0x033C.  */
typedef struct {
    uint8_t fsm_start0      : 1;
    uint8_t fsm_start1      : 1;
    uint8_t fsm_start2      : 1;
    uint8_t fsm_start3      : 1;
    uint8_t fsm_start4      : 1;
    uint8_t fsm_start5      : 1;
    uint8_t fsm_start6      : 1;
    uint8_t fsm_start7      : 1;
} ism330dhcx_fsm_start_add_l_t;
typedef struct {
    uint8_t fsm_start8      : 1;
    uint8_t fsm_start9      : 1;
    uint8_t fsm_start10     : 1;
    uint8_t fsm_start11     : 1;
    uint8_t fsm_start12     : 1;
    uint8_t fsm_start13     : 1;
    uint8_t fsm_start14     : 1;
    uint8_t fsm_start15     : 1;
} ism330dhcx_fsm_start_add_h_t;

/* Pedometer configuration register */
typedef struct {
    uint8_t reserved0       : 3;
    // Set when user wants to generate interrupt only on count overflow event.
    uint8_t carry_count_en  : 1;
    uint8_t reserved1       : 4;
} ism330dhcx_pedo_cmd_reg_t;

/*  Pedometer debounce configuration register
    Debounce threshold.
    Minimum number of steps to increment the step counter (debounce). */
typedef struct {
    uint8_t deb_step0       : 1;
    uint8_t deb_step1       : 1;
    uint8_t deb_step2       : 1;
    uint8_t deb_step3       : 1;
    uint8_t deb_step4       : 1;
    uint8_t deb_step5       : 1;
    uint8_t deb_step6       : 1;
    uint8_t deb_step7       : 1;
} ism330dhcx_pedo_deb_conf_t;

/* Time period register for step detection on delta time
    Time period value   */
typedef struct {
    uint8_t pd_sc_0         : 1;
    uint8_t pd_sc_1         : 1;
    uint8_t pd_sc_2         : 1;
    uint8_t pd_sc_3         : 1;
    uint8_t pd_sc_4         : 1;
    uint8_t pd_sc_5         : 1;
    uint8_t pd_sc_6         : 1;
    uint8_t pd_sc_7         : 1;
} ism330dhcx_pedo_sc_deltat_l_t;
typedef struct {
    uint8_t pd_sc_8         : 1;
    uint8_t pd_sc_9         : 1;
    uint8_t pd_sc_10        : 1;
    uint8_t pd_sc_11        : 1;
    uint8_t pd_sc_12        : 1;
    uint8_t pd_sc_13        : 1;
    uint8_t pd_sc_14        : 1;
    uint8_t pd_sc_15        : 1;
} ism330dhcx_pedo_sc_deltat_h_t;

/*  External magnetometer sensitivity
    value register for the Machine Learning Core */
typedef struct {
    uint8_t mlc_mag_s_0     : 1;
    uint8_t mlc_mag_s_1     : 1;
    uint8_t mlc_mag_s_2     : 1;
    uint8_t mlc_mag_s_3     : 1;
    uint8_t mlc_mag_s_4     : 1;
    uint8_t mlc_mag_s_5     : 1;
    uint8_t mlc_mag_s_6     : 1;
    uint8_t mlc_mag_s_7     : 1;
} ism330dhcx_mlc_mag_sensitivity_l_t;
typedef struct {
    uint8_t mlc_mag_s_8     : 1;
    uint8_t mlc_mag_s_9     : 1;
    uint8_t mlc_mag_s_10    : 1;
    uint8_t mlc_mag_s_11    : 1;
    uint8_t mlc_mag_s_12    : 1;
    uint8_t mlc_mag_s_13    : 1;
    uint8_t mlc_mag_s_14    : 1;
    uint8_t mlc_mag_s_15    : 1;
} ism330dhcx_mlc_mag_sensitivity_h_t;

/******************* Sensor Hub *********************/

/*  Sensor hub output register (r)
    First byte associated to external sensors.
    The content of the register is consistent with the SLAVEx_CONFIG
    number of read operation configurations
    (for external sensors from x = 0 to x = 3). */
typedef struct {
    uint8_t sensor_hub1_0   : 1;
    uint8_t sensor_hub1_1   : 1;
    uint8_t sensor_hub1_2   : 1;
    uint8_t sensor_hub1_3   : 1;
    uint8_t sensor_hub1_4   : 1;
    uint8_t sensor_hub1_5   : 1;
    uint8_t sensor_hub1_6   : 1;
    uint8_t sensor_hub1_7   : 1;
} ism330dhcx_sensor_hub_1_t;
typedef struct {
    uint8_t sensor_hub2_0   : 1;
    uint8_t sensor_hub2_1   : 1;
    uint8_t sensor_hub2_2   : 1;
    uint8_t sensor_hub2_3   : 1;
    uint8_t sensor_hub2_4   : 1;
    uint8_t sensor_hub2_5   : 1;
    uint8_t sensor_hub2_6   : 1;
    uint8_t sensor_hub2_7   : 1;
} ism330dhcx_sensor_hub_2_t;
typedef struct {
    uint8_t sensor_hub3_0   : 1;
    uint8_t sensor_hub3_1   : 1;
    uint8_t sensor_hub3_2   : 1;
    uint8_t sensor_hub3_3   : 1;
    uint8_t sensor_hub3_4   : 1;
    uint8_t sensor_hub3_5   : 1;
    uint8_t sensor_hub3_6   : 1;
    uint8_t sensor_hub3_7   : 1;
} ism330dhcx_sensor_hub_3_t;
typedef struct {
    uint8_t sensor_hub4_0   : 1;
    uint8_t sensor_hub4_1   : 1;
    uint8_t sensor_hub4_2   : 1;
    uint8_t sensor_hub4_3   : 1;
    uint8_t sensor_hub4_4   : 1;
    uint8_t sensor_hub4_5   : 1;
    uint8_t sensor_hub4_6   : 1;
    uint8_t sensor_hub4_7   : 1;
} ism330dhcx_sensor_hub_4_t;
typedef struct {
    uint8_t sensor_hub5_0   : 1;
    uint8_t sensor_hub5_1   : 1;
    uint8_t sensor_hub5_2   : 1;
    uint8_t sensor_hub5_3   : 1;
    uint8_t sensor_hub5_4   : 1;
    uint8_t sensor_hub5_5   : 1;
    uint8_t sensor_hub5_6   : 1;
    uint8_t sensor_hub5_7   : 1;
} ism330dhcx_sensor_hub_5_t;
typedef struct {
    uint8_t sensor_hub6_0   : 1;
    uint8_t sensor_hub6_1   : 1;
    uint8_t sensor_hub6_2   : 1;
    uint8_t sensor_hub6_3   : 1;
    uint8_t sensor_hub6_4   : 1;
    uint8_t sensor_hub6_5   : 1;
    uint8_t sensor_hub6_6   : 1;
    uint8_t sensor_hub6_7   : 1;
} ism330dhcx_sensor_hub_6_t;
typedef struct {
    uint8_t sensor_hub7_0   : 1;
    uint8_t sensor_hub7_1   : 1;
    uint8_t sensor_hub7_2   : 1;
    uint8_t sensor_hub7_3   : 1;
    uint8_t sensor_hub7_4   : 1;
    uint8_t sensor_hub7_5   : 1;
    uint8_t sensor_hub7_6   : 1;
    uint8_t sensor_hub7_7   : 1;
} ism330dhcx_sensor_hub_7_t;
typedef struct {
    uint8_t sensor_hub8_0   : 1;
    uint8_t sensor_hub8_1   : 1;
    uint8_t sensor_hub8_2   : 1;
    uint8_t sensor_hub8_3   : 1;
    uint8_t sensor_hub8_4   : 1;
    uint8_t sensor_hub8_5   : 1;
    uint8_t sensor_hub8_6   : 1;
    uint8_t sensor_hub8_7   : 1;
} ism330dhcx_sensor_hub_8_t;
typedef struct {
    uint8_t sensor_hub9_0   : 1;
    uint8_t sensor_hub9_1   : 1;
    uint8_t sensor_hub9_2   : 1;
    uint8_t sensor_hub9_3   : 1;
    uint8_t sensor_hub9_4   : 1;
    uint8_t sensor_hub9_5   : 1;
    uint8_t sensor_hub9_6   : 1;
    uint8_t sensor_hub9_7   : 1;
} ism330dhcx_sensor_hub_9_t;
typedef struct {
    uint8_t sensor_hub10_0  : 1;
    uint8_t sensor_hub10_1  : 1;
    uint8_t sensor_hub10_2  : 1;
    uint8_t sensor_hub10_3  : 1;
    uint8_t sensor_hub10_4  : 1;
    uint8_t sensor_hub10_5  : 1;
    uint8_t sensor_hub10_6  : 1;
    uint8_t sensor_hub10_7  : 1;
} ism330dhcx_sensor_hub_10_t;
typedef struct {
    uint8_t sensor_hub11_0  : 1;
    uint8_t sensor_hub11_1  : 1;
    uint8_t sensor_hub11_2  : 1;
    uint8_t sensor_hub11_3  : 1;
    uint8_t sensor_hub11_4  : 1;
    uint8_t sensor_hub11_5  : 1;
    uint8_t sensor_hub11_6  : 1;
    uint8_t sensor_hub11_7  : 1;
} ism330dhcx_sensor_hub_11_t;
typedef struct {
    uint8_t sensor_hub12_0  : 1;
    uint8_t sensor_hub12_1  : 1;
    uint8_t sensor_hub12_2  : 1;
    uint8_t sensor_hub12_3  : 1;
    uint8_t sensor_hub12_4  : 1;
    uint8_t sensor_hub12_5  : 1;
    uint8_t sensor_hub12_6  : 1;
    uint8_t sensor_hub12_7  : 1;
} ism330dhcx_sensor_hub_12_t;
typedef struct {
    uint8_t sensor_hub13_0  : 1;
    uint8_t sensor_hub13_1  : 1;
    uint8_t sensor_hub13_2  : 1;
    uint8_t sensor_hub13_3  : 1;
    uint8_t sensor_hub13_4  : 1;
    uint8_t sensor_hub13_5  : 1;
    uint8_t sensor_hub13_6  : 1;
    uint8_t sensor_hub13_7  : 1;
} ism330dhcx_sensor_hub_13_t;
typedef struct {
    uint8_t sensor_hub14_0  : 1;
    uint8_t sensor_hub14_1  : 1;
    uint8_t sensor_hub14_2  : 1;
    uint8_t sensor_hub14_3  : 1;
    uint8_t sensor_hub14_4  : 1;
    uint8_t sensor_hub14_5  : 1;
    uint8_t sensor_hub14_6  : 1;
    uint8_t sensor_hub14_7  : 1;
} ism330dhcx_sensor_hub_14_t;
typedef struct {
    uint8_t sensor_hub15_0  : 1;
    uint8_t sensor_hub15_1  : 1;
    uint8_t sensor_hub15_2  : 1;
    uint8_t sensor_hub15_3  : 1;
    uint8_t sensor_hub15_4  : 1;
    uint8_t sensor_hub15_5  : 1;
    uint8_t sensor_hub15_6  : 1;
    uint8_t sensor_hub15_7  : 1;
} ism330dhcx_sensor_hub_15_t;
typedef struct {
    uint8_t sensor_hub16_0  : 1;
    uint8_t sensor_hub16_1  : 1;
    uint8_t sensor_hub16_2  : 1;
    uint8_t sensor_hub16_3  : 1;
    uint8_t sensor_hub16_4  : 1;
    uint8_t sensor_hub16_5  : 1;
    uint8_t sensor_hub16_6  : 1;
    uint8_t sensor_hub16_7  : 1;
} ism330dhcx_sensor_hub_16_t;
typedef struct {
    uint8_t sensor_hub17_0  : 1;
    uint8_t sensor_hub17_1  : 1;
    uint8_t sensor_hub17_2  : 1;
    uint8_t sensor_hub17_3  : 1;
    uint8_t sensor_hub17_4  : 1;
    uint8_t sensor_hub17_5  : 1;
    uint8_t sensor_hub17_6  : 1;
    uint8_t sensor_hub17_7  : 1;
} ism330dhcx_sensor_hub_17_t;
typedef struct {
    uint8_t sensor_hub18_0  : 1;
    uint8_t sensor_hub18_1  : 1;
    uint8_t sensor_hub18_2  : 1;
    uint8_t sensor_hub18_3  : 1;
    uint8_t sensor_hub18_4  : 1;
    uint8_t sensor_hub18_5  : 1;
    uint8_t sensor_hub18_6  : 1;
    uint8_t sensor_hub18_7  : 1;
} ism330dhcx_sensor_hub_18_t;

/*  Master configuration register */
typedef struct {
    // Number of external sensors to be read by the sensor hub.
    uint8_t aux_sens_on         : 2;
    // Sensor hub I²C master enable
    uint8_t master_on           : 1;
    // Master I²C pull-up enable.
    uint8_t shub_pu_en          : 1;
    // I²C interface pass-throuh.
    uint8_t pass_through_mode   : 1;
    // Sensor hub trigger signal selection.
    uint8_t start_config        : 1;
    // Slave 0 write operation is performed only at the first sensor hub cycle.
    uint8_t write_once          : 1;
    // Reset Master logic and output registers. Must be set to '1' and then set it to '0'.
} ism330dhcx_master_config_t;

/* I²C slave address of the first external sensor (Sensor 1) register */
typedef struct {
    // Read/write operation on Sensor 1.
    uint8_t rw_0                : 1;
    // I²C slave address of Sensor1 that can be read by the sensor hub.
    uint8_t slave0_add          : 7;
} ism330dhcx_slv0_add_t;

/* Adress of register on the first external sensor (Sensor 1) register
    Address of register on Sensor1 that has to be read/written according
    to the rw_0 bit value in SLV0_ADD (15h). */
typedef struct {
    uint8_t slave0_reg0         : 1;
    uint8_t slave0_reg1         : 1;
    uint8_t slave0_reg2         : 1;
    uint8_t slave0_reg3         : 1;
    uint8_t slave0_reg4         : 1;
    uint8_t slave0_reg5         : 1;
    uint8_t slave0_reg6         : 1;
    uint8_t slave0_reg7         : 1;
} ism330dhcx_slv0_subadd_t;

/* First external sensor (Sensor1) configuration and sensor hub settings register */
typedef struct {
    // Number of read operations on Sensor 1.
    uint8_t slave0_numop        : 3;
    // Enable FIFO data batching of first slave.
    uint8_t batch_ext_sens_0_en : 1;
    uint8_t reserved0           : 2;
    // Rate at which the master communicates.
    uint8_t shub_odr            : 2;
} ism330dhcx_slave0_config_t;

/* I²C slave address of the first external sensor (Sensor 2) register */
typedef struct {
    // Read/write operation on Sensor 1.
    uint8_t r_1                : 1;
    // I²C slave address of Sensor1 that can be read by the sensor hub.
    uint8_t slave1_add         : 7;
} ism330dhcx_slv1_add_t;

/* Adress of register on the first external sensor (Sensor 2) register
    Address of register on Sensor1 that has to be read/written according
    to the rw_0 bit value in SLV1_ADD (15h). */
typedef struct {
    uint8_t slave1_reg0         : 1;
    uint8_t slave1_reg1         : 1;
    uint8_t slave1_reg2         : 1;
    uint8_t slave1_reg3         : 1;
    uint8_t slave1_reg4         : 1;
    uint8_t slave1_reg5         : 1;
    uint8_t slave1_reg6         : 1;
    uint8_t slave1_reg7         : 1;
} ism330dhcx_slv1_subadd;

/* First external sensor (Sensor2) configuration and sensor hub settings register */
typedef struct {
    // Number of read operations on Sensor 1.
    uint8_t slave1_numop        : 3;
    // Enable FIFO data batching of first slave.
    uint8_t batch_ext_sens_1_en : 1;
    uint8_t reserved0           : 4;
} ism330dhcx_slave1_config_t;

/* I²C slave address of the first external sensor (Sensor 3) register */
typedef struct {
    // Read/write operation on Sensor 1.
    uint8_t r_2                : 1;
    // I²C slave address of Sensor1 that can be read by the sensor hub.
    uint8_t slave2_add         : 7;
} ism330dhcx_slv2_add_t;

/* Adress of register on the first external sensor (Sensor 3) register
    Address of register on Sensor1 that has to be read/written according
    to the rw_0 bit value in SLV2_ADD (15h). */
typedef struct {
    uint8_t slave2_reg0         : 1;
    uint8_t slave2_reg1         : 1;
    uint8_t slave2_reg2         : 1;
    uint8_t slave2_reg3         : 1;
    uint8_t slave2_reg4         : 1;
    uint8_t slave2_reg5         : 1;
    uint8_t slave2_reg6         : 1;
    uint8_t slave2_reg7         : 1;
} ism330dhcx_slv2_subadd_t;

/* First external sensor (Sensor3) configuration and sensor hub settings register */
typedef struct {
    // Number of read operations on Sensor 1.
    uint8_t slave2_numop        : 3;
    // Enable FIFO data batching of first slave.
    uint8_t batch_ext_sens_2_en : 1;
    uint8_t reserved0           : 4;
} ism330dhcx_slave2_config_t;

/* I²C slave address of the first external sensor (Sensor 4) register */
typedef struct {
    // Read/write operation on Sensor 1.
    uint8_t r_3                : 1;
    // I²C slave address of Sensor1 that can be read by the sensor hub.
    uint8_t slave3_add         : 7;
} ism330dhcx_slv3_add_t;

/* Adress of register on the first external sensor (Sensor 3) register
    Address of register on Sensor1 that has to be read/written according
    to the rw_0 bit value in SLV2_ADD (15h). */
typedef struct {
    uint8_t slave3_reg0         : 1;
    uint8_t slave3_reg1         : 1;
    uint8_t slave3_reg2         : 1;
    uint8_t slave3_reg3         : 1;
    uint8_t slave3_reg4         : 1;
    uint8_t slave3_reg5         : 1;
    uint8_t slave3_reg6         : 1;
    uint8_t slave3_reg7         : 1;
} ism330dhcx_slv3_subadd_t;

/* First external sensor (Sensor3) configuration and sensor hub settings register */
typedef struct {
    // Number of read operations on Sensor 1.
    uint8_t slave3_numop        : 3;
    // Enable FIFO data batching of first slave.
    uint8_t batch_ext_sens_3_en : 1;
    uint8_t reserved0           : 4;
} ism330dhcx_slave3_config_t;

/*  Data to be written into the slave device register */
typedef struct {
    // Data to be written into the slave 0 device according to the rw_0 bit in register SLV0_ADD (15h).
    uint8_t slave0_dataw        : 8;
} ism330dhcx_datawrite_slv0_t;

typedef struct {
    // Sensor hub communication status.
    uint8_t sens_hub_endop      : 1;
    uint8_t reserved0           : 2;
    // Those bits are set to 1 if Not acknowledge occurs on slave N communication.
    uint8_t slave0_nack         : 1;
    uint8_t slave1_nack         : 1;
    uint8_t slave2_nack         : 1;
    uint8_t slave3_nack         : 1;
    // When the bit WRITE_ONCE in MASTER_CONFIG (14h) is configured as 1,
    //  this bit is set to 1 when the write operation on slave 0 has been performed and completed.
    uint8_t wr_once_done        : 1;
} ism330dhcx_status_master_t;

#endif
