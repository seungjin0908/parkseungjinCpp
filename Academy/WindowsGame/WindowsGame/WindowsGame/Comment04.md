## 숙제풀이
```
```
### 수도코드
#### 키인풋
 1. 1~9까지 입력하는것을 currentInput으로 저장
#### Render
```
 if (1 <= currentInput and currentInput <= 9) then
	화면 중앙 currentInput단 출력
 else
	1단 ~ 9단 출력
```

## 마우스 이동 감지 (위치감지)
```
	WM_MOUSMOVE 를 통해 마우스 이동감지를 한다.
```

## 타이머
```
 타이머란 
  - 특정시간이 되면 WM_TIMER를 호출할 수 있게하는 기능

  사용방법
   - SetTimer(_hWnd, 타이머ID, 타이머 호출주기(ms),NULL);
   - KillTimer(_hWnd, 타이머ID)
   - WM_TIMER / wParam이 타이머ID로 오게된다.


게임이 주로 60프레임
```

### 프레임이란?
```
FPS - Frame Per Seconds
1초에 화면이 몇번 전환되느냐

60fps -> 1초에 60번 화면이 전환된다.
타이머에서 InvalidateRect를 호출시켜줄건데
1000 / 60ms 를 호출주기호 가지면
60fps를 유지할 수 있다.
```

## 충돌체크 **(게임에서 가장 많이 쓰이는 기술)**
```
점과 사각형 충돌 (아이템클릭, 버튼클릭, 마우스클릭하는 대부분의 것들)

수학적인 내용

if ( rc.left <= mousePos.x and mousePos.x <= rc.right ) then
	if ( rc.top <= mousePos.y and mousePos.y <= rc.bottom) then
		충돌
```
실습
네모  9개를 그리고
네모를 클릭하면 그 네모를 지워주게끔

```
수도코드
WM_CREATE:
 for(int i=0; i<9;i++)
	enemies.Add(new Enemy({각자 위치}));

WM_PAINT:
	for ( enemy in enemies );
		if ( enemy.IsLive() ) then
			enemy.Draw()

WM_KEYDOWN:
	switch(key)
		case 'A';
			for(enemy in enemies );
				if( enemy.rc.left <= mousePos.x and mousePos.x <= enemy.rc.right ) then
					if( enemy.rc.top <= mousePos.y and mousePos.y <= enemy.rc.bottpm) then
						enemy.Die()
```

### 숙제 - 두더지잡기
```
두더지 9마리가 1초에 랜덤으로 하나씩 땅속에서 나오게된다.
그 두더지가 5초후에 다시 들어간다.
그리고 튀어나와있을때 두더지를 클릭하면 (A키를 누르면)
점수가 1점 오른다.

게임은 끝나지 않는다.
```