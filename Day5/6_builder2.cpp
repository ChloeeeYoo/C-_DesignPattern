// Builder - 154
#include <iostream>
#include <string>

// 축구게임 캐릭터를 생각해 봅시다.
// 모자, 유니폼, 신발등을 변경할수 있습니다.
typedef std::string Hat;			// class Hat{}
typedef std::string Uniform;	    // class Uniform{}
typedef std::string Shoes;			// class Shoes{}
typedef std::string Character;		// class Character{}라고 가정

// 모자, 신발, 유니폼을 만드는 것은 국가별로 달라야 합니다.
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
		// 캐릭터를 만드는 공정은 동일 합니다.
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
	Hat     make_hat()     override { return Hat("갓"); }
	Uniform make_uniform() override { return Uniform("한복"); }
	Shoes   make_shoes()   override { return Shoes("짚신"); }
};

class American : public IBuilder
{
public:
	Hat     make_hat()     override { return Hat("야구모자"); }
	Uniform make_uniform() override { return Uniform("양복"); }
	Shoes   make_shoes()   override { return Shoes("구두"); }
};

int main()
{
	Korean k;
	American a;
	Director d;
//	d.set_builder(&k); // <== 국가 선택을 변경하면 이곳을 변경
	d.set_builder(&a); 

	Character c = d.construct();
	std::cout << c << std::endl;

}
