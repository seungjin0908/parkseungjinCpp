﻿#include <iostream>

// 빙고판 수도코드
// 1. 빙고판의 배열은 5x5로 한다 (25)
// 2. 변수는 컴퓨터와 플레이어로 정한다. int player=0; int computer=0;
// 3. 컴퓨터는 랜덤으로 정한다.
// 4. 플레이어 한번 컴퓨터 한번 이런식으로 플레이를 한다.
// 5. 둘중에 하나라도 빙고3줄을 완성하면 게임은 종료된다. (가로,세로 대각선)



// 빙고판 과제는 추후에 하도록 하겠습니다.
// 이번에는 숫자야구 코드를 외우도록 하겠습니다.
using namespace std;

//매크로
#define NUMBER_SIZE 3
//#define DEV_MODE

//ctrl + r + r
int computerNumber[NUMBER_SIZE] = {};
int userNumber[NUMBER_SIZE] = {};
bool isUserNumberComplete = false;
int strike = 0;
int ball = 0;

// 함수전방선언
void ChooseComputerNumber();
void ChooseUserNumber();
void CheckValidationUserNumber();
void CompareNumbers();
void PrintStrikeBallCount();
void InitUserVariable();

void main() // 숫자야구 코드 외우기
{
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

		if (strike == NUMBER_SIZE)
		{
			break;
		}

		InitUserVariable();
	}
}

void ChooseComputerNumber()
{
	int arr[10] = {};
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < 10000; i++)  // 배열을 섞은다음에
	{
		int index1 = rand() % 10;
		int index2 = rand() % 10;

		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}

	if (arr[0] == 0)  // 첫번째자리가 0만안되게 잘뽑기
	{
		for (int i = 0; i < NUMBER_SIZE; i++)
		{
			computerNumber[i] = arr[9 - i];
		}
	}
	else
	{
		for (int i = 0; i < NUMBER_SIZE; i++)
		{
			computerNumber[i] = arr[i];
		}
	}

#ifdef DEV_MODE
	cout << "[디버깅용] 입력한 computerNumber : ";
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		cout << computerNumber[i];
	}
	cout << endl;
#endif
}

void ChooseUserNumber()
{
	int tempNumber;
	cout << "부를 숫자를 입력해주세요 : ";
	cin >> tempNumber;
	
	// 반복문으로 처리가능하겠다.
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		int length = NUMBER_SIZE - 1 - i;
		int divNumber = 1;
		for (int j = 0; j < length; j++)
		{
			divNumber *= 10;
		}
		userNumber[i] = tempNumber / divNumber % 10;
	}

#ifdef DEV_MODE
	cout << "[디버깅용] 입력한 userNumber : ";
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		cout << userNumber[i];
	}
	cout << endl;
#endif
}
void CheckValidationUserNumber()
{
	//userNumber[0] ~ userNumber[4]
	isUserNumberComplete = true;
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		int checkNumber1 = userNumber[i];
		for (int j = i + 1; j < NUMBER_SIZE; j++)
		{
			int checkNumber2 = userNumber[j];

			if (checkNumber1 == checkNumber2)
			{
				isUserNumberComplete = false;
			}
		}
	}

	//첫번째자릿수는 0이면 안됨.
	if (userNumber[0] == 0)
	{
		isUserNumberComplete = false;
	}
}

void CompareNumbers()
{
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		int currentComputerNumber = computerNumber[i];
		for (int j = 0; j < NUMBER_SIZE; j++)
		{
			int currentUserNumber = userNumber[j];

			if (currentComputerNumber == currentUserNumber)
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
	cout << strike << "스트라이크, " << ball << "볼!" << endl;
}

void InitUserVariable()
{
	for (int i = 0; i < NUMBER_SIZE; i++)
	{
		userNumber[i] = 0;
	}

	isUserNumberComplete = false;
	strike = 0;
	ball = 0;
}