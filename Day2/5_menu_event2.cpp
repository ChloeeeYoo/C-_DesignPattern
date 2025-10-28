#include <iostream>
#include <functional> // std::bind() �� ���� ���
using namespace std::placeholders;  // _1, _2, _3 ... 

// foo �� "4��(���ڰ� 4��)" �Լ�
void foo(int a, int b, int c, int d)
{
	printf("foo : %d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
	foo(1, 2, 3, 4); // ok. 4�� �Լ��̹Ƿ� ���ڰ� 4�� ����


	// std::bind : M �� �Լ��� Ư�� ���ڷ� ������ N �� �Լ� ����� ����(��, M >= N)

	// ���� : std::bind( M�� �Լ� �ּ�, M�� ���� )

	auto f1 = std::bind(&foo, 1, 2, 3, 4);  // "4�� �Լ� => 0 �� �Լ�" �����

	f1(); // foo(1,2,3,4) �ǹ�.. 

	
	auto f2 = std::bind(&foo, 3, _1, 7, _2); // "4���Լ� => 2�� �Լ�" �����. 

	f2(9, 5); // foo(3, 9, 7, 5)


	auto f3 = std::bind(&foo, _3, 2, _1, _2);  // ? ä�켼��

	f3(9, 3, 1);  // foo(1, 2, 9, 3) �ǵ��� �� ? ä�켼��

	// std::bind() �� ��ȯ ����
	// => std::bind ���ڿ� ���� �ٸ� Ÿ���� ��ȯ �˴ϴ�.
	// => ����, auto �� ��Ƽ� ����ؾ� �մϴ�.

	// std::bind �ǹ�
	// => �Լ��� ���ڸ� �����ϰų�, ������ ������ ���ο� �Լ� �����

	// ���̽� : functools.partial() �� ���� ������ ����
}
