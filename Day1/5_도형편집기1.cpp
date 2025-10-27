#include <iostream>
#include <vector>

// 가상함수에 대한 예제

// 파워 포인트 같은 프로그램을 객체지향으로 설계해 봅시다.

// 핵심 #1. 모든 도형을 타입으로 설계하면 편리합니다.
// 핵심 #2. 모든 도형의 공통의 기반 클래스가 있다면
// => 공통의 특징을 한곳에서 관리할수 있고
// => 모든 도형을 하나의 컨테이너에 보관할수 있다.

class Shape
{
	int color;
public:
	virtual ~Shape() {}
};
class Rect : public Shape
{
	// int x, y, w, h, 생성자등은 생략
public:
	void draw() { std::cout << "draw rect\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n"; }
};

int main()
{
	std::vector<Rect*>  v1; // Rect 객체만 보관 가능
	std::vector<Shape*> v2; // 모든 도형을 보관 가능
}


