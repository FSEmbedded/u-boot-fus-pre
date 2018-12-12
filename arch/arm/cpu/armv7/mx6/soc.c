/*
 * (C) Copyright 2007
 * Sascha Hauer, Pengutronix
 *
 * (C) Copyright 2009 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/errno.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <asm/imx-common/boot_mode.h>
#include <asm/imx-common/dma.h>
#include <asm/imx-common/hab.h>
#include <stdbool.h>
#include <asm/arch/mxc_hdmi.h>
#include <asm/arch/crm_regs.h>
#include <dm.h>
#include <imx_thermal.h>
#include <mmc.h>

enum ldo_reg {
	LDO_ARM,
	LDO_SOC,
	LDO_PU,
};

struct scu_regs {
	u32	ctrl;
	u32	config;
	u32	status;
	u32	invalidate;
	u32	fpga_rev;
};

#if defined(CONFIG_IMX_THERMAL)
static const struct imx_thermal_plat imx6_thermal_plat = {
	.regs = (void *)ANATOP_BASE_ADDR,
	.fuse_bank = 1,
	.fuse_word = 6,
};

U_BOOT_DEVICE(imx6_thermal) = {
	.name = "imx_thermal",
	.platdata = &imx6_thermal_plat,
};
#endif

#if defined(CONFIG_SECURE_BOOT)
struct imx_sec_config_fuse_t const imx_sec_config_fuse = {
	.bank = 0,
	.word = 6,
};
#endif

u32 get_nr_cpus(void)
{
	struct scu_regs *scu = (struct scu_regs *)SCU_BASE_ADDR;
	return readl(&scu->config) & 3;
}

u32 get_cpu_rev(void)
{
	struct anatop_regs *anatop = (struct anatop_regs *)ANATOP_BASE_ADDR;
	u32 reg = readl(&anatop->digprog_sololite);
	u32 type = ((reg >> 16) & 0xff);
	u32 major, cfg = 0;

	if (type != MXC_CPU_MX6SL) {
		reg = readl(&anatop->digprog);
		struct scu_regs *scu = (struct scu_regs *)SCU_BASE_ADDR;
		cfg = readl(&scu->config) & 3;
		type = ((reg >> 16) & 0xff);
		if (type == MXC_CPU_MX6DL) {
			if (!cfg)
				type = MXC_CPU_MX6SOLO;
		}

		if (type == MXC_CPU_MX6Q) {
			if (cfg == 1)
				type = MXC_CPU_MX6D;
		}

	}
	major = ((reg >> 8) & 0xff);
	if ((major >= 1) &&
	    ((type == MXC_CPU_MX6Q) || (type == MXC_CPU_MX6D))) {
		major--;
		type = MXC_CPU_MX6QP;
		if (cfg == 1)
			type = MXC_CPU_MX6DP;
	}
	reg &= 0xff;		/* mx6 silicon revision */
	return (type << 12) | (reg + (0x10 * (major + 1)));
}

/*
 * OCOTP_CFG3[17:16] (see Fusemap Description Table offset 0x440)
 * defines a 2-bit SPEED_GRADING
 */
#define OCOTP_CFG3_SPEED_SHIFT	16
#define OCOTP_CFG3_SPEED_800MHZ	0
#define OCOTP_CFG3_SPEED_850MHZ	1
#define OCOTP_CFG3_SPEED_1GHZ	2
#define OCOTP_CFG3_SPEED_1P2GHZ	3

/*
 * For i.MX6UL
 */
#define OCOTP_CFG3_SPEED_528MHZ 1
#define OCOTP_CFG3_SPEED_696MHZ 2

