//1_관찰자패턴1 - 97 page
#include <iostream>
#include <vector>

// 모든 그래프(챠트)의 인터페이스
struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}
};

class Table
{
	std::vector<IGraph*> v;
	int value; // table 의 data 값
public:
	void attach(IGraph* p) 
	{ 
		v.push_back(p); 
	}
	void detach(IGraph* p) 
	{
		v.erase( std::remove( v.begin(), v.end(), p), v.end() );
	}
	void notify(int data)
	{
		// 등록된 모든 그래프에 알려준다.
		for (auto p : v)
			p->update(data);
	}
	void edit()
	{
		while (1)
		{
			std::cout << "Data >>";
			std::cin >> value;

			// 데이타가 수정되었으므로 
			// 등록된 모든 관찰자(chart)에 통보 한다.
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
	Table table; // 관찰의 대상
	BarGraph bg;	
	PieGraph pg; // 관찰자(observer)

	// 관찰의 대상에 관찰자 연결
	table.attach(&bg);
	table.attach(&pg);

	// table 편집 모드
	table.edit();
}





