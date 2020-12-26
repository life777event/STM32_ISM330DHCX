#include <ism330dhcx_ll.h>

extern void Error_Handler(void);

/**
  * @brief  Read generic device register
  *
  * @param  h_ism read / write interface definitions(ptr)
  * @param  reg   register to read
  * @param  data  pointer to buffer that store the data read(ptr)
  * @param  len   number of consecutive register to read
  * @retval       interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t ism330dhcx_read(ISM330DHCX_HandleTypeDef *h_ism, uint8_t reg,
                            uint8_t *data,
                            uint16_t len)
{
  int32_t ret;
  ret = h_ism->read(h_ism->handle, reg, data, len);
  return ret;
}

/**
  * @brief  Write generic device register
  *
  * @param  h_ism read / write interface definitions(ptr)
  * @param  reg   register to write
  * @param  data  pointer to data to write in register reg(ptr)
  * @param  len   number of consecutive register to write
  * @retval       interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t ism330dhcx_write(ISM330DHCX_HandleTypeDef *h_ism, uint8_t reg,
                             uint8_t *data,
                             uint16_t len)
{
  int32_t ret;
  ret = h_ism->write(h_ism->handle, reg, data, len);
  return ret;
}

/**
  * @brief  Device Who am I.[get]
  *
  * @param  h_ism  Read / write interface definitions.(ptr)
  * @param  buff   Buffer that stores data read
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t ism330dhcx_who_am_i(ISM330DHCX_HandleTypeDef *h_ism, uint8_t *buff)
{
    int32_t ret;
    ret = ism330dhcx_read(h_ism, WHO_AM_I, buff, 1);
    return ret;
}

/**
  * @brief  Software reset. Restore the default values in user registers.[set]
  *
  * @param  h_ism  Read / write interface definitions.(ptr)
  * @param  val    Change the values of sw_reset in reg CTRL3_C
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t ism330dhcx_reset_set(ISM330DHCX_HandleTypeDef *h_ism, uint8_t val)
{
  ism330dhcx_ctrl3_c_t ctrl3_c;
  int32_t ret;
  ret = ism330dhcx_read(h_ism, CTRL2_G,
                            (uint8_t *)&ctrl3_c, 1);

  if (ret == 0) {
    ctrl3_c.sw_reset = (uint8_t)val;
    ret = ism330dhcx_write(h_ism, CTRL3_C,
                               (uint8_t *)&ctrl3_c, 1);
  }

  return ret;
}

/**
  * @brief  Software reset. Restore the default values in user registers.[get]
  *
  * @param  h_ism  Read / write interface definitions.(ptr)
  * @param  val    Change the values of sw_reset in reg CTRL3_C
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t ism330dhcx_reset_get(ISM330DHCX_HandleTypeDef *h_ism, uint8_t *val)
{
  ism330dhcx_ctrl3_c_t ctrl3_c;
  int32_t ret;
  ret = ism330dhcx_read(h_ism, CTRL3_C,
                            (uint8_t *)&ctrl3_c, 1);
  *val = ctrl3_c.sw_reset;
  return ret;
}

/**
  * @brief  Block data update.[set]
  *
  * @param  h_ism  Read / write interface definitions.(ptr)
  * @param  val    Change the values of bdu in reg CTRL3_C
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t ism330dhcx_block_data_update_set(ISM330DHCX_HandleTypeDef *h_ism, uint8_t val)
{
  ism330dhcx_ctrl3_c_t ctrl3_c;
  int32_t ret;
  ret = ism330dhcx_read(h_ism, CTRL3_C,
                            (uint8_t *)&ctrl3_c, 1);

  if (ret == 0) {
    ctrl3_c.bdu = (uint8_t)val;
    ret = ism330dhcx_write(h_ism, CTRL3_C,
                               (uint8_t *)&ctrl3_c, 1);
  }

  return ret;
}

/* Set Output Data Update */
int32_t ism330dhcx_xl_data_rate_set(ISM330DHCX_HandleTypeDef *h_ism, ism330dhcx_odr_xl_t val)
{
    ism330dhcx_odr_xl_t odr_xl =  val;
    ism330dhcx_emb_fsm_enable_t fsm_enable;
    ism330dhcx_fsm_odr_t fsm_odr;
    uint8_t mlc_enable;
    ism330dhcx_mlc_odr_t mlc_odr;
    ism330dhcx_ctrl1_xl_t ctrl1_xl;
    int32_t ret;
    /* Check the Finite State Machine data rate constraints */
    ret =  ism330dhcx_fsm_enable_get(h_ism, &fsm_enable);

    if (ret == 0) {
        if ( (fsm_enable.fsm_enable_a.fsm1_en  |
            fsm_enable.fsm_enable_a.fsm2_en  |
            fsm_enable.fsm_enable_a.fsm3_en  |
            fsm_enable.fsm_enable_a.fsm4_en  |
            fsm_enable.fsm_enable_a.fsm5_en  |
            fsm_enable.fsm_enable_a.fsm6_en  |
            fsm_enable.fsm_enable_a.fsm7_en  |
            fsm_enable.fsm_enable_a.fsm8_en  |
            fsm_enable.fsm_enable_b.fsm9_en  |
            fsm_enable.fsm_enable_b.fsm10_en |
            fsm_enable.fsm_enable_b.fsm11_en |
            fsm_enable.fsm_enable_b.fsm12_en |
            fsm_enable.fsm_enable_b.fsm13_en |
            fsm_enable.fsm_enable_b.fsm14_en |
            fsm_enable.fsm_enable_b.fsm15_en |
            fsm_enable.fsm_enable_b.fsm16_en ) == PROPERTY_ENABLE )
        {
			ret =  ism330dhcx_fsm_data_rate_get(h_ism, &fsm_odr);

			if (ret == 0) {
				switch (fsm_odr) {
				case ISM330DHCX_ODR_FSM_12Hz5:
					if (val == ISM330DHCX_XL_ODR_OFF) {
					odr_xl = ISM330DHCX_XL_ODR_12Hz5;
					}

					else {
					odr_xl = val;
					}

					break;

				case ISM330DHCX_ODR_FSM_26Hz:
					if (val == ISM330DHCX_XL_ODR_OFF) {
					odr_xl = ISM330DHCX_XL_ODR_26Hz;
					}

					else if (val == ISM330DHCX_XL_ODR_12Hz5) {
					odr_xl = ISM330DHCX_XL_ODR_26Hz;
					}

					else {
					odr_xl = val;
					}

					break;

				case ISM330DHCX_ODR_FSM_52Hz:
					if (val == ISM330DHCX_XL_ODR_OFF) {
					odr_xl = ISM330DHCX_XL_ODR_52Hz;
					}

					else if (val == ISM330DHCX_XL_ODR_12Hz5) {
					odr_xl = ISM330DHCX_XL_ODR_52Hz;
					}

					else if (val == ISM330DHCX_XL_ODR_26Hz) {
					odr_xl = ISM330DHCX_XL_ODR_52Hz;
					}

					else {
					odr_xl = val;
					}

					break;

				case ISM330DHCX_ODR_FSM_104Hz:
					if (val == ISM330DHCX_XL_ODR_OFF) {
					odr_xl = ISM330DHCX_XL_ODR_104Hz;
					}

					else if (val == ISM330DHCX_XL_ODR_12Hz5) {
					odr_xl = ISM330DHCX_XL_ODR_104Hz;
					}

					else if (val == ISM330DHCX_XL_ODR_26Hz) {
					odr_xl = ISM330DHCX_XL_ODR_104Hz;
					}

					else if (val == ISM330DHCX_XL_ODR_52Hz) {
					odr_xl = ISM330DHCX_XL_ODR_104Hz;
					}

					else {
					odr_xl = val;
					}

					break;

				default:
					odr_xl = val;
					break;
				}
			}
        }
    }

    /* Check the Machine Learning Core data rate constraints */
    mlc_enable = PROPERTY_DISABLE;

    if (ret == 0) {
        ret =  ism330dhcx_mlc_get(h_ism, &mlc_enable);

        if ( mlc_enable == PROPERTY_ENABLE ) {
        ret =  ism330dhcx_mlc_data_rate_get(h_ism, &mlc_odr);

        if (ret == 0) {
            switch (mlc_odr) {
            case ISM330DHCX_ODR_PRGS_12Hz5:
                if (val == ISM330DHCX_XL_ODR_OFF) {
                odr_xl = ISM330DHCX_XL_ODR_12Hz5;
                }

                else {
                odr_xl = val;
                }

                break;

            case ISM330DHCX_ODR_PRGS_26Hz:
                if (val == ISM330DHCX_XL_ODR_OFF) {
                odr_xl = ISM330DHCX_XL_ODR_26Hz;
                }

                else if (val == ISM330DHCX_XL_ODR_12Hz5) {
                odr_xl = ISM330DHCX_XL_ODR_26Hz;
                }

                else {
                odr_xl = val;
                }

                break;

            case ISM330DHCX_ODR_PRGS_52Hz:
                if (val == ISM330DHCX_XL_ODR_OFF) {
                odr_xl = ISM330DHCX_XL_ODR_52Hz;
                }

                else if (val == ISM330DHCX_XL_ODR_12Hz5) {
                odr_xl = ISM330DHCX_XL_ODR_52Hz;
                }

                else if (val == ISM330DHCX_XL_ODR_26Hz) {
                odr_xl = ISM330DHCX_XL_ODR_52Hz;
                }

                else {
                odr_xl = val;
                }

                break;

            case ISM330DHCX_ODR_PRGS_104Hz:
                if (val == ISM330DHCX_XL_ODR_OFF) {
                odr_xl = ISM330DHCX_XL_ODR_104Hz;
                }

                else if (val == ISM330DHCX_XL_ODR_12Hz5) {
                odr_xl = ISM330DHCX_XL_ODR_104Hz;
                }

                else if (val == ISM330DHCX_XL_ODR_26Hz) {
                odr_xl = ISM330DHCX_XL_ODR_104Hz;
                }

                else if (val == ISM330DHCX_XL_ODR_52Hz) {
                odr_xl = ISM330DHCX_XL_ODR_104Hz;
                }

                else {
                odr_xl = val;
                }

                break;

            default:
                odr_xl = val;
                break;
            }
        }
        }
    }

    if (ret == 0) {
        ret = ism330dhcx_read(h_ism, CTRL1_XL,
                                (uint8_t *)&ctrl1_xl, 1);
    }

    if (ret == 0) {
        ctrl1_xl.odr_xl = (uint8_t)odr_xl;
        ret = ism330dhcx_write(h_ism, CTRL1_XL,
                                (uint8_t *)&ctrl1_xl, 1);
    }

    return ret;
}

