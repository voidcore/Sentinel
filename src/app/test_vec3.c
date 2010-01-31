#include <stdio.h>
#include <fw/fw_math.h>

int main (int argc, char const *argv[])
{
	printf("Testing vec3\n");
	
	fw_vec3 a = fw_vec3_create(1.0, 2.0, 3.0);
	fw_vec3 b = fw_vec3_create(1.0, 2.0, 3.0);
	fw_vec3 c;
	fw_vec3_add(&c, a, b);
	
	return 0;
}