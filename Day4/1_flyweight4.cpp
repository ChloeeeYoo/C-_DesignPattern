#include <iostream>

int main()
{
	// �Ʒ� 2���� �������� ?
	char sa[] = "hello";	// ���ڿ� �迭
//	char* sp = "hello";		// ���ڿ� ������
							// �� �ڵ�� C:ok, C++:error

	const char* sp = "hello"; // C/C++ ��� ok.. 

	*sa = 'x'; // ok
	*sp = 'x'; // C��� : runtime error(char* sp ���)
				// C++ : const char* sp �ۿ� �ȵ�. compile time error
}