#include <stdio.h>
#include <fw/fw_math.h>
#include <fw/fw_vec3_array.h>

int main (int argc, char const *argv[])
{
	printf("Testing vec3 array\n");

	fw_vec3_array* arr = fw_vec3_array_create();
	fw_vec3_array* arr2 = fw_vec3_array_create();
	fw_vec3_array* arr3 = fw_vec3_array_create();
	
	for(int i=0; i<16;i++) 
	{
		fw_vec3 a = fw_vec3_create(1.0*i, 2.0*i, 3.0*i);
		fw_vec3_array_push_back(arr, a);
	}
	
	


	fw_vec3_array_destroy(arr);
	fw_vec3_array_destroy(arr2);
	fw_vec3_array_destroy(arr3);

	printf("num arrays: %d\n", fw_vec3_array_get_num_arrays());	
	return 0;
}