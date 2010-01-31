#include <fw/fw_random.h>

fw_real fw_random(fw_real low, fw_real high)
{
	return low + (rand()/(fw_real)RAND_MAX)*(high-low);
}
void fw_random_seed(fw_uint seed)
{
	srand(seed);
}