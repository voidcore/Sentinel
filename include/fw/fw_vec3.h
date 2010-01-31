#ifndef __FW_VEC3_H__
#define __FW_VEC3_H__

#include <fw/fw_math_base.h>

FW_EXTERN_C_BEGIN
//------------------------------------------------------------------------------

typedef struct _fw_vec3
{
	fw_real x;
	fw_real y;
	fw_real z;
} fw_vec3;

//------------------------------------------------------------------------------

FW_INLINE fw_vec3		fw_vec3_create(fw_real x, fw_real y, fw_real z);
FW_INLINE void   	    fw_vec3_print(fw_vec3 v, const char * str);
FW_INLINE void			fw_vec3_add(fw_vec3* res, fw_vec3 v1, fw_vec3 v2);
FW_INLINE void     		fw_vec3_subtract(fw_vec3* res, fw_vec3 v1, fw_vec3 v2);
FW_INLINE fw_bool     	fw_vec3_is_equal(fw_vec3 a, fw_vec3 b);
FW_INLINE fw_real     	fw_vec3_dot(fw_vec3 a, fw_vec3 b);
FW_INLINE fw_real 		fw_vec3_magnitude(fw_vec3 a);
FW_INLINE void 			fw_vec3_normalize(fw_vec3* v);

//------------------------------------------------------------------------------
FW_EXTERN_C_END

#endif /* __FW_VEC3_H__ */