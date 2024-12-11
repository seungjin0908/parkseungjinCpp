### LINQ (데이터를 다루는 기술)
(Language-Intergrated Query)

LINQ는 DB랑 연관이 있어서
간단하게 DB에 대해 설명.

#### DB (Database)

Excel 테이블을 여러개 담아놓은곳이 Database이다.

그중에서 속도 좀 빠르게하고 좀 좋은 기능이 첨가된..

[v]관계형 DB가 있고		>	Excel 데이터
[ ]비관계형 DB가 있는데	>	JSON 데이터

관계형 DB란?

아까 배운 데이터에도 있다.
ChampionData
SkillData
ChampionSkillData

여기에서 관계를 띄는게
ChampionSkillData <--> SkillData (N : 1)
ChampionSkillData <--> ChampionData (N : 1)


#### LINQ와 DB의 상관 관계

DB는 Excel(Table)을 여러개 담아놓은곳이 Database이다.

필터링하고 싶은 데이터
어떤식으로 뽑겠다.
합산데이터
 >> 데이블끼리 엮어서/ 혹은 싱글로 데이터를 추출하는 행위를 Query라고 부른다.
 > 데이터를 내맘대로 뽑는 방법을 Query라고 한다.
 > 렙이 50이상인 캐릭터
 > 피가 50퍼 미만인 몬스터
 > 몬스터 리스트중에 보스 몬스터
 > 파티원이 넣은 총데미지

 LINQ
 (Language-Intergrated Query)
  > C#에서도 가능하게 해주겠다. Query역할을.

DB에서의 Query가

완전까지는 아니고, 많이 똑같다.

linq를 배우면 spl을 배우는 효과까지 얻는다.

spl은 무엇이냐?
 DB문법이다.

 코딩테스트랑 연관이 깊다고 했는데??

 코딩테스트는 list나 dictaionary 이런거 좀 자주 쓴다.

 이중에서 홀수만 찾아라,
 이중에서 뭐만 찾아라

 코드 가독성을 언헤치면서 코딩테스트를 풀 수 있다.

 오늘은 LINQ 찍먹만하고

