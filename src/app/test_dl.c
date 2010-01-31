#include <stdio.h>
#include <dlfcn.h>
#include "dlcode.h"


typedef void* lib_handle;

lib_handle load_lib(const char* lib_name)
{
	void* dl_lib = dlopen(lib_name, RTLD_LAZY);
	if(dl_lib == NULL) 
	{
	   	printf("Couldnt load library\n");
		return NULL;
	} 
	else 
	{
		printf("Library (\"%s\") loaded successfully\n", lib_name );
		return (lib_handle)dl_lib;
	}
}

typedef int (*printfunc)(const char*);

typedef struct _printer
{
	void (*f)(const char*);
}printer;



int main (int argc, char const *argv[])
{
	printf("Testing dynamic code loading\n");
	
	lib_handle lib = load_lib("libdlcode.dylib");
	if (lib==NULL) goto error;
	else 
	{
		printf("Extracting symbols\n");
		
		void* f2 = dlsym(lib,"dl_print2");
		void* f3 = dlsym(lib,"dl_print3");
		
		if (f2==NULL || f3 == NULL) goto error;
		else
		{
			printfunc func2 = *((printfunc*)(&f2));	
			printfunc func3 = *((printfunc*)(&f3));	
			for (int i=0;i<6;i++)
			{
				printfunc pf = (i%2)?func2:func3;
				
				pf("Calling you!");
			}
		}
		
		
	}

	return 0;
	
	error:
	printf("error!\n");
	
}