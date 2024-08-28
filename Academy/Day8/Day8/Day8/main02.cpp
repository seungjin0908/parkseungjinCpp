#include <iostream>

using namespace std;

void main()
{
	// 숙제풀이
	// 하이로우 세븐

	// 1. 트럼프카드 정의하기
	// 2. 트럼프카드 출력하는거 구현하기
	// 3. 트럼프카드 섞어보기

	int card[52] = {};
	
	for (int i = 0; i < 52; i++)
	{
		card[i] = i;
	}

	cout << "0번째 트럼프카드 : " << endl;
	cout << card[0] << endl;
	
	switch (card[0] / 13)
	{
	case0:
		cout << "♤";
		break;
	case1:
		cout << "◆";
		break;
	case2:
		cout << "♥";
		break;
	case3:
		cout << "♧";
		break;
	default:
		break;
	}

	switch (card[0] % 13 + 1)
	{

	}
}