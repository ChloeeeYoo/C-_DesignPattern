// github.com/codenuri/dsdp 
#include <iostream>

// chain of responsibility - 166
// => 책임의 고리(전가)
// => 발생된문제(이벤트, 사건)을 하나의 객체만 처리하지 않고
//    여러객체가 고리로 연결되어서 처리하는 것

// 책임의 고리 패턴의 흐름
// 1. 자신이 먼저 문제 해결을 시도
// 2. 문제를 해결하지 못한경우, 다른객체에 전달

// => 문제를 해결하는 모든 팀은, 위와 동일한 로직 사용
// => 하지만 문제 해결방법은 다름


struct Handler
{
	Handler* next = nullptr;

	Handler* set_next(Handler* n) 
	{ 
		next = n; 
		return next; 
	}

	// 책임의 고리 패턴의 핵심 코드 
	// => 아래 코드만 정확히 이해 하면 됩니다.
	void handle(int problem)
	{
		// #1. 자신이 먼저 처리를 시도
		if (resolve(problem) == true)
			return;

		// #2. 문제를 해결하지 못한 경우, 옆팀이 있다면 전달
		if (next != nullptr )
			next->handle(problem);
	}

	virtual bool resolve(int problem) = 0;
};
//------------------------------------
class Team1 : public Handler
{
public:
	bool resolve(int problem) override
	{
		std::cout << "start Team1\n";

		if (problem == 7)
		{
			std::cout << "Team1 : Resolve the Problem\n";
			return true;
		}
		return false;
	}
};

class Team2 : public Handler
{
public:
	bool resolve(int problem) override
	{
		std::cout << "start Team2\n";

		if (problem % 2 ==  0)
		{
			std::cout << "Team2 : Resolve the Problem\n";
			return true;
		}
		return false;
	}
};

class Team3 : public Handler
{
public:
	bool resolve(int problem) override
	{
		std::cout << "start Team3\n";

		if (problem > 10)
		{
			std::cout << "Team3 : Resolve the Problem\n";
			return true;
		}
		return false;
	}
};

int main()
{
	Team1 t1;
	Team2 t2;
	Team3 t3;

	// t1 => t2 => t3 순서로 연결
	t1.set_next(&t2)->set_next(&t3);

	// 1번째 팀에게 문제 전달
//	t1.handle(7);	// Team1 이 해결
//	t1.handle(8);	// Team1 => Team2 이 해결
//	t1.handle(13);	// Team1 => Team2 => Team3 이 해결
	t1.handle(9);	// Team1 => Team2 => Team3... 아무도 해결 못함
}
// 핵심
// => 하나에 문제(이벤트)에 대한 해결을
// => 여러 객체에서 처리하게 한다.
// => 문제를 해결하는 객체들의 순서도 변경 가능하다.
