/*
** ###################################################################
**     Processors:          MIMX8QX6AVLFZ
**                          MIMX8QX6CVLDZ
**
**     Compilers:           GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**                          Keil ARM C/C++ Compiler
**
**     Reference manual:    IMX8DQXPRM, Rev. E, 6/2019
**     Version:             rev. 4.0, 2018-08-22
**     Build:               b191126
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIMX8QX6_cm4
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2019 NXP
**     All rights reserved.
**
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-06-02)
**         Initial version.
**     - rev. 2.0 (2017-08-23)
**         RevA Header EAR
**     - rev. 3.0 (2018-08-22)
**         RevB Header EAR
**     - rev. 4.0 (2018-08-22)
**         RevC Header RFP
**
** ###################################################################
*/

/*!
 * @file MIMX8QX6_cm4.h
 * @version 4.0
 * @date 2018-08-22
 * @brief CMSIS Peripheral Access Layer for MIMX8QX6_cm4
 *
 * CMSIS Peripheral Access Layer for MIMX8QX6_cm4
 */

#ifndef _MIMX8QX6_CM4_H_
#define _MIMX8QX6_CM4_H_                         /**< Symbol preventing repeated inclusion */


/* ----------------------------------------------------------------------------
   -- I2S Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2S_Peripheral_Access_Layer I2S Peripheral Access Layer
 * @{
 */

/** I2S - Register Layout Typedef */
typedef struct {
  __IO uint32_t TCSR;                              /**< SAI Transmit Control Register, offset: 0x0 */
  __IO uint32_t TCR1;                              /**< SAI Transmit Configuration 1 Register, offset: 0x4 */
  __IO uint32_t TCR2;                              /**< SAI Transmit Configuration 2 Register, offset: 0x8 */
  __IO uint32_t TCR3;                              /**< SAI Transmit Configuration 3 Register, offset: 0xC */
  __IO uint32_t TCR4;                              /**< SAI Transmit Configuration 4 Register, offset: 0x10 */
  __IO uint32_t TCR5;                              /**< SAI Transmit Configuration 5 Register, offset: 0x14 */
       uint8_t RESERVED_0[8];
  __O  uint32_t TDR[1];                            /**< SAI Transmit Data Register, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_1[28];
  __I  uint32_t TFR[1];                            /**< SAI Transmit FIFO Register, array offset: 0x40, array step: 0x4 */
       uint8_t RESERVED_2[28];
  __IO uint32_t TMR;                               /**< SAI Transmit Mask Register, offset: 0x60 */
       uint8_t RESERVED_3[28];
  __IO uint32_t RCSR;                              /**< SAI Receive Control Register, offset: 0x80 */
  __IO uint32_t RCR1;                              /**< SAI Receive Configuration 1 Register, offset: 0x84 */
  __IO uint32_t RCR2;                              /**< SAI Receive Configuration 2 Register, offset: 0x88 */
  __IO uint32_t RCR3;                              /**< SAI Receive Configuration 3 Register, offset: 0x8C */
  __IO uint32_t RCR4;                              /**< SAI Receive Configuration 4 Register, offset: 0x90 */
  __IO uint32_t RCR5;                              /**< SAI Receive Configuration 5 Register, offset: 0x94 */
       uint8_t RESERVED_4[8];
  __I  uint32_t RDR[1];                            /**< SAI Receive Data Register, array offset: 0xA0, array step: 0x4 */
       uint8_t RESERVED_5[28];
  __I  uint32_t RFR[1];                            /**< SAI Receive FIFO Register, array offset: 0xC0, array step: 0x4 */
       uint8_t RESERVED_6[28];
  __IO uint32_t RMR;                               /**< SAI Receive Mask Register, offset: 0xE0 */
} I2S_Type;

/* ----------------------------------------------------------------------------
   -- I2S Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2S_Register_Masks I2S Register Masks
 * @{
 */

/*! @name TCSR - SAI Transmit Control Register */
/*! @{ */
#define I2S_TCSR_FRDE_MASK                       (0x1U)
#define I2S_TCSR_FRDE_SHIFT                      (0U)
/*! FRDE - FIFO Request DMA Enable
 *  0b0..Disables the DMA request.
 *  0b1..Enables the DMA request.
 */
#define I2S_TCSR_FRDE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FRDE_SHIFT)) & I2S_TCSR_FRDE_MASK)
#define I2S_TCSR_FWDE_MASK                       (0x2U)
#define I2S_TCSR_FWDE_SHIFT                      (1U)
/*! FWDE - FIFO Warning DMA Enable
 *  0b0..Disables the DMA request.
 *  0b1..Enables the DMA request.
 */
#define I2S_TCSR_FWDE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FWDE_SHIFT)) & I2S_TCSR_FWDE_MASK)
#define I2S_TCSR_FRIE_MASK                       (0x100U)
#define I2S_TCSR_FRIE_SHIFT                      (8U)
/*! FRIE - FIFO Request Interrupt Enable
 *  0b0..Disables the interrupt.
 *  0b1..Enables the interrupt.
 */
#define I2S_TCSR_FRIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FRIE_SHIFT)) & I2S_TCSR_FRIE_MASK)
#define I2S_TCSR_FWIE_MASK                       (0x200U)
#define I2S_TCSR_FWIE_SHIFT                      (9U)
/*! FWIE - FIFO Warning Interrupt Enable
 *  0b0..Disables the interrupt.
 *  0b1..Enables the interrupt.
 */
