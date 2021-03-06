#include <fw/fw_vec3_array.h>
#define FW_MAX_NUM_ARRAYS 32768
typedef struct _all_arrays {
	fw_uint num_arrays;
	fw_vec3_array* arrays[FW_MAX_NUM_ARRAYS];
	fw_uint alive[FW_MAX_NUM_ARRAYS];
}all_arrays;

static all_arrays s_all_arrays;


fw_uint fw_vec3_array_get_num_arrays()
{
	return s_all_arrays.num_arrays;
}
void increment_num_arrays(fw_vec3_array* arr)
{
 	s_all_arrays.num_arrays++;
}
void decrement_num_arrays(fw_vec3_array* arr)
{
 	s_all_arrays.num_arrays--;
}

//------------------------------------------------------------------------------
fw_vec3_array* fw_vec3_array_create()
{
	fw_vec3_array* arr = FW_ALLOCATE(fw_vec3_array);
	arr->data = FW_ALLOCATE_ARRAY(fw_vec3, FW_DEFAULT_ARRAY_LENGTH);
	arr->reserved = FW_DEFAULT_ARRAY_LENGTH;
	arr->current = 0;
	increment_num_arrays(arr);
	return arr;
}
//------------------------------------------------------------------------------
void fw_vec3_array_destroy(fw_vec3_array* arr)
{
	if (arr!=NULL) 
	{
		FW_FREE(arr->data);
		arr->data = NULL;
		FW_FREE(arr);
		arr = NULL;
		decrement_num_arrays(arr);
		
	}
	
}
//------------------------------------------------------------------------------
void fw_vec3_array_print(fw_vec3_array* arr)
{
	for (int i=0; i<arr->current;i++)
	{
		printf("data[%d]: ", i);
		fw_vec3_print(arr->data[i], "");

	}
}
//------------------------------------------------------------------------------
void fw_vec3_array_push_back(fw_vec3_array* arr, fw_vec3 elt)
{
	FW_DEBUG_PRINT("Pushing vector onto stack\n");
	if (arr->current < arr->reserved)
	{
		printf("Stack big enough\n");
		arr->data[arr->current++] = elt;
	}
	else
	{	
		printf("Stack to small, expanding...\n");
		arr->data = FW_REALLOCATE_ARRAY(arr->data, fw_vec3, arr->reserved*2);
		arr->data[arr->current++] = elt;
	}
	FW_DEBUG_DO(fw_vec3_array_print(arr));		
}
//------------------------------------------------------------------------------