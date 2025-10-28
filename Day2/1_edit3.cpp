// github.com / codenuri / dsdp ���� DAY2.zip ������  ���� Ǯ�� DAY2.sln ���� ���� Ŭ���Ͻø� �˴ϴ�.
//-------------------------------------------------
#include <iostream>
#include <string>
#include <conio.h>

// �ٽ� : Validation ��å�� ��ü �����ؾ� �մϴ�.

class Edit
{
	std::string data;
public:
	// ���뼺�� �������� �и�
	// => ������ ���� �ڵ� ���ο� �ִ� ���ؾ� �ϴ� �κ��� �и��Ǿ�� �Ѵ�.

	// ��� #1. ���ϴ� �κ��� ã�Ƽ� �����Լ��� �и��Ѵ�.

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

			if (validate(c)) // ���� ��ȿ�� Ȯ���� �����Լ��� ����.
			{
				data.push_back(c);
				std::cout << c;
			}
		}
		std::cout << '\n';
		return data;
	}
};
// �� ������ �ǵ�!!
// => validation ��å�� �����Ϸ���
// => �Ļ� Ŭ������ ���� ��ӵ� �����Լ��� override �϶�� ��

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


