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
	// C �Լ� ������ : �������� �����ϴ�
	//				  signature�� ������ �Լ��ּҸ� ������ �ֽ��ϴ�.
	void(*fp)(int);
	fp = &f1; // ok
//	fp = &f2; // error
//	fp = &Dialog::close; // error.

	// C++ std::function : �Լ� �������� �Ϲ�ȭ ����
	// ���� : std::function<�Լ����> 
	// void(*)(int) : �Լ� ������ Ÿ��
	// void(int)    : �Լ� Ÿ��
	std::function<void(int)> f;

	f = &f1;	// ok
	f(10);		// f1(10);

	f = &f2;   // error. f2�� ���ڰ� 2��.. signature�� �ٸ���.

	// �ٽ� 
	// => std::function �� std::bind �� ��ȯ ���� ������ �ִ�.
	// => ��, ���ڰ� �������� �Լ���, ���� �Ѱ��� �����ؼ� 
	//    f�� ������ �ȴ�.
	f = std::bind(&f2, 3, _1); // ok.

	f(10); // f2(3, 10)

	// f : ���ڰ� int �Ѱ��� �͸� ����.
	//	   f4 �� ���ڰ� 4�� �̹Ƿ� std::bind �� "���� �Ѱ� �Լ��� ������ �Ѵ�."
	f = std::bind(&f4, 8, _1, 3, 2 );

	f(7); // f4(8, 7, 3, 2) �ǵ��� �� ? ä�켼��

	//----------------------------------
	// ��� �Լ��� ����
	// => �Լ� �ּ�, ���� ���ڷ�, ��ü �ּ� ����
	Dialog dlg;
	f = std::bind(&Dialog::move, &dlg, 3, _1);
	f(7);	// dlg.move(3, 7)


}
