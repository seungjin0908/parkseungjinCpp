## DB란?

Database 란?
< 데이터 집합

많은 데이터들이 모여있는 창고이다.

게임클라이언트
Scene이란?
 < GameObject 집합
 < Component 집합.


 DB의 종류에는 크게 2가지가 있다.
 1. 관계형 DB (얘를 더 많이 쓰고, 앞으로도 그럴거 같다.)
 2. 비관계형 DB (소규모 프로젝트에, DB를 잘안다뤄본 사람들이 자주 쓴다.)


 1. 관계형 DB에서 유명한 제품
  - MSSQL
  - MySQL
  - MariaDB
	
 2. 오브젝트형 DB
  - PostgreSQL (조금 자주쓰인다. 특히 java 진영에서) (쓰는것은 관계형 DB처럼 쓰인다.)
  - MongoDB


관계형 DB는 (RelationDB ManagementSystem RDBMS)
 - 엑셀로 표현할 수 있는 데이터
 - SQL로 컨트롤



오브젝트형 DB (Object Relation DB ManagementSystem ORDBMS)
 - 오브젝트로 표현할 수 있는 데이터
 - Object Query Language로 컨트롤


### 관계형 DB
ID Name  Hp	 Attack		Def
1  가렌  100   30		 15
2  갈리오  200 20		 30
3  갱플랭크  300 10		  5


### 오브젝트형 DB
(주로 Json을 써서 저장한다.)
json
{
	"Id" : 1,
	"Name" : "가렌",
	"Hp"   : 100,
	"Attack" : 30,
	"Def"  : 15
};


### 관계형 DB - 2

Releation Database
 < 테이블 집합

 // 테이블이란?
    엑셀데이터처럼 생긴것.


테이블은 ROW, COLLUMN 으로 이루어져있다.

COLLUMN : Id, Name, Hp, Attack, Def 와 같이, 데이터 정보를 의미한다.
(COLLUMN을 추가한다 => 데이터 정보를 추가한다.)

ROW(줄) : 데이터 세트 1개당 1ROW를 차지한다.

테이블이 여러개가 있고, 테이블끼리 관계가 엮여있는것이 관계형 DB라고 한다.

[데이터 배울때 다 배운 내용이다.]

PRIMARY KEY (ID)
 해당 ROW의 고유한 값을 설정하는걸 PRIMARY KEY라고 한다.
 가렌 1,
 갈리오 2,
 갱플랭크 3

 메모장 같은곳에
 [
 1번째줄 가렌정보
 2번째줄 갈리오 정보
 3번째줄 갱플랭크 정보
 ]
 라고 적어두고

 만약에 3번 ID를 가진 챔피언을 보고싶다.
 라고하면
 그냥 저 메모장켜서 3번째줄로 점프한다.
 그럼 시간복잡도 O(1)이다.
FOREIN KEY

INDEXING
### DB, 서버 공통

엑셀이나 이런건 수정을 동시에 못한다.
DB는 공용데이터 창고라고 보면된다.
처리속도가 그만큼 빠르다.


서버?
DB서버?

서버는 2가지 의미로 많이 쓰인다.
이 의미를 그때그때 알잘딱 해석해야한다.

1. 프로그래밍적으로의 서버.
 - 클라이언트가 서버에 데이터를 던지고, 서버가 그 데이터를 어떻게 처리하고 반환하는지.
	
2. 인프라로써의 서버.
 - PC라고 생각하면 된다.
 - 서버 프로그램이 떠져있는 PC라고 생각하면 된다.
	
DB서버, DB많이 부르는데
 - DB프로그램이 떠져있는 PC라고 생각하면 된다.
	
클라우드
 - PC를 켜는데, 주로 이제 집에있는 PC를 킨다.
 - 회사에서 작업한 서버 프로그램을 집에 있는 PC로 혹은 회사 PC로 안킨다.
 (당연히 킬순있다.)
 - 따로 빌려서 킨다. (가상 PC를 대여해주는 업체)
 AWS - Amazon Web Service
 Azure - Microsoft Azure Service
 GCP - Goole Cloud Service
 NCP - Naver Cloud Service
	
 여기서 가상 PC를 하나 사서, 원격으로 켜겠다.

Q. 왜 가상 PC를 굳이 사서 키나?? 내 PC나 새로사면 되지않나?
A. 첫번째로 비싸다. 램이 200GB정도가 필요하다. 128CPU 정도가 필요하다.
   가상 PC를 사면, 한달에 400만원정도로 살수있다.
	
   두번째로는, 샀을때 물리PC의 리스크
   (느려졌다. 어떤 부품이 고장났다. 아니면 정전)
	
   세번째로는, 보안