#define I2S_TCSR_FWIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FWIE_SHIFT)) & I2S_TCSR_FWIE_MASK)
#define I2S_TCSR_FEIE_MASK                       (0x400U)
#define I2S_TCSR_FEIE_SHIFT                      (10U)
/*! FEIE - FIFO Error Interrupt Enable
 *  0b0..Disables the interrupt.
 *  0b1..Enables the interrupt.
 */
#define I2S_TCSR_FEIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FEIE_SHIFT)) & I2S_TCSR_FEIE_MASK)
#define I2S_TCSR_SEIE_MASK                       (0x800U)
#define I2S_TCSR_SEIE_SHIFT                      (11U)
/*! SEIE - Sync Error Interrupt Enable
 *  0b0..Disables interrupt.
 *  0b1..Enables interrupt.
 */
#define I2S_TCSR_SEIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_SEIE_SHIFT)) & I2S_TCSR_SEIE_MASK)
#define I2S_TCSR_WSIE_MASK                       (0x1000U)
#define I2S_TCSR_WSIE_SHIFT                      (12U)
/*! WSIE - Word Start Interrupt Enable
 *  0b0..Disables interrupt.
 *  0b1..Enables interrupt.
 */
#define I2S_TCSR_WSIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_WSIE_SHIFT)) & I2S_TCSR_WSIE_MASK)
#define I2S_TCSR_FRF_MASK                        (0x10000U)
#define I2S_TCSR_FRF_SHIFT                       (16U)
/*! FRF - FIFO Request Flag
 *  0b0..Transmit FIFO watermark has not been reached.
 *  0b1..Transmit FIFO watermark has been reached.
 */
#define I2S_TCSR_FRF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FRF_SHIFT)) & I2S_TCSR_FRF_MASK)
#define I2S_TCSR_FWF_MASK                        (0x20000U)
#define I2S_TCSR_FWF_SHIFT                       (17U)
/*! FWF - FIFO Warning Flag
 *  0b0..No enabled transmit FIFO is empty.
 *  0b1..Enabled transmit FIFO is empty.
 */
#define I2S_TCSR_FWF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FWF_SHIFT)) & I2S_TCSR_FWF_MASK)
#define I2S_TCSR_FEF_MASK                        (0x40000U)
#define I2S_TCSR_FEF_SHIFT                       (18U)
/*! FEF - FIFO Error Flag
 *  0b0..Transmit underrun not detected.
 *  0b1..Transmit underrun detected.
 */
#define I2S_TCSR_FEF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FEF_SHIFT)) & I2S_TCSR_FEF_MASK)
#define I2S_TCSR_SEF_MASK                        (0x80000U)
#define I2S_TCSR_SEF_SHIFT                       (19U)
/*! SEF - Sync Error Flag
 *  0b0..Sync error not detected.
 *  0b1..Frame sync error detected.
 */
#define I2S_TCSR_SEF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_SEF_SHIFT)) & I2S_TCSR_SEF_MASK)
#define I2S_TCSR_WSF_MASK                        (0x100000U)
#define I2S_TCSR_WSF_SHIFT                       (20U)
/*! WSF - Word Start Flag
 *  0b0..Start of word not detected.
 *  0b1..Start of word detected.
 */
#define I2S_TCSR_WSF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_WSF_SHIFT)) & I2S_TCSR_WSF_MASK)
#define I2S_TCSR_SR_MASK                         (0x1000000U)
#define I2S_TCSR_SR_SHIFT                        (24U)
/*! SR - Software Reset
 *  0b0..No effect.
 *  0b1..Software reset.
 */
#define I2S_TCSR_SR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_SR_SHIFT)) & I2S_TCSR_SR_MASK)
#define I2S_TCSR_FR_MASK                         (0x2000000U)
#define I2S_TCSR_FR_SHIFT                        (25U)
/*! FR - FIFO Reset
 *  0b0..No effect.
 *  0b1..FIFO reset.
 */
#define I2S_TCSR_FR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_FR_SHIFT)) & I2S_TCSR_FR_MASK)
#define I2S_TCSR_BCE_MASK                        (0x10000000U)
#define I2S_TCSR_BCE_SHIFT                       (28U)
/*! BCE - Bit Clock Enable
 *  0b0..Transmit bit clock is disabled.
 *  0b1..Transmit bit clock is enabled.
 */
#define I2S_TCSR_BCE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_BCE_SHIFT)) & I2S_TCSR_BCE_MASK)
#define I2S_TCSR_DBGE_MASK                       (0x20000000U)
#define I2S_TCSR_DBGE_SHIFT                      (29U)
/*! DBGE - Debug Enable
 *  0b0..Transmitter is disabled in Debug mode, after completing the current frame.
 *  0b1..Transmitter is enabled in Debug mode.
 */
#define I2S_TCSR_DBGE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_DBGE_SHIFT)) & I2S_TCSR_DBGE_MASK)
#define I2S_TCSR_STOPE_MASK                      (0x40000000U)
#define I2S_TCSR_STOPE_SHIFT                     (30U)
/*! STOPE - Stop Enable
 *  0b0..Transmitter disabled in Stop mode.
 *  0b1..Transmitter enabled in Stop mode.
 */
#define I2S_TCSR_STOPE(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_STOPE_SHIFT)) & I2S_TCSR_STOPE_MASK)
#define I2S_TCSR_TE_MASK                         (0x80000000U)
#define I2S_TCSR_TE_SHIFT                        (31U)
/*! TE - Transmitter Enable
 *  0b0..Transmitter is disabled.
 *  0b1..Transmitter is enabled, or transmitter has been disabled and has not yet reached end of frame.
 */
#define I2S_TCSR_TE(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TCSR_TE_SHIFT)) & I2S_TCSR_TE_MASK)
/*! @} */