u32 get_cpu_speed_grade_hz(void)
{
	struct ocotp_regs *ocotp = (struct ocotp_regs *)OCOTP_BASE_ADDR;
	struct fuse_bank *bank = &ocotp->bank[0];
	struct fuse_bank0_regs *fuse =
		(struct fuse_bank0_regs *)bank->fuse_regs;
	uint32_t val;

	val = readl(&fuse->cfg3);
	val >>= OCOTP_CFG3_SPEED_SHIFT;
	val &= 0x3;

	/* UL: 2b'00: Reserved, 2b'01: 528MHz, 2b'10: 696MHz, 2b'11: Reserved */
	if (is_cpu_type(MXC_CPU_MX6UL)) {
		switch (val) {
		case 1:
			return 528000000;
		case 2:
			return 696000000;
		default:
			return 0;
		}
	}
	/* ULL: 2b'00: Reserved, 2b'01: 528MHz, 2b'10: 792MHz, 2b'11: 900MHz */
	if (is_cpu_type(MXC_CPU_MX6ULL)) {
		switch (val) {
		case 1:
			return 528000000;
		case 2:
			return 792000000;
		case 3:
			return 900000000;
		default:
			return 0;
		}
	}

	switch (val) {
	/* Valid for IMX6DQ */
	case OCOTP_CFG3_SPEED_1P2GHZ:
		if (is_cpu_type(MXC_CPU_MX6Q) || is_cpu_type(MXC_CPU_MX6D) ||
			is_cpu_type(MXC_CPU_MX6QP) || is_cpu_type(MXC_CPU_MX6DP))
			return 1200000000;
	/* Valid for IMX6SX/IMX6SDL/IMX6DQ */
	case OCOTP_CFG3_SPEED_1GHZ:
		return 996000000;
	/* Valid for IMX6DQ */
	case OCOTP_CFG3_SPEED_850MHZ:
		if (is_cpu_type(MXC_CPU_MX6Q) || is_cpu_type(MXC_CPU_MX6D) ||
			is_cpu_type(MXC_CPU_MX6QP) || is_cpu_type(MXC_CPU_MX6DP))
			return 852000000;
	/* Valid for IMX6SX/IMX6SDL/IMX6DQ */
	case OCOTP_CFG3_SPEED_800MHZ:
		return 792000000;
	}
	return 0;
}

/*
 * OCOTP_MEM0[7:6] (see Fusemap Description Table offset 0x480)
 * defines a 2-bit Temperature Grade
 *
 * return temperature grade and min/max temperature in celcius
 */
#define OCOTP_MEM0_TEMP_SHIFT          6

u32 get_cpu_temp_grade(int *minc, int *maxc)
{
	struct ocotp_regs *ocotp = (struct ocotp_regs *)OCOTP_BASE_ADDR;
	struct fuse_bank *bank = &ocotp->bank[1];
	struct fuse_bank1_regs *fuse =
		(struct fuse_bank1_regs *)bank->fuse_regs;
	uint32_t val;

	val = readl(&fuse->mem0);
	val >>= OCOTP_MEM0_TEMP_SHIFT;
	val &= 0x3;

	if (minc && maxc) {
		if (val == TEMP_AUTOMOTIVE) {
			*minc = -40;
			*maxc = 125;
		} else if (val == TEMP_INDUSTRIAL) {
			*minc = -40;
			*maxc = 105;
		} else if (val == TEMP_EXTCOMMERCIAL) {
			*minc = -20;
			*maxc = 105;
		} else {
			*minc = 0;
			*maxc = 95;
		}
	}
	return val;
}

#ifdef CONFIG_REVISION_TAG
u32 __weak get_board_rev(void)
{
	u32 cpurev = get_cpu_rev();
	u32 type = ((cpurev >> 12) & 0xff);
	if (type == MXC_CPU_MX6SOLO)
		cpurev = (MXC_CPU_MX6DL) << 12 | (cpurev & 0xFFF);

	if (type == MXC_CPU_MX6D)
		cpurev = (MXC_CPU_MX6Q) << 12 | (cpurev & 0xFFF);

	if (type == MXC_CPU_MX6QP || type == MXC_CPU_MX6DP)
		cpurev = (MXC_CPU_MX6Q) << 12 | ((cpurev + 0x10) & 0xFFF);

	return cpurev;
}
#endif

static void clear_ldo_ramp(void)
{
	struct anatop_regs *anatop = (struct anatop_regs *)ANATOP_BASE_ADDR;
	int reg;

	/* ROM may modify LDO ramp up time according to fuse setting, so in
	 * order to be in the safe side we neeed to reset these settings to
	 * match the reset value: 0'b00
	 */
	reg = readl(&anatop->ana_misc2);
	reg &= ~(0x3f << 24);
	writel(reg, &anatop->ana_misc2);
}

