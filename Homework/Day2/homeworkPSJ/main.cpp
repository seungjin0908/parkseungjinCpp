#include <iostream>
using namespace std;

void main()
{
	/*
 1. BMI ���� ���α׷� �����
 // ��¿���
	Ű(m)�� �Է����ּ���.
	������ (kg)�� �Է����ּ���.
	BMI ���� : 24.5
	��ü���Դϴ�. (0 ~ 18.5 ��ü��, ~ 23 ����ü��, ~25 ��ü�� , ~30 ��, ~ ���Ѵ� ����)
*/

/*
 2. ���� ����
 // ��¿���
 //	 �߰��� ������ �Է����ּ���.
 //	 �⸻�� ������ �Է����ּ���.
 //  �⼮������ �Է����ּ���.
 //  ���� ������ �Է����ּ���.
 // F�Դϴ�. (0 ~ 60 F, ~ 70 D, ~ 80 C, ~ 90 B, ~ 100 A)
*/

/*
3. Ȧ��¦�� �Ǻ���
 // ��� ����
 // ���ڸ� �Է����ּ���. [14]
 // 14�� ¦���Դϴ�.
*/

	float height = 0.0; // Ű
	float weight = 0.0; // ������
	float bmi = 0; 

	printf("Ű�� �Է����ּ���(m)\n");
	scanf_s("%f", &height);
	printf("�����Ը� �Է����ּ���(kg)\n");
	scanf_s("%f", &weight);

	height = height / 100;
	bmi = weight / (height * height);

	if (0 <= bmi && bmi < 18.5)
	{
		printf("��ü���Դϴ�.[%f] \n", bmi);
	}
	else if (bmi >= 18.5 && bmi < 23)
	{
		printf("����ü���Դϴ�.\n", bmi);
	}
	else if (bmi >=23 && bmi < 25)
	{
		printf("��ü���Դϴ�.\n", bmi);
	}
	else if (bmi >= 25 && bmi < 30)
	{
		printf("���Դϴ�.\n", bmi);
	}
	else
	{
		printf("�����Դϴ�.\n", bmi);
	}

	printf("===========================\n");

	int middlescore = 0; // �߰���� ����
	int finishscore = 0; // �⸻��� ����
	int total = 0; // ����
	int come = 0; // �⼮ ����
	int homework = 0; // ���� ����

	total = (middlescore + finishscore + come + homework);

	printf("�߰��� ������ �Է����ּ���\n");
	scanf_s("%d", &middlescore);
	printf("�⸻�� ������ �Է����ּ���\n");
	scanf_s("%d", &finishscore);
	printf("�⼮ ������ �Է����ּ���\n");
	scanf_s("%d", &come);
	printf("���� ������ �Է����ּ���\n");
	scanf_s("%d", &homework);

	if (total <= 60)
	{
		printf("F�Դϴ�.\n", total);
	}
	else if (total <= 70)
	{
		printf("D�Դϴ�.\n", total);
	}
	else if (total <= 80)
	{
		printf("C�Դϴ�.\n", total);
	}
	else if (total <= 90)
	{
		printf("B�Դϴ�.\n", total);
	}
	else if (total <= 100)
	{
		printf("A�Դϴ�.\n", total);
	}

	printf("============================\n");

	int number = 0;

	printf("���ڸ� �Է����ּ���\n");
	scanf_s("%d", &number);




}