/*! @name TCR1 - SAI Transmit Configuration 1 Register */
/*! @{ */
#define I2S_TCR1_TFW_MASK                        (0x3FU)
#define I2S_TCR1_TFW_SHIFT                       (0U)
/*! TFW - Transmit FIFO Watermark
 */
#define I2S_TCR1_TFW(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR1_TFW_SHIFT)) & I2S_TCR1_TFW_MASK)
/*! @} */

/*! @name TCR2 - SAI Transmit Configuration 2 Register */
/*! @{ */
#define I2S_TCR2_DIV_MASK                        (0xFFU)
#define I2S_TCR2_DIV_SHIFT                       (0U)
/*! DIV - Bit Clock Divide
 */
#define I2S_TCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_DIV_SHIFT)) & I2S_TCR2_DIV_MASK)
#define I2S_TCR2_BCD_MASK                        (0x1000000U)
#define I2S_TCR2_BCD_SHIFT                       (24U)
/*! BCD - Bit Clock Direction
 *  0b0..Bit clock is generated externally in Slave mode.
 *  0b1..Bit clock is generated internally in Master mode.
 */
#define I2S_TCR2_BCD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BCD_SHIFT)) & I2S_TCR2_BCD_MASK)
#define I2S_TCR2_BCP_MASK                        (0x2000000U)
#define I2S_TCR2_BCP_SHIFT                       (25U)
/*! BCP - Bit Clock Polarity
 *  0b0..Bit clock is active high with drive outputs on rising edge and sample inputs on falling edge.
 *  0b1..Bit clock is active low with drive outputs on falling edge and sample inputs on rising edge.
 */
#define I2S_TCR2_BCP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BCP_SHIFT)) & I2S_TCR2_BCP_MASK)
#define I2S_TCR2_MSEL_MASK                       (0xC000000U)
#define I2S_TCR2_MSEL_SHIFT                      (26U)
/*! MSEL - MCLK Select
 *  0b00..Bus Clock selected.
 *  0b01..Master Clock (MCLK) 1 option selected.
 *  0b10..Master Clock (MCLK) 2 option selected.
 *  0b11..Master Clock (MCLK) 3 option selected.
 */
#define I2S_TCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_MSEL_SHIFT)) & I2S_TCR2_MSEL_MASK)
#define I2S_TCR2_BCI_MASK                        (0x10000000U)
#define I2S_TCR2_BCI_SHIFT                       (28U)
/*! BCI - Bit Clock Input
 *  0b0..No effect.
 *  0b1..Internal logic is clocked as if bit clock was externally generated.
 */
#define I2S_TCR2_BCI(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BCI_SHIFT)) & I2S_TCR2_BCI_MASK)
#define I2S_TCR2_BCS_MASK                        (0x20000000U)
#define I2S_TCR2_BCS_SHIFT                       (29U)
/*! BCS - Bit Clock Swap
 *  0b0..Use the normal bit clock source.
 *  0b1..Swap the bit clock source.
 */
#define I2S_TCR2_BCS(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_BCS_SHIFT)) & I2S_TCR2_BCS_MASK)
#define I2S_TCR2_SYNC_MASK                       (0xC0000000U)
#define I2S_TCR2_SYNC_SHIFT                      (30U)
/*! SYNC - Synchronous Mode
 *  0b00..Asynchronous mode.
 *  0b01..Synchronous with receiver.
 *  0b10..Synchronous with another SAI transmitter.
 *  0b11..Synchronous with another SAI receiver.
 */
#define I2S_TCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR2_SYNC_SHIFT)) & I2S_TCR2_SYNC_MASK)
/*! @} */

/*! @name TCR3 - SAI Transmit Configuration 3 Register */
/*! @{ */
#define I2S_TCR3_WDFL_MASK                       (0x1FU)  /* Merged from fields with different position or width, of widths (3, 5), largest definition used */
#define I2S_TCR3_WDFL_SHIFT                      (0U)
/*! WDFL - Word Flag Configuration
 */
#define I2S_TCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR3_WDFL_SHIFT)) & I2S_TCR3_WDFL_MASK)  /* Merged from fields with different position or width, of widths (3, 5), largest definition used */
#define I2S_TCR3_TCE_MASK                        (0x10000U)
#define I2S_TCR3_TCE_SHIFT                       (16U)
/*! TCE - Transmit Channel Enable
 */
#define I2S_TCR3_TCE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR3_TCE_SHIFT)) & I2S_TCR3_TCE_MASK)
/*! @} */

/*! @name TCR4 - SAI Transmit Configuration 4 Register */
/*! @{ */
#define I2S_TCR4_FSD_MASK                        (0x1U)
#define I2S_TCR4_FSD_SHIFT                       (0U)
/*! FSD - Frame Sync Direction
 *  0b0..Frame sync is generated externally in Slave mode.
 *  0b1..Frame sync is generated internally in Master mode.
 */
#define I2S_TCR4_FSD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FSD_SHIFT)) & I2S_TCR4_FSD_MASK)
#define I2S_TCR4_FSP_MASK                        (0x2U)
#define I2S_TCR4_FSP_SHIFT                       (1U)
/*! FSP - Frame Sync Polarity
 *  0b0..Frame sync is active high.
 *  0b1..Frame sync is active low.
 */
#define I2S_TCR4_FSP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FSP_SHIFT)) & I2S_TCR4_FSP_MASK)
#define I2S_TCR4_ONDEM_MASK                      (0x4U)
#define I2S_TCR4_ONDEM_SHIFT                     (2U)
/*! ONDEM - On Demand Mode
 *  0b0..Internal frame sync is generated continuously.
 *  0b1..Internal frame sync is generated when the FIFO warning flag is clear.
 */
