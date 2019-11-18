//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//中景园电子
//店铺地址：http://shop73023976.taobao.com
//
//  文 件 名   : main.c
//  版 本 号   : v2.0
//  作    者   : HuangKai
//  生成日期   : 2018-0101
//  最近修改   : 
//  功能描述   : STM32L151AC8T6开发板点亮0.96寸OLED显示屏实验
//              说明: 
//              ----------------------------------------------------------------
//              GND    电源地
//              VCC  接5V或3.3v电源
//              D0   接PA0（SCL）
//              D1   接PA1（SDA）
//              RES  接PA2
//              DC   接PA3
//              CS   接PA4               
//              ----------------------------------------------------------------
// 修改历史   :
// 日    期   : 
// 作    者   : HuangKai
// 修改内容   : 创建文件
//版权所有，盗版必究。
//Copyright(C) 中景园电子2018
//All rights reserved
//******************************************************************************/
#ifndef __OLED_H
#define __OLED_H			  	 
#include "stm32f4xx_hal.h"
#include "stdlib.h"	    	
//OLED模式设置
//0:4线串行模式
//1:并行8080模式
#define OLED_MODE 0
#define SIZE 16
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    						  
#define  u8  unsigned char
#define  u32 unsigned int 
//#define OLED_SCLK_Clr() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0, GPIO_PIN_RESET)//CLK
//#define OLED_SCLK_Set() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0, GPIO_PIN_SET)

//#define OLED_SDIN_Clr() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1, GPIO_PIN_RESET)//DIN
//#define OLED_SDIN_Set() HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1, GPIO_PIN_SET)

#define OLED_RST_Clr() HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4, GPIO_PIN_RESET)//RES
#define OLED_RST_Set() HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4, GPIO_PIN_SET)

#define OLED_DC_Clr() HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5, GPIO_PIN_RESET)
#define OLED_DC_Set() HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5, GPIO_PIN_SET)
 
#define OLED_CS_Clr()  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0, GPIO_PIN_RESET)
#define OLED_CS_Set()  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0, GPIO_PIN_SET)
 
#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据


//OLED控制用函数
void OLED_WR_Byte(u8 dat,u8 cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);	   							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_ShowChar(u8 x,u8 y,u8 chr);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);
void OLED_ShowString(u8 x,u8 y, u8 *p);	 
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowCHinese(u8 x,u8 y,u8 no);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
void OLED_On(void) ;
#endif  
	 



