#include <iostream>
using namespace std;

void main()
{
	//[TF 문]
	// 프로그래밍에서 제일 중요.
	// 그리고 가장 많이 사용함.

	// IF문의 정의 : ~~하면 ~~한다.
	// IF문부터는 거의 말로 바꿀수 있음. (수도코드)
	// IF문 사용방법
	// 
	// if ( boolean)
	// {
	//    boolean이 true면 실행할 내용
	// }

	bool check = true;

	int year = 2024;
	if (check)
	{
		printf("올해는 2024년도 입니다.\n");
	}

	// [비교연산자]
	// 말이 어려운 말이지
	// 사실 초등학교 수학시간에 다 배움.

	// >   (왼쪽이 더 크면)
	// <   (오른쪽이 더 크면)
	// >= (왼쪽이 오른쪽보다 같거나 크면)
	// <= (오른쪽이 왼쪽보다 같거나 크면)
	// == (왼쪽과 오른쪽이 같으면)
	// != (왼쪽과 오른쪽이 다르면)

	// 비교연산자의 결과는 항상 boolean
	// ex. 1 > 2 (false)
	// ex. 1 < 2 (true)

	if (year != 2024)
	{
		printf("올해는 2024년도 입니다.\n");
	}

	// [if else 문]
	// if 연장선
	// if ( boolean)
	// {
	//    boolean이 true면 실행할 내용
	// }
	// else
	// {
	//     boolean이 false면 실행할 내용
	// }

	int hp = 10;
	if (0 < hp)
	{
		printf("이 유닛은 살아있습니다.\n");
	}
	else
	{
		printf("이 유닛은 죽었습니다.\n");
	}

	// [if esle if else 문]
	// if 연장선
	// if ( boolean )
	// {
	//    boolean이 true면 실행할 내용
	// }
	// else if ( boolean2 )
	// {
	//     boolean 이 false고,
	//     boolean2 이 false면 실행할 내용
	// }
	// else
	// {
	//     boolean 이 false고,
	//     boolean2 이 false면 실행할 내용
	// }

	// 한국어로 충분히 풀어짐.
	// 




	int score = 80;
	
	if (90 < score)
	{
		printf("이 학생은 A학점입니다.\n");
	}
	else if (80 <= score)
	{
		printf("이 학생은 B학점입니다.\n");
	}
	else if (70 <= score)
	{
		printf("이 학생은 C학점입니다.\n");
	}
	else if (60 <= score)
	{
		printf("이 학생은 D학점입니다.\n");
	}
	else
	{
		printf("이 학생은 F학점입니다.\n");
	}

	// 연산자
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