#define I2S_TCR4_ONDEM(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_ONDEM_SHIFT)) & I2S_TCR4_ONDEM_MASK)
#define I2S_TCR4_FSE_MASK                        (0x8U)
#define I2S_TCR4_FSE_SHIFT                       (3U)
/*! FSE - Frame Sync Early
 *  0b0..Frame sync asserts with the first bit of the frame.
 *  0b1..Frame sync asserts one bit before the first bit of the frame.
 */
#define I2S_TCR4_FSE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FSE_SHIFT)) & I2S_TCR4_FSE_MASK)
#define I2S_TCR4_MF_MASK                         (0x10U)
#define I2S_TCR4_MF_SHIFT                        (4U)
/*! MF - MSB First
 *  0b0..LSB is transmitted first.
 *  0b1..MSB is transmitted first.
 */
#define I2S_TCR4_MF(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_MF_SHIFT)) & I2S_TCR4_MF_MASK)
#define I2S_TCR4_SYWD_MASK                       (0x1F00U)
#define I2S_TCR4_SYWD_SHIFT                      (8U)
/*! SYWD - Sync Width
 */
#define I2S_TCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_SYWD_SHIFT)) & I2S_TCR4_SYWD_MASK)
#define I2S_TCR4_FRSZ_MASK                       (0x1F0000U)  /* Merged from fields with different position or width, of widths (3, 5), largest definition used */
#define I2S_TCR4_FRSZ_SHIFT                      (16U)
/*! FRSZ - Frame size
 */
#define I2S_TCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FRSZ_SHIFT)) & I2S_TCR4_FRSZ_MASK)  /* Merged from fields with different position or width, of widths (3, 5), largest definition used */
#define I2S_TCR4_FPACK_MASK                      (0x3000000U)
#define I2S_TCR4_FPACK_SHIFT                     (24U)
/*! FPACK - FIFO Packing Mode
 *  0b00..FIFO packing is disabled
 *  0b01..Reserved
 *  0b10..8-bit FIFO packing is enabled
 *  0b11..16-bit FIFO packing is enabled
 */
#define I2S_TCR4_FPACK(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FPACK_SHIFT)) & I2S_TCR4_FPACK_MASK)
#define I2S_TCR4_FCONT_MASK                      (0x10000000U)
#define I2S_TCR4_FCONT_SHIFT                     (28U)
/*! FCONT - FIFO Continue on Error
 *  0b0..On FIFO error, the SAI will continue from the start of the next frame after the FIFO error flag has been cleared.
 *  0b1..On FIFO error, the SAI will continue from the same word that caused the FIFO error to set after the FIFO warning flag has been cleared.
 */
#define I2S_TCR4_FCONT(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_TCR4_FCONT_SHIFT)) & I2S_TCR4_FCONT_MASK)
/*! @} */

/*! @name TCR5 - SAI Transmit Configuration 5 Register */
/*! @{ */
#define I2S_TCR5_FBT_MASK                        (0x1F00U)
#define I2S_TCR5_FBT_SHIFT                       (8U)
/*! FBT - First Bit Shifted
 */
#define I2S_TCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR5_FBT_SHIFT)) & I2S_TCR5_FBT_MASK)
#define I2S_TCR5_W0W_MASK                        (0x1F0000U)
#define I2S_TCR5_W0W_SHIFT                       (16U)
/*! W0W - Word 0 Width
 */
#define I2S_TCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR5_W0W_SHIFT)) & I2S_TCR5_W0W_MASK)
#define I2S_TCR5_WNW_MASK                        (0x1F000000U)
#define I2S_TCR5_WNW_SHIFT                       (24U)
/*! WNW - Word N Width
 */
#define I2S_TCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_TCR5_WNW_SHIFT)) & I2S_TCR5_WNW_MASK)
/*! @} */

/*! @name TDR - SAI Transmit Data Register */
/*! @{ */
#define I2S_TDR_TDR_MASK                         (0xFFFFFFFFU)
#define I2S_TDR_TDR_SHIFT                        (0U)
/*! TDR - Transmit Data Register
 */
#define I2S_TDR_TDR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TDR_TDR_SHIFT)) & I2S_TDR_TDR_MASK)
/*! @} */

/* The count of I2S_TDR */
#define I2S_TDR_COUNT                            (1U)

/*! @name TFR - SAI Transmit FIFO Register */
/*! @{ */
#define I2S_TFR_RFP_MASK                         (0x7FU)
#define I2S_TFR_RFP_SHIFT                        (0U)
/*! RFP - Read FIFO Pointer
 */
#define I2S_TFR_RFP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TFR_RFP_SHIFT)) & I2S_TFR_RFP_MASK)
#define I2S_TFR_WFP_MASK                         (0x7F0000U)
#define I2S_TFR_WFP_SHIFT                        (16U)
/*! WFP - Write FIFO Pointer
 */
#define I2S_TFR_WFP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TFR_WFP_SHIFT)) & I2S_TFR_WFP_MASK)
/*! @} */

/* The count of I2S_TFR */
#define I2S_TFR_COUNT                            (1U)

/*! @name TMR - SAI Transmit Mask Register */
/*! @{ */
#define I2S_TMR_TWM_MASK                         (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (8, 32), largest definition used */
#define I2S_TMR_TWM_SHIFT                        (0U)
/*! TWM - Transmit Word Mask
 *  0b00000000000000000000000000000000..Word N is enabled.
 *  0b00000000000000000000000000000001..Word N is masked. The transmit data pins are tri-stated when masked.
 */
