#define USING_GUI
#include "cppmaster.h"



class Window
{
	int handle;
public:
	void create(const std::string& title)
	{
		handle = ec_make_window(foo, title);
	}

	// 핵심 #1
	// => 아래 함수가 static 이어야 하는 이유를 정확히 알아야 합니다.
	// => ec_make_window() 1번째 인자는 반드시 인자가 4개 이어야 하는데
	//    멤버 함수로 만들면 "this" 가 추가됩니다.
	//    this 가 추가되지 않게 하려면 "static"
	// 
	// => C 언어의 "callback" 함수 개념을 class 로 설계 하려면 반드시 
	//    "static 멤버 함수" 이어야 합니다.

	static int foo(int hwnd, int msg, int a, int b)
	{
		switch (msg)
		{
		case WM_LBUTTONDOWN: std::cout << "LBUTTON " << hwnd << std::endl; break;
		case WM_KEYDOWN:     std::cout << "KEYDOWN " << hwnd << std::endl; break;
		}
		return 0;
	}
};

int main()
{
	Window w;
	w.create("A"); // 이순간 윈도우를 생성. "A" 는 캡션 문자열 

	ec_process_message(); // 프로그램을 종료하지 말고, 이벤트루프를 수행해 달라
}

