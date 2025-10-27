#include <iostream>

// 용어 정리
// 
// #1.
// 추상 클래스 : 지켜야 하는 규칙 + 다른 멤버도 있는 경우
// 인터 페이스 : 지켜야 하는 규칙 만 가진 경우
// java, C# : abstract, interface 라는 키워드 존재, 그래서 명확함.
// C++ : 키워드 없고, 단지, 추상클래스 안에 순수 가상함수만 있는가로 구별

// #2. coupling
// 강한결합(tightly coupling )
// => 하나의 클래스가 다른 클래스 사용시 클래스 이름을 직접 사용하는것
// => People:use_camera(HDCamera*)
// => 교체 불가능한 경직된 디자인

// 약한결합(loosely coupling )
// => 하나의 클래스가 다른 클래스 사용시 규칙을 담은 
//    인터페이스 이름을 통해서 사용하는것
// => People:use_camera(ICamera*)
// => 교체 가능한 유연한 디자인


//-------------------------------------------------------
// 규칙 : "모든 카메라는 아래 클래스로 부터 파생되어야 한다." 라고 표현하지 말고
//       "모든 카메라는 아래 인터페이스를 구현해야 한다" 라고 표현!

//class ICamera  // 접근 지정자 생략시 private 이 디폴트
struct ICamera   // 접근 지정자 생략시 public  이 디폴트
{
//public:
	virtual void take() = 0;
	virtual ~ICamera() {} // 인터페이스도 결국 문법적으로는 기반 클래스
						  // "항상 소멸자는 virtual" 을 잊지 마세요. 
};




class People
{
public:
	void use_camera(ICamera* p) { p->take(); }
};


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
	p.use_camera(&uhc); 
}




