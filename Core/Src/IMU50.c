/*
 * IMU50.c
 *
 *  Created on: Nov 17, 2022
 *      Author: Teeho
 */
#include "IMU50.h"

static UART_HandleTypeDef MyUart;
uint8_t *respond;
uint16_t lenBuffer;

Data_Triaxis_Def Angle;

void IMU50_SendCommand(uint8_t *cmd, uint16_t len)
{
	HAL_UART_Transmit(&MyUart,cmd, len, 100);
}


void IMU50_Init(UART_HandleTypeDef *huart, uint8_t mode, uint8_t *inBuff, uint16_t len)
{
	respond  = inBuff;
	lenBuffer = len;
	memcpy(&MyUart,huart,sizeof(*huart));
	IMU50_SendCommand((uint8_t*)__SET_AUTO_OUT(mode),6);
	HAL_Delay(100);
}

void IMU50_Read_Angle()
{
	IMU50_SendCommand((uint8_t*)READ_ANGLE,5);
	if(respond[0] == 0x77 && respond[1] == 0x0D)
	{
		Angle.x = (-2*(respond[4]>>4)+1)*((respond[4]&0x0f)*100 + (respond[5]>>4)*10 + (respond[5]&0x0f) + (respond[6]>>4)*0.1 + (respond[6]&0x0f)*0.01);
		Angle.y = (-2*(respond[7]>>4)+1)*((respond[7]&0x0f)*100 + (respond[8]>>4)*10 + (respond[8]&0x0f) + (respond[9]>>4)*0.1 + (respond[9]&0x0f)*0.01);
		Angle.z = (-2*(respond[10]>>4)+1)*((respond[10]&0x0f)*100 + (respond[11]>>4)*10 + (respond[11]&0x0f) + (respond[12]>>4)*0.1 + (respond[12]&0x0f)*0.01);
	}
}



