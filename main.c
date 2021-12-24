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

char a[1][3][2] = {
	{{0, 4},
	 {15, 19},
	 {35, 39}},
};

void _start()
{
	int ind = 0;

	strcc(a[ind][0][0], a[ind][0][1]);
	strcc(a[ind][1][0], a[ind][1][1]);
	strcc(a[ind][2][0], a[ind][2][1]);
	strcc(44,54);
	__asm__ volatile ("int $0x80": "=a"(re): "0"(162), "b"((long)&T), "c"(0)); //sleep
	__asm__ volatile ("int $0x80": "=a"(re): "0"(1),"b" (0));
}