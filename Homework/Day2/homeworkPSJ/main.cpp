#include <iostream>
using namespace std;

void main()
{
	/*
 1. BMI 측정 프로그램 만들기
 // 출력예시
	키(m)를 입력해주세요.
	몸무게 (kg)을 입력해주세요.
	BMI 지수 : 24.5
	과체중입니다. (0 ~ 18.5 저체중, ~ 23 정상체중, ~25 과체중 , ~30 비만, ~ 무한대 고도비만)
*/

/*
 2. 학점 계산기
 // 출력예시
 //	 중간평가 점수를 입력해주세요.
 //	 기말평가 점수를 입력해주세요.
 //  출석점수를 입력해주세요.
 //  과제 점수를 입력해주세요.
 // F입니다. (0 ~ 60 F, ~ 70 D, ~ 80 C, ~ 90 B, ~ 100 A)
*/

/*
3. 홀수짝수 판별기
 // 출력 예시
 // 숫자를 입력해주세요. [14]
 // 14는 짝수입니다.
*/

	float height = 0.0; // 키
	float weight = 0.0; // 몸무게
	float bmi = 0; 

	printf("키를 입력해주세요(m)\n");
	scanf_s("%f", &height);
	printf("몸무게를 입력해주세요(kg)\n");
	scanf_s("%f", &weight);

	height = height / 100;
	bmi = weight / (height * height);

	if (0 <= bmi && bmi < 18.5)
	{
		printf("저체중입니다.[%f] \n", bmi);
	}
	else if (bmi >= 18.5 && bmi < 23)
	{
		printf("정상체중입니다.\n", bmi);
	}
	else if (bmi >=23 && bmi < 25)
	{
		printf("과체중입니다.\n", bmi);
	}
	else if (bmi >= 25 && bmi < 30)
	{
		printf("비만입니다.\n", bmi);
	}
	else
	{
		printf("고도비만입니다.\n", bmi);
	}

	printf("===========================\n");

	int middlescore = 0; // 중간고사 점수
	int finishscore = 0; // 기말고사 점수
	int total = 0; // 총합
	int come = 0; // 출석 점수
	int homework = 0; // 과제 점수

	total = (middlescore + finishscore + come + homework);

	printf("중간평가 점수를 입력해주세요\n");
	scanf_s("%d", &middlescore);
	printf("기말평가 점수를 입력해주세요\n");
	scanf_s("%d", &finishscore);
	printf("출석 점수를 입력해주세요\n");
	scanf_s("%d", &come);
	printf("과제 점수를 입력해주세요\n");
	scanf_s("%d", &homework);

	if (total <= 60)
	{
		printf("F입니다.\n", total);
	}
	else if (total <= 70)
	{
		printf("D입니다.\n", total);
	}
	else if (total <= 80)
	{
		printf("C입니다.\n", total);
	}
	else if (total <= 90)
	{
		printf("B입니다.\n", total);
	}
	else if (total <= 100)
	{
		printf("A입니다.\n", total);
	}

	printf("============================\n");

	int number = 0;

	printf("숫자를 입력해주세요\n");
	scanf_s("%d", &number);




}