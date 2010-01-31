#ifndef __FW_VEC3_ARRAY_H__
#define __FW_VEC3_ARRAY_H__

#include <fw/fw_vec3.h>

FW_EXTERN_C_BEGIN
//------------------------------------------------------------------------------
typedef struct _fw_vec3_array
{
	fw_vec3* 	data;
	fw_uint 	reserved, current;
} fw_vec3_array;
//------------------------------------------------------------------------------
// For debugging purposes only
fw_uint			fw_vec3_array_get_num_arrays();
//------------------------------------------------------------------------------
fw_vec3_array* 	fw_vec3_array_create();
void			fw_vec3_array_destroy(fw_vec3_array* arr);
void 			fw_vec3_array_push_back(fw_vec3_array* arr, fw_vec3 elt);
void 			fw_vec3_array_print(fw_vec3_array* arr);
//------------------------------------------------------------------------------
FW_EXTERN_C_END

#endif /* __FW_VEC3_ARRAY_H__ */