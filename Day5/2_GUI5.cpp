#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

// �ٽ� : chain of responsibility 

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
			self->handle_lbutton_down(); //å���� �� ������ ������ �Լ�
			break;

		case WM_KEYDOWN:
			self->key_down();
			break;
		}
		return 0;
	}

	// �Ʒ� �ڵ尡 å���� ���� �ٽ�
	void handle_lbutton_down()
	{
		// #1. �ڽ��� ���� ó��
		if (lbutton_down() == true)
			return;

		// #2. ó������ ���� ��� �θ� ����(parent �� �ᱹ chain!!)
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

		//return true; // ���� ó�������Ƿ� �̺�Ʈ ó�� ����
		return false;  // ���� ó�������� �̺�Ʈ�� �θ𿡰Ե� ���� �޶�.
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

// ��κ��� GUI ���̺귯���� �̺�Ʈ ó���� ���� �����մϴ�.
// => chain of responsibility ������ ���� �Դϴ�

// �׷���, �� ���̺귯���� �̷� ����� "�ڽŵ� ���� �̸� ���" �մϴ�.

// IOS    : Responder Chain �̶�� ��� ���
// C# WPF : Bubbling Event
// C++ MFC : Message Routing