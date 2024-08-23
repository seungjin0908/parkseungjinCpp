#include <iostream>
using namespace std;

// 매크로
#define NUMBER_SIZE 4
#define DEV_MODE
#define RELEASE_MODE
#define STEEL_CONTENTS
// 해적질 컨텐츠가 이번 개발로 추가가 된다.
// 작업하다가

// 갑자기 당일날 해적질 컨텐츠가 안들어가게 됐음.

int size = 4;
// ctrl + r + r
int computerNumber[4] = {};
int userNumber[4] = {};
bool  isUserNumberComplete = false;
int strike = 0;
int ball = 0;
// 함수전방선언
void ChooseComputerNumber();
void ChooseUserNumber();
void CompareNumbers();
void CheckValidationUserNumber();
void PrintStrikeBallCount();
void InitUserVaribale();
void main()
{
	// 숫자야구 (4자리)
	// 수도코드
	// 
	// 가장 간단한 룰
	// 
	// 1. 컴퓨터가 랜덤숫자를 뽑는다. (4자리)
	// 2. 유저가 랜덤숫자를 외친다.
	// 3. 그 외친숫자가 올바른 숫자인지 판단한다.
	// 4. 올바른 숫자라면 5번으로, 올바르지 않은 숫자라면 2번으로 간다.
	// 5. 외친숫자와 컴퓨터가 정한 숫자를 비교하여 스트라이크, 볼을 체크한다.

	// 가장간단한 룰 형태를 함수로 바꾸기
	// 1. ChooseComputerNumber();
	// 2. ChooseUserNumber();
	// 3. CheckValidationUserNumber();
	// 4.  - 
	// 5. CompareNumbers();
	// 6. PrintStrikeBallCount();

	srand(time(NULL));
	ChooseComputerNumber();
	for (int i = 0; i < 9; i++)
	{
		while (isUserNumberComplete == false)
		{
			ChooseUserNumber();
			CheckValidationUserNumber();
		}
		CompareNumbers();
		PrintStrikeBallCount();

		if (strike == 4)
		{
			break;
		}

		InitUserVaribale();
	}
}

void ChooseComputerNumber()
{
	cout << "Call ChooseComputerNumber" << endl;
	// 컴퓨터가 랜덤숫자를 뽑는다. (4자리)
	// 이 기능에 대한 수도코드
	// 랜던숫자를 뽑는 방법

	int arr[10] = {};
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < 10000; i++)
	{
		int index1 = rand() % 10;
		int index2 = rand() % 10;

		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}

	// 첫번째자리가 0만안되게 잘뽑기
	if (arr[0] == 0)
	{
		computerNumber[0] = arr[9];
		computerNumber[1] = arr[8];
		computerNumber[2] = arr[7];
		computerNumber[3] = arr[6];
		for (int i = 0; i < 4; i++)
		{
			computerNumber[i] = arr[i];
		}
	}
}
void ChooseUserNumber()
{
	int tempNumber;
	cout << "부를 숫자를 입력해주세요 : ";
	cin >> tempNumber;
	userNumber[0] = tempNumber / 1000;
}
void CheckValidationUserNumber()
{
	// 1. 각자릿수별로 for문을 돈다.
	// 2. 각 자리에서 그 다음자릿수들을 for문을 또 돈다.

	for (int i = 0; i < 4; i++)
	{
		int checkNumber1 = userNumber[i];
		for (int j = i + 1; j < 4; j++)
		{
			int checkNumber2 = userNumber[j];

			if (checkNumber1 == checkNumber2)
			{
				isUserNumberComplete = false;
			}
		}
	}

	if (userNumber[0] == 0)
	{
		isUserNumberComplete = false;
	}
}
void CompareNumbers()
{
	// computerNuber를 순회하고 => 이 변수를 currentComputerNumber
	// userNumber를 순회한다. => 이 변수를 currentUserNumber
	// 만약 currentComputerNumber == currentUserNumber 이면
	//		만약 computerNumber를 순회한 인덱스와 같다면
	//			strike++;
	//		그렇지 않으면
	//			ball++;

	for (int i = 0; i < 4; i++)
	{
		int curentComputerNumber = computerNumber[i];
		for (int j = 0; j < 4; j++)
		{
			int currentUserNumber = userNumber[j];

			if (curentComputerNumber == currentUserNumber)
			{
				if (i == j)
				{
					strike++;
				}
				else
				{
					ball++;
				}
			}
		}
	}
}
void PrintStrikeBallCount()
{

}

void InitUserVaribale()
{

}