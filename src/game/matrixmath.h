#ifndef MATRIXMATH_H
#define MATRIXMATH_H

#include "ultra64.h"

typedef f32 vec3[3];

// Float version of a graphics matrix, which has higher precision than an Mtx.
// Matrices are stored as Mtxfs then converted to an Mtx when passed to the GPU.
// Mtxs use a union and a long long int to force alignments. Mtxfs are not
// aligned but still use the union for consistency with Mtx.
typedef union {
    f32 m[4][4];
    s32 unused;
} Mtxf;

void matrix_4x4_rotate_vector_in_place(Mtxf *matrix, vec3 vector);
void matrix_4x4_7F059694(Mtxf *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);

void matrix_4x4_multiply(Mtxf *lhs, Mtxf *rhs, Mtxf *result);
void matrix_4x4_set_position(vec3 position, Mtxf *matrix);
void matrix_4x4_7F059424(Mtxf *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9);
u16 sub_GAME_7F05997C(f32 arg0, f32 arg1);
void matrix_4x4_7F05A310(Mtxf *arg0, Mtxf *arg1);

f32 matrix_4x4_determinant(Mtxf *matrix);
f32 matrix_3x3_determinant(f32 a, f32 d, f32 g, f32 b, f32 e, f32 h, f32 c, f32 f, f32 i);
f32 matrix_2x2_determinant(f32 a, f32 c, f32 b, f32 d);

/* matrixmath_misc.h */

void sub_GAME_7F05AE00(vec3 x, vec3 y, f32 scaler, vec3 result);

#endif
