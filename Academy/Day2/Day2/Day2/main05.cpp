#include <iostream>
using namespace std;

void main()
{
	//계산기 만들기
	// 내가 뭘해야할지 모르겠다.
	// 이프로그램의 Output(출력부분) 만 따라쳐보기.
	int result = 0;

	printf("숫자 1을 입력해주세요 : \n");
	printf("숫자 2를 입력해주세요 : \n");
	printf("어떤 연산을 진행할까요? : ( 1 : +, 2 : -, 3 : *, 4 : / ) \n");
	printf("결과 : %d\n", result);

	// 이후에는 입력해야할 내용을 변수로 선언하기.
	int num1 = 0;
	int num2 = 0;
	int choice = 0;

	// 입력해야하는 타이밍에 맞춰 scanf_s 함수를 쓰기.

	printf("숫자 1을 입력해주세요 : \n");
	scanf_s("%d", &num1);
	printf("숫자 2를 입력해주세요 : \n");
	scanf_s("%d", &num2);
	printf("어떤 연산을 진행할까요? : ( 1 : +, 2 : -, 3 : *, 4 : / ) \n");
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
	printf("결과 : %d\n", result);


	// 그 이후에 뭔가 잘모르겠으면 확인용도로 입력값을 확인해주는 출력문을 하나 하기.
	printf("입력값 확인용:: num1(%d), num2(%d), choice(%d)\n", num1, num2, choice);
}