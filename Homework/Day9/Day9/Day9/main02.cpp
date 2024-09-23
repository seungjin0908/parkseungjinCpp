#include <iostream>
using namespace std;

#define NUMBER_SIZE 3

int computerNumber[NUMBER_SIZE] = {};
int userNumber[NUMBER_SIZE] = {};
bool isUserNumberComplate = false;
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
	ChooseComputerNumber();
	for (int i = 0; i < 9; i++)
	{
		while (isUserNumberComplate == false)
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

		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
}

void ChooseUserNumber()
{

}

void CheckValidationUserNumber()
{

}

void CompareNumbers()
{

}

void PrintStrikeCount()
{

}

void InitUserVariable()
{

}