/*
 * Set the PMU_REG_CORE register
 *
 * Set LDO_SOC/PU/ARM regulators to the specified millivolt level.
 * Possible values are from 0.725V to 1.450V in steps of
 * 0.025V (25mV).
 */
static int set_ldo_voltage(enum ldo_reg ldo, u32 mv)
{
	struct anatop_regs *anatop = (struct anatop_regs *)ANATOP_BASE_ADDR;
	u32 val, step, old, reg = readl(&anatop->reg_core);
	u8 shift;

	if (mv < 725)
		val = 0x00;	/* Power gated off */
	else if (mv > 1450)
		val = 0x1F;	/* Power FET switched full on. No regulation */
	else
		val = (mv - 700) / 25;

	clear_ldo_ramp();

	switch (ldo) {
	case LDO_SOC:
		shift = 18;
		break;
	case LDO_PU:
		shift = 9;
		break;
	case LDO_ARM:
		shift = 0;
		break;
	default:
		return -EINVAL;
	}

	old = (reg & (0x1F << shift)) >> shift;
	step = abs(val - old);
	if (step == 0)
		return 0;

	reg = (reg & ~(0x1F << shift)) | (val << shift);
	writel(reg, &anatop->reg_core);

	/*
	 * The LDO ramp-up is based on 64 clock cycles of 24 MHz = 2.6 us per
	 * step
	 */
	udelay(3 * step);

	return 0;
}

static void set_ahb_rate(u32 val)
{
	struct mxc_ccm_reg *mxc_ccm = (struct mxc_ccm_reg *)CCM_BASE_ADDR;
	u32 reg, div;

	div = get_periph_clk() / val - 1;
	reg = readl(&mxc_ccm->cbcdr);

	writel((reg & (~MXC_CCM_CBCDR_AHB_PODF_MASK)) |
		(div << MXC_CCM_CBCDR_AHB_PODF_OFFSET), &mxc_ccm->cbcdr);
}

static void clear_mmdc_ch_mask(void)
{
	struct mxc_ccm_reg *mxc_ccm = (struct mxc_ccm_reg *)CCM_BASE_ADDR;
	u32 reg;
	reg = readl(&mxc_ccm->ccdr);

	/* Clear MMDC channel mask */
	if (is_cpu_type(MXC_CPU_MX6SX) || is_cpu_type(MXC_CPU_MX6UL) ||
	    is_cpu_type(MXC_CPU_MX6SL) || is_cpu_type(MXC_CPU_MX6ULL))
		reg &= ~(MXC_CCM_CCDR_MMDC_CH1_HS_MASK);
	else
		reg &= ~(MXC_CCM_CCDR_MMDC_CH1_HS_MASK | MXC_CCM_CCDR_MMDC_CH0_HS_MASK);
	writel(reg, &mxc_ccm->ccdr);
}

static void init_bandgap(void)
{
	struct anatop_regs *anatop = (struct anatop_regs *)ANATOP_BASE_ADDR;
	/*
	 * Ensure the bandgap has stabilized.
	 */
	while (!(readl(&anatop->ana_misc0) & 0x80))
		;
	/*
	 * For best noise performance of the analog blocks using the
	 * outputs of the bandgap, the reftop_selfbiasoff bit should
	 * be set.
	 */
	writel(BM_ANADIG_ANA_MISC0_REFTOP_SELBIASOFF, &anatop->ana_misc0_set);
}


#ifdef CONFIG_MX6SL
static void set_preclk_from_osc(void)
{
	struct mxc_ccm_reg *mxc_ccm = (struct mxc_ccm_reg *)CCM_BASE_ADDR;
	u32 reg;

	reg = readl(&mxc_ccm->cscmr1);
	reg |= MXC_CCM_CSCMR1_PER_CLK_SEL_MASK;
	writel(reg, &mxc_ccm->cscmr1);
}
#endif

