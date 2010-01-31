#include <fw/fw_gauss.h>

fw_real fw_gauss(fw_real x, fw_real cutoff)
{
	return 1.0/cutoff * fw_exp(-FW_PI*fw_pow(x/cutoff, 2.0));
}

fw_real fw_gauss_2d(fw_real x, fw_real y, fw_real cutoff)
{
	return fw_gauss(x, cutoff) * fw_gauss(y, cutoff);
}

void fw_gauss_fill_ub(fw_ubyte* data, fw_uint width, fw_uint height, fw_real cutoff)
{
    fw_uint y = 0;
	for(y=0; y<height; y++)
	{
        fw_uint x;
		for(x=0; x<width; x++)
		{			
			fw_real g = fw_gauss_2d(
				2.0*x/(fw_real)width-1.0, 
				2.0*y/(fw_real)height-1.0, 
				cutoff
			);  
			g = fw_clamp(g, 0.0, 1.0);
			data[y*width + x] = (fw_ubyte)(g*255.0);
		}
	}
}