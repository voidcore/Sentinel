#ifndef __FW_MATH_BASE_H__
#define __FW_MATH_BASE_H__

#include "fw_core.h"

FW_EXTERN_C_BEGIN
//------------------------------------------------------------------------------

#define FW_PI 3.14159265358979323846264338327950288
#define FW_HALF_PI 1.570796326794897
#define FW_QUARTER_PI 0.785398163397448
#define FW_DEG2RAD 0.017453292519943
#define FW_RAD2DEG 57.295779513082325
#define FW_MAT4_INDEX(i,j) (j*4+i)

FW_INLINE fw_real fw_cos(fw_real t);
FW_INLINE fw_real fw_sin(fw_real t);
FW_INLINE fw_real fw_tan(fw_real t);
FW_INLINE fw_real fw_cosa(fw_real t);
FW_INLINE fw_real fw_sina(fw_real t);
FW_INLINE fw_real fw_cos(fw_real t);
FW_INLINE fw_real fw_abs(fw_real f);
FW_INLINE fw_real fw_min(fw_real a, fw_real b);
FW_INLINE fw_real fw_max(fw_real a, fw_real b);
FW_INLINE fw_real fw_clamp(fw_real value, fw_real minValue, fw_real maxValue);
FW_INLINE fw_real fw_sqrt(fw_real a);
FW_INLINE fw_real fw_floor(fw_real a);
FW_INLINE fw_real fw_ceil(fw_real a);
FW_INLINE fw_real fw_pow(fw_real a,fw_real e);
FW_INLINE fw_real fw_exp(fw_real a);

FW_INLINE fw_real fw_deg_to_rad(fw_real deg);
FW_INLINE fw_real fw_rad_to_deg(fw_real rad);

FW_INLINE fw_uint fw_next_pow2(fw_uint a);
//------------------------------------------------------------------------------
FW_EXTERN_C_END

#endif /* __FW_MATH_BASE_H__ */