#define I2S_TMR_TWM(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_TMR_TWM_SHIFT)) & I2S_TMR_TWM_MASK)  /* Merged from fields with different position or width, of widths (8, 32), largest definition used */
/*! @} */

/*! @name RCSR - SAI Receive Control Register */
/*! @{ */
#define I2S_RCSR_FRDE_MASK                       (0x1U)
#define I2S_RCSR_FRDE_SHIFT                      (0U)
/*! FRDE - FIFO Request DMA Enable
 *  0b0..Disables the DMA request.
 *  0b1..Enables the DMA request.
 */
#define I2S_RCSR_FRDE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FRDE_SHIFT)) & I2S_RCSR_FRDE_MASK)
#define I2S_RCSR_FWDE_MASK                       (0x2U)
#define I2S_RCSR_FWDE_SHIFT                      (1U)
/*! FWDE - FIFO Warning DMA Enable
 *  0b0..Disables the DMA request.
 *  0b1..Enables the DMA request.
 */
#define I2S_RCSR_FWDE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FWDE_SHIFT)) & I2S_RCSR_FWDE_MASK)
#define I2S_RCSR_FRIE_MASK                       (0x100U)
#define I2S_RCSR_FRIE_SHIFT                      (8U)
/*! FRIE - FIFO Request Interrupt Enable
 *  0b0..Disables the interrupt.
 *  0b1..Enables the interrupt.
 */
#define I2S_RCSR_FRIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FRIE_SHIFT)) & I2S_RCSR_FRIE_MASK)
#define I2S_RCSR_FWIE_MASK                       (0x200U)
#define I2S_RCSR_FWIE_SHIFT                      (9U)
/*! FWIE - FIFO Warning Interrupt Enable
 *  0b0..Disables the interrupt.
 *  0b1..Enables the interrupt.
 */
#define I2S_RCSR_FWIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FWIE_SHIFT)) & I2S_RCSR_FWIE_MASK)
#define I2S_RCSR_FEIE_MASK                       (0x400U)
#define I2S_RCSR_FEIE_SHIFT                      (10U)
/*! FEIE - FIFO Error Interrupt Enable
 *  0b0..Disables the interrupt.
 *  0b1..Enables the interrupt.
 */
#define I2S_RCSR_FEIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FEIE_SHIFT)) & I2S_RCSR_FEIE_MASK)
#define I2S_RCSR_SEIE_MASK                       (0x800U)
#define I2S_RCSR_SEIE_SHIFT                      (11U)
/*! SEIE - Sync Error Interrupt Enable
 *  0b0..Disables interrupt.
 *  0b1..Enables interrupt.
 */
#define I2S_RCSR_SEIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_SEIE_SHIFT)) & I2S_RCSR_SEIE_MASK)
#define I2S_RCSR_WSIE_MASK                       (0x1000U)
#define I2S_RCSR_WSIE_SHIFT                      (12U)
/*! WSIE - Word Start Interrupt Enable
 *  0b0..Disables interrupt.
 *  0b1..Enables interrupt.
 */
#define I2S_RCSR_WSIE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_WSIE_SHIFT)) & I2S_RCSR_WSIE_MASK)
#define I2S_RCSR_FRF_MASK                        (0x10000U)
#define I2S_RCSR_FRF_SHIFT                       (16U)
/*! FRF - FIFO Request Flag
 *  0b0..Receive FIFO watermark not reached.
 *  0b1..Receive FIFO watermark has been reached.
 */
#define I2S_RCSR_FRF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FRF_SHIFT)) & I2S_RCSR_FRF_MASK)
#define I2S_RCSR_FWF_MASK                        (0x20000U)
#define I2S_RCSR_FWF_SHIFT                       (17U)
/*! FWF - FIFO Warning Flag
 *  0b0..No enabled receive FIFO is full.
 *  0b1..Enabled receive FIFO is full.
 */
#define I2S_RCSR_FWF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FWF_SHIFT)) & I2S_RCSR_FWF_MASK)
#define I2S_RCSR_FEF_MASK                        (0x40000U)
#define I2S_RCSR_FEF_SHIFT                       (18U)
/*! FEF - FIFO Error Flag
 *  0b0..Receive overflow not detected.
 *  0b1..Receive overflow detected.
 */
#define I2S_RCSR_FEF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FEF_SHIFT)) & I2S_RCSR_FEF_MASK)
#define I2S_RCSR_SEF_MASK                        (0x80000U)
#define I2S_RCSR_SEF_SHIFT                       (19U)
/*! SEF - Sync Error Flag
 *  0b0..Sync error not detected.
 *  0b1..Frame sync error detected.
 */
#define I2S_RCSR_SEF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_SEF_SHIFT)) & I2S_RCSR_SEF_MASK)
#define I2S_RCSR_WSF_MASK                        (0x100000U)
#define I2S_RCSR_WSF_SHIFT                       (20U)
/*! WSF - Word Start Flag
 *  0b0..Start of word not detected.
 *  0b1..Start of word detected.
 */
#define I2S_RCSR_WSF(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_WSF_SHIFT)) & I2S_RCSR_WSF_MASK)
#define I2S_RCSR_SR_MASK                         (0x1000000U)
#define I2S_RCSR_SR_SHIFT                        (24U)
/*! SR - Software Reset
 *  0b0..No effect.
 *  0b1..Software reset.
 */
#define I2S_RCSR_SR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_SR_SHIFT)) & I2S_RCSR_SR_MASK)
#define I2S_RCSR_FR_MASK                         (0x2000000U)
#define I2S_RCSR_FR_SHIFT                        (25U)
/*! FR - FIFO Reset
 *  0b0..No effect.
 *  0b1..FIFO reset.
 */
