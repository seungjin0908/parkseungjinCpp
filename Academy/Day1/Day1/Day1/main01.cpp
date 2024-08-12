#include <iostream>

using namespace std;

void main()
{
	printf("Hello World!\n");
	printf("Hello World!\n");
	// 줄을 띄우려면 \n은 엔터(줄띄움)의 효과를 가지고있다.

	// 실습
	// 애국가 1절 출력하기
	printf("동해물과 백두산이\n");
	printf("마르고 닳도록\n");
	printf("하나님이 보우하사\n");
	printf("우리나라 만세\n");
	printf("무궁화 삼천리\n");
	printf("화려강산 대한사람\n");
	printf("대한으로 길이 보전하세\n");
}
// ctrl + f5 로 실행

//  기본적으로 프로그래밍은
// 항상 (어떤언어든, 어떤 프레임워크든 동일함.)
// main 함수를 실행함.

// main 함수는 프로그래밍 시작점
// #include <iostream>
// iostream << [input output] stream을 다루는 내용을
//					포함한다.
// using namespace std;
// 얘네는 무엇인가?
// using namespace std; << 얘는 아직 안쓰고 있음. 사실 지워도 무방.

// Control F5를 누를때 어떤 행동이 컴퓨터에서 실행되는지 알아보겠음
//
// 첫날에 말하는 대부분의 내용은 필요없음.(자세히 알 필요)
// 컴퓨터 사이언스 지식
// [빌드] -> [실행]
//
// 빌드
// -> 우리가 작성한 code를 EXE로 변환해주는 과정을 빌드라고한다.
//						  (APK, IPA, EXE)
// 일반적으로는 코드형태로는 유저들이 사용할 수가 없다.

// [실행]
// main문 안에 내용을 실행한다.
// 저 안의 내용을 실행하려면 EXE안에 코드를 저장?
// 실행하면 컴퓨터메모리에 우리 코드를 저장하는 메모리 공간에 넣게됨.
// 코드영역 << 이게있어서 나중에 디버깅이라는걸 할 수 있게됨.
// [데이터 영역] [코드영역]  [힙영역] [스택영역]