int32_t ism330dhcx_gy_data_rate_set(ISM330DHCX_HandleTypeDef *h_ism, ism330dhcx_odr_g_t val)
{
  ism330dhcx_odr_g_t odr_gy =  val;
  ism330dhcx_emb_fsm_enable_t fsm_enable;
  ism330dhcx_fsm_odr_t fsm_odr;
  uint8_t mlc_enable;
  ism330dhcx_mlc_odr_t mlc_odr;
  ism330dhcx_ctrl2_g_t ctrl2_g;
  int32_t ret;
  /* Check the Finite State Machine data rate constraints */
  ret =  ism330dhcx_fsm_enable_get(h_ism, &fsm_enable);

  if (ret == 0) {
    if ( (fsm_enable.fsm_enable_a.fsm1_en  |
          fsm_enable.fsm_enable_a.fsm2_en  |
          fsm_enable.fsm_enable_a.fsm3_en  |
          fsm_enable.fsm_enable_a.fsm4_en  |
          fsm_enable.fsm_enable_a.fsm5_en  |
          fsm_enable.fsm_enable_a.fsm6_en  |
          fsm_enable.fsm_enable_a.fsm7_en  |
          fsm_enable.fsm_enable_a.fsm8_en  |
          fsm_enable.fsm_enable_b.fsm9_en  |
          fsm_enable.fsm_enable_b.fsm10_en |
          fsm_enable.fsm_enable_b.fsm11_en |
          fsm_enable.fsm_enable_b.fsm12_en |
          fsm_enable.fsm_enable_b.fsm13_en |
          fsm_enable.fsm_enable_b.fsm14_en |
          fsm_enable.fsm_enable_b.fsm15_en |
          fsm_enable.fsm_enable_b.fsm16_en ) == PROPERTY_ENABLE ) {
      ret =  ism330dhcx_fsm_data_rate_get(h_ism, &fsm_odr);

      if (ret == 0) {
        switch (fsm_odr) {
          case ISM330DHCX_ODR_FSM_12Hz5:
            if (val == ISM330DHCX_GY_ODR_OFF) {
              odr_gy = ISM330DHCX_GY_ODR_12Hz5;
            }

            else {
              odr_gy = val;
            }

            break;

          case ISM330DHCX_ODR_FSM_26Hz:
            if (val == ISM330DHCX_GY_ODR_OFF) {
              odr_gy = ISM330DHCX_GY_ODR_26Hz;
            }

            else if (val == ISM330DHCX_GY_ODR_12Hz5) {
              odr_gy = ISM330DHCX_GY_ODR_26Hz;
            }

            else {
              odr_gy = val;
            }

            break;

          case ISM330DHCX_ODR_FSM_52Hz:
            if (val == ISM330DHCX_GY_ODR_OFF) {
              odr_gy = ISM330DHCX_GY_ODR_52Hz;
            }

            else if (val == ISM330DHCX_GY_ODR_12Hz5) {
              odr_gy = ISM330DHCX_GY_ODR_52Hz;
            }

            else if (val == ISM330DHCX_GY_ODR_26Hz) {
              odr_gy = ISM330DHCX_GY_ODR_52Hz;
            }

            else {
              odr_gy = val;
            }

            break;

          case ISM330DHCX_ODR_FSM_104Hz:
            if (val == ISM330DHCX_GY_ODR_OFF) {
              odr_gy = ISM330DHCX_GY_ODR_104Hz;
            }

            else if (val == ISM330DHCX_GY_ODR_12Hz5) {
              odr_gy = ISM330DHCX_GY_ODR_104Hz;
            }

            else if (val == ISM330DHCX_GY_ODR_26Hz) {
              odr_gy = ISM330DHCX_GY_ODR_104Hz;
            }

            else if (val == ISM330DHCX_GY_ODR_52Hz) {
              odr_gy = ISM330DHCX_GY_ODR_104Hz;
            }

            else {
              odr_gy = val;
            }

            break;

          default:
            odr_gy = val;
            break;
        }
      }
    }
  }

  /* Check the Machine Learning Core data rate constraints */
  mlc_enable = PROPERTY_DISABLE;

  if (ret == 0) {
    ret =  ism330dhcx_mlc_get(h_ism, &mlc_enable);

    if ( mlc_enable == PROPERTY_ENABLE ) {
      ret =  ism330dhcx_mlc_data_rate_get(h_ism, &mlc_odr);

      if (ret == 0) {
        switch (mlc_odr) {
          case ISM330DHCX_ODR_PRGS_12Hz5:
            if (val == ISM330DHCX_GY_ODR_OFF) {
              odr_gy = ISM330DHCX_GY_ODR_12Hz5;
            }

            else {
              odr_gy = val;
            }

            break;

          case ISM330DHCX_ODR_PRGS_26Hz:
            if (val == ISM330DHCX_GY_ODR_OFF) {
              odr_gy = ISM330DHCX_GY_ODR_26Hz;
            }

            else if (val == ISM330DHCX_GY_ODR_12Hz5) {
              odr_gy = ISM330DHCX_GY_ODR_26Hz;
            }

            else {
              odr_gy = val;
            }

            break;

          case ISM330DHCX_ODR_PRGS_52Hz:
            if (val == ISM330DHCX_GY_ODR_OFF) {
              odr_gy = ISM330DHCX_GY_ODR_52Hz;
            }

            else if (val == ISM330DHCX_GY_ODR_12Hz5) {
              odr_gy = ISM330DHCX_GY_ODR_52Hz;
            }

            else if (val == ISM330DHCX_GY_ODR_26Hz) {
              odr_gy = ISM330DHCX_GY_ODR_52Hz;
            }

            else {
              odr_gy = val;
            }

            break;

          case ISM330DHCX_ODR_PRGS_104Hz:
            if (val == ISM330DHCX_GY_ODR_OFF) {
              odr_gy = ISM330DHCX_GY_ODR_104Hz;
            }

            else if (val == ISM330DHCX_GY_ODR_12Hz5) {
              odr_gy = ISM330DHCX_GY_ODR_104Hz;
            }

            else if (val == ISM330DHCX_GY_ODR_26Hz) {
              odr_gy = ISM330DHCX_GY_ODR_104Hz;
            }

            else if (val == ISM330DHCX_GY_ODR_52Hz) {
              odr_gy = ISM330DHCX_GY_ODR_104Hz;
            }

            else {
              odr_gy = val;
            }

            break;

          default:
            odr_gy = val;
            break;
        }
      }
    }
  }

  if (ret == 0) {
    ret = ism330dhcx_read(h_ism, CTRL2_G,
                              (uint8_t *)&ctrl2_g, 1);
  }

  if (ret == 0) {
    ctrl2_g.odr_g = (uint8_t)odr_gy;
    ret = ism330dhcx_write(h_ism, CTRL2_G,
                               (uint8_t *)&ctrl2_g, 1);
  }

  return ret;
}

