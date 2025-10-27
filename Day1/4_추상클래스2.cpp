//1_추상클래스2.cpp
#include <iostream>


class Camera
{
public:	
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};


class People
{
public:	
	void use_camera(Camera* p) { p->take(); }
	void use_camera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc); // ok

}


// 위 코드는 OCP 를 위반한 안좋은 코드
// => 새로운 카메라 추가시
// => People 클래스가 수정됩니다.



