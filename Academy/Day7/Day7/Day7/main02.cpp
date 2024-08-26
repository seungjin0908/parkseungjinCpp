#include <iostream>

using namespace std;

int myBingo[25] = {};
int comBingo[25] = {};
int calledNumber = 0;
int turn = 0;
int myBingCount = 0;
int comBingCount = 0;
bool isGamePlaying = true;

void MakeBoard();
void ShuffleBoard();
void PrintBoard();
void CallBingoNumber();
void MarkBingoNumber();
void GoToNextTurn();
void checkBingoCount();

void main()
{
	// 빙고

	// 빙고의 수도코드
	// 1. 내 빙고판과 컴퓨터 빙고판 정의
	// myBingo[25] = {1 ~ 25} , comBingo[25] = {1 ~ 25}
	// 2. 빙고판 셔플 (나, 컴퓨터)
	// 3. 빙고판을 출력 (나, 컴퓨터)
	// [내턴]
	// 4. 내가 숫자를 하나 부른다.
	// 5. 그 숫자를 내 빙고판과, 컴퓨터 빙고판에서 숫자를 -1로 대체한다.
	// (-1이 삭제라고 우리끼리 룰을 정한거임.)
	// 6. 컴퓨터가 숫자를 하나 부른다.
	// 7. 그 숫자를 내 빙고판과, 컴퓨터 빙고판에서 숫자를 -1로 대체한다.
	// (-1이 삭제라고 우리끼리 룰을 정한거임.)
	// 8. 4번으로 돌아가서 내용을 반복한다.
	
	srand(time(NULL));
	// 1. 내 빙고판과 컴퓨터 빙고판 정의
	MakeBoard();
	// 2. 빙고판 셔플. (나, 컴퓨터)
	ShuffleBoard();
	while (true)
	{
		// 3. 빙고판을 출력 (나, 컴퓨터)
		PrintBoard();
		// 4. 내가 숫자를 하나 부른다.
		CallBingoNumber();
		// 5. 그 숫자를 내 빙고판과, 컴퓨터 빙고판에서 숫자를 -1로 대체한다.
		MarkBingoNumber();
		// 6. 턴 변경
		GoToNextTurn();

		// 7. 빙고카운트 체크
		checkBingoCount();
		// 8. 내 빙고카운트가 3이상이면 내가 승리, 게임종료

		if (myBingCount == 3)
		{
			cout << "나의 승리!" << endl;
			cout << "게임종료" << endl;
			exit(0);
		}
		// 9. 상대방 빙고카운트가 3이상이면 컴퓨터가 승리, 게임종료

		if (comBingCount == 3)
		{
			cout << "나의 승리!" << endl;
			cout << "게임종료" << endl;
			exit(0);
		}
	}
}

// 1. 내 빙고판과 컴퓨터 빙고판 정의
void MakeBoard()
{
	cout << "내 빙고판과 컴퓨터 빙고판 정의" << endl;

	// 수도코드
	// myBingo, comBingo를 for를 써서 1-25까지 초기화

	// 내 빙고판 초기화
	for (int i = 0; i < 25; i++)
	{
		myBingo[i] = i + 1;
	}

	// 컴퓨터 빙고판 초기화
	for (int i = 0; i < 25; i++)
	{
		comBingo[i] = i + 1;
	}
}

// 2. 빙고판 셔플. (나, 컴퓨터)
void ShuffleBoard()
{
	cout << "빙고판 셔플.(나, 컴퓨터)" << endl;

	for (int i = 0; i < 10000; i++)
	{

	}
}

// 3. 빙고판을 출력 (나, 컴퓨터)
void PrintBoard()
{
	cout << "빙고판을 출력 (나, 컴퓨터)" << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			//[i,j]
			// i => 세로줄
			// j => 가로줄
			// 세로줄인덱스 * 가로길이 + 가로줄인덱스
			if (myBingo[i * 5 + j] == -1)
			{
				cout << "xx\t";
			}
			else
			{
				cout << myBingo[i * 5 + j] << "\t";
			}
		}
		cout << endl;
	}

	cout << "상대 빙고판 " << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << comBingo[i * 5 + j] << "\t";
		}
		cout << endl;
	}
}

// 4. 내가 숫자를 하나 부른다.
void CallBingoNumber()
{
	cout << "내가 숫자를 하나 부른다." << endl;

	cout << "[" << turn << "] 번째 턴!" << endl;

	if (turn % 2 == 1)
	{
		cout << "빙고 숫자를 입력해주세요." << endl;

		int input;
		cin >> input;

		calledNumber = input;
	}
	else
	{
		// 상대가 숫자부르는 로직 수도코드
		// 일단 간단하게
		calledNumber = rand() % 25 + 1;
	}

	cout << "불린 숫자 : " << calledNumber << endl;
}

// 5. 그 숫자를 내 빙고판과, 컴퓨터 빙고판에서 숫자를 -1로 대체한다.
void MarkBingoNumber()
{
	cout << "그 숫자를 내 빙고판과, 컴퓨터 빙고판에서 숫자를 -1로 대체한다." << endl;

	// 수도코드
	// 내 빙고판에서 calledNumber가 있는지 체크
	// 있으면 -1로 수정

	// 내 빙고판에서 calledNumber가 있는지 없는지 체크는 하나씩 비교하면 됨.

	for (int i = 0; i < 25; i++)
	{

	}
}

// 6. 턴 변경
void GoToNextTurn()
{
	cout << "턴 변경" << endl;
}

void chekcBingCount()
{
	cout << "빙고갯수 체크" << endl;

	// 가로줄 체크
	// 세로줄 체크
	// 대각선 / 방향
	// 대각선 \ 방향
	myBingCount = 0;

	// 내 빙고판 체크
	// -1이 마크된것.
	// 가로줄을 쭉 체크했을때, -1인지.

	// 가로줄 체크
	for (int i = 0; i < 5; i++)
	{
		bool isBingoLine = true;

		for (int j = 0; j < 5; j++)
		{
			if (myBingo[i * 5 + j] != -1)
			{
				isBingoLine = false;
			}
		}

		if (isBingoLine)
		{
			myBingCount++;
		}
	}

	// 세로줄 체크
	for (int i = 0; i < 5; i++)
	{
		bool isBingoLine = true;

		for (int j = 0; j < 5; j++)
		{
			if (myBingo[j * 5 + i] != -1)
			{
				isBingoLine = false;
			}
		}

		if (isBingoLine)
		{
			myBingCount++;
		}
	}

	{
		bool isBingoLine = true;
		for (int i = 0; i < 5; i++)
		{
			if (myBingo[i * 5 + i] != -1)
			{
				isBingoLine = false;
			}
		}
		if (isBingoLine)
		{
			myBingCount++;
		}
	}

	cout << "내 빙고카운트 : " << myBingCount << endl;
}