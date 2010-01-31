#include <fw/fw_math_base.h>

#include <math.h>

//------------------------------------------------------------------------------
FW_INLINE fw_real fw_cos(fw_real t)
{
    return cos(t);
}
FW_INLINE fw_real fw_sin(fw_real t)
{
    return sin(t);
}

FW_INLINE fw_real fw_tan(fw_real t)
{
    return tan(t);
}

FW_INLINE fw_real fw_cosa(fw_real t)
{
    return cos(FW_DEG2RAD*t);
}
FW_INLINE fw_real fw_sina(fw_real t)
{
    return sin(FW_DEG2RAD*t);
}

FW_INLINE fw_real fw_acos(fw_real t)
{
    return acos(t);
}

FW_INLINE fw_real fw_abs(fw_real f)
{
	return (f<0.0? f:-f);
}
FW_INLINE fw_real fw_sqrt(fw_real a)
{
    return sqrt(a);
}

FW_INLINE fw_real fw_min(fw_real a, fw_real b)
{
	return a < b ? a : b; 
}

FW_INLINE fw_real fw_max(fw_real a, fw_real b)
{
	return a > b ? a : b; 
}

FW_INLINE fw_real fw_clamp(fw_real value, fw_real min_value, fw_real max_value)
{
	return fw_min(fw_max(value, min_value), max_value); 
}

FW_INLINE fw_real fw_deg_to_rad(fw_real deg)
{
    return deg*FW_PI/180.0;
}


FW_INLINE fw_real fw_rad_to_deg(fw_real rad)
{
    return rad*180.0/FW_PI;
}

FW_INLINE fw_uint fw_next_pow2(fw_uint a)
{
    fw_uint rval=1;
    while(rval<a) rval<<=1;
    return rval;
}

FW_INLINE fw_real fw_floor(fw_real a)
{
	return floorf(a);
}

FW_INLINE fw_real fw_ceil(fw_real a)
{
	return ceilf(a);
}

FW_INLINE fw_real fw_pow(fw_real a, fw_real e)
{
	return powf(a, e);
}


FW_INLINE fw_real fw_exp(fw_real a)
{
	return expf(a);
}
//------------------------------------------------------------------------------