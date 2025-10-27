#include <iostream>


// 카메라 제작자와 카메라 사용자가 지켜야하는 규칙을 먼저 설계합니다.
// 규칙 : 모든 카메라는 아래 클래스로 부터 파생되어야 한다.

class ICamera
{
public:
	virtual void take() = 0;
};

// 실제 카메라는 없지만 카메라를 사용하는 코드를 만들수 있습니다.
// => 규칙대로만 사용하면 됩니다.

class People
{
public:
	void use_camera(ICamera* p) { p->take(); }
};

// 이제 모든 카메라는 규칙을 지켜야 합니다.
class Camera : public ICamera
{
public:
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "Take UHD Picture" << std::endl; }
};


int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); 

	UHDCamera uhc;
	p.use_camera(&uhc); // ok.. 
						// People 이 수정되지 않아도 
						// 새로운 카메라 사용가능.
						// OCP 만족하는 좋은 코드
}




