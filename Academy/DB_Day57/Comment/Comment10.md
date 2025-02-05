## DB 라이브러리화 이후, 사용방법
```
 DbContext가 존재합니다.
 (우리 프로젝트에서는 SbsDbContext)

 SbsDbContext 안에 DbSet<> 해둔 Table 변수들을
 LinQ형식으로 사용.
```

### Column에 Default Value 넣기

1. 해당하는 Migrations에 defaultValue를 직접 추가할 수 있음
 => 요 방식으로하면 철학적으로 문제가생긴다.
  => Migrations는 자동으로 생기는 파일인데
  => 수동의 관리요소가 들어가는 부분이 껄끄러움.
  (놀랍게도 MSDN에서 소개되는 방법이다.)

2. Annotation 기능을 직접 만드는 방법
* Annotation이란?
 [Requried] 이런것들
 (함수, 클래스, 프로퍼티, 변수)를 꾸며주는 기능이다.

