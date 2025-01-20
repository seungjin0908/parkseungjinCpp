### DDL SQL 문법

### 1. Table 만들기
sql
MySQL, MariaDB

CREATE TABLE [테이블명] (
	[컬럼명] [자료형] [옵션],
);

[테이블명],[컬럼명]
변수명 짓듯이 지어주면된다.

[자료형] (각 DB마다 조금씩 다르다.)
 정수형 : INT(4), SMALLINT(2), BIGINT(8), TINYINT(1)
 문자열 : VARCHAR(문자열 길이)
 실수형 (되도록 안쓴다.) : DECIMAL			(고정 소수형)
                        : FLOAT, DOUBLE		(부동 소수형)
 날짜형 : DATETIME 

[옵션]은 천천히 배워보겠다.
 NULL 가능한 컬럼인지?
 => NOT NULL
 KEY가 되는 컬럼인지?
 Default 값은 무엇인지?
 => DEFAULT(값)
 => 무조건 1씩 증가하는 값
 AUTO_INCREMENT


 CREATE TABLE PSJPlayers (
	Id INT,
	Name VARCHAR(100),
	Level INT,
	Experience INT
 );

  CREATE TABLE PSJPlayers (
	Id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
	Name VARCHAR(100),
	Level INT,
	Experience INT
 );


#### Table에 데이터 넣기 (C = Create)
INSERT INTO [테이블명] (컬럼1, 컬럼2, 컬럼3 ...)
	VALUES (컬럼1데이터, 컬럼2데이터, 컬럼3데이터 ...);

-- 주석

~ `` (1옆에있는 문자)
INSERT INTO PSJPlayers (`Id`, `Name`, `Level`, `Experience`)
	VALUES (1, 'Player1', 1,0);


#### Table의 데이터 조회 (R = Read)
sql
가장 기본적인 형태
SELECT [조회할 컬럼들]
FROM [테이블명]

[조회할 컬럼들]
Id, Name 이런내용들
다적기 귀찮다. 그냥 다 조회할거다. << * 을 사용

-- ex 1.
SELECT *
	FROM PSJPlayers

-- ex 2.
SELECT `Id`, `Name`, `Experience`, `Level`
	FROM PSJPlayers

-- 옵션 추가
SELECT [조회할 컬럼들]
	FROM [테이블명]
	WHERE [필터링옵션]

[필터링 옵션]
컬럼명 = 1 (SQL에서는 == 가 = 이다.)
컬럼명 > 1
컬럼명 >= 1
컬럼명 <= 1
컬럼명 <> 1 (SQL에서는 != 가 <> 이거이다.)
WHERE 컬럼명 BETWEEN A AND B
=> (A와 B사이)
WHERE 컬럼명 IN (A, B, C)
=> 해당 컬럼이 A, B, C 중에 해당하는 값이 있는걸 필터링

-- ex 3.
SELECT `Id`, `Name`, `Experience`, `Level`
	FROM PSJPlayers
	WHERE `Id` = 1

-- ex 4.
SELECT `Id`, `Name`, `Experience`, `Level`
	FROM PSJPlayers
	WHERE `Id` IN (1, 2, 3)

-- ex 5.
SELECT `Id`, `Name`, `Experience`, `Level`
	FROM PSJPlayers
	WHERE `Level` BETWEEN 1 AND 5
	WHERE `Id` IN (1, 2, 3)
	WHERE `Experience` = 0

[OrderBy]
SELECT 

-- 실습 [40분]
Players 테이블에
데이터를 10개이상 넣고

SELECT를 해볼건데,
 3레벨 이상인 유저들만 Id를 조회해볼거다.


 #### Table의 데이터 수정 (U = Update)
 sql
 UPDATE [테이블명]
	SET [컬럼명] = 값
	WHERE [조건]

UPDATE [테이블명]
	SET [컬럼명] = 값,
		[컬럼명] = 값,
		[컬럼명] = 값
	WHERE [조건]

