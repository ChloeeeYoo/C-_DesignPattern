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

// 인터넷에서 다운 로드한 그림에 "다양한 이모티콘 추가" 등의 기능을 추가해 봅시다.

// 상속을 사용한 기능의 추가
// => 객체가 아닌 "클래스에 기능을 추가" 한것
// => 단점 : 중첩된 기능 추가가 어렵다.
// Emoticon : 이모티콘 기능 추가
// Frame    : 액자 그림 기능 추가
// => 2개 동시에 기능 추가하려면 ???? 다중 상속 필요 " 복잡해 진다."
class Emoticon : public Image
{
public:
	Emoticon(const std::string& url) : Image(url) {}

	void draw()
	{
		std::cout << "$$$$$$$$$$$$$$$$$$$$\n"; // 추가된 기능
		Image::draw(); // Image 의 원래 기능 사용
		std::cout << "$$$$$$$$$$$$$$$$$$$$\n";
	}
};
// 액자 기능 추가
class Frame : public Image
{
public:
	Frame(const std::string& url) : Image(url) {}

	void draw()
	{
		std::cout << "####################\n"; // 추가된 기능
		Image::draw(); // Image 의 원래 기능 사용
		std::cout << "####################\n";
	}
};

int main()
{
	Image img("www.image.com/car.png");
	img.draw();

	// Car.png 는 이미 위코드에서 load되었고
	// img 객체가 관리합니다

	// 그런데, 아래 코드는 이모티콘 기능을 추가하기 위해
	// => 이미 load해서 관리하는 img 객체에 기능 추가가 아니라!!
	// => 기능 추가를 위한 새로운 객체(다시 그림 load)를 만든것!!

	Emoticon e("www.image.com/car.png");
	e.draw();
}
