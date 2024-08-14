#include <iostream>

using namespace std;

void main()
{
	// 수도코드
	// [출력] 중간평가 점수를 입력해주세요.
	// [입력] middleScore
	// [출력] 기말평가 점수를 입력해주세요.
	// [입력] finalScore
	// [출력] 출석 점수를 입력해주세요.
	// [입력] attendanceScore
	// [출력] 과제 점수를 입력해주세요.
	// [입력] homeworkScore
	// [연산] totalScore = middleScore + finalScore + attendanceScore + homeworkScore
	// if ( totalScore <= 60 )

	int middleScore = 0;
	int finalScore = 0;
	int attendanceScore = 0;
	int homeworkScore = 0;
	int totalScore = 0;
	printf("중간평가 점수를 입력해주세요\n");
	scanf_s("%d", &middleScore);
	printf("기말평가 점수를 입력해주세요\n");
	scanf_s("%d", &finalScore);
	printf("출석 점수를 입력해주세요\n");
	scanf_s("%d", &attendanceScore);
	printf("과제 점수를 입력해주세요\n");
	scanf_s("%d", &homeworkScore);


}