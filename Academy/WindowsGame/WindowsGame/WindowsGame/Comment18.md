## Flipbook
```
```

Unity
Unreal

2d sprite animation

Flipbook 이란?

여러개의 스프라이트를 연속으로 변경시켜서
애니매이션처럼 보이게하는 방법

유니티는 Animatior라고 2d랑 3d랑 통합시킴.
```

```
Flipbook - 2D Animation

(Sprite Sheet)

원리는 간단함.
준비해야할것 - 여러개의 스프라이트

스프라이트 - Texture의 일부

SpriteSheet를 만들어줄거임.
 - 엔진에서는 알아서 영역을 찾아서 분리를 해준다.
 - Texture를 격자로 나눈 다음에
  - 그영역을 잘라서 Sprite로 쓸거다.

  + start ~ end까지 보여지는지 총 몇초가 걸리는지
  + 이 애니매이션은 반복을 하는지 
```

```
Flipbook

Texture* texture;
Vector2Int Size
int start
int end
int line
float duration
bool loop