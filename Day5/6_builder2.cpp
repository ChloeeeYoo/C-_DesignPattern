// Builder - 154
#include <iostream>
#include <string>

// �౸���� ĳ���͸� ������ ���ô�.
// ����, ������, �Źߵ��� �����Ҽ� �ֽ��ϴ�.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}��� ����

// ����, �Ź�, �������� ����� ���� �������� �޶�� �մϴ�.
struct IBuilder
{
	virtual Hat     make_hat() = 0;
	virtual Uniform make_uniform() = 0;
	virtual Shoes   make_shoes() = 0;

	virtual ~IBuilder() {}
};

class Director
{
	IBuilder* builder = nullptr;
public:
	void set_builder(IBuilder* b) { builder = b; }

	Character construct()
	{
		// ĳ���͸� ����� ������ ���� �մϴ�.
		Character c;
		c = c + builder->make_hat();
		c = c + builder->make_uniform();
		c = c + builder->make_shoes();
		return c;
	}
};

class Korean : public IBuilder
{
public:
	Hat     make_hat()     override { return Hat("��"); }
	Uniform make_uniform() override { return Uniform("�Ѻ�"); }
	Shoes   make_shoes()   override { return Shoes("¤��"); }
};

class American : public IBuilder
{
public:
	Hat     make_hat()     override { return Hat("�߱�����"); }
	Uniform make_uniform() override { return Uniform("�纹"); }
	Shoes   make_shoes()   override { return Shoes("����"); }
};

int main()
{
	Korean k;
	American a;
	Director d;
//	d.set_builder(&k); // <== ���� ������ �����ϸ� �̰��� ����
	d.set_builder(&a); 

	Character c = d.construct();
	std::cout << c << std::endl;

}
