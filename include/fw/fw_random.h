#ifndef __FW_RANDOM_H__
#define __FW_RANDOM_H__

#include <fw/fw_core.h>
#include <stdlib.h> /* for rand() and RAND_MAX */

FW_EXTERN_C_BEGIN

/* Random */
fw_real fw_random(fw_real low, fw_real high);
void fw_random_seed(fw_uint seed);

FW_EXTERN_C_END

#endif /* __FW_RANDOM_H__ */