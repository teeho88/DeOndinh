/*
 * IMU50.h
 *
 *  Created on: Nov 17, 2022
 *      Author: Teeho
 */

#ifndef INC_IMU50_H_
#define INC_IMU50_H_

#include "main.h"
#include "stdio.h"
#include "string.h"

#define READ_ANGLE 0x7704000408
#define READ_ACCEL 0x7704005458
#define READ_GYR 0x7704005054U
#define READ_QUATERNION 0x770400575B
#define __SET_BAUD_RATE(x) (0x7705000B0012|(x<<8))
#define __SET_OUT_FREQ(x) (0x7705000C0011|(x<<8))
#define __SET_AUTO_OUT(x) (0x77050056005B|(x<<8))
#define SAVE_SETTING 0x7704000A0E

enum BAUD_RATE {
	BAUD_2400 = 0x00,
	BAUD_4800 = 0x01,
	BAUD_9600 = 0x02,
	BAUD_19200 = 0x03,
	FREQ_115200 = 0x04
};

enum OUT_FREQ {
	ANSWER = 0x00,
	FREQ_5HZ = 0x01,
	FREQ_10HZ = 0x02,
	FREQ_20HZ = 0x03,
	FREQ_25HZ = 0x04,
	FREQ_50HZ = 0x05,
	FREQ_100HZ = 0x06
};

enum AUTO_OUTPUT {
	ANGLE = 0x00,
	ACCEL = 0x01,
	GYR = 0x02,
	ANGLE_RESERVING = 0x03,
	QUATERNION = 0x04,
	ALL = 0x05
};

typedef struct
{
	float x;
	float y;
	float z;
}Data_Triaxis_Def;

typedef struct
{
	float q0;
	float q1;
	float q2;
	float q3;
}QUATERN;

void IMU50_Init(UART_HandleTypeDef *huart, uint8_t mode, uint8_t *inBuff, uint16_t len);
void IMU50_Read_Angle();



#endif /* INC_IMU50_H_ */
