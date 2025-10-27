#include <iostream>

class Animal
{
	int age = 0; // sizeof(int) �� 4�Դϴ�.

public:
	// non-virtual : ȣ��� �⺻ ���ε��� static binding �ش޶�� ��
	//				 �����Ϸ��� ������ Ÿ������ �Լ� ȣ�� ����
	//				������� ����. ����
	void cry1() { std::cout << "Animal Cry1" << std::endl; }


	// virtual : �Լ� ȣ��� dynamic binding �ش޶�� ��
	//			 ������ Ÿ���� �ƴ� �޸𸮸� �����ؼ� ���� ��ü Ÿ������
	//			 ȣ�� ����
	//			�ణ�� �������
	virtual void cry2() { std::cout << "Animal Cry2" << std::endl; }
};







class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog Cry1" << std::endl; }
	void cry2() { std::cout << "Dog Cry2" << std::endl; }
};



int main()
{
	std::cout << sizeof(Animal) << std::endl;
				// sizeof(��� ����Ÿ age) +  sizeof(������)
				//							=>Ÿ������ ������
	Dog    d; 

	Animal* p = &d;

	p->cry1();  // non-virtual, static binding, �����Ϸ��� ������Ÿ������ ����
				// Animal Cry1 ȣ��, ����.
	p->cry2();  // virtual, dynamic binding, ����� �޸� ������ ����
				// Dog Cry1 ȣ��. ����.
}

// godbolt.org ����Ʈ ����
// => �پ��� ����� ������ ���(����, ����� ���)�� Ȯ�� ������ ����Ʈ

// virtual �Լ� ����
// => ��ü ���� Ÿ�������� ����Ű�� �����Ͱ� �߰��ǹǷ� �ణ�� �޸� �������
// => �����Լ� ���̺��̶�� ���� ������ �޸� �������

// => ȣ���, ����ð��� �޸� ���翡 ���� ���� �������
//    (move ���� �ڵ�  3~4�� ���� �߰�, �����Ϸ� ���� �ٸ��� �ִ�)

// ���� ȣ��Ǵ� �Լ� ��� "���� �ص� �˴ϴ�."
// ������, ���� �ȿ��� ȣ���̶�� ���� ����ؾ� �մϴ�.