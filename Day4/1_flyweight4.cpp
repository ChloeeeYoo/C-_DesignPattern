#include <iostream>

int main()
{
	// 아래 2줄의 차이점은 ?
	char sa[] = "hello";	// 문자열 배열
//	char* sp = "hello";		// 문자열 포인터
							// 이 코드는 C:ok, C++:error

	const char* sp = "hello"; // C/C++ 모두 ok.. 

	*sa = 'x'; // ok
	*sp = 'x'; // C언어 : runtime error(char* sp 라면)
				// C++ : const char* sp 밖에 안됨. compile time error
}