#include <iostream>
using namespace std;

void main()
{
	//���� �����
	// ���� ���ؾ����� �𸣰ڴ�.
	// �����α׷��� Output(��ºκ�) �� �����ĺ���.
	int result = 0;

	printf("���� 1�� �Է����ּ��� : \n");
	printf("���� 2�� �Է����ּ��� : \n");
	printf("� ������ �����ұ��? : ( 1 : +, 2 : -, 3 : *, 4 : / ) \n");
	printf("��� : %d\n", result);

	// ���Ŀ��� �Է��ؾ��� ������ ������ �����ϱ�.
	int num1 = 0;
	int num2 = 0;
	int choice = 0;

	// �Է��ؾ��ϴ� Ÿ�ֿ̹� ���� scanf_s �Լ��� ����.

	printf("���� 1�� �Է����ּ��� : \n");
	scanf_s("%d", &num1);
	printf("���� 2�� �Է����ּ��� : \n");
	scanf_s("%d", &num2);
	printf("� ������ �����ұ��? : ( 1 : +, 2 : -, 3 : *, 4 : / ) \n");
	scanf_s("%d", &choice);
	if (choice == 1)
	{
		result = num1 + num2;
	}
	else if (choice == 2)
	{
		result = num1 - num2;
	}
	else if (choice == 3)
	{
		result = num1 * num2;
	}
	else if (choice == 4)
	{
		result = num1 / num2;
	}
	printf("��� : %d\n", result);


	// �� ���Ŀ� ���� �߸𸣰����� Ȯ�ο뵵�� �Է°��� Ȯ�����ִ� ��¹��� �ϳ� �ϱ�.
	printf("�Է°� Ȯ�ο�:: num1(%d), num2(%d), choice(%d)\n", num1, num2, choice);
}