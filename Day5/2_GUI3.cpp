#define USING_GUI
#include "cppmaster.h"
#include <map>

class Window
{
	int handle;

	// �Ʒ� ������ �ٽ� : ���� ������ ���
	//					C ��� => C++ ��� �� �����ϱ� ���� �ٽɱ��
	inline static std::map<int, Window*> this_map;

public:
	void create(const std::string& title)
	{
		handle = ec_make_window(foo, title);

		// ������ ��ȣ�� Ű������ this ������ ����
		this_map[handle] = this;
	}

	static int foo(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];

		// ���� self �� �ᱹ this �Դϴ�.
		// => self �� ������ ��� ��� ����Ÿ, ��� �Լ�, �����Լ� ��밡���մϴ�.

		switch (msg)
		{
		case WM_LBUTTONDOWN: 
			//lbutton_down();	// this->lbutton_down(); �� �Ǿ�� �ϴµ�
								// static ��� �Լ� �ȿ��� this�� �����ϴ�.
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
// �� Ŭ������ ���̺귯�� ���� �ڵ�
// ����ڴ� �Ļ� Ŭ���� ���� ��ӵ� �����Լ��� override �ؼ� �̺�Ʈ ó���ϸ�˴ϴ�.

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