int arch_cpu_init(void)
{
	if (!is_cpu_type(MXC_CPU_MX6SL) && !is_cpu_type(MXC_CPU_MX6SX)
	    && !is_cpu_type(MXC_CPU_MX6UL) && !is_cpu_type(MXC_CPU_MX6ULL)) {
		/*
		 * imx6sl doesn't have pcie at all.
		 * this bit is not used by imx6sx anymore
		 */
		u32 val;

		/*
		 * There are about 0.02% percentage, random pcie link down
		 * when warm-reset is used.
		 * clear the ref_ssp_en bit16 of gpr1 to workaround it.
		 * then warm-reset imx6q/dl/solo again.
		 */
		val = readl(IOMUXC_BASE_ADDR + 0x4);
		if (val & (0x1 << 16)) {
			val &= ~(0x1 << 16);
			writel(val, IOMUXC_BASE_ADDR + 0x4);
			reset_cpu(0);
		}
	}

	init_aips();

	/* Need to clear MMDC_CHx_MASK to make warm reset work. */
	clear_mmdc_ch_mask();

	/*
	 * Disable self-bias circuit in the analog bandap.
	 * The self-bias circuit is used by the bandgap during startup.
	 * This bit should be set after the bandgap has initialized.
	 */
	init_bandgap();

	if (!is_cpu_type(MXC_CPU_MX6UL) && !is_cpu_type(MXC_CPU_MX6ULL)) {
		/*
		 * When low freq boot is enabled, ROM will not set AHB
		 * freq, so we need to ensure AHB freq is 132MHz in such
		 * scenario.
		 */
		if (mxc_get_clock(MXC_ARM_CLK) == 396000000)
			set_ahb_rate(132000000);
	}

	if (is_cpu_type(MXC_CPU_MX6UL)) {
		if (is_soc_rev(CHIP_REV_1_0)) {
			/*
			 * According to the design team's requirement on i.MX6UL,
			 * the PMIC_STBY_REQ PAD should be configured as open
			 * drain 100K (0x0000b8a0).
			 */
			writel(0x0000b8a0, IOMUXC_BASE_ADDR + 0x29c);
		} else {
			/*
			 * From TO1.1, SNVS adds internal pull up control for POR_B,
			 * the register filed is GPBIT[1:0], after system boot up,
			 * it can be set to 2b'01 to disable internal pull up.
			 * It can save about 30uA power in SNVS mode.
			 */
			writel((readl(MX6UL_SNVS_LP_BASE_ADDR + 0x10) & (~0x1400)) | 0x400,
				MX6UL_SNVS_LP_BASE_ADDR + 0x10);
		}
	}

	if (is_cpu_type(MXC_CPU_MX6ULL)) {
		/*
		 * GPBIT[1:0] is suggested to set to 2'b11:
		 * 2'b00 : always PUP100K
		 * 2'b01 : PUP100K when PMIC_ON_REQ or SOC_NOT_FAIL
		 * 2'b10 : always disable PUP100K
		 * 2'b11 : PDN100K when SOC_FAIL, PUP100K when SOC_NOT_FAIL
		 * register offset is different from i.MX6UL, since
		 * i.MX6UL is fixed by ECO.
		 */
		writel(readl(MX6UL_SNVS_LP_BASE_ADDR) |
			0x3, MX6UL_SNVS_LP_BASE_ADDR);
	}

#if defined(CONFIG_MX6SL)
	/* Set perclk to source from OSC 24MHz */
	set_preclk_from_osc();
#endif

	imx_set_wdog_powerdown(false); /* Disable PDE bit of WMCR register */

#ifdef CONFIG_APBH_DMA
	/* Start APBH DMA */
	mxs_dma_init();
#endif

#ifndef CONFIG_PCIE_IMX
	if (is_cpu_type(MXC_CPU_MX6SX))
		set_ldo_voltage(LDO_PU, 0);	/* Set LDO for PCIe to off */
#endif

	init_src();

	return 0;
}

#ifdef CONFIG_ENV_IS_IN_MMC
__weak int board_mmc_get_env_dev(int devno)
{
	return CONFIG_SYS_MMC_ENV_DEV;
}

