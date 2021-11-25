#ifndef _MATH_H_
#define _MATH_H_

#define DEG2RAD(x) ((x * 3.1415927f) / 360.0f)

#define M_PI 3.14159265358979323846
#define M_PI_F 3.1415927f

#define M_2PI    6.2831855
#define M_2PI_F  6.2831855f
#define M_TAU    M_2PI_F

#define M_45_DEG_IN_RAD 0.7853982f
#define M_100_DEG_IN_RAD 1.7453293f
#define M_110_DEG_IN_RAD 1.9198622f
#define M_250_DEG_IN_RAD 4.363323f
#define M_260_DEG_IN_RAD 4.537856f
#define M_315_DEG_IN_RAD 5.4977875f

#define M_U16_MAX_VALUE_F 65536.0f

float sinf(float);
double sin(double);
float cosf(float);
double cos(double);

float sqrtf(float);

#endif
