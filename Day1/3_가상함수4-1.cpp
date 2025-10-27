// 3_�����Լ�4-1

#include <iostream>

// �����Լ�4.cpp

// ����Ҹ��� ������ ����ϸ�
// => �����Լ��� ����ϰ� �ǹǷ�, �����Լ� ���̺��� ������尡 ����� �˴ϴ�.

class Base
{
	// protected �Ҹ����ǵ�
	// => �Ʒ� main �Լ��� "A" �κ� ó�� ������� ���ϰ� �ϱ� ���� �ڵ�
	// => A ó�� ���� ������ ����.
protected:
	~Base() {}	
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
	Base* p = new Derived; 

//	delete p;	// A. error

	delete static_cast<Derived*>(p); // ok

}

// ���
// 1. �������� �Ϻ��� ����  �ȵǸ�
// => ������ ��� Ŭ���� �Ҹ��ڴ� virtual �ϼ���!!!

// 2. �� ������ ��Ȯ�� �����ϰ�
// => ��� Ŭ������ ���� ������, ������ �߿��ϸ�
// => �� ��� ���

// isocpp.org ����
// => ��� �޴����� "Core Guidelines" ����
// => C35 �� Ȯ��