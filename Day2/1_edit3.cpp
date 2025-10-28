// github.com / codenuri / dsdp 에서 DAY2.zip 받은후  압축 풀고 DAY2.sln 파일 더블 클릭하시면 됩니다.
//-------------------------------------------------
#include <iostream>
#include <string>
#include <conio.h>

// 핵심 : Validation 정책은 교체 가능해야 합니다.

class Edit
{
	std::string data;
public:
	// 공통성과 가변성의 분리
	// => 변하지 않은 코드 내부에 있는 변해야 하는 부분은 분리되어야 한다.

	// 방법 #1. 변하는 부분을 찾아서 가상함수로 분리한다.

	virtual bool validate(char c)
	{
		return true;
	}

	virtual bool is_complete(const std::string& s)
	{
		return true;
	}

	std::string get_data()
	{
		data.clear();

		while (true)
		{
			char c = _getch();

			if (c == 13 && is_complete(data) ) break;	// enter key

			if (validate(c)) // 값의 유효성 확인을 가상함수에 위임.
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};
// 위 설계의 의도!!
// => validation 정책을 변경하려면
// => 파생 클래스를 만들어서 약속된 가상함수를 override 하라는 것

class NumEdit : public Edit
{
public:
	bool validate(char c) override
	{
		return isdigit(c);
	}
};

int main()
{
//	Edit e;
	NumEdit e;
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


