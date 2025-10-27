#include <iostream>
class Animal
{
public:
	virtual ~Animal() {}  // ���� �Ҹ���..!! ���Ŀ� �ڼ��� ����
						  // �����Լ��� ������ "�����Լ� ���̺����"
						  // ���̺� �ȿ� Ÿ�� ���� ����
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
int main()
{
	Dog d;
	Animal a;

//	Animal* p = &d; // upcasting
	Animal* p = &a; // p�� ����Ű�� ���� Dog �ƴ� Animal

	// upcasting : �Ļ� Ŭ���� �ּҸ� ��� Ŭ���� �����ͷ� 
	// downcasting  : ��� Ŭ���� �ּҸ� �Ļ� Ŭ���� �����ͷ�!
	//				  �ݵ�� ����� ĳ���� �ʿ�

	// static_cast : ������ �ð� ĳ����
	// => �����Ϸ��� p�� ����Ű�� ���� Dog ���� �˼� ����
	// => ������ ����� ��û�̹Ƿ� "������ ���" �ؼ�
	//    �ּҸ� ��ȯ �Ѵ�.
	// => �̰�� p�� ����Ű�� ���� Dog �� �ƴ϶�� "pd->color = 10" ��
	//    �߸��� ����(����� å��)
	// Dog* pd = static_cast<Dog*>(p); 


	// dynamic_cast : ����ð� ĳ����
	// => p�� ����Ű�� ���� Dog �� �ƴ϶�� 0(nullptr) ��ȯ.
	// => p�� ����Ű�� ���� Dog �� �´� ��츸 �ּ� ��ȯ
	// => ��, ����Ϸ��� "�����Լ��� �Ѱ� �̻� �ִ� Ŭ����"�� ��밡��
	//    �����Լ� ���̺��� ����ؼ� Ÿ�� ������ �����ϹǷ�!

	Dog* pd = dynamic_cast<Dog*>(p);

	std::cout << pd << std::endl;
}











