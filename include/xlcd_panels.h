/*
 * LCD Panel Database
 *
 * (C) Copyright 2012
 * Hartmut Keller, F&S Elektronik Systeme GmbH, keller@fs-net.de
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef _XLCD_PANELS_H_
#define _XLCD_PANELS_H_

/************************************************************************/
/* DEFINITIONS								*/
/************************************************************************/

/* Maximum length of a panel name */
#define MAX_NAME 32

/* Values for type entry of vidinfo_t; if TFT is set, all other bits must be
   zero. Therefore the range of this value is 0..8 */
#define VI_TYPE_SINGLESCAN 0x00		  /* Bit 0: single or dual scan */
#define VI_TYPE_DUALSCAN   0x01
#define VI_TYPE_4BITBUS    0x00		  /* Bit 1: 4-bit or 8-bit buswidth */
#define VI_TYPE_8BITBUS    0x02
#define VI_TYPE_STN        0x00		  /* Bit 2: STN or CSTN */
#define VI_TYPE_CSTN       0x04
#define VI_TYPE_STN_CSTN   0x00		  /* Bit 3: (C)STN or TFT */
#define VI_TYPE_TFT        0x08

/* Signal polaritiy */
#define HS_HIGH     (0<<0)		  /* HSYNC active high */
#define HS_LOW      (1<<0)		  /* HSYNC active low */
#define VS_HIGH     (0<<1)		  /* VSYNC active high */
#define VS_LOW      (1<<1)		  /* VSYNC active low */
#define DEN_HIGH    (0<<2)		  /* Data Enable active high */
#define DEN_LOW     (1<<2)		  /* Data Enable active low */
#define CLK_RISING  (0<<3)		  /* Take data with rising edge */
#define CLK_FALLING (1<<3)		  /* Take data with falling edge */

/* Number of power-on/power-off sequence values */
#define POW_COUNT 5

/* Power-on sequence indexes */
#define PON_LOGIC 0			  /* Display logic power (VLCD) */
#define PON_DISP  1			  /* Display Enable (DEN) */
#define PON_CONTR 2			  /* Controller and signal buffers */
#define PON_PWM   3			  /* PWM (backlight brightness) */
#define PON_BL    4			  /* Backlight power (VCFL) */

/* Power-off sequence indexes */
#define POFF_BL    0			  /* Backlight power (VCFL) */
#define POFF_PWM   1			  /* PWM (backlight brightness) */
#define POFF_CONTR 2			  /* Controller and signal buffers */
#define POFF_DISP  3			  /* Display Enable (DEN) */
#define POFF_LOGIC 4			  /* Display logic power (VLCD) */


/************************************************************************/
/* TYPES AND STRUCTURES							*/
/************************************************************************/

/* Common LCD panel information */
typedef struct lcdinfo {
	/* Resolution */
	u_short	hres;		/* Horizontal pixel resolution (i.e. 640) */
	u_short	vres;		/* Vertical pixel resolution (i.e. 480) */

	/* Horizontal timing */
	u_short	hfp;		/* Front porch (between data and HSYNC) */
	u_short hsw;		/* Horizontal sync pulse (HSYNC) width */
	u_short hbp;		/* Back porch (between HSYNC and data) */

	/* Vertical timing */
	u_short vfp;		/* Front porch (between data and VSYNC) */
	u_short	vsw;		/* Vertical sync pulse (VSYNC) width */
	u_short vbp;		/* Back porch (between VSYNC and data) */

	/* Signal polarity */
	u_char  pol;	        /* HSYNC, VSYNC, DEN and CLK polarity */

	/* Display type */
	u_char  type;		/* Bit 0: 0: 4-bit bus, 1: 8-bit bus
				   Bit 1: 0: single-scan, 1: dual-scan
				   Bit 2: 0: STN, 1: CSTN
				   Bit 3: 0: (C)STN, 1: TFT */

	/* Frequency */
	u_short fps;		/* Frame rate (in frames per second) */
	u_int   clk;		/* Pixel clock (in Hz) */

	/* Backlight settings */
	u_int   pwmfreq;	/* PWM frequency */
	u_short pwmvalue;	/* PWM value (voltage, 0=0V, 4096=3.3V) */

	/* Power-on and power-off timings (absolute delays in ms) */
	u_short ponseq[5];	/* Power-on delays */
	u_short poffseq[5];	/* Power-off delays */

	/* General info */
	u_short	hdim;		/* Width of display area in millimeters */
	u_short	vdim;		/* Height of display area in millimeters */
	char    name[MAX_NAME];	/* Manufacturer, display and resolution */
} lcdinfo_t;


/************************************************************************/
/* PROTOTYPES OF EXPORTED FUNCTIONS					*/
/************************************************************************/

/* Find predefined lcd panel by index (NULL on bad index) */
extern const lcdinfo_t *lcd_get_lcdinfo_p(u_int index);

/* Return index of next panel matching string s (or 0 if no match); start
   search at given index */
extern u_int lcd_search_lcd(char *s, u_int index);


#endif /*!_XLCD_PANELS_H_*/
