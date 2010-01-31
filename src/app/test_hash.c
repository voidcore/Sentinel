#include <stdio.h>
#include <stdarg.h>

#include <fw/fw_hash.h>
#if 0
typedef enum _notification_level {DEBUG=0, SILENT=1, INFO=2 } notification_level;
notification_level g_notification_level = SILENT; 
int g_is_initialized = 0;
notification_level get_notification_level()
{	
	notification_level n = SILENT;
	char* p;
    p = getenv ( "FW_NOTIFY_LEVEL" );
    if (p != NULL) {
       

		if (strstr(p, "DEBUG") > 0){
			n = DEBUG;
			printf ("FW_NOTIFY_LEVEL is DEBUG (%s)\n", p);
		}
		else if (strstr(p, "SILENT") > 0){
			n = DEBUG;
			printf ("FW_NOTIFY_LEVEL is SILENT: (%s)\n", p);
		}
		else if (strstr(p, "INFO") > 0){
			n = INFO;
			printf ("FW_NOTIFY_LEVEL is INFO: (%s)\n", p);
		}
		
    }
	return n;
}

void debug_printf(const char* format, ...)
{
	if (!g_is_initialized) {
		g_notification_level = get_notification_level();
		g_is_initialized = 1;
	}
	char buffer[256];
	va_list args;
	va_start (args, format);
	vsprintf (buffer, format, args);
	va_end (args);
	
	switch(g_notification_level) {
		case DEBUG:
			printf("%s", buffer);
			break;
			
		default:
		break;
		
	}
}
#endif 

typedef struct _blob
{
	fw_uint size;
	fw_char name[255];
}blob;

blob* blob_create()
{
	blob* b = FW_ALLOCATE(blob);
	b->size = 0;
	strncpy(b->name, "no-name", 7); 
	return b;
}


int main (int argc, char const *argv[])
{
	//debug_printf(DEBUG, "write only in debug\n");
	//debug_printf(INFO, "write in info and debug\n");
	//debug_printf(ALWAYS, "write in all cases\n");
	fw_info_printf("Testing hash %d\n", 1);
	
	blob* b = blob_create();
	strncpy(b->name, "blob-1", 6);
	blob* b2 = blob_create();
	strncpy(b2->name, "blob-2", 6);
	
	fw_hash* h = fw_hash_create();
	fw_hash_insert(h, "first-key", b);
	fw_hash_insert(h, "first-key", b2);
	
	blob* found_blob = fw_hash_find(h, "first-key");
	if (found_blob) {
		found_blob = (blob*)found_blob;
		fw_debug_printf("Found blob: \"%s\"\n", found_blob->name);
	}else
	{
		fw_debug_printf("Couldn't find any blob for key!\n");
	}
	
	
	
	return 0;
}