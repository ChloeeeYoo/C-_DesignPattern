#include <iostream>
#include <functional>
using namespace std::placeholders;

void f1(int a)		  { printf("f1, %d\n", a); }
void f2(int a, int b) { printf("f2, %d, %d\n", a, b); }
void f4(int a, int b, int c, int d)
{
	printf("f4, %d, %d, %d, %d\n", a, b, c, d);
}
class Dialog
{
public:
	void close(int exitcode) { printf("Dialog::close, %d\n", exitcode); }
	void move(int x, int y)  { printf("Dialog::move, %d, %d\n", x, y); }
};

int main()
{
	// C 함수 포인터 : 유연성이 없습니다
	//				  signature가 동일한 함수주소만 담을수 있습니다.
	void(*fp)(int);
	fp = &f1; // ok
//	fp = &f2; // error
//	fp = &Dialog::close; // error.

	// C++ std::function : 함수 포인터의 일반화 버전
	// 사용법 : std::function<함수모양> 
	// void(*)(int) : 함수 포인터 타입
	// void(int)    : 함수 타입
	std::function<void(int)> f;

	f = &f1;	// ok
	f(10);		// f1(10);

	f = &f2;   // error. f2는 인자가 2개.. signature가 다르다.

	// 핵심 
	// => std::function 은 std::bind 의 반환 값을 담을수 있다.
	// => 즉, 인자가 여러개인 함수라도, 인자 한개로 변경해서 
	//    f에 담으면 된다.
	f = std::bind(&f2, 3, _1); // ok.

	f(10); // f2(3, 10)

	// f : 인자가 int 한개인 것만 가능.
	//	   f4 는 인자가 4개 이므로 std::bind 로 "인자 한개 함수로 만들어야 한다."
	f = std::bind(&f4, 8, _1, 3, 2 );

	f(7); // f4(8, 7, 3, 2) 되도록 위 ? 채우세요

	//----------------------------------
	// 멤버 함수도 가능
	// => 함수 주소, 다음 인자로, 객체 주소 전달
	Dialog dlg;
	f = std::bind(&Dialog::move, &dlg, 3, _1);
	f(7);	// dlg.move(3, 7)


}
