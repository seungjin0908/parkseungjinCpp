﻿## 핀볼 숙제풀이
---

```
 본격적인 게임 프레임워크를 만든 이후에 
 처음으로 게임만드는 숙제

 일단은 당장은 어떻게든 만들수있기만하면 돼요.
 그리고 저는 숙제풀이할때 보편적으로 쉽게 만들수있는
 방법으로 만들거에요.

 디자인패턴들이 계속 튀어나올겁니다.
 구현하고 나중에 설명하는 시간을 가질게요.
```

핀볼 룰 설명
```
 - 양쪽에 벽이 있습니다.

 - 왼쪽벽은 플레이어가 컨트롤하는 벽
 - 오른쪽벽은 위아래로 계속 패트롤하는 벽
 - 공은 벽에 맞거나 위아래부딪히면 반사한다.
 - 공이 왼쪽으로 넘어가면 컴퓨터 1점 추가
 - 공이 오른쪽으로 넘어가면 플레이어 1점 추가
 - 시작할때 공은 왼쪽벽에 붙어있고,  
   마우스를 클릭하면 그 방향으로 공이 날라간다.
```

```
  - 그래서 게임을 어떻게 만들지?

  - 그림을 그릴거에요.
   -> 어떻게? 
   - 공, 왼쪽벽, 오른쪽벽
    - 객체를 안만들고 Scene에다가 다 해볼게요.

```


## 리소스 매니저
---
### 리소스란?
```
 리소스 : 게임에 사용하는 에셋

 예를들면
 Texture, 
 Sprite, 
 Animation(Flipbook), 
 Sound
```

 - 첫번째로 구현할 내용
    - 이미지 출력

```
 Texture란?
  - 텍스처는 이미지파일 그자체
   (어떤 이미지를 로딩했고, 그 이미지에 대한 정보)
   (이미지를 담을 변수)
   ( + 투명색 )
   (WindowsAPI에서는 .bmp 확장자 파일만 그릴수있습니다.)


 Sprite란?
  - 스프라이트는 텍스처의 일부
   (여기부터 여기까지 잘라서 이만큼만 사용하겠다.)
   (텍스처 정보랑, x, y , width, height)

```


```
// 숙제 오목만들기
(백돌 흑돌 다 플레이어가 구현)
// 백돌은 쌍삼금지 쌍사금지

// 원 - 백돌
// 네모 - 흑돌
```