레벌업 쿼리를 짠다.
UPDATE Players
	SET `Level` = `Level` + 1,
		`Experience` = 0
	WHERE `Id` = 해당 엔티티 Id

#### Table의 데이터 삭제 (D = Delete)
sql
DELETE FROM [테이블명]
	WHERE [조건]

Id가 1인애를 삭제하고싶다.

DELETE FROM Players
	WHERE `Id` = 1

DELETE는 되게 위험한 문법이기 때문에,
SELECT로 무조건 꼭 한번 확인해주고, 그 조건이 제대로된 값인지 체크한 후에,
삭제 진행하는걸 권장


#### Table을 어떻게 초기화하는지?
sql
Table을 아예 생성만했던 그 상태로 초기화 시키고싶다.
되게 위험한 문법이다.

TRUNCATE TALBE [테이블명];

#### Table을 수정하는 방법
sql
수정하는방법이 되게 많아서
자주안다루면 보통 인터넷 검색 많이 한다.

1. 컬럼추가
ALTER TABLE [테이블명]
	ADD COLUMN [컬럼명] [자료형] [옵션]

2. 컬럼 변경
ALTER TABLE [테이블명]
	MODIFY COULMN [컬럼명] [자료형] [옵션]

3. 컬럼 이름까지 변경
ALTER TABLE [테이블명]
	CHANGE COLUMN [기존 컬럼명] [변경될 컬럼명] [자료형] [옵션]

4. 컬럼 삭제
ALTER TABLE [테이블명]
	DROP COULMN [컬럼명]

5. 테이블 이름 변경
ALTER TABLE [기존 테이블명]
	RENAME [변경할 테이블명]


 #### 실습 풀이
INSERT INTO PSJPlayers (`Id`, `Name`, `Level`, `Experience`)
	VALUES (1, 'Player1', 1,0);

-- ex. 한번에 많은 데이터 넣기.
INSERT INTO PSJPlayers (`Id`, `Name`, `Level`, `Experience`)
	VALUES ('Player2', 2, 0);
	,('Player3', 2, 80)
	,('Player4', 2, 25)
	,('Player5', 3, 20)
	,('Player6', 3, 44)
	,('Player7', 3, 80)
	,('Player8', 5, 5)
	,('Player9', 5, 1)
	,('Player10', 6, 15)
	,('Player11', 7, 25)
	,('Player12', 100, 1000);

SELECT `Id`
	FROM PSJPlayers
	WHERE `Level` >= 3
	ORDER BY `Experience` DESC



 #### 테이블 삭제하는 방법

 -- 데이터까지 같이 삭제됨 조심.
 DROP TABLE [테이블명];




##### 참고사항

(0.1 + 0.2 == 0.3) => false

C++ 배울때 EPSILON (부동소수점 오차를 막아주는 범위)
(1e-6)

소수점을 어떻게 기억하는지 원리를 알면 저 내용을 이해할수있다.

0.5를 기억할때 대체 배열이 어떻게 되는지?

FLOAT (4바이트) (0000 0000 0000 0000 0000 0000 0000 0000)
 < 정수범위 바이트 / 소수범위 바이트를 나눈다.
 < 정수가 되게 크면 정수범위 바이트를 되게 크게 먹는다.
 < 10억까지 정수범위를 표현해야한다 - (소수점을 그만큼 덜 표현하게 된다.)
 < 소수점은 어떻게 표현하나??
 1 * 1/2
 1 * 1/4
 1 * 1/8
 이렇게 밖에 표현이 안된다.
 0.2 => 1/8 + 1/16 + ... 해서 비슷하게 표현하는 거다.

 정수형으로 3을표현할때는
 1*1 + 1*2 => 이렇게 3을 표현했다.

INT (0000 0000 0000 0000 0000 0000 0000 0000)

DB에 부동소수형을 저장하면
(0.3을 저장했는데 0.30000004가 저장되는 마법을 볼수있다.)

고정소수형 - 일정 소수점이하는 그냥 잘라버린다.