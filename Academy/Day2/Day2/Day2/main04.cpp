#include <iostream>
using namespace std;

void main()
{
	//[TF ��]
	// ���α׷��ֿ��� ���� �߿�.
	// �׸��� ���� ���� �����.

	// IF���� ���� : ~~�ϸ� ~~�Ѵ�.
	// IF�����ʹ� ���� ���� �ٲܼ� ����. (�����ڵ�)
	// IF�� �����
	// 
	// if ( boolean)
	// {
	//    boolean�� true�� ������ ����
	// }

	bool check = true;

	int year = 2024;
	if (check)
	{
		printf("���ش� 2024�⵵ �Դϴ�.\n");
	}

	// [�񱳿�����]
	// ���� ����� ������
	// ��� �ʵ��б� ���нð��� �� ���.

	// >   (������ �� ũ��)
	// <   (�������� �� ũ��)
	// >= (������ �����ʺ��� ���ų� ũ��)
	// <= (�������� ���ʺ��� ���ų� ũ��)
	// == (���ʰ� �������� ������)
	// != (���ʰ� �������� �ٸ���)

	// �񱳿������� ����� �׻� boolean
	// ex. 1 > 2 (false)
	// ex. 1 < 2 (true)

	if (year != 2024)
	{
		printf("���ش� 2024�⵵ �Դϴ�.\n");
	}

	// [if else ��]
	// if ���弱
	// if ( boolean)
	// {
	//    boolean�� true�� ������ ����
	// }
	// else
	// {
	//     boolean�� false�� ������ ����
	// }

	int hp = 10;
	if (0 < hp)
	{
		printf("�� ������ ����ֽ��ϴ�.\n");
	}
	else
	{
		printf("�� ������ �׾����ϴ�.\n");
	}

	// [if esle if else ��]
	// if ���弱
	// if ( boolean )
	// {
	//    boolean�� true�� ������ ����
	// }
	// else if ( boolean2 )
	// {
	//     boolean �� false��,
	//     boolean2 �� false�� ������ ����
	// }
	// else
	// {
	//     boolean �� false��,
	//     boolean2 �� false�� ������ ����
	// }

	// �ѱ���� ����� Ǯ����.
	// 




	int score = 80;
	
	if (90 < score)
	{
		printf("�� �л��� A�����Դϴ�.\n");
	}
	else if (80 <= score)
	{
		printf("�� �л��� B�����Դϴ�.\n");
	}
	else if (70 <= score)
	{
		printf("�� �л��� C�����Դϴ�.\n");
	}
	else if (60 <= score)
	{
		printf("�� �л��� D�����Դϴ�.\n");
	}
	else
	{
		printf("�� �л��� F�����Դϴ�.\n");
	}

	// ������
	// +, -, *, /
	int result1 = 3 + 5;
	int result2 = 3 - 5;
	int result3 = 3 * 5;
	int result4 = 3 / (float)5;
	printf("result1 : %f\n", result1);
	printf("result2 : %f\n", result2);
	printf("result3 : %f\n", result3);
	printf("result4 : %f\n", result4);
}