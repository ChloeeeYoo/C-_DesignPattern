class Dialog
{
public:
	void close(int a) {}		//void close(Dialog* this, int a) {}  //
	static void close2(int a) {}//void close2( int a) {} 
};

void foo(int a) {}

// 함수 포인터와 this : 약간 까다로운 내용. 몰라도 되지만 참고로 알아 두세요

int main()
{
	// 핵심 #1. 일반 함수 포인터에 멤버함수의 주소를 담을수 없습니다.
	//      #2. 일반 함수 포인터에 static 멤버함수의 주소를 담을수 있습니다.

	void(*f1)(int) = &foo; // ok
	void(*f2)(int) = &Dialog::close; // error. 인자가 2개인 함수
	void(*f3)(int) = &Dialog::close2;// ok

}