/* Set Full Scale */
int32_t ism330dhcx_xl_full_scale_set(ISM330DHCX_HandleTypeDef *h_ism, ism330dhcx_fs_xl_t val)
{
  ism330dhcx_ctrl3_ois_t ctrl3_ois;
  int32_t ret;
  ret = ism330dhcx_read(h_ism, CTRL3_OIS,
                            (uint8_t *)&ctrl3_ois, 1);

  if (ret == 0) {
    ctrl3_ois.fs_xl_ois = (uint8_t)val;
    ret = ism330dhcx_write(h_ism, CTRL3_OIS,
                               (uint8_t *)&ctrl3_ois, 1);
  }

  return ret;
}

int32_t ism330dhcx_gy_full_scale_set(ISM330DHCX_HandleTypeDef *h_ism, ism330dhcx_fs_g_t val)
{
  ism330dhcx_ctrl2_g_t ctrl2_g;
  int32_t ret = 0;
  ret = ism330dhcx_read(h_ism, CTRL2_G,
                            (uint8_t *)&ctrl2_g, 1);

  if (ret == 0) {
    ctrl2_g.fs_g = (uint8_t)val;
    ret = ism330dhcx_write(h_ism, CTRL2_G,
                               (uint8_t *)&ctrl2_g, 1);
  }

  return ret;
}

