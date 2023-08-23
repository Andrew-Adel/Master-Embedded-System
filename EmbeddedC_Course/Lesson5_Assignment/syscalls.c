#include "platform_types.h"
struct	stat 
{
};

void* _sbrk(int incr)
{
	static uint8* heap_ptr = NULL;
	uint8* prev_heap_ptr = NULL;
	extern uint32 _heap_End;
	extern uint32 _E_BSS;
	
	if (heap_ptr == NULL)
		heap_ptr = (uint8*)&_E_BSS;

	prev_heap_ptr = heap_ptr;
	if ((heap_ptr + incr) > (uint8*)(&_heap_End) )
		return (void*) NULL;

	prev_heap_ptr = heap_ptr;
	heap_ptr+= incr;
	return (void*)prev_heap_ptr;
}

extern int __io_putchar(int ch) __attribute__((weak));
extern int __io_getchar(void) __attribute__((weak));

int __io_putchar(int ch){
	// write to the uart
}
int __io_getchar(void){
	// get by uart
}
__attribute__((weak)) int _write(int file, char* ptr, int len){
	int DataIdx;
	for (DataIdx = 0; DataIdx < len; ++DataIdx)
	{
		__io_putchar(*ptr++);
	}
	return len;
}
__attribute__((weak)) int _read(int file, char *ptr, int len)
{
	int DataIdx;

	for (DataIdx = 0; DataIdx < len; DataIdx++)
	{
		*ptr++ = __io_getchar();
	}

return len;
}

int _close(int file){
	return -1;
}

int _fstat(int file, struct stat *st){
	// st->st_mode = S_IFCHR;
	return 0;
}

int _isatty(int file){
	return 1;
}

int _lseek(int file, int ptr, int dir){
	return 0;
}

int _open(char *path, int flags, ...){
	//pretent like we always fall
	return -1;
}

int _wait(int *status){
	// errno = ECHILD;
	return -1;
}

