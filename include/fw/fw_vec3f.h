#ifndef __FW_VEC3F_H__
#define __FW_VEC3F_H__

#include <fw/fw_math_base.h>

FW_EXTERN_C_BEGIN
//------------------------------------------------------------------------------

typedef struct _fw_vec3f
{
	fw_float x;
	fw_float y;
	fw_float z;
} fw_vec3f;

//------------------------------------------------------------------------------

FW_INLINE fw_vec3f		fw_vec3f_create(fw_real x, fw_real y, fw_real z);
FW_INLINE void   	    fw_vec3f_print(fw_vec3f v, const char * str);
FW_INLINE void			fw_vec3f_add(fw_vec3f* res, fw_vec3f v1, fw_vec3f v2);
FW_INLINE void     		fw_vec3f_subtract(fw_vec3f* res, fw_vec3f v1, fw_vec3f v2);
FW_INLINE fw_bool     	fw_vec3f_is_equal(fw_vec3f a, fw_vec3f b);
FW_INLINE fw_real     	fw_vec3f_dot(fw_vec3f a, fw_vec3f b);
FW_INLINE fw_real 		fw_vec3f_magnitude(fw_vec3f a);
FW_INLINE void 			fw_vec3f_normalize(fw_vec3f* v);

//------------------------------------------------------------------------------
FW_EXTERN_C_END

#endif /* __FW_VEC3F_H__ */