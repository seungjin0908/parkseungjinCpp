﻿## 핀볼 숙제풀이
```

```
 본격적인 게임 프레임워크를 만든 이후에
 처음으로 게임만드는 숙제

 일단은 당장은 어떻게든 만들 수 있기만 하면 됨.

 디자인 패턴들이 계속 튀어나올거임.
```

핀볼 룰 설명
```

- 양쪽에 벽이 있다.

- 왼쪽벽은 플레이어가 컨트롤하는 벽
- 오른쪽벽은 위아래로 계속 패트롤하는 벽
- 공은 벽에 맞거나 위아래 부딪히면 반사한다.
- 공이 왼쪽으로 넘어가면 컴퓨터 1점 추가
- 공이 오른쪽으로 넘어가면 플레이어 1점 추가
```

```
 - 그래서 게임을 어떻게 만들지?

 - 그림을 그릴거임.
  -> 어떻게?
  - 공, 왼쪽벽, 오른쪽벽
   - 객체를 안 만들고 Scene에다가 다 해볼거임.

```

## 리소스 매니저
```
### 리소스란?
```
 리소스 : 게임에 사용하는 에셋
 
 예를들면
 Texture,
 Sprite,
 Animation(Filpbook),
 Sound
```

 - 첫번째로 구현할 내용
  - 이미지 출력

```
 Texture란?
  - 텍스처는 이미지파일 그자체
  (어떤 이미지를 로딩했고, 그 이미지에 대한 정보)
  (이미지를 담을 변수)
  ( + 투명색)
  (WindowsAPI에서는 .bmp 확장자 파일만 그릴 수 있다.)

Sprite란?
 - 스프라이트는 텍스처의 일부
   (여기부터 여기까지 잘라서 이만큼만 사용하겠다.)
   (텍스처 정보랑, x, y, width, height)

```

// 숙제 오목만들기
(백돌 흑돌 다 플레이어가 구현)
// 백돌은 쌍쌍금지 흑돌도 금지

// 원 - 백돌
// 네모 - 흑돌