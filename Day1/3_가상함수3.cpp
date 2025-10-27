// 2_가상함수재정의
class Base
{
public:
	virtual void foo() {}
	virtual void goo(int) {}
};
class Derived : public Base
{
public:
	// #1. 가상함수 재정의시 "virtual" 키워드는 없어도 됩니다.
//	virtual void foo() {} // ok
//	void foo() {} // ok.  위와 완벽히 동일

	// #2. 가상함수 재정의시 실수(오타) 가 있어도 에러 아닙니다.
	// => 컴파일러는 다른 함수라고 생각하게 됩니다.
//	virtual void fooo() {}		// ok
//	virtual void goo(double){}	// ok

	// #3. #2 와 같은 문제를 해결하기 위해서 C++11 에서 override 키워드 추가
	void fooo() override {}			// error		
	void goo(double) override {}	// error
};

int main()
{
}





