// github.com / codenuri / dsdp 에서 DAY2.zip 받은후
// 압축 풀고 DAY2.sln 파일 더블 클릭하시면 됩니다.

#include <iostream>
#include <string>
#include <conio.h>

// 33page ~ 

class Edit
{
	std::string data;
public:
	std::string get_data()
	{
		std::cin >> data;
		return data;
	}
};

int main()
{
	Edit e;

	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


