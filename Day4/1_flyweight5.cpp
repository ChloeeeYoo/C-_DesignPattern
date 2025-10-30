#include <iostream>
#include <string>
#include <string_view>
int main()
{
	char sa1[] = "hello";
	char sa2[] = "hello";

	const char* sp1 = "hello";
	const char* sp2 = "hello";

	// 핵심 : 아래 코드의 결과(주소)예측해 보세요 ? 같은 주소 ? 다른주소
	printf("%p, %p\n", sa1, sa2); // 다른 주소
	printf("%p, %p\n", sp1, sp2); // 같은 주소

	std::string s = "hello";// 힙을 할당해서 "hello" 문자열 보관
							// 즉, 문자열을 소유

	std::string_view sv = "hello"; // sv 는 내부적으로 const char* 를 가짐
							// 즉, 상수 메모리에 있는 문자열 가리킴
	
	printf("%p\n", s.data());
	printf("%p\n", sv.data());
}

// 위 내용을 정확히 학습하려면

// => 실행 파일 포맷(PE, ELF) 학습
// => ".rodata" 학습해 보세요
// => 구글에서 "C .rodata" 검색...
// => .rodata => 상수 메모리를 의미 ( read only data)