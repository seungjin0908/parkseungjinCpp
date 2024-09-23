# Windows API 1일차
---

## 1. 구구단 찍기
### 구구단 찍을때 필요한 기능
 1. 글자 출력하는 방법
```cpp
 // TextOut
 TextOut(HDC hdc,int x,int y,LPCWSTR lpString, int c)

 // hdc - Device Context (화면 구조체)
 // x,y - 어떤위치에
 // lpString - 어떤글자를
 // c - 문자열길이

 // 콘솔에서 printf랑 같은 기능
 // 나중에 쓸거임.
 // 보통 개발할때 옆에 콘솔창 띄워두고 한다.
 // printf는 콘솔창에 써지고
 // TextOut은 화면에 그려진다.

 // LPCWSTR - WCHAR* 형태
 // WCHAR - wchar_t
```
### WCHAR, CHAR 차이
```
 //wchar_t - 은 무엇일까
 //char, wchar

 char - 1byte
 wchar - 2byte

 한글은 2byte고
 영문은 1byte이다.

 1byte는 크기가 256이다.
 그러다보니 전세계문자를 다 표현할수가 없다.

 1byte는 UTF-8 (ASCII) 이라고 하는 문자열 포맷을 사용한다.
 UTF-8 - 국제적으로 ?bit를 사용할때 65는 0 32는 a 이렇게 표현하자
		 라고 약속하는 문자열 규격
 UTF-16 - 국제적으로 16비트를 사용할때 사용하는 문자열 규격

 2바이트를 적었는데.
 어떤컴퓨터에서는
 aa라고 인식하고
 어떤컴퓨터에서는
 특수문자로 인식

 이거를 하나로 통일시켜줘야한다.

 보통 해외국가까지 퍼블리싱을 생각하면
 UTF-16으로 작업하게한다.

 UTF-8 - char
 UTF-16 - wchar 이다.

 string, char랑 짝이고
 wstring, wchar랑 짝이다.
```
 
## 2. 사각형 그리기
### 사각형 그릴때 필요한 기능
 1. 사각형/원을 그리는 방법
```cpp
  //사각형그리기
  Rectangle(hdc,left,top,right,bottom);
  //원그리기
  Ellipse(hdc,left,top,right,bottom);
  // left - 좌측 x좌표
  // top - 상단 y좌표
  // right - 우측 x좌표
  // bottom - 하단 y좌표

  // windows api의 좌표계는
  // 좌측상단이 0,0 이다.

  // 사각형을 그리거나
  // 타원을 그릴때
  // x,y,width,height 
```
### namespace
```
namespace는 이름공간

using namespace std;
// std를 생략하고 함수를 작성하겠다.
// std::cout ==> cout

format이라는 함수를 A라이브러리 개발자도 만들 수 있고, 나도 만들 수 있다.

namespace std
{
  void format()
}