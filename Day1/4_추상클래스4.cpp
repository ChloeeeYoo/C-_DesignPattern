#include <iostream>

// ��� ����
// 
// #1.
// �߻� Ŭ���� : ���Ѿ� �ϴ� ��Ģ + �ٸ� ����� �ִ� ���
// ���� ���̽� : ���Ѿ� �ϴ� ��Ģ �� ���� ���
// java, C# : abstract, interface ��� Ű���� ����, �׷��� ��Ȯ��.
// C++ : Ű���� ����, ����, �߻�Ŭ���� �ȿ� ���� �����Լ��� �ִ°��� ����

// #2. coupling
// ���Ѱ���(tightly coupling )
// => �ϳ��� Ŭ������ �ٸ� Ŭ���� ���� Ŭ���� �̸��� ���� ����ϴ°�
// => People:use_camera(HDCamera*)
// => ��ü �Ұ����� ������ ������

// ���Ѱ���(loosely coupling )
// => �ϳ��� Ŭ������ �ٸ� Ŭ���� ���� ��Ģ�� ���� 
//    �������̽� �̸��� ���ؼ� ����ϴ°�
// => People:use_camera(ICamera*)
// => ��ü ������ ������ ������


//-------------------------------------------------------
// ��Ģ : "��� ī�޶�� �Ʒ� Ŭ������ ���� �Ļ��Ǿ�� �Ѵ�." ��� ǥ������ ����
//       "��� ī�޶�� �Ʒ� �������̽��� �����ؾ� �Ѵ�" ��� ǥ��!

//class ICamera  // ���� ������ ������ private �� ����Ʈ
struct ICamera   // ���� ������ ������ public  �� ����Ʈ
{
//public:
	virtual void take() = 0;
	virtual ~ICamera() {} // �������̽��� �ᱹ ���������δ� ��� Ŭ����
						  // "�׻� �Ҹ��ڴ� virtual" �� ���� ������. 
};




class People
{
public:
	void use_camera(ICamera* p) { p->take(); }
};


class Camera : public ICamera
{
public:
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() { std::cout << "Take UHD Picture" << std::endl; }
};


int main()
{
	People p;

	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc);

	UHDCamera uhc;
	p.use_camera(&uhc); 
}