#define I2S_RCSR_FR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_FR_SHIFT)) & I2S_RCSR_FR_MASK)
#define I2S_RCSR_BCE_MASK                        (0x10000000U)
#define I2S_RCSR_BCE_SHIFT                       (28U)
/*! BCE - Bit Clock Enable
 *  0b0..Receive bit clock is disabled.
 *  0b1..Receive bit clock is enabled.
 */
#define I2S_RCSR_BCE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_BCE_SHIFT)) & I2S_RCSR_BCE_MASK)
#define I2S_RCSR_DBGE_MASK                       (0x20000000U)
#define I2S_RCSR_DBGE_SHIFT                      (29U)
/*! DBGE - Debug Enable
 *  0b0..Receiver is disabled in Debug mode, after completing the current frame.
 *  0b1..Receiver is enabled in Debug mode.
 */
#define I2S_RCSR_DBGE(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_DBGE_SHIFT)) & I2S_RCSR_DBGE_MASK)
#define I2S_RCSR_STOPE_MASK                      (0x40000000U)
#define I2S_RCSR_STOPE_SHIFT                     (30U)
/*! STOPE - Stop Enable
 *  0b0..Receiver disabled in Stop mode.
 *  0b1..Receiver enabled in Stop mode.
 */
#define I2S_RCSR_STOPE(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_STOPE_SHIFT)) & I2S_RCSR_STOPE_MASK)
#define I2S_RCSR_RE_MASK                         (0x80000000U)
#define I2S_RCSR_RE_SHIFT                        (31U)
/*! RE - Receiver Enable
 *  0b0..Receiver is disabled.
 *  0b1..Receiver is enabled, or receiver has been disabled and has not yet reached end of frame.
 */
#define I2S_RCSR_RE(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RCSR_RE_SHIFT)) & I2S_RCSR_RE_MASK)
/*! @} */

/*! @name RCR1 - SAI Receive Configuration 1 Register */
/*! @{ */
#define I2S_RCR1_RFW_MASK                        (0x3FU)
#define I2S_RCR1_RFW_SHIFT                       (0U)
/*! RFW - Receive FIFO Watermark
 */
#define I2S_RCR1_RFW(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR1_RFW_SHIFT)) & I2S_RCR1_RFW_MASK)
/*! @} */

/*! @name RCR2 - SAI Receive Configuration 2 Register */
/*! @{ */
#define I2S_RCR2_DIV_MASK                        (0xFFU)
#define I2S_RCR2_DIV_SHIFT                       (0U)
/*! DIV - Bit Clock Divide
 */
#define I2S_RCR2_DIV(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_DIV_SHIFT)) & I2S_RCR2_DIV_MASK)
#define I2S_RCR2_BCD_MASK                        (0x1000000U)
#define I2S_RCR2_BCD_SHIFT                       (24U)
/*! BCD - Bit Clock Direction
 *  0b0..Bit clock is generated externally in Slave mode.
 *  0b1..Bit clock is generated internally in Master mode.
 */
#define I2S_RCR2_BCD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BCD_SHIFT)) & I2S_RCR2_BCD_MASK)
#define I2S_RCR2_BCP_MASK                        (0x2000000U)
#define I2S_RCR2_BCP_SHIFT                       (25U)
/*! BCP - Bit Clock Polarity
 *  0b0..Bit Clock is active high with drive outputs on rising edge and sample inputs on falling edge.
 *  0b1..Bit Clock is active low with drive outputs on falling edge and sample inputs on rising edge.
 */
#define I2S_RCR2_BCP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BCP_SHIFT)) & I2S_RCR2_BCP_MASK)
#define I2S_RCR2_MSEL_MASK                       (0xC000000U)
#define I2S_RCR2_MSEL_SHIFT                      (26U)
/*! MSEL - MCLK Select
 *  0b00..Bus Clock selected.
 *  0b01..Master Clock (MCLK) 1 option selected.
 *  0b10..Master Clock (MCLK) 2 option selected.
 *  0b11..Master Clock (MCLK) 3 option selected.
 */
#define I2S_RCR2_MSEL(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_MSEL_SHIFT)) & I2S_RCR2_MSEL_MASK)
#define I2S_RCR2_BCI_MASK                        (0x10000000U)
#define I2S_RCR2_BCI_SHIFT                       (28U)
/*! BCI - Bit Clock Input
 *  0b0..No effect.
 *  0b1..Internal logic is clocked as if bit clock was externally generated.
 */
#define I2S_RCR2_BCI(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BCI_SHIFT)) & I2S_RCR2_BCI_MASK)
#define I2S_RCR2_BCS_MASK                        (0x20000000U)
#define I2S_RCR2_BCS_SHIFT                       (29U)
/*! BCS - Bit Clock Swap
 *  0b0..Use the normal bit clock source.
 *  0b1..Swap the bit clock source.
 */
#define I2S_RCR2_BCS(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_BCS_SHIFT)) & I2S_RCR2_BCS_MASK)
#define I2S_RCR2_SYNC_MASK                       (0xC0000000U)
#define I2S_RCR2_SYNC_SHIFT                      (30U)
/*! SYNC - Synchronous Mode
 *  0b00..Asynchronous mode.
 *  0b01..Synchronous with transmitter.
 *  0b10..Synchronous with another SAI receiver.
 *  0b11..Synchronous with another SAI transmitter.
 */
#define I2S_RCR2_SYNC(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR2_SYNC_SHIFT)) & I2S_RCR2_SYNC_MASK)
/*! @} */

