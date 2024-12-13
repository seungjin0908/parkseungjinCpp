## LINQ

LINQ ( Language Intergrated Query )

Query - DB에 있는 Table들을 다룰때 사용하는 기능 (추출)

Table - Excel 이나 Json 데이터 시트들과 비슷한

LINQ에서 다루는 Table => List. Dictionary, Array (Collection)


### LINQ 기능

LINQ 기능은 기본적으로 DB 명령어와 매우 유사하게 생겼다.

1. Where
 - Collection에서 내가 원하는 데이터들만 필터링해서 가져오는 기능
 - 퀘스트창 열면, 진행중인 퀘스트, 완료한 퀘스트 상태별로 나누어서 가져올 수 있다.
	
2. Select
 - Collection에서 데이터를 가져올때, 그 구조체나 클래스로 가져오는게 아니라,
   그 데이터를 기반으로 새로운 데이터를 창조해낼때 사용

3. Any / All
 - Any(조건) => Count != 0 (하나로도 있으면 True 반환)
 - All(조건) => Count == Original.Count (모두 조건을 달성하면 True 반환)
 ex) 특정 적이 내 범위안에 있는지?	
	 
4. First / FirstOrDefault
 - 첫번째
   List[0] 가져오면 되지않나?
 - 배열길이가 0이면, default 값으로 내보내게
	
5. Take
 - Take같은경우에는 배열길이를 자른다.
 ex. Take(10) 을 하면 0~9까지 가져오는거다.
	 랭킹창 같은곳에서 주로 사용.
	 (1등부터 10등까지만 보여줘야한다.)
	
6. Skip
 - 주로 Take와 사용한다.
 - 데이터가 30개짜리 Collection을 다룰때
   Skip(10).Take(10) 하면
   10~19를 가져온다.
	
   (랭킹등 페이징이 필요한 곳에서 사용한다.)
	
7. Min / Max
 - Collection중에 최솟값 / 최댓값 구하기
	
8. Orderby / OrderbyDescending
 - Collection 정렬
	
9. Join, GroupBy, Aggregate (알면 유용하다.)


간단한 문법은 월요일에 추가로 진행할거임.

지금은 뭘할거냐

코테 들어가기전에 

C#에 익숙해져야할 필요가 있어서

실습할거임.

어떤 언어를 배우던
그 언어를 한번 쭉 다배웠으면

[가위바위보하나빼기 / 숫자야구 / 카드게임류 하이로우세븐]
이거를 딱히 안막히고 만들 수 있으면

그 문법을 이제 프로덕트 단위로 넘어가도 된다는 뜻이다.