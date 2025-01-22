## EntityFramework 설치

필요한 Nuget 패키지가 기본적으로 3개.
 + DB 드라이버 1개

Microsoft.EntityFrameworkCore
Microsoft.EntityFrameworkCore.Design
Microsoft.EntityFrameworkCore.Tools

[DB 드라이버 1개]
 (MariaDB로 연결했다.)
 (MariaDB == MySQL)
 Pomelo.EntityFrameworkCore.MySql

 로그용 패키지
 Microsoft.Extensions.Logging.Console

 ## ORM 종류

 DB First 와
 Code First 두개의 종류가 있다.

 DB First
  DB구성을 먼저하고
  명령어를 치면 테이블 내용을 코드에 적용하는형식

 Code First
  Table Class를 코드로 먼저치고
  명령어를 치면 Table Class 내용을 DB에 적용하는 형식