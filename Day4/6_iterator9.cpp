#include <iostream>
#include <vector>

// C#, Java, C++, Python, Rust, Swift �� ���� ��� �����
// => for ��(C ��Ÿ�� ����, Python ��Ÿ��)�� ������
// => �ݺ��� �Դϴ�.

// => �׷��� for �� ������ �ִ� ��ü�� �䱸 ������
// => "iterable �� ��ü" �Դϴ�.

struct Point3D
{
	int x = 1;
	int y = 2;
	int z = 3;

	int* begin() { return &x ; }
	int* end()   { return &z + 1 ; }
};

int main()
{
	Point3D p;

	for (int e : p)
	{
		std::cout << e << std::endl;
	}

	/*
	for (; first != last; ++first)
	{
		auto e = *first;
		//---------------------------------------
		std::cout << e << std::endl;
	}
	*/
}
// �� �ڵ� ���� �Դϴ�.
// 1. �� �����ϱ�� ?
// 2. ���� �޼��� Ȯ��
// 3. ���� ������ �ϼ��� ������