#include <stdio.h>

// pe.c
int g = 0x11223344;

int main()
{
	int x = 10;
	static int s = 0x55667788;

	printf("ABCDEFG");

	printf("�Լ��ּ�:%p\n", &main);
	printf("��������:%p\n", &g);
	printf("static��������:%p\n", &s);
	printf("��������:%p\n", &x);
	printf("���ڿ����ͷ�:%p\n", "ABCDEFG");
}