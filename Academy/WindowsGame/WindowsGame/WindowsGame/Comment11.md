## TimeManager

```
 60fps
 144fps

 100ms가 넘어간다.

 fps -> 1초에 화면갱신이 몇번 되는지
 ms -> 이전 화면갱신부터 지금 화면갱신까지 몇ms가 걸렸는지
```

TimeManager는 단순하게
 이전업데이트 부터 현재 업데이트까지 걸린 시간을 재는게 TimeManager이다.

 기능으로는
```

GetFps() -> 1초에 화면갱신이 몇번 되는지
GetDeltaTime() -> 이전 화면갱신부터 지금 화면갱신까지 몇ms가 걸렸는지
```

## 게임수학-1
```
 방정식
 1s : spee(px) = deltaTime(s) : ??px

 spee * deltaTime = 1 * ??
 ?? = spee * deltaTime
```

## 클릭한 곳으로 이동하기 (게임수학-2)