static int mmc_get_boot_dev(void)
{
	struct src *src_regs = (struct src *)SRC_BASE_ADDR;
	u32 soc_sbmr = readl(&src_regs->sbmr1);
	u32 bootsel;
	int devno;

	/*
	 * Refer to
	 * "i.MX 6Dual/6Quad Applications Processor Reference Manual"
	 * Chapter "8.5.3.1 Expansion Device eFUSE Configuration"
	 * i.MX6SL/SX/UL has same layout.
	 */
	bootsel = (soc_sbmr & 0x000000FF) >> 6;

	/* No boot from sd/mmc */
	if (bootsel != 1)
		return -1;

	/* BOOT_CFG2[3] and BOOT_CFG2[4] */
	devno = (soc_sbmr & 0x00001800) >> 11;

	return devno;
}

int mmc_get_env_dev(void)
{
	int devno = mmc_get_boot_dev();

	/* If not boot from sd/mmc, use default value */
	if (devno < 0)
		return CONFIG_SYS_MMC_ENV_DEV;

	return board_mmc_get_env_dev(devno);
}

#ifdef CONFIG_SYS_MMC_ENV_PART
__weak int board_mmc_get_env_part(int devno)
{
	return CONFIG_SYS_MMC_ENV_PART;
}

uint mmc_get_env_part(struct mmc *mmc)
{
	int devno = mmc_get_boot_dev();

	/* If not boot from sd/mmc, use default value */
	if (devno < 0)
		return CONFIG_SYS_MMC_ENV_PART;

	return board_mmc_get_env_part(devno);
}
#endif
#endif

int board_postclk_init(void)
{
	set_ldo_voltage(LDO_SOC, 1175);	/* Set VDDSOC to 1.175V */

	return 0;
}

#if defined(CONFIG_FEC_MXC)
void imx_get_mac_from_fuse(int dev_id, unsigned char *mac)
{
	struct ocotp_regs *ocotp = (struct ocotp_regs *)OCOTP_BASE_ADDR;
	struct fuse_bank *bank = &ocotp->bank[4];
	struct fuse_bank4_regs *fuse =
			(struct fuse_bank4_regs *)bank->fuse_regs;

	if ((is_cpu_type(MXC_CPU_MX6SX) || is_cpu_type(MXC_CPU_MX6UL) ||
	    is_cpu_type(MXC_CPU_MX6ULL)) && dev_id == 1) {
		u32 value = readl(&fuse->mac_addr2);
		mac[0] = value >> 24 ;
		mac[1] = value >> 16 ;
		mac[2] = value >> 8 ;
		mac[3] = value ;

		value = readl(&fuse->mac_addr1);
		mac[4] = value >> 24 ;
		mac[5] = value >> 16 ;
	} else {
		u32 value = readl(&fuse->mac_addr1);
		mac[0] = (value >> 8);
		mac[1] = value ;

		value = readl(&fuse->mac_addr0);
		mac[2] = value >> 24 ;
		mac[3] = value >> 16 ;
		mac[4] = value >> 8 ;
		mac[5] = value ;
	}

}
#endif

/*
 * cfg_val will be used for
 * Boot_cfg4[7:0]:Boot_cfg3[7:0]:Boot_cfg2[7:0]:Boot_cfg1[7:0]
 * After reset, if GPR10[28] is 1, ROM will use GPR9[25:0]
 * instead of SBMR1 to determine the boot device.
 */
const struct boot_mode soc_boot_modes[] = {
	{"normal",	MAKE_CFGVAL(0x00, 0x00, 0x00, 0x00)},
	/* reserved value should start rom usb */
	{"usb",		MAKE_CFGVAL(0x01, 0x00, 0x00, 0x00)},
	{"sata",	MAKE_CFGVAL(0x20, 0x00, 0x00, 0x00)},
	{"ecspi1:0",	MAKE_CFGVAL(0x30, 0x00, 0x00, 0x08)},
	{"ecspi1:1",	MAKE_CFGVAL(0x30, 0x00, 0x00, 0x18)},
	{"ecspi1:2",	MAKE_CFGVAL(0x30, 0x00, 0x00, 0x28)},
	{"ecspi1:3",	MAKE_CFGVAL(0x30, 0x00, 0x00, 0x38)},
	/* 4 bit bus width */
	{"esdhc1",	MAKE_CFGVAL(0x40, 0x20, 0x00, 0x00)},
	{"esdhc2",	MAKE_CFGVAL(0x40, 0x28, 0x00, 0x00)},
	{"esdhc3",	MAKE_CFGVAL(0x40, 0x30, 0x00, 0x00)},
	{"esdhc4",	MAKE_CFGVAL(0x40, 0x38, 0x00, 0x00)},
	{NULL,		0},
};

