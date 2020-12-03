#ifndef MATRIXMATH_H
#define MATRIXMATH_H

#include "ultra64.h"

typedef f32 vec3[3];
typedef f32 mat44[4][4];

void matrix_4x4_rotate_vector_in_place(mat44 matrix, vec3 vector);

#endif