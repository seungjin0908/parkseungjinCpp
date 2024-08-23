#include <iostream>

using namespace std;

//숫자야구 룰 
// 
// (3자리가 수월하면 4자리 숫자로 진행)
// 컴퓨터가 랜덤으로 겹치지 않는 3자리 숫자를 고른다. (이때 첫번째 자리는 무조건 1이상이어야함)
// ex. 777(x), 789(o), 154(o), 155(x), 014(x), 104(o)

// 플레이어는 1회, 2회, 3회 ... 9회까지 게임을 플레이한다.
// 플레이어는 회마다 겹치지 않는 숫자를 부른다. (이때 첫번째 자리는 무조건 1이상이어야함)
// ex. 777(x), 789(o), 154(o), 155(x), 014(x), 104(o)

// 자릿수와 숫자가 모두 일치하면 strike
// 숫자는일치하지만 자릿수가 일치하지 않으면 ball
// 을 카운트하여 현황판을 출력한다

// ex. 컴퓨터가 고른숫자 : 154
// ex. 플레이어가 부른숫자 : 149
//  ==> 1strike 1ball

// ex. 컴퓨터가 고른숫자 : 154
// ex. 플레이어가 부른숫자 : 501
//   ==> 0strike 2ball

// 승리조건 : 숫자를 맞추면 승리

void main()
{
	// 과제1 숫자야구 만들기

	// 숫자야구 수도코드
	// 플레이어 변수명을 정한다. int player
	// 컴퓨터 변수명을 정한다. int computer
	// 랜덤을 정한다.
	// 컴퓨터가 랜덤을 돌릴때 겹치지 않는 3자리 숫자를 고른다.
	// 컴퓨터가 랜덤으로 돌릴때 첫번째 자리는 무조건 1이상이어야 한다.
	// while문을 사용해서 9회까지 플레이를 한다.
	// 숫자 야구의 룰은 자릿수와 숫자가 모두 일치하면 스트라이크
	//  숫자는일치하지만 자릿수가 일치하지 않으면 볼
	// 카운트하여 결과를 출력한다.
	
	srand(time(NULL));

	int player = 0;

	int computerFirstnumber = 0;
	int computerSecondnumber = 0;
	int computerThirdnumber = 0;

	int firstNumber = 0;
	int secondNumber = 0;
	int thirdNumber = 0;

	int baseBallround = 0;

	while (player < 9)
	{
		
	}


	// 2중포문 별찍기
	for (int i = 0; i < 5; i++) // 예시
	{
		for (int j = 0; j < 5; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; i++) // 1번
	{
		for (int j = 0; j < 5; j++)
		{
			if (j <= i)
			{
				cout << "*";
			}
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; i++) // 2번
	{
		for (int j = 0; j < 5; j++)
		{
			if (i<=j)
			{
				cout << "*";
			}
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 5; i++) // 3번
	{
		for (int j = 5; j > 0; j--)
		{
			if (j <= i+1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 5; i++) // 4번
	{
		for (int j = 0; j < 5; j++)
		{
			if (i <= j)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	cout << endl;
}


// 2중 포문으로 만들기
// 1번
// *
// **
// ***
// ****
// *****

// 2번
// *****
// ****
// ***
// **
// *

// 3번
//     *
//    **
//   ***
//  ****
// *****

// 4번
// *****
//  ****
//   ***
//    **
//     *

// 5번
// *    *****
// **   ****
// ***  ***
// **** **
// ******
//     ******
//    ** ****
//   ***  ***
//  ****   **
// *****    *