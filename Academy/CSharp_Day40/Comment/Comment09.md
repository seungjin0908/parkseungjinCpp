특징			EXCEL							JSON				XML
가독성		테이블형식으로 DB처럼 읽기 쉬움	사람이 읽기 쉬움		가독성이 많이 떨어짐
계층구조		제한적							가능					가능
크기			큼								가벼움				작은데 JSON보다 크다.
용도			기획자 데이터						프로그래밍 데이터		몬스터 AI 데이터


LOL 챔피언 데이터 설계

챔피언

스킬

	CSharp
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
	// 스탯들은 생략.
}

JSON -> JavaScript Object Notation

### JSON 으로 표현하기
	json
ChampionData

{
	"Id" : 1,
	"Name" : "가렌",
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
		}
		{
			
			"Id" : 10004,
			"Name" : "가렌 R스킬 이름"
		}

	]
}


#### EXCEL로 표현하기

ChampionData

Id Name

1 가렌

SkillData

Id		Name
10001	가렌 Q스킬 이름
10002	가렌 W스킬 이름
10003	가렌 E스킬 이름
10004	가렌 R스킬 이름

ChampionSkillData (1:N) (N:N) 상관관계가 있을때 만들어줌.

Id		ChampionId		SkillId
20001	1				10001
20002	1				10002
20003	1				10003
20004	1				10004


#### EXCEL serialize, deserialize

엑셀같은 경우에는 용량이 크다.
용량이 크면, 데이터 로딩시간이 길어진다.
시리얼라이즈 시간도 길어진다.

Microsoft에서 제공해주는 Excel 라이브러리가 있는데
이거 쓰면 100줄 로딩하는데 10초걸린다.

물론 빠른 라이브러리들이 있다. (NPOI 라는 라이브러리)

그래서 큰 상태로는 안쓴다.

방법이 어떻게 되냐??

1. Excel을 > Binary파일로 따로 바꿔주는 툴을 만들어준다.
2. Binary 파일을 이제 게임에서 읽어준다.
3. Binary 파일의 양식은 회사마다 다르게 만들어준다.
(관심이 있다.)
(NOPI 라이브러리 활용해서 Excel 시리얼라이즈해서 binary 파일로 만들어보는)
(NOPI.Excel)


[2] - 엑셀을 쓰고는 싶은데 작은 규모의 회사나 인디게임회사의 경우
1). Excel에서 csv로 저장하는 방법이 있다.
	다만 단점이 있는데, 데이터에 그 어떠한 경우라도 쉼표를 못넣는다.
	(쉼푤르 특수문자로 사용하기도 한다.)

2.). csv를 로딩한다.


#### 참고사항



간단한거 수정하는거 보는거라도 프로그래머 손을 타야하면

다른 사람들의 작업속도가 늦어진다.

EXE를 빌드하고나서도
값을 수정하고 다시빌드해야하면,  (빌드하는데 보통 30분 걸린다.)
30분동안 모두가 웨이팅걸리는거다.