/*! @name RCR3 - SAI Receive Configuration 3 Register */
/*! @{ */
#define I2S_RCR3_WDFL_MASK                       (0x1FU)  /* Merged from fields with different position or width, of widths (3, 5), largest definition used */
#define I2S_RCR3_WDFL_SHIFT                      (0U)
/*! WDFL - Word Flag Configuration
 */
#define I2S_RCR3_WDFL(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR3_WDFL_SHIFT)) & I2S_RCR3_WDFL_MASK)  /* Merged from fields with different position or width, of widths (3, 5), largest definition used */
#define I2S_RCR3_RCE_MASK                        (0x10000U)
#define I2S_RCR3_RCE_SHIFT                       (16U)
/*! RCE - Receive Channel Enable
 */
#define I2S_RCR3_RCE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR3_RCE_SHIFT)) & I2S_RCR3_RCE_MASK)
/*! @} */

/*! @name RCR4 - SAI Receive Configuration 4 Register */
/*! @{ */
#define I2S_RCR4_FSD_MASK                        (0x1U)
#define I2S_RCR4_FSD_SHIFT                       (0U)
/*! FSD - Frame Sync Direction
 *  0b0..Frame Sync is generated externally in Slave mode.
 *  0b1..Frame Sync is generated internally in Master mode.
 */
#define I2S_RCR4_FSD(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FSD_SHIFT)) & I2S_RCR4_FSD_MASK)
#define I2S_RCR4_FSP_MASK                        (0x2U)
#define I2S_RCR4_FSP_SHIFT                       (1U)
/*! FSP - Frame Sync Polarity
 *  0b0..Frame sync is active high.
 *  0b1..Frame sync is active low.
 */
#define I2S_RCR4_FSP(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FSP_SHIFT)) & I2S_RCR4_FSP_MASK)
#define I2S_RCR4_ONDEM_MASK                      (0x4U)
#define I2S_RCR4_ONDEM_SHIFT                     (2U)
/*! ONDEM - On Demand Mode
 *  0b0..Internal frame sync is generated continuously.
 *  0b1..Internal frame sync is generated when the FIFO warning flag is clear.
 */
#define I2S_RCR4_ONDEM(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_ONDEM_SHIFT)) & I2S_RCR4_ONDEM_MASK)
#define I2S_RCR4_FSE_MASK                        (0x8U)
#define I2S_RCR4_FSE_SHIFT                       (3U)
/*! FSE - Frame Sync Early
 *  0b0..Frame sync asserts with the first bit of the frame.
 *  0b1..Frame sync asserts one bit before the first bit of the frame.
 */
#define I2S_RCR4_FSE(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FSE_SHIFT)) & I2S_RCR4_FSE_MASK)
#define I2S_RCR4_MF_MASK                         (0x10U)
#define I2S_RCR4_MF_SHIFT                        (4U)
/*! MF - MSB First
 *  0b0..LSB is received first.
 *  0b1..MSB is received first.
 */
#define I2S_RCR4_MF(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_MF_SHIFT)) & I2S_RCR4_MF_MASK)
#define I2S_RCR4_SYWD_MASK                       (0x1F00U)
#define I2S_RCR4_SYWD_SHIFT                      (8U)
/*! SYWD - Sync Width
 */
#define I2S_RCR4_SYWD(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_SYWD_SHIFT)) & I2S_RCR4_SYWD_MASK)
#define I2S_RCR4_FRSZ_MASK                       (0x1F0000U)  /* Merged from fields with different position or width, of widths (3, 5), largest definition used */
#define I2S_RCR4_FRSZ_SHIFT                      (16U)
/*! FRSZ - Frame Size
 */
#define I2S_RCR4_FRSZ(x)                         (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FRSZ_SHIFT)) & I2S_RCR4_FRSZ_MASK)  /* Merged from fields with different position or width, of widths (3, 5), largest definition used */
#define I2S_RCR4_FPACK_MASK                      (0x3000000U)
#define I2S_RCR4_FPACK_SHIFT                     (24U)
/*! FPACK - FIFO Packing Mode
 *  0b00..FIFO packing is disabled
 *  0b01..Reserved.
 *  0b10..8-bit FIFO packing is enabled
 *  0b11..16-bit FIFO packing is enabled
 */
#define I2S_RCR4_FPACK(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FPACK_SHIFT)) & I2S_RCR4_FPACK_MASK)
#define I2S_RCR4_FCONT_MASK                      (0x10000000U)
#define I2S_RCR4_FCONT_SHIFT                     (28U)
/*! FCONT - FIFO Continue on Error
 *  0b0..On FIFO error, the SAI will continue from the start of the next frame after the FIFO error flag has been cleared.
 *  0b1..On FIFO error, the SAI will continue from the same word that caused the FIFO error to set after the FIFO warning flag has been cleared.
 */
#define I2S_RCR4_FCONT(x)                        (((uint32_t)(((uint32_t)(x)) << I2S_RCR4_FCONT_SHIFT)) & I2S_RCR4_FCONT_MASK)
/*! @} */

/*! @name RCR5 - SAI Receive Configuration 5 Register */
/*! @{ */
#define I2S_RCR5_FBT_MASK                        (0x1F00U)
#define I2S_RCR5_FBT_SHIFT                       (8U)
/*! FBT - First Bit Shifted
 */
#define I2S_RCR5_FBT(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR5_FBT_SHIFT)) & I2S_RCR5_FBT_MASK)
#define I2S_RCR5_W0W_MASK                        (0x1F0000U)
#define I2S_RCR5_W0W_SHIFT                       (16U)
/*! W0W - Word 0 Width
 */
