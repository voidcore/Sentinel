#ifndef __FW_CORE_H__
#define __FW_CORE_H__ 

// set by hand or -D
//#define FW_DEBUG 
//#FW_REAL_IS_DOUBLE 

#ifdef __cplusplus
#  define FW_EXTERN_C_BEGIN extern "C" {
#  define FW_EXTERN_C_END   }
#else
#  define FW_EXTERN_C_BEGIN
#  define FW_EXTERN_C_END
#endif

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef _WIN32
#define FW_SNPRINTF _snprintf
#else
#include <stdbool.h>
#define FW_SNPRINTF snprintf
#endif
#include <stdlib.h>

#define FW_INLINE 


// Debug
typedef enum _fw_notification_level {
	FW_NOTIFICATION_SILENT = 0,
	FW_NOTIFICATION_INFO = 1, 
	FW_NOTIFICATION_DEBUG = 2,
} fw_notification_level;
void fw_info_printf(const char* format, ...);
void fw_debug_printf(const char* format, ...);
#ifdef FW_DEBUG
#define FW_DEBUG_PRINT(msg) printf("DEBUG: (%s %d): %s\n",__FILE__, __LINE__, msg);
#define FW_DEBUG_DO(what) what;
#else
#define FW_DEBUG_PRINT(msg) 
#define FW_DEBUG_DO(what)
#endif 
#define FW_FALSE 0
#define FW_TRUE 1

// Memory management
#define FW_ALLOCATE(type) ((type*)calloc(1, sizeof(type)))
#define FW_DEFAULT_ARRAY_LENGTH 16
#define FW_ALLOCATE_ARRAY(type, len) ((type*)calloc(len, sizeof(type)))
#define FW_REALLOCATE_ARRAY(arr, type, len) ((type*)realloc(arr, sizeof(type)*len))
#define FW_FREE(ptr) (free(ptr))

// Float compare
#define FW_EPSILON 0.00001f
#define FW_ALMOST_EQUAL(a, b) (a+FW_EPSILON > b && a - FW_EPSILON < b)

// Graphics /Opengl
#define FW_POSITION_LOCATION  0
#define FW_TEX_COORD_LOCATION 1
#define FW_NORMAL_LOCATION    2
#define FW_TANGENT_LOCATION   3

#ifdef __cplusplus
extern "C" {
#endif
//------------------------------------------------------------------------------

/* Types, enums and structs */
typedef int				fw_int;
typedef unsigned char	fw_ubyte;
typedef char			fw_char;
typedef float			fw_float;
#ifdef FW_REAL_IS_DOUBLE 
typedef double			fw_real;
#else
typedef float			fw_real;
#endif

typedef unsigned int	fw_uint;
typedef unsigned short  fw_ushort;
typedef int				fw_size;
typedef int				fw_bool;

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif /* __FW_CORE_H__ */