/* Configure Filtering chain (no Aux interface)
    Accelerometer - LPF1 + LPF2 path            */
int32_t ism330dhcx_xl_hp_path_on_out_set(ISM330DHCX_HandleTypeDef *h_ism, ism330dhcx_hp_slope_xl_en_t val)
{
  ism330dhcx_ctrl8_xl_t ctrl8_xl;
  int32_t ret;
  ret = ism330dhcx_read(h_ism, CTRL8_XL,
                            (uint8_t *)&ctrl8_xl, 1);

  if (ret == 0) {
    ctrl8_xl.hp_slope_xl_en = (((uint8_t)val & 0x10U) >> 4);
    ctrl8_xl.hp_ref_mode_xl = (((uint8_t)val & 0x20U) >> 5);
    ctrl8_xl.hpcf_xl = (uint8_t)val & 0x07U;
    ret = ism330dhcx_write(h_ism, CTRL8_XL,
                               (uint8_t *)&ctrl8_xl, 1);
  }

  return ret;
}

int32_t ism330dhcx_xl_filter_lp2_set(ISM330DHCX_HandleTypeDef *h_ism, uint8_t val)
{
    ism330dhcx_ctrl1_xl_t ctrl1_xl;
    int32_t ret;
    ret = ism330dhcx_read(h_ism, CTRL1_XL,
                            (uint8_t *)&ctrl1_xl, 1);

    if (ret == 0) {
        ctrl1_xl.lpf2_xl_en = (uint8_t)val;
        ret = ism330dhcx_write(h_ism, CTRL1_XL,
                               (uint8_t *)&ctrl1_xl, 1);
    }
  return ret;
}

