## 데이터

### C++에서는 아직 안다룬 내용
```
 C++에서 먼저 배우면, 유니코드, 멀티바이트 이런개념이 없습니다.

 데이터를 다룰때도 저게 귀찮고, 저거때문에 괜히 본질을 햇갈리실까봐
 미뤄왔습니다.
```


```
 게임을 만들때, 데이터가 핵심입니다.

 데이터에따라 다른게임이 될수도 있어요.

 스킬구현도 데이터
 유닛스탯 이런건 당연히 데이터

 LOL이라는 게임이
 이터널리턴이 될수도있습니다.

 룰을 조금바꾸면

 프로그래머는 룰을 만드는 사람이지 게임을 만드는 사람이 아닙니다.

 그 룰위에서 데이터대로 움직이게 하는게 프로그래머 역할

 
```

데이터가 무엇인가?
```
 데이터는 기획자가 입력하는 값들입니다.

 보통 excel로 이루어져있어요.

 공교롭게도 프로그래밍에서는 Excel을 읽는게 생각보다 느려요.
 그래서 꼼수가 Excel로 만든파일을 csv로 바꿀수있습니다.

 프로그래밍에서 읽기 쉬운 데이터파일들은 무엇이 있을까?
  - CSV (Excel을 ,로 분리한 것)
  - XML (이게 무엇인가요?)
  - JSON (핵심)

 Excel에는 치명적인 단점이 있습니다.
  - 클래스처럼 구현을 못합니다.
  (트리구조를 사용못한다.)
```
### Excel
|Title|Author|Version|Author Age|Author BirthDate|
|--|--|--|
|Learning Amazon Web Services|Mark Wilkins|3|25|2000-01-01|

```csharp
 //클래스로 만들때는

 public class Author
 {
	public string Name;
	public String BirthDate;
	public int Age;
 }

 public class Book
 {
	public Author Author;
	public string Title;
	public int Version;
 }
```



### XML
```
<book>
	<title> Learning Amazon Web Services </title>
	<author> Mark Wilkins </author>
	<version> 3 </version>
</book>

 => 

public class Book
{
    private string title;
    private string author;
    private int version;
}

<book>
	<title> Learning Amazon Web Services </title>
	<author> 
		<name>Mark Wilkins</name>
		<birthDate>2000-01-01</age>
		<age>25</age>
	</author>
	<version> 3 </version>
</book>
```

### JSON
```json
{
	"title" : "Learning Amazon Web Services",
	"author" : "Mark Wilkins",
	"version" : 3
}

public class Book
{
    public string title { get; set; }
    public string author { get; set; }
    public int version { get; set; }
}

{
	"title" : "Learning Amazon Web Services",
	"author" : {
		"name" : "Mark Wilkins",
		"age" : 25,
		"birthDate" : "2000-01-01"
	},
	"version" : 3
}
```

|특징|EXCEL|JSON|XML|
|--|--|--|--|
|가독성|테이블형식으로 DB처럼 읽기 쉬움| 사람이 읽기 쉬움 | 가독성이 많이 떨어짐 |
|계층구조|제한적|가능|가능|
|크기|큼|가벼움|작은데 JSON보단 큽니다|
|용도|기획자 데이터|프로그래밍 데이터|몬스터 AI 데이터|


```
 LOL 챔피언 데이터 설계

 챔피언

 스킬
```

```csharp

 // 1. 어떤 객체든지 어떤 데이터를 가르키는지 알수있는 Id가 필요하다. 

 public struct ChampionData
 {
	public int Id;
	public string Name;
	// 스탯들은 생략.
	public List<SkillData> Skills;
 }

 public struct SkillData
 {
	public int Id;
	public string Name;
	//스탯들 생략.
 }
```

※JSON -> JavaScript Object Notation

#### JSON 으로 표현하기
```json
ChampionData

{
	"Id" : 1,
	"Name": "가렌",
	"Skills" : [
		{
			"Id" : 10001,
			"Name" : "가렌 Q스킬 이름"
		}, 
		{
			"Id" : 10002,
			"Name" : "가렌 W스킬 이름"
		}, 
		{
			"Id" : 10003,
			"Name" : "가렌 E스킬 이름"
		},
		{
			"Id" : 10004,
			"Name" : "가렌 R스킬 이름"
		}
	]
}
```

#### EXCEL로 표현하기

 - Champion Data

|Id|Name|
|--|--|
|1|가렌|

 - Skill Data

|Id|Name|
|--|--|
|10001|가렌 Q스킬 이름|
|10002|가렌 W스킬 이름|
|10003|가렌 E스킬 이름|
|10004|가렌 R스킬 이름|

 - ChampionSkillData (1:N) (N:N) 상관관계가 있을떄 만들어 줌.

|Id|ChampionId|SkillId|
|--|--|--|
|20001|1|10001|
|20002|1|10002|
|20003|1|10003|
|20004|1|10004|

#### EXCEL serialize, deserialize

```
 엑셀같은 경우에는 용량이 큽니다.
 용량이 크면, 데이터 로딩시간이 길어집니다.
 시리얼라이즈 시간도 길어져요. 


 Microsoft에서 제공해주는 Excel 라이브러리가있는데
 이거 쓰면 100줄 로딩하는데 10초걸려요.

 물론 빠른 라이브러리들 있습니다 (NPOI 라는 라이브러리)

 그래서 큰상태로는 안씁니다.

 방법이 어떻게되냐??
 [1]
 1). Excel > Binary 파일로 따로 바꿔주는 툴을 만들어줍니다.
 2). Binary 파일을 이제 게임에서 읽어줍니다.
 3). Binary 파일의 양식은 회사마다 다르게 만들어줍니다.
 (관심이 있다.) 
 (NPOI 라이브러리 활용해서 Excel 시리얼라이즈해서 binary 파일로 만들어보는)
 (NPOI.Excel)


 [2] - 엑셀을 쓰고는 싶은데 작은규모의 회사나 인디게임회사의 경우

   1). Excel에서 csv로 저장하는 방법이 있습니다.
	  - 다만 단점이 있는데, 데이터에 그 어떠한 경우라도 쉼표를 못넣어요.
	   (쉼표를 특수문자로 사용하기도합니다.)
   2). csv를 로딩합니다.
```


#### ※ 참고사항
```
 데이터를 코드에 입력하는 행위 : 하드코딩 

 간단한거 수정하는거 보는거라도 프로그래머 손을 타야하면

 다른 사람들의 작업속도 늦어집니다.


 기획자나 아트디자이너가 어 이거 아이콘 바꿔보고싶은데? > 행동, 
	(어 저사람 지금 바빠보이는데, 조금있다가 한번에 물어보지)

 EXE를 만들고 나서도,
 값을 수정하고 다시빌드해야하면,  (빌드하는데 보통 30분 걸리거든요)
 30분동안 모두가 웨이팅걸리는거에요.
 ```