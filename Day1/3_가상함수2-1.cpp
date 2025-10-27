// 3_�����Լ�2-1
// �����Ϸ��� Base �� ������ �Ҷ� ��� �����Լ��� �ּҸ� ����
// �迭�� ���������� ����
void* base_vtable[] = { Base_type_info, &Base::f1, &Base::f2, &Base::f3 };

class Base
{
	void* vtptr = base_vtable;	// �����Ϸ��� �߰��� ������

	int age;
public:
	virtual void f1() {}
	virtual void f2() {}
	virtual void f3() {}
};

//-----------------------------------
void* derived_vtable[] = { Derived_type_info, &Base::f1, &Derived::f2, &Base::f3 };

class Derived : public Base
{
	void* vtptr = derived_vtable;
public:
	void f2() {}
};
int main()
{
	Base b1, b2;
	Derived d1;

	Base* p = &d1;
	p->f2();	// 1. �����Ϸ��� f2�� �������� �ƴ��� ����
				// => ���� �ƴϸ� "call Base::f2()"
				// => �����̸� "p->vtptr[2]()" ��� �ǹ��� ���� ����

}