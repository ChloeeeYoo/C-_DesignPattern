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

int main()
{
	Image img("www.image.com/car.png");
	img.draw();
}