/********** Reading samples on Polling mod (no int) **********/

/* Read Acceleration Data Ready Flag */
int32_t ism330dhcx_xl_flag_data_ready_get(ISM330DHCX_HandleTypeDef *h_ism, uint8_t *val)
{
    ism330dhcx_spi_aux_t status_spiaux;
    int32_t ret;
    ret = ism330dhcx_read(h_ism, STATUS_SPIAUX,
                            (uint8_t *)&status_spiaux, 1);
    *val = status_spiaux.xlda;
    return ret;
}

/* Read Acceleration Field Data */
int32_t ism330dhcx_acceleration_raw_get(ISM330DHCX_HandleTypeDef *h_ism, int16_t *val)
{
    int32_t ret = 0;
    uint8_t buff[6];

    ret = ism330dhcx_read(h_ism, OUTX_L_A, buff, 6);

    if(!ret) {
    	val[0] = (int16_t)buff[1]*256 + (int16_t)buff[0];	//< [OUTX_A] = OUTX_H_A<<8 | OUTX_L_A
    	val[1] = (int16_t)buff[3]*256 + (int16_t)buff[2];	//< [OUTY_A]
    	val[2] = (int16_t)buff[5]*256 + (int16_t)buff[4];	//<	[OUTZ_A]
    }

    return ret;
}

