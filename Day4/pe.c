#include <stdio.h>

// pe.c
int g = 0x11223344;

int main()
{
	int x = 10;
	static int s = 0x55667788;

	printf("ABCDEFG");

	printf("함수주소:%p\n", &main);
	printf("전역변수:%p\n", &g);
	printf("static지역변수:%p\n", &s);
	printf("지역변수:%p\n", &x);
	printf("문자열리터럴:%p\n", "ABCDEFG");
}