#define I2S_RCR5_W0W(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR5_W0W_SHIFT)) & I2S_RCR5_W0W_MASK)
#define I2S_RCR5_WNW_MASK                        (0x1F000000U)
#define I2S_RCR5_WNW_SHIFT                       (24U)
/*! WNW - Word N Width
 */
#define I2S_RCR5_WNW(x)                          (((uint32_t)(((uint32_t)(x)) << I2S_RCR5_WNW_SHIFT)) & I2S_RCR5_WNW_MASK)
/*! @} */

/*! @name RDR - SAI Receive Data Register */
/*! @{ */
#define I2S_RDR_RDR_MASK                         (0xFFFFFFFFU)
#define I2S_RDR_RDR_SHIFT                        (0U)
/*! RDR - Receive Data Register
 */
#define I2S_RDR_RDR(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RDR_RDR_SHIFT)) & I2S_RDR_RDR_MASK)
/*! @} */

/* The count of I2S_RDR */
#define I2S_RDR_COUNT                            (1U)

/*! @name RFR - SAI Receive FIFO Register */
/*! @{ */
#define I2S_RFR_RFP_MASK                         (0x7FU)
#define I2S_RFR_RFP_SHIFT                        (0U)
/*! RFP - Read FIFO Pointer
 */
#define I2S_RFR_RFP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RFR_RFP_SHIFT)) & I2S_RFR_RFP_MASK)
#define I2S_RFR_WFP_MASK                         (0x7F0000U)
#define I2S_RFR_WFP_SHIFT                        (16U)
/*! WFP - Write FIFO Pointer
 */
#define I2S_RFR_WFP(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RFR_WFP_SHIFT)) & I2S_RFR_WFP_MASK)
/*! @} */

/* The count of I2S_RFR */
#define I2S_RFR_COUNT                            (1U)

/*! @name RMR - SAI Receive Mask Register */
/*! @{ */
#define I2S_RMR_RWM_MASK                         (0xFFFFFFFFU)  /* Merged from fields with different position or width, of widths (8, 32), largest definition used */
#define I2S_RMR_RWM_SHIFT                        (0U)
/*! RWM - Receive Word Mask
 *  0b00000000000000000000000000000000..Word N is enabled.
 *  0b00000000000000000000000000000001..Word N is masked.
 */
#define I2S_RMR_RWM(x)                           (((uint32_t)(((uint32_t)(x)) << I2S_RMR_RWM_SHIFT)) & I2S_RMR_RWM_MASK)  /* Merged from fields with different position or width, of widths (8, 32), largest definition used */
/*! @} */


/*!
 * @}
 */ /* end of group I2S_Register_Masks */


/* I2S - Peripheral instance base addresses */
/** Peripheral ADMA__SAI0 base address */
#define ADMA__SAI0_BASE                          (0x59040000u)
/** Peripheral ADMA__SAI0 base pointer */
#define ADMA__SAI0                               ((I2S_Type *)ADMA__SAI0_BASE)
/** Peripheral ADMA__SAI1 base address */
#define ADMA__SAI1_BASE                          (0x59050000u)
/** Peripheral ADMA__SAI1 base pointer */
#define ADMA__SAI1                               ((I2S_Type *)ADMA__SAI1_BASE)
/** Peripheral ADMA__SAI2 base address */
#define ADMA__SAI2_BASE                          (0x59060000u)
/** Peripheral ADMA__SAI2 base pointer */
#define ADMA__SAI2                               ((I2S_Type *)ADMA__SAI2_BASE)
/** Peripheral ADMA__SAI3 base address */
#define ADMA__SAI3_BASE                          (0x59070000u)
/** Peripheral ADMA__SAI3 base pointer */
#define ADMA__SAI3                               ((I2S_Type *)ADMA__SAI3_BASE)
/** Peripheral ADMA__SAI4 base address */
#define ADMA__SAI4_BASE                          (0x59820000u)
/** Peripheral ADMA__SAI4 base pointer */
#define ADMA__SAI4                               ((I2S_Type *)ADMA__SAI4_BASE)
/** Peripheral ADMA__SAI5 base address */
#define ADMA__SAI5_BASE                          (0x59830000u)
/** Peripheral ADMA__SAI5 base pointer */
#define ADMA__SAI5                               ((I2S_Type *)ADMA__SAI5_BASE)
/** Array initializer of I2S peripheral base addresses */
#define I2S_BASE_ADDRS                           { ADMA__SAI0_BASE, ADMA__SAI1_BASE, ADMA__SAI2_BASE, ADMA__SAI3_BASE, ADMA__SAI4_BASE, ADMA__SAI5_BASE }
/** Array initializer of I2S peripheral base pointers */
#define I2S_BASE_PTRS                            { ADMA__SAI0, ADMA__SAI1, ADMA__SAI2, ADMA__SAI3, ADMA__SAI4, ADMA__SAI5 }
/** Interrupt vectors for the I2S peripheral type */
#define I2S_RX_IRQS                              { ADMA_SAI0_INT_IRQn, ADMA_SAI1_INT_IRQn, ADMA_SAI2_INT_IRQn, ADMA_SAI3_INT_IRQn, ADMA_SAI4_INT_IRQn, ADMA_SAI5_INT_IRQn }
#define I2S_TX_IRQS                              { ADMA_SAI0_INT_IRQn, ADMA_SAI1_INT_IRQn, ADMA_SAI2_INT_IRQn, ADMA_SAI3_INT_IRQn, ADMA_SAI4_INT_IRQn, ADMA_SAI5_INT_IRQn }

/*!
 * @}
 */ /* end of group I2S_Peripheral_Access_Layer */
#endif  /* _MIMX8QX6_CM4_H_ */