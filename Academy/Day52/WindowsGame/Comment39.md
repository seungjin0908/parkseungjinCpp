## Direct 2D
```
 Direct X - [하드웨어를 컨트롤할수있는 API]

 Direct X는 사실 하드웨어 컨트롤중에서도 GPU 컨트롤이 가장 까다로워서 
 보통 렌더링으로 많이 치우치게됩니다.

 보통 그 렌더링중에 제일 유명한게 3D겠죠.

 Direct 3D - Direct X, API 중에서 3D 렌더링 기능을 떼서 말하는게 Direct 3D에요.
 Direct 2D - Direct3D API를 2D용으로 사용하기 쉽게 새로 래핑한(감싼) API 입니다.
             (Wrapping)

 Direct 3D에서의 주된 내용이 렌더링 파이프라인 입니다.
 Direct 2D는 아 그런거 까다로워 하면서 다 지워버렸어요.
```


## 프레임워크 바뀌는 내용
```
 1. 화면 초기화 : Windows API로 초기화 되어있는걸 DirectX로 바꿔야합니다.
 2. 더블버퍼링 기능 : 새롭게 구현을 해줘야합니다.
  (BackBuffer를 Bitblt로 고속복사해주고)
  (BackBuffer를 PatBlt로 깔끔하게 지워주고)
  (BackBuffer에 그림그리기 반복)

 3. 모든 그리기 함수들을 변경
  (텍스트 쓰는것부터, 이미지 출력까지 모두 WindowsAPI함수를 사용하고 있습니다.)
  (Direct2D 기법으로 바꿔야합니다.)
```

## InitDirect2D

```
ID2D1Factory
ID2D1HwndRenderTarget

둘을 초기화
```

### ID2D1Factory
```
Direct 2D의 근본입니다. (루트)
 - 여기에서 모든 리소스를 관리해줍니다.

 팩토리를 초기화할때 내부에서 알아서 하드웨어 가속화가 다 들어가있습니다.
 DirectX 원본 기준으로는 저 함수 매게변수가 약 10개 넘게들어가요.
```

### ID2D1HwndRenderTarget
```
 Windows API로 따지면 HDC
  - DeviceContext
  화면
```


## Direct 2D로 그림 그려보기 (텍스트)
```
 IDWriteFactory           < 텍스트쓸때 필요한 본체
 IDWriteTextFormat        < 텍스트의 레이아웃
```



## 참고
```
자료올리는거 백업안해두면 언제사라질지 몰라요.
백업필요하신분은 틈틈히해두세요.
제가 딱 반년간만 유지하겠습니다.

이번기수마지막으로 강사직을 완전히 그만두는데,

취업관련이나 전공관련으로 궁금하신거있으면 따로 카톡이나 DM 계속하셔도 상관없습니다.
다만 제가 계쏙 깨있는게아니라서
답장타임이 새벽이될수도있고, 랜덤이 있다는점
24시간안에는 답장해드려요. (아마도)
```