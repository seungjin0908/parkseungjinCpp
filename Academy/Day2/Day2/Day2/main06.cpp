#include <iostream>
using namespace std;

void main()
{
	// ���α׷��� ���鶧,
	// Ȥ�� �Ϻ� ������ ���鶧

	// �����ϸ� �����ڵ带 ����.

	// ��Ʈ�� ���°� ����Ʈ��
	// ���� ��Ʈ�� �ȵ��ٴѴ�.
	// (��Ʈ�� ���� �����) �ּ����� ����

	int num1 = 0, num2 = 0, choice = 0;
	int result = 0;
	printf("���� 1�� �Է����ּ��� : \n");
	scanf_s("%d", &num1);
	printf("���� 2�� �Է����ּ��� : \n");
	scanf_s("%d", &num2);
	printf("� ������ �����ұ��? : ( 1 : +, 2 : -, 3 : *, 4 : / ) \n");
	scanf_s("%d", &choice);
	printf("��� : %\n", result);

	// �����ڵ�
	// ��� : "����1�� �Է����ּ���"
	// �Է� : num1 ����
	// ��� : "����2�� �Է����ּ���"
	// �Է� : num2 ����
	// ��� : "� ������ �����ұ��? : ( 1 : +, 2 : -, 3 : *, 4 : / ) \n");
	// �Է� : choice ����
	// 
	// ���� choice == 1 �̸�
	//		result = num1 + num2
	// �׷��� �ʰ� ���� choice == 2 �̸�
	//		result = num1 - num2
	// �׷��� �ʰ� ���� choice == 3 �̸�
	//		result = num1 * num2
	// �׷��� �ʰ� ���� choice == 4 �̸�
	//		result = num1 / num2
	//
	// ��� : ��� : result

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
}