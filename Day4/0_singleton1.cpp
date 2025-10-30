// github.com/codenuri/dsdp 에서 DAY4.zip 받으시면 됩니다.

#include <iostream>
#include <thread>

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	void operator=(const Cursor&) = delete; 
public:

	// 아래 코드는 멀티 스레드 환경에서 안전할까요 ?
	// => 아래 코드는 안전합니다.
	// => static 지역 객체의 생성자 호출은 멀티 스레드 환경에서 안전하다고 언어에서보장
	// => godbolt.org 에서 아래 코드 넣어 보세요
	//    (call    __cxa_guard_acquire 같은 코드가 동기화를 위한 기계어 코드)
	static Cursor& get_instance()
	{

		static Cursor instance;


		return instance;

	}

};


void foo()
{
	Cursor& c = Cursor::get_instance();
}

int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);

	t1.join();
	t2.join();
}


