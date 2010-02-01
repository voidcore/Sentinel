#include <fw/fw_core.h>

fw_notification_level s_notification_level = FW_NOTIFICATION_SILENT; 
int s_is_initialized = 0;

void fw_set_notification_level(fw_notification_level lvl)
{
	s_notification_level = lvl;
}

fw_notification_level fw_get_notification_level()
{	
	fw_notification_level n = FW_NOTIFICATION_SILENT;
	char* p;
    p = getenv ( "FW_NOTIFY_LEVEL" );
    if (p != NULL) {
       

		if (strstr(p, "DEBUG") > 0){
			n = FW_NOTIFICATION_DEBUG;
			printf ("FW_NOTIFY_LEVEL is DEBUG (%s)\n", p);
		}
		else if (strstr(p, "SILENT") > 0){
			n = FW_NOTIFICATION_SILENT;
			printf ("FW_NOTIFY_LEVEL is SILENT: (%s)\n", p);
		}
		else if (strstr(p, "INFO") > 0){
			n = FW_NOTIFICATION_INFO;
			printf ("FW_NOTIFY_LEVEL is INFO: (%s)\n", p);
		}
		
    }
	return n;
}

void fw_debug_printf(const char* format, ...)
{
	if (!s_is_initialized) {
		s_notification_level = fw_get_notification_level();
		s_is_initialized = 1;
	}
	char buffer[256];
	va_list args;
	va_start (args, format);
	vsprintf (buffer, format, args);
	va_end (args);
	
	switch(s_notification_level) {
		case FW_NOTIFICATION_DEBUG:
			printf("DEBUG - %s", buffer);
			break;
			
		default:
		break;
		
	}
}


void fw_info_printf(const char* format, ...)
{
	if (!s_is_initialized) {
		s_notification_level = fw_get_notification_level();
		s_is_initialized = 1;
	}
	char buffer[256];
	va_list args;
	va_start (args, format);
	vsprintf (buffer, format, args);
	va_end (args);
	
	switch(s_notification_level) {
		case FW_NOTIFICATION_INFO:
		case FW_NOTIFICATION_DEBUG:
			printf("INFO -  %s", buffer);
			break;
			
		default:
		break;
		
	}
}