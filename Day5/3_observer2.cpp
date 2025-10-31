#include <iostream>
#include <vector>

struct IGraph
{
	virtual void update(int data) = 0;
	virtual ~IGraph() {}
};

// 관찰자 패턴의 기본 로직은
// Table 의 데이타와 관련없이 항상 동일합니다.
// => 기반 클래스를 만들어서 제공하면 됩니다.
// => 디자인 패턴에서 "observer" 의 반대말(관찰의 대상)을 "subject" 라고합니다.

class Subject
{
	std::vector<IGraph*> v;
public:
	void attach(IGraph* p)
	{
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
public:
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





