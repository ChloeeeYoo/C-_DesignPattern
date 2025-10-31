#define USING_GUI
#include "cppmaster.h"
#include <map>

class Window
{
	int handle;

	// 아래 한줄이 핵심 : 아주 유명한 기술
	//					C 언어 => C++ 언어 로 변경하기 위한 핵심기술
	inline static std::map<int, Window*> this_map;

public:
	void create(const std::string& title)
	{
		handle = ec_make_window(foo, title);

		// 윈도우 번호를 키값으로 this 포인터 보관
		this_map[handle] = this;
	}

	static int foo(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		// 이제 self 는 결국 this 입니다.
		// => self 만 있으면 모든 멤버 데이타, 멤버 함수, 가상함수 사용가능합니다.

		switch (msg)
		{
		case WM_LBUTTONDOWN: 
			//lbutton_down();	// this->lbutton_down(); 가 되어야 하는데
								// static 멤버 함수 안에는 this가 없습니다.
			self->lbutton_down();
			break;

		case WM_KEYDOWN:     
			self->key_down(); 
			break;
		}
		return 0;
	}

	virtual void lbutton_down() {}
	virtual void key_down() {}
};
// 위 클래스는 라이브러리 내부 코드
// 사용자는 파생 클래스 만들어서 약속된 가상함수를 override 해서 이벤트 처리하면됩니다.

class MainWindow : public Window
{
public:
	void lbutton_down() override 
	{
		std::cout << "lbutton_down\n";
	}
	void key_down() override 
	{
		std::cout << "key_down\n";
	}
};

int main()
{
	MainWindow w;
	w.create("A"); 

	ec_process_message();
}

