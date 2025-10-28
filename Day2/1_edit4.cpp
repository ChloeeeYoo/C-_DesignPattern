#include <iostream>
#include <string>
#include <conio.h>

// ���ϴ� ���� �и��ϴ� 2���� ���
// #1. ���ϴ� ���� �����Լ��� �и� - Edit3.cpp, template method
// #2. ���ϴ� ���� �ٸ� Ŭ������ - Edit4.cpp.   strategy

// ��� Validator �� ��Ģ�� ���� �������̽�
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;	
	virtual bool is_complete(const std::string& s) { return true; }
};
// �ֹε�� ��ȣ : 901  1   Ȯ�� 

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

			if (validator == nullptr || validator->validate(data, c)) // ��ȿ�� ���縦 ���� ��ü�� ����
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};

// ���� �Է°��� ��ȿ���� Ȯ���ϴ� �پ��� ������ validator �� �����ϸ�˴ϴ�.
// => �ֹ� ��ȣ validator,�̸��� validator, ��ȭ��ȣ validator ��..

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