/* Read Acceleration Data Ready Flag */
int32_t ism330dhcx_gy_flag_data_ready_get(ISM330DHCX_HandleTypeDef *h_ism, uint8_t *val)
{
	ism330dhcx_spi_aux_t status_spiaux;
	int32_t ret;
	ret = ism330dhcx_read(h_ism, STATUS_SPIAUX,
                            (uint8_t *)&status_spiaux, 1);
	*val = status_spiaux.gda;
	return ret;
}
/* Read Angular Rate Field Data */
int32_t ism330dhcx_angular_rate_raw_get(ISM330DHCX_HandleTypeDef *h_ism, int16_t *val)
{
    int32_t ret = 0;
    uint8_t buff[6];

    ret = ism330dhcx_read(h_ism, OUTX_L_G, buff, 6);

    if(!ret) {
    	val[0] = (int16_t)buff[1]*256 + (int16_t)buff[0];	//< OUTX_G
    	val[1] = (int16_t)buff[3]*256 + (int16_t)buff[2];	//< OUTY_G
    	val[2] = (int16_t)buff[5]*256 + (int16_t)buff[4];	//< OUTZ_G
    }
    return ret;
}

/* Read Temperature Data Ready Flag */
int32_t ism330dhcx_temp_flag_data_ready_get(ISM330DHCX_HandleTypeDef *h_ism, uint8_t *val)
{
    ism330dhcx_status_reg_t status_reg;
    int32_t ret;
    ret = ism330dhcx_read(h_ism, STATUS_SPIAUX,
                            (uint8_t *)&status_reg, 1);
    *val = status_reg.tda;
    return ret;
}

/* Read Temperature  Data */
int32_t ism330dhcx_temperature_raw_get(ISM330DHCX_HandleTypeDef *h_ism, int16_t *val)
{
    uint8_t buff[2];
    int32_t ret;
    ret = ism330dhcx_read(h_ism, OUT_TEMP_L, buff, 2);
    *val = (int16_t)buff[1];
    *val = (*val * 256) +  (int16_t)buff[0];
    return ret;
}

