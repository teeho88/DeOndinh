#ifndef KALMAN_H
#define KALMAN_H

#define Q 0.13
#define R 1

float KalmanFilterGyr(float z);
float KalmanFilterRFC(float z);


#endif

