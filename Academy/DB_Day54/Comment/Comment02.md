## DB 기초

```
강의에서는 관계형 DB만 다룹니다.

DB는 Table들의 집합

 - Table을 어떻게 만들고
 - Table을 어떻게 삭제하고
 - Table을 어떻게 수정하고
 - 어떻게 Table의 데이터를 넣고
 - 어떻게 Table의 데이터를 수정하고
 - 어떻게 Table의 데이터를 삭제하는지
 - 어떻게 Table의 데이터를 읽는지

 [DDL]
 - Table을 어떻게 만들고
 - Table을 어떻게 삭제하고
 - Table을 어떻게 수정하고

 [CRUD]
  - Create
  - Read
  - Update
  - Delete
```

```
 DB서버를 생성해야 DB에 테이블을 생성하던, 데이터를 넣던 할수있습니다.

 로컬 PC를 DB서버로 쓸수도있습니다.

 제가 개인용으로 쓰고있는 DB서버에 계정을 파서 여러분들께 권한을 드리겠습니다.

 DB에 접근하기 위해서
 WorkBench, Dbeaver를 많이 사용합니다 
 (무료 GUI DB Tool 중에서는 저거 두개가 가장 유명합니다.)
 https://dbeaver.io/download/
 수업에서 사용 : Dbeaver
```

### DB 서버 접속정보
```
Server Host : creams.synology.me
User - PAStudy
Password - PAtmxjel22..
(PA스터디22..)
```

### DB 서버 구조
```
 DB 서버 (creams.synoloy.me 라는 PC)
  - MariaDB라는 프로그램이 실행되고 있는겁니다.
  - DB가 여러개 있는 상태 
   - 이중에서 SBS_Study_20250120 DB를 Set As Default해서 사용한다.
```


### SQL이란?

```
 SQL은 DB를 다루기위해 사용되는 프로그래밍 언어
 (C, C++, C# 와 같은 문법)

 ex.
  - Table을 어떻게 만들고 [CREATE TABLE]
  - Table을 어떻게 삭제하고 [DROP TABLE]
  - Table을 어떻게 수정하고
  - Table을 어떻게 초기화하는지 [TRUNCATE TABLE]
  - 어떻게 Table의 데이터를 넣고 [INSERT INTO ~ VALUES ]
  - 어떻게 Table의 데이터를 수정하고 [UPDATE SET (WHERE)]
  - 어떻게 Table의 데이터를 삭제하는지 [DELETE FROM (WHERE)]
  - 어떻게 Table의 데이터를 읽는지 [SELECT FROM (WHERE)]

 이런 기능들을 하기 위한 프로그래밍 언어
```