/**
  * @brief  Embedded final state machine functions mode.[get]
  *
  * @param  h_ism    Read / write interface definitions.(ptr)
  * @param  val    Structure of registers from FSM_ENABLE_A to FSM_ENABLE_B
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t ism330dhcx_fsm_enable_get(ISM330DHCX_HandleTypeDef *h_ism,
                                  ism330dhcx_emb_fsm_enable_t *val)
{
  int32_t ret;
  ret = ism330dhcx_mem_bank_set(h_ism, ISM330DHCX_EMBEDDED_FUNC_BANK);

  if (ret == 0) {
    ret = ism330dhcx_read(h_ism, FSM_ENABLE_A,
                              (uint8_t *)&val->fsm_enable_a, 1);
  }

  if (ret == 0) {
    ret = ism330dhcx_read(h_ism, FSM_ENABLE_B,
                              (uint8_t *)&val->fsm_enable_b, 1);
  }

  if (ret == 0) {
    ret = ism330dhcx_mem_bank_set(h_ism, ISM330DHCX_USER_BANK);
  }

  return ret;
}

/**
  * @brief  Enable access to the embedded functions/sensor hub configuration
  *         registers.[set]
  *
  * @param  h_ism    Read / write interface definitions.(ptr)
  * @param  val    Change the values of reg_access in reg FUNC_CFG_ACCESS
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t ism330dhcx_mem_bank_set(ISM330DHCX_HandleTypeDef *h_ism,
                                ism330dhcx_reg_access_t val)
{
  ism330dhcx_func_cfg_access_t func_cfg_access;
  int32_t ret;
  ret = ism330dhcx_read(h_ism, FUNC_CFG_ACCESS,
                            (uint8_t *)&func_cfg_access, 1);

  if (ret == 0) {
    func_cfg_access.reg_access = (uint8_t)val;
    ret = ism330dhcx_write(h_ism, FUNC_CFG_ACCESS,
                               (uint8_t *)&func_cfg_access, 1);
  }

  return ret;
}

/**
  * @brief  Finite State Machine ODR configuration.[get]
  *
  * @param  h_ism    Read / write interface definitions.(ptr)
  * @param  val    Get the values of fsm_odr in reg EMB_FUNC_ODR_CFG_B
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t ism330dhcx_fsm_data_rate_get(ISM330DHCX_HandleTypeDef *h_ism,
                                     ism330dhcx_fsm_odr_t *val)
{
  ism330dhcx_emb_func_odr_cfg_b_t emb_func_odr_cfg_b;
  int32_t ret;
  ret = ism330dhcx_mem_bank_set(h_ism, ISM330DHCX_EMBEDDED_FUNC_BANK);

  if (ret == 0) {
    ret = ism330dhcx_read(h_ism, EMB_FUNC_ODR_CFG_B,
                              (uint8_t *)&emb_func_odr_cfg_b, 1);
  }

  if (ret == 0) {
    ret = ism330dhcx_mem_bank_set(h_ism, ISM330DHCX_USER_BANK);
  }

  switch (emb_func_odr_cfg_b.fsm_odr) {
    case ISM330DHCX_ODR_FSM_12Hz5:
      *val = ISM330DHCX_ODR_FSM_12Hz5;
      break;

    case ISM330DHCX_ODR_FSM_26Hz:
      *val = ISM330DHCX_ODR_FSM_26Hz;
      break;

    case ISM330DHCX_ODR_FSM_52Hz:
      *val = ISM330DHCX_ODR_FSM_52Hz;
      break;

    case ISM330DHCX_ODR_FSM_104Hz:
      *val = ISM330DHCX_ODR_FSM_104Hz;
      break;

    default:
      *val = ISM330DHCX_ODR_FSM_12Hz5;
      break;
  }

  return ret;
}

/**
  * @brief  Enable Machine Learning Core.[get]
  *
  * @param  h_ism      read / write interface definitions
  * @param  val      Get the values of mlc_en in
  *                  reg EMB_FUNC_EN_B
  *
  */
