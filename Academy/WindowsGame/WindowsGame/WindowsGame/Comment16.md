## Collision Manager

충돌체크를 관리하는 역할

게임엔진들을 보면
Collider라고 있음.

### Collider
충돌체

### Collider Component
해당 오브젝트를 충돌체로 만들어주는 역할을 해줌.

### Collier 종류
1. Circle Collider
    - 원형 충돌체
2. Box Collider
   - 네모난 충돌체

### Collision Nanager
 - A Collider와 B Collider가 충돌했다. 라는걸 알려줌.
     - OnTriggerEnter (충돌이 시작하였을 때)
     - OnTriggerExit (충돌이 끝났을 때)
 - Collider 입장에서는
    - 모든 애랑 충돌하면 원하는 기능이 안나오거나, 너무 성능이 과부화된다.
    - 게임에서 (그래픽을 제외하고) 가장 무거운 기능이 충돌체크
    - 그렇기 때문에 최대한 내가 원하는 객체랑만 충돌하도록 설정
        - Collision Layer를 따로 만들어 줌.


### Collision Layer
 - Character = 1
 - Ground = 2
 - Item = 3