#include <iostream>
#include <vector>

class Subject;	// 완전한 클래스 선언이 없어도 포인터 변수 생성 가능

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}

	// 관찰자(그래프)도 대상체(TAble)의 포인터가 있어야
	// => 그래프를 그리기위한 데이타를 얻을수 있습니다.
	Subject* subject = nullptr;
};


class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p)
	{
		p->subject = this;
		v.push_back(p);
	}
	void detach(IGraph* p)
	{
		v.erase(std::remove(v.begin(), v.end(), p), v.end());
	}
	void notify(int data)
	{
		for (auto p : v)
			p->update(data);
	}
};

class Table : public Subject
{
	int value;
	
	// 이제 Table에는 많은 데이타가 있습니다.
	int data[5] = { 1,2,3,4,5 };
public:
	int* get_data() { return data; }

	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;
			notify(value);
		}
	}
};



//----------------------
class BarGraph : public IGraph
{
public:
	void update(int n) override
	{
		// Table 에 변경이 있다고 통보가 왔으므로
		// => Table에 모든 데이타를 가져 와서 다시 그려야 한다.

	//	int* data = subject->get_data(); // error
					// subject 가 Table을 가리키느 것은 맞지만
					// 포인터 타입이 Subject 이므로
					// Table 고유 멤버 접근 안됨. 캐스팅 필요

		// QT : signal/slot
		// MFC : Doc/View
		// Java : MVC 
		// => 등의 기술이 모두 observer 패턴의 응용입니다.
		// => 그런데, 항상 이런 기술을 사용하다 보면 아래 처럼 캐스팅 등장합니다
		//    약간의 단점!!

		Table* table = static_cast<Table*>(subject);

		int* data = table->get_data();




		// 이제 data 내용으로 그림을 그리면 됩니다.

		std::cout << "Bar Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "*";

		std::cout << std::endl;
	}
};




class PieGraph : public IGraph
{
public:
	void update(int n) override
	{
		std::cout << "Pie Graph : ";

		for (int i = 0; i < n; i++)
			std::cout << "(";

		std::cout << std::endl;
	}
};

int main()
{
	Table table;
	BarGraph bg;
	PieGraph pg;

	table.attach(&bg);
	table.attach(&pg);

	table.edit();
}





