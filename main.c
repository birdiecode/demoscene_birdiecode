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

char a[7][3][2] = {
	{{0, 6},
	 {15, 19},
	 {35, 39}}, // frame 0
	{{5, 10},
	 {19, 24},
	 {35, 39}}, // frame 1
	{{5, 10},
	 {23, 28},
	 {35, 39}}, // frame 2
	{{10, 15},
	 {27, 32},
	 {35, 39}}, // frame 3
	{{0, 6},
	 {32, 36},
	 {39, 43}}, // frame 4
	{{10, 15},
	 {27, 32},
	 {42, 44}}, // frame 5
	{{0, 6},
	 {32, 36},
	 {42, 44}}  // frame 6
};

char anim[16] = {0,1,2,1,2,1,0,3,4,5,6,5,6,5,6,0};
void _start()
{
	for (int i = 0; i < 16; ++i)
	{
		strcc(a[anim[i]][0][0], a[anim[i]][0][1]);
		strcc(a[anim[i]][1][0], a[anim[i]][1][1]);
		strcc(a[anim[i]][2][0], a[anim[i]][2][1]);
		strcc(44,54);
		__asm__ volatile ("int $0x80": "=a"(re): "0"(162), "b"((long)&T), "c"(0)); //sleep
		strcc(55, 59);
	}
	__asm__ volatile ("int $0x80": "=a"(re): "0"(1),"b" (0));
}