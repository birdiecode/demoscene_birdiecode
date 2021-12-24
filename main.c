#define SPRITE "<`)     //<`)// (//(`>/ (`> (/  (\\\\  1  \\  \"birdiecode\n"
long re;

struct timespec {
long int tv_sec; // seconds
long tv_nsec; // and nanoseconds
} T = {1, 0};


void _start() __asm__("_start");

void strcc(char s, char n)
{
	for (; s < n; ++s)
	{
		__asm__ volatile ("int $0x80": "=a"(re): "0"(4), "b"(1), "c"((long)&SPRITE[s]), "d"((long)(1)));
	}
	__asm__ volatile ("int $0x80": "=a"(re): "0"(4), "b"(1), "c"((long)&SPRITE[54]), "d"((long)(1)));
	
}

void _start()
{
	strcc(0, 4);
	strcc(15,19);
	strcc(35,39);
	strcc(44,54);
	__asm__ volatile ("int $0x80": "=a"(re): "0"(162), "b"((long)&T), "c"(0)); //sleep
	__asm__ volatile ("int $0x80": "=a"(re): "0"(1),"b" (0));
}