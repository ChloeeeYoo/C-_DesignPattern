#include <iostream>
#include <string>
#include <map>

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}

public:
	void draw() { std::cout << "Draw " << image_url << std::endl; }

	// static 멤버 데이타
	// => 클래스 외부에 정의 필요 

	// inline static 멤버 데이타 - C++17 부터
	// => 클래스 외부 정의 필요 없음.

	inline static std::map<std::string, Image*> image_map;

	// 자신의 객체를 만드는 static 멤버 함수
	static Image* create(const std::string& url)
	{
		Image* img = nullptr;

		// #1. 자료구조에서 image 객체가 있는지 검색
		auto it = image_map.find(url);

		if (it != image_map.end())
		{
			img = it->second;	// 맵의 반복자 it는 first : key, second : value
		}
		else
		{
			img = new Image(url);
			image_map[url] = img;
		}
		return img;
	}
};



int main()
{
	Image* img1 = Image::create("www.naver.com/a.png");
	img1->draw();

	Image* img2 = Image::create("www.naver.com/a.png");
	img2->draw();

}



