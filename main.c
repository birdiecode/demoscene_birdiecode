#include <stdio.h>
#include <unistd.h>

#define BC "birdiecode\n"
#define F0 "<`)  \n (//\n  1\n"
#define F1 "   //\n(`>/\n  1\n"
#define F2 "   //\n (`>\n  1\n"
#define F3 "<`)//\n (/ \n  1\n"
#define F4 "<`)  \n (\\\\\n  \\\n"
#define F5 "<`)//\n (/ \n  \"\n"
#define F6 "<`)  \n (\\\\\n  \"\n"


int main (int argc, char ** argv)
{
	printf("%s%s", F0, BC);  // frame 0
	sleep (1);
	printf("\033[4A%s%s", F1, BC); // frame 1
	sleep (1);
	printf("\033[4A%s%s", F2, BC); // frame 2
	sleep (1);
	printf("\033[4A%s%s", F1, BC); // frame 1
	sleep (1);
	printf("\033[4A%s%s", F2, BC); // frame 2
	sleep (1);
	printf("\033[4A%s%s", F1, BC); // frame 1
	sleep (1);
	printf("\033[4A%s%s", F0, BC);  // frame 0
	sleep (1);
	printf("\033[4A%s%s", F3, BC);  // frame 3
	sleep (1);
	printf("\033[4A%s%s", F4, BC);  // frame 4
	sleep (1);
	printf("\033[4A%s%s", F5, BC);  // frame 5
	sleep (1);
	printf("\033[4A%s%s", F6, BC);  // frame 6
	sleep (1);
	printf("\033[4A%s%s", F5, BC);  // frame 5
	sleep (1);
	printf("\033[4A%s%s", F6, BC);  // frame 6
	sleep (1);
	printf("\033[4A%s%s", F5, BC);  // frame 5
	sleep (1);
	printf("\033[4A%s%s", F6, BC);  // frame 6
	sleep (1);
	printf("\033[4A%s%s", F0, BC);  // frame 0
	return 0;
}