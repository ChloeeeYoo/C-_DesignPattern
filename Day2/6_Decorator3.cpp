#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

// Decorator - 62 page
// Image : �׸��� ���ͳݿ��� �ٿ�ε��ؼ� ȭ�鿡 �׸��� Ŭ����
class Image
{
	std::string url;
public:
	Image(const std::string& url) : url(url)
	{
		std::cout << "downloading... " << url << std::endl;

		std::this_thread::sleep_for(3s); // 3�ʰ� ���
	}

	void draw()
	{
		std::cout << "draw " << url << std::endl;
	}
};

// ������ ����� ����� �߰�
class Emoticon 
{
	Image* origin; // �ٽ� : �����ͳ� ���� Ÿ��
				   // => �ǵ� : �ܺο� �̹� ������ ��ü�� ����Ű�ڴٴ°�
public:
	Emoticon(Image* img) : origin(img) {}

	// �Ʒ� �Լ��� �ٽ�
	void draw()
	{
		std::cout << "$$$$$$$$$$$$$$$$$$$\n";
		origin->draw();
		std::cout << "$$$$$$$$$$$$$$$$$$$\n";
	}
};
// �׸��� ���� ����� �߰�
class Frame
{
	Image* origin; 
public:
	Frame(Image* img) : origin(img) {}

	void draw()
	{
		std::cout << "####################\n";
		origin->draw();
		std::cout << "####################\n";
	}
};
int main()
{
	Image img("www.image.com/car.png");
	img.draw();		// ���� ��ü�� ��ɸ� ����

	Emoticon e(&img); // e �� img �� ����߰� ��ü(decorator)
	e.draw();		// ���� ��ü��� + �߰� ��� ����

	Frame f(&img); 
	f.draw();

	Frame f2(&e); // "������ ����߰�"�� �ٽ� ��� �߰�
				  // => Decorator ���� �ٽ�. 
				  // => ������ ������ ����!!
				  // => �ذ��� ���� �ҽ�
	f2.draw();
}
