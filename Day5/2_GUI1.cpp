// 이 예제는 32bit 로 빌드해야 합니다
#define USING_GUI
#include "cppmaster.h"

int foo(int hwnd, int msg, int a, int b) 
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON " << hwnd << std::endl; break;
	case WM_KEYDOWN:     std::cout << "KEYDOWN " << hwnd << std::endl; break;
	}
	return 0;
}

int main()
{
	int h1 = ec_make_window(foo,	// 이벤트를 처리할 함수(인자가 int 타입 4개)
							"A");	// 윈도우 캡션 문자열

	int h2 = ec_make_window(foo, "B");

	// cppmaster.h 에는 아래 함수도 있습니다.
	
	ec_set_window_rect(h1, 0, 0, 200, 200);

	ec_add_child(h2, h1); // h2 에 h1 을 자식 윈도우로 부착

	ec_process_message();
}

