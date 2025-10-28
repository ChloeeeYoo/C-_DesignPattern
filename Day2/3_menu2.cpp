#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 

// 객체지향 프로그램
// => 모든 것은 "객체" 이어야 한다.
// => 필요한 타입을 먼저 설계 한다.

class MenuItem
{
	std::string title;	
	int id;	
	// 복습할때 "단축키" 등도 추가해 보세요
public:
	MenuItem(const std::string& title, int id) : title(title), id(id) {}

	std::string get_title() { return title; }

	void command()
	{
		std::cout << get_title() << " 메뉴 선택됨\n";

		_getch(); // 잠시대기
	}
};
int main()
{
	MenuItem m1("김밥", 11);
	MenuItem m2("라면", 12);

	m1.command(); // 김밥 메뉴 선택시 호출될 함수
}




