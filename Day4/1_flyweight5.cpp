#include <iostream>
#include <string>
#include <string_view>
int main()
{
	char sa1[] = "hello";
	char sa2[] = "hello";

	const char* sp1 = "hello";
	const char* sp2 = "hello";

	// �ٽ� : �Ʒ� �ڵ��� ���(�ּ�)������ ������ ? ���� �ּ� ? �ٸ��ּ�
	printf("%p, %p\n", sa1, sa2); // �ٸ� �ּ�
	printf("%p, %p\n", sp1, sp2); // ���� �ּ�

	std::string s = "hello";// ���� �Ҵ��ؼ� "hello" ���ڿ� ����
							// ��, ���ڿ��� ����

	std::string_view sv = "hello"; // sv �� ���������� const char* �� ����
							// ��, ��� �޸𸮿� �ִ� ���ڿ� ����Ŵ
	
	printf("%p\n", s.data());
	printf("%p\n", sv.data());
}

// �� ������ ��Ȯ�� �н��Ϸ���

// => ���� ���� ����(PE, ELF) �н�
// => ".rodata" �н��� ������
// => ���ۿ��� "C .rodata" �˻�...
// => .rodata => ��� �޸𸮸� �ǹ� ( read only data)