void reset_misc(void)
{
#ifdef CONFIG_VIDEO_MXS
	lcdif_power_down();
#endif
}

void s_init(void)
{
	struct anatop_regs *anatop = (struct anatop_regs *)ANATOP_BASE_ADDR;
	struct mxc_ccm_reg *ccm = (struct mxc_ccm_reg *)CCM_BASE_ADDR;
	u32 mask480;
	u32 mask528;
	u32 reg, periph1, periph2;

	if (is_cpu_type(MXC_CPU_MX6SX) || is_cpu_type(MXC_CPU_MX6UL) ||
	    is_cpu_type(MXC_CPU_MX6ULL))
		return;

	/* Due to hardware limitation, on MX6Q we need to gate/ungate all PFDs
	 * to make sure PFD is working right, otherwise, PFDs may
	 * not output clock after reset, MX6DL and MX6SL have added 396M pfd
	 * workaround in ROM code, as bus clock need it
	 */

	mask480 = ANATOP_PFD_CLKGATE_MASK(0) |
		ANATOP_PFD_CLKGATE_MASK(1) |
		ANATOP_PFD_CLKGATE_MASK(2) |
		ANATOP_PFD_CLKGATE_MASK(3);
	mask528 = ANATOP_PFD_CLKGATE_MASK(1) |
		ANATOP_PFD_CLKGATE_MASK(3);

	reg = readl(&ccm->cbcmr);
	periph2 = ((reg & MXC_CCM_CBCMR_PRE_PERIPH2_CLK_SEL_MASK)
		>> MXC_CCM_CBCMR_PRE_PERIPH2_CLK_SEL_OFFSET);
	periph1 = ((reg & MXC_CCM_CBCMR_PRE_PERIPH_CLK_SEL_MASK)
		>> MXC_CCM_CBCMR_PRE_PERIPH_CLK_SEL_OFFSET);

	/* Checking if PLL2 PFD0 or PLL2 PFD2 is using for periph clock */
	if ((periph2 != 0x2) && (periph1 != 0x2))
		mask528 |= ANATOP_PFD_CLKGATE_MASK(0);

	if ((periph2 != 0x1) && (periph1 != 0x1) &&
		(periph2 != 0x3) && (periph1 != 0x3))
		mask528 |= ANATOP_PFD_CLKGATE_MASK(2);

	writel(mask480, &anatop->pfd_480_set);
	writel(mask528, &anatop->pfd_528_set);
	writel(mask480, &anatop->pfd_480_clr);
	writel(mask528, &anatop->pfd_528_clr);
}

#ifdef CONFIG_IMX_HDMI
void imx_enable_hdmi_phy(void)
{
	struct hdmi_regs *hdmi = (struct hdmi_regs *)HDMI_ARB_BASE_ADDR;
	u8 reg;
	reg = readb(&hdmi->phy_conf0);
	reg |= HDMI_PHY_CONF0_PDZ_MASK;
	writeb(reg, &hdmi->phy_conf0);
	udelay(3000);
	reg |= HDMI_PHY_CONF0_ENTMDS_MASK;
	writeb(reg, &hdmi->phy_conf0);
	udelay(3000);
	reg |= HDMI_PHY_CONF0_GEN2_TXPWRON_MASK;
	writeb(reg, &hdmi->phy_conf0);
	writeb(HDMI_MC_PHYRSTZ_ASSERT, &hdmi->mc_phyrstz);
}

