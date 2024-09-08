#include <iostream>

using namespace std;

#define NUMBER_SIZE 3

int computerNumber[NUMBER_SIZE] = {};
int userNumber[NUMBER_SIZE] = {};
bool isUserNumberComplete = false;
int strike = 0;
int ball = 0;

void ChooseComputerNumber();
void ChooseUserNumber();
void CheckValidationUserNumber();
void CompareNumbers();
void PrintStrikeBallCount();
void InitUserVariable();

void main()
{
	srand(time(NULL));
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

	for (int i = 0; i < 10000; i++)
	{
		int index1 = rand() % 10;
		int index2 = rand() % 10;

		int temp = index2;
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}

	if (arr[0] == 0)
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