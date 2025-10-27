// 3_가상함수2-2
class Base
{
public:
	virtual void f1() {}
	virtual void f2() {}
	virtual void f3() {}
};
class Derived : public Base
{
public:
	void f2() {}
};
int main()
{
	Base b1, b2;
	Derived d1;

	Base* p = &d1;
	p->f2();
}