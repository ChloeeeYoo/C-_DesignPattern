#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

// 핵심 : chain of responsibility 

class Window
{
	int handle;
	inline static std::map<int, Window*> this_map;

	std::vector<Window*> child_vec;
	Window* parent = nullptr;

public:
	void add_child(Window* child)
	{
		child->parent = this;
		child_vec.push_back(child);
		ec_add_child(this->handle, child->handle);
		ec_set_window_rect(child->handle, 100, 100, 300, 300);
	}





	void create(const std::string& title)
	{
		handle = ec_make_window(foo, title);
		this_map[handle] = this;
	}

	static int foo(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		switch (msg)
		{
		case WM_LBUTTONDOWN:
			//self->lbutton_down();
			self->handle_lbutton_down(); //책임의 고리 패턴을 구현한 함수
			break;

		case WM_KEYDOWN:
			self->key_down();
			break;
		}
		return 0;
	}

	// 아래 코드가 책임의 고리의 핵심
	void handle_lbutton_down()
	{
		// #1. 자신이 먼저 처리
		if (lbutton_down() == true)
			return;

		// #2. 처리하지 않은 경우 부모에 전달(parent 가 결국 chain!!)
		if (parent != nullptr)
			parent->handle_lbutton_down();
	}

	virtual bool lbutton_down() { return false; }
	virtual bool key_down()     { return false; }
};

class MainWindow : public Window
{
public:
	bool lbutton_down() override 
	{ 
		std::cout << "MainWindow lbutton_down\n"; 
		return true;
	}
};
class ImageView : public Window
{
public:
	bool lbutton_down() override 
	{ 
		std::cout << "ImageView lbutton_down\n"; 

		//return true; // 내가 처리했으므로 이벤트 처리 종료
		return false;  // 내가 처리했지만 이벤트를 부모에게도 보내 달라.
	}
};







int main()
{
	MainWindow w;
	w.create("A");

	ImageView imgview;
	imgview.create("imageview");

	w.add_child(&imgview);

	ec_process_message();
}

// 대부분의 GUI 라이브러리의 이벤트 처리는 위와 유사합니다.
// => chain of responsibility 패턴의 응용 입니다

// 그런데, 각 라이브러리가 이런 기법에 "자신들 만의 이름 사용" 합니다.

// IOS    : Responder Chain 이라는 용어 사용
// C# WPF : Bubbling Event
// C++ MFC : Message Routing