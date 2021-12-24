#define SPRITE "<`)     //<`)// (//(`>/ (`> (/  (\\\\  1  \\  \"birdiecode\n"
long re;


struct timespec {
	long tv_sec;        /* seconds */
	long tv_nsec;       /* nanoseconds */
};

void _start() __asm__("_start");

void strcc(char s, char n)
{
	for (; s < n; ++s)
	{
		__asm__ volatile ("int $0x80": "=a"(re): "0"(4), "b"(1), "c"((long)&SPRITE[s]), "d"((long)(1))); //write(1, &SPRITE[s], 1);
	}

	__asm__ volatile ("int $0x80": "=a"(re): "0"(4), "b"(1), "c"((long)&SPRITE[54]), "d"((long)(1)));
}

void _start()
{
	struct timespec T;
	T.tv_sec = 1;
	T.tv_nsec = 1000000;

	strcc(0, 4);
	strcc(15,19);
	strcc(35,39);
	strcc(44,54);

	// sleep 
	//asm("movl eax, 162");
	//asm("movl ebx, T");
	//asm("movl ecx, 0");
	//asm("int $0x80");
	// or
	//__asm__ volatile ("int $0x80": "=a"(re): "0"(162), "b"((long)&T), "c"(0));

	__asm__ volatile ("int $0x80": "=a"(re): "0"(1),"b" (0));
}