void imx_setup_hdmi(void)
{
	struct mxc_ccm_reg *mxc_ccm = (struct mxc_ccm_reg *)CCM_BASE_ADDR;
	struct hdmi_regs *hdmi  = (struct hdmi_regs *)HDMI_ARB_BASE_ADDR;
	int reg, count;
	u8 val;

	/* Turn on HDMI PHY clock */
	reg = readl(&mxc_ccm->CCGR2);
	reg |=  MXC_CCM_CCGR2_HDMI_TX_IAHBCLK_MASK|
		 MXC_CCM_CCGR2_HDMI_TX_ISFRCLK_MASK;
	writel(reg, &mxc_ccm->CCGR2);
	writeb(HDMI_MC_PHYRSTZ_DEASSERT, &hdmi->mc_phyrstz);
	reg = readl(&mxc_ccm->chsccdr);
	reg &= ~(MXC_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL_MASK|
		 MXC_CCM_CHSCCDR_IPU1_DI0_PODF_MASK|
		 MXC_CCM_CHSCCDR_IPU1_DI0_CLK_SEL_MASK);
	reg |= (CHSCCDR_PODF_DIVIDE_BY_3
		 << MXC_CCM_CHSCCDR_IPU1_DI0_PODF_OFFSET)
		 |(CHSCCDR_IPU_PRE_CLK_540M_PFD
		 << MXC_CCM_CHSCCDR_IPU1_DI0_PRE_CLK_SEL_OFFSET);
	writel(reg, &mxc_ccm->chsccdr);

	/* Workaround to clear the overflow condition */
	if (readb(&hdmi->ih_fc_stat2) & HDMI_IH_FC_STAT2_OVERFLOW_MASK) {
		/* TMDS software reset */
		writeb((u8)~HDMI_MC_SWRSTZ_TMDSSWRST_REQ, &hdmi->mc_swrstz);
		val = readb(&hdmi->fc_invidconf);
		for (count = 0 ; count < 5 ; count++)
			writeb(val, &hdmi->fc_invidconf);
	}
}
#endif

#ifdef CONFIG_IMX_BOOTAUX
int arch_auxiliary_core_set_reset_address(u32 boot_private_data)
{
	u32 stack, pc;

	if (!boot_private_data)
		return 1;

	if (boot_private_data != M4_BOOTROM_BASE_ADDR) {
		stack = *(u32 *)boot_private_data;
		pc = *(u32 *)(boot_private_data + 4);

		/* Set the stack and pc to M4 bootROM */
		writel(stack, M4_BOOTROM_BASE_ADDR);
		writel(pc, M4_BOOTROM_BASE_ADDR + 4);
	}

	return 0;
}

void arch_auxiliary_core_set(u32 core_id, enum aux_state state)
{
	struct src *src_reg = (struct src *)SRC_BASE_ADDR;
	struct mxc_ccm_reg *mxc_ccm = (struct mxc_ccm_reg *)CCM_BASE_ADDR;

	if (state == aux_off || state == aux_stopped)
		/* Assert SW reset, i.e. stop M4 if running */
		setbits_le32(&src_reg->scr, 0x00000010);

	if (state == aux_off)
		/* Disable M4 */
		clrbits_le32(&src_reg->scr, 0x00400000);

	if (state == aux_off || state == aux_paused)
		/* Disable M4 clock */
		clrbits_le32(&mxc_ccm->CCGR3, MXC_CCM_CCGR3_M4_MASK);

	if (state == aux_stopped || state == aux_running)
		/* Enable M4 clock */
		setbits_le32(&mxc_ccm->CCGR3, MXC_CCM_CCGR3_M4_MASK);

	if (!(state == aux_off)) {
		/* Enable M4 */
		setbits_le32(&src_reg->scr, 0x00400000);
	}

	if (state == aux_running || state == aux_paused)
		/* Assert SW reset, i.e. stop M4 if running */
		clrbits_le32(&src_reg->scr, 0x00000010);
}

enum aux_state arch_auxiliary_core_get(u32 core_id)
{
	struct src *src_reg = (struct src *)SRC_BASE_ADDR;
	struct mxc_ccm_reg *mxc_ccm = (struct mxc_ccm_reg *)CCM_BASE_ADDR;
	int flags = 0;
	int reg = 0;

	reg = readl(&src_reg->scr);
	if (reg & 0x00000010)
		flags |= 0x4;
	if (reg & 0x00400000)
		flags |= 0x1;
	reg = readl(&mxc_ccm->CCGR3);
	if (reg & MXC_CCM_CCGR3_M4_MASK)
		flags |= 0x2;

	switch (flags)
	{
		case 0x4:
			return aux_off;
		case 0x7:
			return aux_stopped;
		case 0x3:
			return aux_running;
		case 0x1:
			return aux_paused;
	}

	return aux_undefined;
}
#endif
