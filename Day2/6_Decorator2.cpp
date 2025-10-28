#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;


class Image
{
	std::string url;
public:
	Image(const std::string& url) : url(url)
	{
		std::cout << "downloading... " << url << std::endl;

		std::this_thread::sleep_for(3s); 
	}

	void draw()
	{
		std::cout << "draw " << url << std::endl;
	}
};

// ���ͳݿ��� �ٿ� �ε��� �׸��� "�پ��� �̸�Ƽ�� �߰�" ���� ����� �߰��� ���ô�.

// ����� ����� ����� �߰�
// => ��ü�� �ƴ� "Ŭ������ ����� �߰�" �Ѱ�
// => ���� : ��ø�� ��� �߰��� ��ƴ�.
// Emoticon : �̸�Ƽ�� ��� �߰�
// Frame    : ���� �׸� ��� �߰�
// => 2�� ���ÿ� ��� �߰��Ϸ��� ???? ���� ��� �ʿ� " ������ ����."
class Emoticon : public Image
{
public:
	Emoticon(const std::string& url) : Image(url) {}

	void draw()
	{
		std::cout << "$$$$$$$$$$$$$$$$$$$$\n"; // �߰��� ���
		Image::draw(); // Image �� ���� ��� ���
		std::cout << "$$$$$$$$$$$$$$$$$$$$\n";
	}
};
// ���� ��� �߰�
class Frame : public Image
{
public:
	Frame(const std::string& url) : Image(url) {}

	void draw()
	{
		std::cout << "####################\n"; // �߰��� ���
		Image::draw(); // Image �� ���� ��� ���
		std::cout << "####################\n";
	}
};

int main()
{
	Image img("www.image.com/car.png");
	img.draw();

	// Car.png �� �̹� ���ڵ忡�� load�Ǿ���
	// img ��ü�� �����մϴ�

	// �׷���, �Ʒ� �ڵ�� �̸�Ƽ�� ����� �߰��ϱ� ����
	// => �̹� load�ؼ� �����ϴ� img ��ü�� ��� �߰��� �ƴ϶�!!
	// => ��� �߰��� ���� ���ο� ��ü(�ٽ� �׸� load)�� �����!!

	Emoticon e("www.image.com/car.png");
	e.draw();
}
