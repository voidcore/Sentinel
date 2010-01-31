#include <fw/fw_vec3.h>

//------------------------------------------------------------------------------
FW_INLINE fw_vec3 
fw_vec3_create(fw_real x, fw_real y, fw_real z)
{
	fw_vec3 v;
	v.x = x;
	v.y = y;
	v.z = z;
	
	FW_DEBUG_PRINT("In fw_vec3_create");
	FW_DEBUG_DO(fw_vec3_print(v, "Initiated"));
	
	return v;
}
//------------------------------------------------------------------------------
FW_INLINE void 
fw_vec3_print(fw_vec3 v, const char * str)
{
	char buf[100];
	FW_SNPRINTF(buf, 100, "x: %2.2f y: %2.2f z: %2.2f\n", v.x, v.y, v.z);
	//FW_DEBUG_PRINT("In fw_vec3_print");
	printf("%s %s", str, buf);
}
//------------------------------------------------------------------------------
FW_INLINE void 
fw_vec3_add(fw_vec3* res, fw_vec3 v1, fw_vec3 v2)
{
	res->x = v1.x + v2.x;
	res->y = v1.y + v2.y;
	res->z = v1.z + v2.z;
	FW_DEBUG_PRINT("In fw_vec3_add");
	FW_DEBUG_DO(fw_vec3_print(*res, "Result of add"));	
}
//------------------------------------------------------------------------------
FW_INLINE void 
fw_vec3_subtract(fw_vec3* res, fw_vec3 v1, fw_vec3 v2)
{
	fw_vec3 result;
	res->x = v1.x - v2.x;
	res->y = v1.y - v2.y;
	res->z = v1.z - v2.z;
	FW_DEBUG_PRINT("In fw_vec3_subtract");
	FW_DEBUG_DO(fw_vec3_print(*res, "Result of subtraction"));
}
//------------------------------------------------------------------------------
FW_INLINE fw_bool 
fw_vec3_is_equal(fw_vec3 a, fw_vec3 b)
{
	// \TODO: add floating point epsilon
    return (a.x==b.x && a.y==b.y && a.z==b.z);
}
//------------------------------------------------------------------------------
FW_INLINE fw_real 
fw_vec3_dot(fw_vec3 a, fw_vec3 b)
{
	return a.x*b.x + a.y*b.y + a.z*b.z;
}
//------------------------------------------------------------------------------
FW_INLINE fw_real 
fw_vec3_magnitude(fw_vec3 a)
{
	return fw_sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}
//------------------------------------------------------------------------------
FW_INLINE void 
fw_vec3_normalize(fw_vec3* v)
{
    fw_real len = fw_vec3_magnitude(*v);
    if (len <= 0.0) 
    {
       // let it be
    }
    else 
    {
        v->x /= len;
        v->y /= len;
        v->z /= len;
    }
}
//------------------------------------------------------------------------------




