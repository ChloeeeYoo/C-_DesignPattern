// 6_Bridge1 - 90 page
#include <iostream>

class IPod 
{
public:
	void play() { std::cout << "Play MP3 with IPod" << std::endl; }
	void stop() { std::cout << "Stop" << std::endl; }
};

class People
{
public:
	void use(IPod* p)
	{
		p->Play();
		p->Stop();
	}
};
int main()
{
	People p;
	IPod pod;
	p.Use(&pod);
}


