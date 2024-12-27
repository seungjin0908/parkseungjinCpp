## LINQ (데이터를 다루는 기술)
(Language-Intergrated Query)

```
LINQ는  DB랑 연관이 있어서
간단하게 DB에 대해 설명하겠습니다.
```

#### DB (Database)
```
 Excel(Table)을 여러개 담아놓은곳이 Database입니다.

 그중에서 속도좀 빠르게하고 좀 좋은 기능이 첨가된..

 [v]관계형 DB가 있고		> Excel 데이터
 [ ]비관계형 DB가 있는데		> JSON 데이터

 관계형 DB란?

 아까 배운 데이터에도 있습니다.
 ChampionData
 SkillData
 ChampionSkillData

 여기에서 관계를 띄는게
 ChampionSkillData <--> SkillData (N : 1)
 ChampionSkillData <--> ChampionData (N : 1)
```

#### LINQ와 DB의 상관 관계
```
 DB는 Excel(Table)을 여러개 담아놓은곳이 Database입니다.

 필터링하고 싶은 데이터
 어떤식으로 뽑겠다.
 합산데이터
  >> 테이블끼리 엮어서/ 혹은 싱글로 데이터를 추출하는 행위를 Query라고 부릅니다.
  > 데이터를 내맘대로 뽑는 방법을 Query라고 합니다.
  > 렙이 50이상인 캐릭터
  > 피가 50퍼 미만인 몬스터
  > 몬스터리스트중에 보스몬스터
  > 파티원이 넣은 총데미지


LINQ 
(Language-Intergrated Query)
 > C#에서도 가능하게 해주겠다. Query역할을.

DB에서의 Query가 


완전까진아니고, 많이 똑같아요.

linq를 배우면 sql을 배우는 효과까지 얻습니다.

sql은 무엇이냐??
 db문법입니다.
```


아까 분명히 코테랑 연관이 깊다고 하셨는데??
```
 코딩테스트에서는 list나 dictaionary 이런거 좀 자주쓰거든요

 이중에서 홀수만 찾아라,
 이중에서 뭐만찾아라

 코드 가독성을 안헤치면서 코딩테스트를 풀수있습니다.
```

오늘은 LINQ 찍먹만하고

다음시간부터 LINQ 제대로하겠습니다.

C# 끝나면 코딩테스트 몇문제 풀어볼게요.

Level 1 ~ 5 까지있는데

```
 Level 3 까지는 많이나옵니다.
 Level 4 는 킬러문제 나오는데  << 이건 알면 풀고 공부한다고 되는 레벨아닙니다.

 // 애초에 안나옵니다. 
 Level 5 << 못푼다고 보시면됩니다.  < 이거는 코딩의 영역이 아닙니다.
  푸는방법은 레벨3,4랑 안달라요. 그런데 공식이 수학과에서 배우는 그런 수학공식들이 첨가돼요.
```