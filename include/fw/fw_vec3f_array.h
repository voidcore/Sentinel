#ifndef __FW_VEC3F_ARRAY_H__
#define __FW_VEC3F_ARRAY_H__

#include <fw/fw_vec3f.h>

FW_EXTERN_C_BEGIN
//------------------------------------------------------------------------------
typedef struct _fw_vec3f_array fw_vec3f_array;
//------------------------------------------------------------------------------
// For debugging purposes only
fw_uint			fw_vec3f_array_get_num_arrays();
//------------------------------------------------------------------------------
fw_vec3f_array* fw_vec3f_array_create();
void			fw_vec3f_array_destroy(fw_vec3f_array* arr);
void 			fw_vec3f_array_push_back(fw_vec3f_array* arr, fw_vec3f elt);
fw_uint 		fw_vec3f_array_get_length(fw_vec3f_array* arr);
fw_vec3f* 		fw_vec3f_array_get_data(fw_vec3f_array* arr);
void 			fw_vec3f_array_print(fw_vec3f_array* arr);
//------------------------------------------------------------------------------
FW_EXTERN_C_END

#endif /* __FW_VEC3F_ARRAY_H__ */