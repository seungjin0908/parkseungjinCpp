#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void GotoXY(int x, int y);


void main()
{
	// 과제 3
	// 학생부 만들기

	// 학생부 수도코드
	// 1. 학생수를 정한다. 간단하게 10명으로 정한다.
	// 2. 학생들의 영어, 수학, 국어 변수명을 정한다.
	// 3. 영어, 수학, 국어 점수의 총합을 구한다.
	// 4. 총합의 평균을 구한다.
	// 5. GotoXY를 이용해서 꾸면준다. (할 수 있으면)

	int Students = 10; // 학생수
	int English = 0; // 영어
	int Math = 0; // 수학
	int Korean = 0; // 국어
	int total = 0;

	cout << "학생수를 입력해주세요" << endl;
	cin >> Students;
	cout << "국어점수를 입력해주세요" << endl;
	cin >> Korean;
	cout << "영어점수를 입력해주세요" << endl;
	cin >> English;
	cout << "수학점수를 입력해주세요" << endl;
	cin >> Math;
}

void GotoXY(int x, int y)
{
	COORD pos = { x, y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//숙제3.
// 학생부 시스템
//1) 영어, 수학, 국어 성적 입력하게 끔해주고
//2) 입력을 모두했으면, 학생의 평균점수를 확인해주는 프로그램
// Gotoxy 써서 이쁘게하면 좋습니다.