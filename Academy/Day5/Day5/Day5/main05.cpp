#include <iostream>

using namespace std;

void main()
{
	// continue; break;

	// 반복문을 조금 윤택하게 사용하기위해 나온 문법
	
	// continue; => 이번분기를 스킵하고 계속 진행한다.
	// break; => 반복문을 종료한다.
	int arr[1000] = {};
	for (int i = 0; i < 1000; i++)
	{
		// i가 3의 배수만 특별하게 처리해주고 싶다.
		if (i % 3 == 0)
		{
			arr[i] = 1000 + i;
		}
	}

	// arr의 배열에서 3의 배수만 출력하고싶다.
	for (int i = 0; i < 1000; i++)
	{
		if (arr[i] % 3 != 0)
		{
			// 반복문 로직안에서 유효성체크할때 많이 쓰임.
			continue;
		}
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}

	// break;
	// 중간에 반복문을 나와버림.
	bool isEnd = false;
	while (isEnd == false)
	{
		for (int i = 0; i < 1000; i++)
		{
			if (i == 500)
			{
				break;
			}
			cout << i << endl;
		}
	}
}