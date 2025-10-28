#include <iostream>
#include <string>
#include <conio.h>

// 변하는 것을 분리하는 2가지 기술
// #1. 변하는 것을 가상함수로 분리 - Edit3.cpp, template method
// #2. 변하는 것을 다른 클래스로 - Edit4.cpp.   strategy

// 모든 Validator 의 규칙을 담은 인터페이스
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;	
	virtual bool is_complete(const std::string& s) { return true; }
};
// 주민등록 번호 : 901  1   확인 

class Edit
{
	std::string data;

	IValidator* validator = nullptr;
public:
	void set_validator(IValidator* v) { validator = v; }

	std::string get_data()
	{
		data.clear();
		while (true)
		{
			char c = _getch();

			if (c == 13 && (validator == nullptr || validator->is_complete(data)) ) break;

			if (validator == nullptr || validator->validate(data, c)) // 유효성 조사를 위부 객체에 위임
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// 이제 입력값의 유효성을 확인하는 다양한 종류의 validator 를 제공하면됩니다.
// => 주민 번호 validator,이메일 validator, 전화번호 validator 등..

class LimitDigitValidator : public IValidator
{
	int value;
public:
	LimitDigitValidator(int n) : value(n) {}

	bool validate(const std::string& s, char c) override
	{
		return isdigit(c) && s.size() < value;
	}
	bool is_complete(const std::string& s) override 
	{ 
		return s.size() == value;
	}
};
int main()
{
	Edit e;
	LimitDigitValidator v(5);
	e.set_validator(&v);

	LimitDigitValidator v2(15);
	e.set_validator(&v2);

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


