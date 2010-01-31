#ifndef __FW_GLUTIL_H__
#define __FW_GLUTIL_H__

#include <fw/fw_math.h>

FW_EXTERN_C_BEGIN

#include <fw/fw_glutil.h>
//------------------------------------------------------------------------------
void fw_matrix_identity(fw_real A[16]);
void fw_matrix_translate(fw_real A[16], fw_real tx, fw_real ty, fw_real tz);
void fw_matrix_rotate_z(fw_real A[16], fw_real angle);
void fw_matrix_multiply(fw_real C[16], fw_real A[16], fw_real B[16]);
void fw_matrix_print(fw_real mat[16]);
void fw_matrix_create_perspective(fw_real *mat, fw_real fov_deg, fw_real aspect, fw_real znear,fw_real zfar);
void fw_matrix_create_frustum(fw_real *mat, fw_real left, fw_real right, fw_real bottom, fw_real top, fw_real nearVal, fw_real farVal);
void fw_matrix_create_ortho(fw_real mat[16], fw_real w, fw_real h);

//------------------------------------------------------------------------------
FW_EXTERN_C_END

#endif /* __FW_GLUTIL_H__ */