#define SPRITE "<`)     //<`)// (//(`>/ (`> (/  (\\\\  1  \\  \"birdiecode\n\033[5A"
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

char a[2][3][2] = {
	{{0, 4},
	 {15, 19},
	 {35, 39}},
	{{5, 10},
	 {19, 24},
	 {35, 40}},

};

void _start()
{
	for (int i = 0; i < 2; ++i)
	{
		strcc(a[i][0][0], a[i][0][1]);
		strcc(a[i][1][0], a[i][1][1]);
		strcc(a[i][2][0], a[i][2][1]);
		strcc(44,54);
		__asm__ volatile ("int $0x80": "=a"(re): "0"(162), "b"((long)&T), "c"(0)); //sleep
		strcc(55, 59);
	}
	__asm__ volatile ("int $0x80": "=a"(re): "0"(1),"b" (0));
}