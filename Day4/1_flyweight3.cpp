#include <iostream>
#include <string>
#include <map>
#include "singleton.h"

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}

public:
	void draw() { std::cout << "Draw " << image_url << std::endl; }


	friend class ImageFactory;  // friend class
								// => ImageFactory 는 Image 의 private
								//    접근할수 있게 해달라!
};

// SRP(단일 책임의 원칙) : 하나의 클래스는 하나의 책임만

// Image : 그림을 다운로드해서 그리고
// ImageFactory : Image 객체의 생성과 공유를 책임.

class ImageFactory
{
	MAKE_SINGLETON(ImageFactory)

	std::map<std::string, Image*> image_map;

public:
	Image* create(const std::string& url)
	{
		Image* img = nullptr;

		auto it = image_map.find(url);

		if (it != image_map.end())
		{
			img = it->second;
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
	ImageFactory& factory = ImageFactory::get_instance();

	Image* img1 = factory.create("www.naver.com/a.png");
	img1->draw();

	Image* img2 = factory.create("www.naver.com/a.png");
	img2->draw();

}



