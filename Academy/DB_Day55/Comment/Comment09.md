## 포린키

### DB

creams.synology.me 서버에
 SBS_Study_BSY_20250120 라는 DB가 있고 그안에는
  TblPlayer
  TblPlayerItem
     Id,
     ItemId
           => 아이템 데이터 시트와 연관
     OwnerId
           => TblPlayer와 연관되어있음.
     Count
 __EFMigrationsHistory
 가 존재한다.



### ForeinKey (외래키)

다른 테이블과 연관관계를 가지고있는걸 표현해주는 키


### ORM의 역할

DB관리를 코드로 관리할수있는것도 있겠지만,

CRUBD되 되어야함.