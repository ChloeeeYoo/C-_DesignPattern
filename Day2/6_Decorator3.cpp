#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std::literals;

// Decorator - 62 page
// Image : 그림을 인터넷에서 다운로드해서 화면에 그리는 클래스
class Image
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

// 포함을 사용한 기능의 추가
class Emoticon 
{
	Image* origin; // 핵심 : 포인터나 참조 타입
				   // => 의도 : 외부에 이미 생성된 객체를 가리키겠다는것
public:
	Emoticon(Image* img) : origin(img) {}

	// 아래 함수가 핵심
	void draw()
	{
		std::cout << "$$$$$$$$$$$$$$$$$$$\n";
		origin->draw();
		std::cout << "$$$$$$$$$$$$$$$$$$$\n";
	}
};
// 그림에 액자 모양을 추가
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
	img.draw();		// 원본 객체의 기능만 수행

	Emoticon e(&img); // e 는 img 에 기능추가 객체(decorator)
	e.draw();		// 원본 객체기능 + 추가 기능 수행

	Frame f(&img); 
	f.draw();

	Frame f2(&e); // "원본에 기능추가"에 다시 기능 추가
				  // => Decorator 패턴 핵심. 
				  // => 하지만 지금은 에러!!
				  // => 해결은 다음 소스
	f2.draw();
}
