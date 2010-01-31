#include <dlcode.h>
#include <stdio.h>

int dl_print()
{
	printf("Hello from the dynamic code!\n");
}

int dl_print2(const char* str)
{
	printf("PRINT2 %s\n", str);
}

int dl_print3(const char* str)
{
	printf("PRINT3 --  %s --\n", str);
}