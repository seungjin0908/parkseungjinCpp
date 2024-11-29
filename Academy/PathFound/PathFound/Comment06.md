﻿### 미로 그리기

```
 플레이어를 만들고,
 시작지점과 끝지점을 정해서
 0.1초마다 플레이어가 시작점부터 끝지점까지 미로를 탈출하는걸 그릴거임.
```

```
 1. 보드의 출발지점과 끝지점을 만들어준다.
 2. 플레이어의 position을 보드의 출발지점으로 만들어준다.
 3. 0.1초마다 플레이어가 아무방향이나 움직일 수 있게끔 세팅해준다.
  - (눈으로 움직이는걸 확인하기 위해서)
  - 벽으로는 이동하지 못하도록 설정
 4. 길찾기 알고리즘으로 길 이동하도록 세팅
  // DFS, BFS, RightHand
  // 만약에 동굴에 갖혔는데, 출구를 찾아야한다.
  //  - 내 손을 오른쪽으로 뻗습니다.
  //  - 오른쪽에 벽이 안짚이면 오른쪽으로 회전화여 움직인다.
  //  - 오른쪽에 벽이 짚이면 직진한다.
  //  - 직진하다가 앞이 막혀있다. + 오른쪽도 막혀있다.
  //  - 왼쪽으로 간다.
  //  - 왼쪽도 막혀있다. 그럼 뒤로 간다.
```

#### 번외
#### 디버깅 심화
```
디버깅에 조건을 걸 수 있다.
브레이킹 포인트 걸고 우클릭한 다음에 조건을 누르면됨.
```
####
```
	// enter, exit
	// start, finish
	// begin, end
```