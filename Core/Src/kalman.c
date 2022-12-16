#include "kalman.h"

float x_w = 0;
float D_w = 1000;
float x_RFC = 0;
float D_RFC = 1000;

float KalmanFilterGyr(float z)
{
	float D_ = D_w + Q;
	float K = D_ / (D_ + R);
	x_w = x_w + K * (z - x_w);
	D_w = (1 - K) * D_;
	return x_w;
}

float KalmanFilterRFC(float z)
{
	float D_ = D_RFC + Q;
	float K = D_ / (D_ + R);
	x_RFC = x_RFC + K * (z - x_RFC);
	D_RFC = (1 - K) * D_;
	return x_RFC;
}
