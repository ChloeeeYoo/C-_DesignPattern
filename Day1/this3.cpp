class Dialog
{
public:
	void close(int a) {}	
};
void foo(int a) {}

int main()
{
	// #1. 일반 함수 포인터에 멤버 함수 주소를 담을수 없다.
	void(*f1)(int) = &foo; // ok
	//void(*f2)(int) = &Dialog::close; // error. 

	// #2. 멤버 함수 주소를 담으려면 멤버 함수 포인터를 사용해야 한다.
	void(Dialog::*f2)(int) = &Dialog::close; // ok

	// #3. 멤버 함수 포인터 사용하기
	f2(10); // error. "객체(this)" 가 없습니다.
			// Dialog dlg;
			// dlg.close(10) 이렇게 해야 합니다.

	Dialog dlg;
//	dlg.f2(10); // error. dlg 안에는 f2라는 멤버는 없습니다.

	// #4. pointer to member 라는 연산자를 알아야 합니다.
	// => .*, ->* 연산자

//	dlg.*f2(10);  // error. 연산자 우선순위 문제!!
					// => .* 연산자 보다 ( 연산자가 우선순위가 높다)

	(dlg.*f2)(10); // ok. 이 코드가 멤버 함수 주소를
					// 함수 포인터에 담았다가 사용하는 코드
					// 복잡해 보이지만,C++ 진영에서 아주 널리 사용됩니다.
}