#include <fw/fw_hash.h>

fw_uint fw_hash_func(const fw_char* str)
{
	fw_uint v=0;
	while ((*str)!= '\0')
	{
		//printf("c:%c v:%d \n", *str, *str);
		v+= *str;
		v*= 13;
		*str++;
		//printf("key: %d\n", v);
	}
	//printf("fw_hash_func: returning key: %d\n", v%FW_TABLE_WIDTH);
	return (v%FW_TABLE_WIDTH);
}


fw_hash* fw_hash_create()
{
	fw_hash* h = FW_ALLOCATE(fw_hash);
	return h;
}

void fw_hash_insert(fw_hash* h, const fw_char* key, void* ptr)
{
	fw_uint k = fw_hash_func(key);
	if (h->table[k] != NULL)
	{
		fw_debug_printf("fw_hash_insert: slot is taken for \"%s\"!\n", key);
	}
	else
	{
		fw_debug_printf("fw_hash_insert: inserting data for \"%s\" in slot: %d\n", key, k);
		h->table[k] = ptr;	
	}
	
	
}

void* fw_hash_find(fw_hash*h, const fw_char* key)
{
	return h->table[fw_hash_func(key)];
}
