// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright 2019 NXP
 *
 */

#ifndef PCA9450_H_
#define PCA9450_H_

#define PCA9450_REGULATOR_DRIVER "pca9450_regulator"

enum {
	PCA9450_REG_DEV_ID      = 0x00,
	PCA9450_INT1            = 0x01,
	PCA9450_INT1_MSK        = 0x02,
	PCA9450_STATUS1         = 0x03,
	PCA9450_STATUS2         = 0x04,
	PCA9450_PWRON_STAT      = 0x05,
	PCA9450_SW_RST          = 0x06,
	PCA9450_PWR_CTRL        = 0x07,
	PCA9450_RESET_CTRL      = 0x08,
	PCA9450_CONFIG1         = 0x09,
	PCA9450_CONFIG2         = 0x0A,
	PCA9450_BUCK123_DVS     = 0x0C,
	PCA9450_BUCK1OUT_LIMIT  = 0x0D,
	PCA9450_BUCK2OUT_LIMIT  = 0x0E,
	PCA9450_BUCK3OUT_LIMIT  = 0x0F,
	PCA9450_BUCK1CTRL       = 0x10,
	PCA9450_BUCK1OUT_DVS0   = 0x11,
	PCA9450_BUCK1OUT_DVS1   = 0x12,
	PCA9450_BUCK2CTRL       = 0x13,
	PCA9450_BUCK2OUT_DVS0   = 0x14,
	PCA9450_BUCK2OUT_DVS1   = 0x15,
	PCA9450_BUCK3CTRL       = 0x16,
	PCA9450_BUCK3OUT_DVS0   = 0x17,
	PCA9450_BUCK3OUT_DVS1   = 0x18,
	PCA9450_BUCK4CTRL       = 0x19,
	PCA9450_BUCK4OUT        = 0x1A,
	PCA9450_BUCK5CTRL       = 0x1B,
	PCA9450_BUCK5OUT        = 0x1C,
	PCA9450_BUCK6CTRL       = 0x1D,
	PCA9450_BUCK6OUT        = 0x1E,
	PCA9450_LDO_AD_CTRL     = 0x20,
	PCA9450_LDO1CTRL        = 0x21,
	PCA9450_LDO2CTRL        = 0x22,
	PCA9450_LDO3CTRL        = 0x23,
	PCA9450_LDO4CTRL        = 0x24,
	PCA9450_LDO5CTRL_L      = 0x25,
	PCA9450_LDO5CTRL_H      = 0x26,
	PCA9450_LOADSW_CTRL     = 0x2A,
	PCA9450_VRFLT1_STS      = 0x2B,
	PCA9450_VRFLT2_STS      = 0x2C,
	PCA9450_VRFLT1_MASK     = 0x2D,
	PCA9450_VRFLT2_MASK     = 0x2E,
	PCA9450_REG_NUM,
};

int power_pca9450a_init(unsigned char bus);
int power_pca9450b_init(unsigned char bus);

#endif
