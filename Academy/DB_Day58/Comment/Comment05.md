## EntityFramework 설치
```
 필요한 Nuget 패키지 기본적으로 3개.
  + DB 드라이버 1개

 Microsoft.EntityFrameworkCore (8.0.3)
 Microsoft.EntityFrameworkCore.Design (8.0.3)
 Microsoft.EntityFrameworkCore.Tools (8.0.3)

 [DB 드라이버 1개] 
  - (MariaDB로 연결했잖아요)
  - (MariaDB == MySQL)
  - Pomelo.EntityFrameworkCore.MySql (8.0.2)


 로그용 패키지
 Microsoft.Extensions.Logging.Console (8.0.0)
```


## ORM 종류
```
 DB First 와 
 Code First 두개의 종류가 있습니다.

 DB First
  - DB구성을 먼저하고 구성하고
  명령어를 치면 테이블 내용을 코드에 적용하는 형식

 Code First
  - Table Class를 코드로 먼저치고 
  명령어를 치면 Table Class 내용을 DB에 적용하는 형식
```