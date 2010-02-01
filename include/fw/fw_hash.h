#include <fw/fw_core.h>

FW_EXTERN_C_BEGIN
#define FW_TABLE_WIDTH 50000
//------------------------------------------------------------------------------
typedef struct _fw_hash 
{
	void* 	table[FW_TABLE_WIDTH];
	fw_uint slots[FW_TABLE_WIDTH];
}fw_hash;

fw_hash* fw_hash_create();
void fw_hash_insert(fw_hash* h, const fw_char* key, void* ptr);
void* fw_hash_find(fw_hash*h, const fw_char* key);


//------------------------------------------------------------------------------
FW_EXTERN_C_END
