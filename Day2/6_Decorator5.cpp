#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

// Image 클래스와
// Image 에 기능을 추가하는 모든 Decorator 는 
// 동일한 인터페이스를 사용해야 한다.

struct IDraw
{
	virtual void draw() = 0;
	virtual ~IDraw() {}
};


class Image : public IDraw
{
	std::string url;
public:
	Image(const std::string& url) : url(url)
	{
		std::cout << "downloading... " << url << std::endl;

		std::this_thread::sleep_for(3s); // 3초간 대기
	}

	void draw()
	{
		std::cout << "draw " << url << std::endl;
	}
};

// 기능 추가 클래스는 공통의 특징이 있을수 있습니다.
// 이런 특징을 관리하는 기반 클래스 설계
class Decorator : public IDraw
{	
	IDraw* origin;
//  int x, y 등의 멤버도 있을수 있습니다.

public:
	Decorator(IDraw* p) : origin(p) {}

	void draw() { origin->draw(); }
};

class Emoticon : public Decorator
{
public:
	Emoticon(IDraw* img) : Decorator(img) {}

	void draw()
	{
		std::cout << "$$$$$$$$$$$$$$$$$$$\n";
		Decorator::draw();
		std::cout << "$$$$$$$$$$$$$$$$$$$\n";
	}
};

class Frame : public Decorator
{
public:
	Frame(IDraw* img) : Decorator(img) {}

	void draw()
	{
		std::cout << "####################\n";
		Decorator::draw();
		std::cout << "####################\n";
	}
};
int main()
{
	Image img("www.image.com/car.png");
	img.draw();

	Emoticon e(&img);
	e.draw();

	Frame f(&e);
	f.draw();
}
