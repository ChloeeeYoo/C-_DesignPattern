// ������1.cpp - 3page
#include <iostream>

// �Ʒ� �ڵ忡�� ������ ��� ã�� ������
class Base
{
public:
	Base(int a) {  }
};
class Derived : public Base
{
public:
	// �ٽ� #1. Base �� ����Ʈ �����ڰ� ������ �Ʒ� 2����
	//			���� �Դϴ�.
	// => �����Ϸ��� ������ �ڵ带 �˰� �־�� �մϴ�.
	// ����� �ڵ�		// �����Ϸ� ������ �ڵ�
//	Derived()      { }	// Derived()      : Base() { }
//	Derived(int a) { }  // Derived(int a) : Base() { }

	// �ٽ� #2. �ذ�å 
	// => Derived Ŭ���� �����ڰ� Base �� �ٸ� �����ڸ� ���������
	//    ȣ���ؾ� �մϴ�.
	Derived()      : Base(0) {}
	Derived(int a) : Base(a) {}
};
int main()
{
}
