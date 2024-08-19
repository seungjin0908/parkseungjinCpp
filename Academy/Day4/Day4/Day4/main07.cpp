#include <iostream>

using namespace std;

void main()
{
	// for문 + 배열
	int arr[10] = {};

	// 배열의 초기화
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	// 출력
	for (int i = 0; i < 10; i++)
	{
		//cout << "arr[" << i << "]" << arr[i] << endl;
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	// arr에 담긴 변수들 섞어보기.
	//
	srand(time(NULL));
	for (int i = 0; i < 100000; i++)
	{
		//인덱스를 2개 잡고 Swap
		int index1 = rand() % 10;
		int index2 = rand() % 10;

		// arr[index1] 과 arr[index2]의 변수를 swap
		int temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	// 반복문안에 반복문
	// 2중 for문

	// 왜 항상 i로 시작하나??
	for (int i = 0; i < 10; i++)
	{
		//알파벳상 i 다음으로 오는게 j
		for (int j = 0; j < 10; j++)
		{
			cout << "[" << i << " " << j << "]" << " ";
		}
		cout << endl;
	}

	// i가 0인상태로 첫 for-j 문을 시작
	// i가 0인상태로 j가 0~9까지 반복
	// i가 1이 됨.
	// i가 1인 상태로 for-j를 시작
	// i가 1인 상태로 j가 0~9를 반복
	//.
	//..
	//...
	// i가 9인 상태로 for-j를 시작하여 j가 0~9를 반복
}

// 숙제 2개
// 1번 숙제 : 로또번호 생성기
//	힌트 : 로또 통 lotto[45] 배열을 선언
//			이거를 섞어준후에, 7개를 뽑으면 됨.
// 2번 숙제 : 가위바위보 하나빼기

// 아직 좀 프로그래밍 어렵다고 느껴진다.
// 하면좋은거
// 가위바위보 코드외우기

// 프로그래밍 수업은 에피소드 형식이 아님.
// 한번 놓치면 계속 못따라옴.
// 10분내로 칠 수 있도록 외우기.
// 외움으로써 문법을 외우게됨.