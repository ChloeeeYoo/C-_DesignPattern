// 3_가상함수2-1
// 컴파일러는 Base 를 컴파일 할때 모든 가상함수의 주소를 담은
// 배열을 전역적으로 생성
void* base_vtable[] = { Base_type_info, &Base::f1, &Base::f2, &Base::f3 };

class Base
{
	void* vtptr = base_vtable;	// 컴파일러가 추가한 포인터

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
	p->f2();	// 1. 컴파일러는 f2가 가상인지 아닌지 조사
				// => 가상 아니면 "call Base::f2()"
				// => 가상이면 "p->vtptr[2]()" 라는 의미의 기계어 생성

}