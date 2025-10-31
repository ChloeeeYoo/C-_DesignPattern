#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

// 핵심 : 자식윈도우 개념 추가

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

		// 이제 C 함수를 사용해서 실제 자식윈도우 부착
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

class MainWindow : public Window
{
public:
	void lbutton_down() override {std::cout << "MainWindow lbutton_down\n";	}
};
class ImageView : public Window
{
public:
	void lbutton_down() override {std::cout << "ImageView lbutton_down\n";	}
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

