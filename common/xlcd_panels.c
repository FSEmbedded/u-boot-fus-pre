/*
 * LCD Panel Database
 *
 * (C) Copyright 2012
 * Hartmut Keller, F&S Elektronik Systeme GmbH, keller@fs-net.de
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <config.h>
#include <common.h>
#include <xlcd_panels.h>		  /* Own interface */

/************************************************************************/
/* LCD Panel Database 							*/
/************************************************************************/
const lcdinfo_t lcdlist[] = {
	{				  /* Panel 0 */
		name: "(no display)",	  /* Name and type */
		type:		VI_TYPE_TFT,
		hdim:		0,
		vdim:		0,
		hres:		0,	  /* Resolution */
		vres:		0,
		hfp:		24,	  /* Signal timing and polarity */
		hsw:		96,
		hbp:		40,
		vfp:		10,
		vsw:		2,
		vbp:		33,
		pol:		HS_LOW | VS_LOW | DEN_HIGH | CLK_RISING,
		fps:		60,	  /* Frame rate or pixel clock */
		clk:		0,
		pwmvalue:	0,	  /* PWM/Backlight setting */
		pwmfreq:	1000,
		ponseq:		{0, 40, 60, 80, 80}, /* Power-on sequence */
		poffseq:	{0, 0, 10, 40, 50},  /* Power-off sequence */
	},
	{				  /* Panel 1 */
		name: "LG.Philips LB064V02", /* Name and type */
		type:		VI_TYPE_TFT,
		hdim:		132,
		vdim:		98,
		hres:		640,	  /* Resolution */
		vres:		480,
		hfp:		24,	  /* Signal timing and polarity */
		hsw:		96,
		hbp:		40,
		vfp:		10,
		vsw:		2,
		vbp:		33,
		pol:		HS_LOW | VS_LOW | DEN_HIGH | CLK_RISING,
		fps:		60,	  /* Frame rate or pixel clock */
		clk:		0,
		pwmvalue:	0,	  /* PWM/Backlight setting */
		pwmfreq:	1000,
		ponseq:		{0, 40, 60, 80, 80}, /* Power-on sequence */
		poffseq:	{0, 0, 10, 40, 50},  /* Power-off sequence */
	},
	{				  /* Panel 1 */
		name: "Ampire AM320240LTNQW",	  /* Name and type */
		type:		VI_TYPE_TFT,
		hdim:		70,
		vdim:		53,
		hres:		320,	  /* Resolution */
		vres:		240,
		hfp:		20,	  /* Signal timing and polarity */
		hsw:		30,
		hbp:		38,
		vfp:		5,
		vsw:		3,
		vbp:		15,
		pol:		HS_LOW | VS_LOW | DEN_HIGH | CLK_RISING,
		fps:		60,	  /* Frame rate or pixel clock */
		clk:		0,
		pwmvalue:	0,	  /* PWM/Backlight setting */
		pwmfreq:	1000,
	},
	{				  /* Panel ? */
		name: "Ampire AM320240N1TMQW",	  /* Name and type */
		type:		VI_TYPE_TFT,
		hdim:		115,
		vdim:		86,
		hres:		320,	  /* Resolution */
		vres:		241,
		hfp:		20,	  /* Signal timing and polarity */
		hsw:		30,
		hbp:		38,
		vfp:		5,
		vsw:		3,
		vbp:		15,
		pol:		HS_LOW | VS_LOW | DEN_HIGH | CLK_RISING,
		fps:		60,	  /* Frame rate or pixel clock */
		clk:		0,
		pwmvalue:	0,	  /* PWM/Backlight setting */
		pwmfreq:	1000,
	},
	{				  /* Panel ? */
		name: "Ampire AM640480GHTNQW",	  /* Name and type */
		type:		VI_TYPE_TFT,
		hdim:		115,
		vdim:		86,
		hres:		640,	  /* Resolution */
		vres:		480,
		hfp:		16,	  /* Signal timing and polarity */
		hsw:		30,
		hbp:		114,
		vfp:		7,
		vsw:		3,
		vbp:		35,
		pol:		HS_LOW | VS_LOW | DEN_HIGH | CLK_RISING,
		fps:		60,	  /* Frame rate or pixel clock */
		clk:		0,
		pwmvalue:	0,	  /* PWM/Backlight setting */
		pwmfreq:	1000,
	},
	{				  /* Panel ? */
		name: "Ampire AM800480E2TMQW",	  /* Name and type */
		type:		VI_TYPE_TFT,
		hdim:		152,
		vdim:		91,
		hres:		800,	  /* Resolution */
		vres:		480,
		hfp:		40,	  /* Signal timing and polarity */
		hsw:		48,
		hbp:		40,
		vfp:		13,
		vsw:		3,
		vbp:		29,
		pol:		HS_LOW | VS_LOW | DEN_HIGH | CLK_FALLING,
		fps:		60,	  /* Frame rate or pixel clock */
		clk:		0,
		pwmvalue:	0,	  /* PWM/Backlight setting */
		pwmfreq:	1000,
	},
	{				  /* Panel ? */
		name: "EDT ET035009DH6",  /* Name and type */
		type:		VI_TYPE_TFT,
		hdim:		70,
		vdim:		53,
		hres:		320,	  /* Resolution */
		vres:		240,
		hfp:		20,	  /* Signal timing and polarity */
		hsw:		30,
		hbp:		38,
		vfp:		4,
		vsw:		2,
		vbp:		16,
		pol:		HS_LOW | VS_LOW | DEN_LOW | CLK_RISING,
		fps:		60,	  /* Frame rate or pixel clock */
		clk:		0,
		pwmvalue:	0,	  /* PWM/Backlight setting */
		pwmfreq:	1000,
	},
	{				  /* Panel ? */
		name: "EDT ET035080DH6",  /* Name and type */
		type:		VI_TYPE_TFT,
		hdim:		70,
		vdim:		53,
		hres:		320,	  /* Resolution */
		vres:		240,
		hfp:		20,	  /* Signal timing and polarity */
		hsw:		30,
		hbp:		38,
		vfp:		4,
		vsw:		2,
		vbp:		16,
		pol:		HS_LOW | VS_LOW | DEN_HIGH | CLK_RISING,
		fps:		60,	  /* Frame rate or pixel clock */
		clk:		0,
		pwmvalue:	0,	  /* PWM/Backlight setting */
		pwmfreq:	1000,
	},
	{				  /* Panel ? */
		name: "EDT ET043000DH6",  /* Name and type */
		type:		VI_TYPE_TFT,
		hdim:		95,
		vdim:		54,
		hres:		480,	  /* Resolution */
		vres:		272,
		hfp:		2,	  /* Signal timing and polarity */
		hsw:		41,
		hbp:		2,
		vfp:		2,
		vsw:		10,
		vbp:		2,
		pol:		HS_LOW | VS_LOW | DEN_HIGH | CLK_FALLING,
		fps:		60,	  /* Frame rate or pixel clock */
		clk:		0,
		pwmvalue:	0,	  /* PWM/Backlight setting */
		pwmfreq:	1000,
	},
	{				  /* Panel ? */
		name: "EDT ET050080DH6",  /* Name and type */
		type:		VI_TYPE_TFT,
		hdim:		109,
		vdim:		65,
		hres:		800,	  /* Resolution */
		vres:		480,
		hfp:		40,	  /* Signal timing and polarity */
		hsw:		128,
		hbp:		88,
		vfp:		10,
		vsw:		2,
		vbp:		33,
		pol:		HS_LOW | VS_LOW | DEN_HIGH | CLK_RISING,
		fps:		60,	  /* Frame rate or pixel clock */
		clk:		0,
		pwmvalue:	0,	  /* PWM/Backlight setting */
		pwmfreq:	1000,
	},
	{				  /* Panel ? */
		name: "EDT ET057080DH6",  /* Name and type */
		type:		VI_TYPE_TFT,
		hdim:		115,
		vdim:		86,
		hres:		320,	  /* Resolution */
		vres:		240,
		hfp:		20,	  /* Signal timing and polarity */
		hsw:		30,
		hbp:		38,
		vfp:		5,
		vsw:		3,
		vbp:		15,
		pol:		HS_LOW | VS_LOW | DEN_LOW | CLK_RISING,
		fps:		60,	  /* Frame rate or pixel clock */
		clk:		0,
		pwmvalue:	0,	  /* PWM/Backlight setting */
		pwmfreq:	1000,
	},
	{				  /* Panel ? */
		name: "EDT ET057090DHU",  /* Name and type */
		type:		VI_TYPE_TFT,
		hdim:		115,
		vdim:		86,
		hres:		640,	  /* Resolution */
		vres:		480,
		hfp:		16,	  /* Signal timing and polarity */
		hsw:		30,
		hbp:		114,
		vfp:		10,
		vsw:		3,
		vbp:		32,
		pol:		HS_LOW | VS_LOW | DEN_LOW | CLK_RISING,
		fps:		60,	  /* Frame rate or pixel clock */
		clk:		0,
		pwmvalue:	0,	  /* PWM/Backlight setting */
		pwmfreq:	1000,
	},
	{				  /* Panel ? */
		name: "EDT ET070080DH6",  /* Name and type */
		type:		VI_TYPE_TFT,
		hdim:		152,
		vdim:		91,
		hres:		800,	  /* Resolution */
		vres:		480,
		hfp:		40,	  /* Signal timing and polarity */
		hsw:		128,
		hbp:		88,
		vfp:		10,
		vsw:		2,
		vbp:		33,
		pol:		HS_LOW | VS_LOW | DEN_LOW | CLK_RISING,
		fps:		60,	  /* Frame rate or pixel clock */
		clk:		0,
		pwmvalue:	0,	  /* PWM/Backlight setting */
		pwmfreq:	1000,
	},
};

/* Find predefined lcd panel by index (NULL on bad index) */
const lcdinfo_t *lcd_get_lcdinfo_p(u_int index)
{
	return (index < ARRAY_SIZE(lcdlist)) ? &lcdlist[index] : NULL;
}

/* Return index of next lcd panel matching string s (or 0 if no match); start
   search at given index */
u_int lcd_search_lcd(char *s, u_int index)
{
	for ( ; index < ARRAY_SIZE(lcdlist); index++) {
		if (strstr(lcdlist[index].name, s))
		    return index;	  /* match */
	}

	return 0;			  /* no more matches */
}
