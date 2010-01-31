#ifndef __FW_GAUSS_H__
#define __FW_GAUSS_H__

#include <fw/fw_math_base.h>

FW_EXTERN_C_BEGIN
//------------------------------------------------------------------------------

fw_real fw_gauss(fw_real x, fw_real cutoff);
fw_real fw_gauss_2d(fw_real x, fw_real y, fw_real cutoff);	
void fw_gauss_fill_ub(fw_ubyte* data, fw_uint width, fw_uint height, fw_real cutoff);

//------------------------------------------------------------------------------
FW_EXTERN_C_END

#endif /* __FW_GAUSS_H__ */