int32_t ism330dhcx_mlc_get(ISM330DHCX_HandleTypeDef *h_ism, uint8_t *val)
{
  ism330dhcx_emb_func_en_b_t reg;
  int32_t ret;
  ret = ism330dhcx_mem_bank_set(h_ism, ISM330DHCX_EMBEDDED_FUNC_BANK);

  if (ret == 0) {
    ret = ism330dhcx_read(h_ism, EMB_FUNC_EN_B,
                              (uint8_t *)&reg, 1);
  }

  if (ret == 0) {
    ret = ism330dhcx_mem_bank_set(h_ism, ISM330DHCX_USER_BANK);
    *val  = reg.mlc_en;
  }

  return ret;
}

/**
  * @brief  Machine Learning Core data rate selection.[get]
  *
  * @param  h_ism      read / write interface definitions
  * @param  val      change the values of mlc_odr in
  *                  reg EMB_FUNC_ODR_CFG_C
  *
  */
int32_t ism330dhcx_mlc_data_rate_get(ISM330DHCX_HandleTypeDef *h_ism,
                                     ism330dhcx_mlc_odr_t *val)
{
  ism330dhcx_emb_func_odr_cfg_c_t reg;
  int32_t ret;
  ret = ism330dhcx_mem_bank_set(h_ism, ISM330DHCX_EMBEDDED_FUNC_BANK);

  if (ret == 0) {
    ret = ism330dhcx_read(h_ism, EMB_FUNC_ODR_CFG_C,
                              (uint8_t *)&reg, 1);
  }

  if (ret == 0) {
    switch (reg.mlc_odr) {
      case ISM330DHCX_ODR_PRGS_12Hz5:
        *val = ISM330DHCX_ODR_PRGS_12Hz5;
        break;

      case ISM330DHCX_ODR_PRGS_26Hz:
        *val = ISM330DHCX_ODR_PRGS_26Hz;
        break;

      case ISM330DHCX_ODR_PRGS_52Hz:
        *val = ISM330DHCX_ODR_PRGS_52Hz;
        break;

      case ISM330DHCX_ODR_PRGS_104Hz:
        *val = ISM330DHCX_ODR_PRGS_104Hz;
        break;

      default:
        *val = ISM330DHCX_ODR_PRGS_12Hz5;
        break;
    }

    ret = ism330dhcx_mem_bank_set(h_ism, ISM330DHCX_USER_BANK);
  }

  return ret;
}

/**********          Conversion Function            **********/
/* Extern functions */
float_t ism330dhcx_from_fs2g_to_mg(int16_t lsb)
{
    return ((float_t)lsb * 0.061f / 1000.0f);
}
float_t ism330dhcx_from_fs4g_to_mg(int16_t lsb)
{
    return ((float_t)lsb * 0.122f / 1000.0f);
}
float_t ism330dhcx_from_fs8g_to_mg(int16_t lsb)
{
  return ((float_t)lsb * 0.244f / 1000.0f);
}
float_t ism330dhcx_from_fs16g_to_mg(int16_t lsb)
{
  return ((float_t)lsb * 0.488f / 1000.0f);
}
float_t ism330dhcx_from_fs125dps_to_mdps(int16_t lsb)
{
  return ((float_t)lsb * 4.375f / 1000.0f);
}
float_t ism330dhcx_from_fs250dps_to_mdps(int16_t lsb)
{
  return ((float_t)lsb * 8.75f / 1000.0f);
}
float_t ism330dhcx_from_fs500dps_to_mdps(int16_t lsb)
{
  return ((float_t)lsb * 17.50f / 1000.0f);
}
float_t ism330dhcx_from_fs1000dps_to_mdps(int16_t lsb)
{
  return ((float_t)lsb * 35.0f / 1000.0f);
}
float_t ism330dhcx_from_fs2000dps_to_mdps(int16_t lsb)
{
  return ((float_t)lsb * 70.0f / 1000.0f);
}
float_t ism330dhcx_from_fs4000dps_to_mdps(int16_t lsb)
{
  return ((float_t)lsb * 140.0f / 1000.0f);
}
float_t ism330dhcx_from_lsb_to_celsius(int16_t lsb)
{
  return (((float_t)lsb / 256.0f) + 25.0f);
}
float_t ism330dhcx_from_lsb_to_nsec(int32_t lsb)
{
  return ((float_t)lsb * 25000.0f);
}
