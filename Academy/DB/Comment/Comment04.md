### ORM
SQL 문법은 사실 다 배우긴 했다.
진짜 어려운 JOIN, GROUP BY 이런 내용들은 안배우긴했지만,
기본기는 다배웠다.

DB를 사용할때는

[Game Client] <----> [Game Server] <----> [DB Server]

이런 구조로 통신한다.

SQL은 DB를 다루는 언어이다.

Client도 C#이나 C++로 만들거고
Server도 C#이나 C++로 만들건데,
 DB를 다룰때는 SQL롤 요청을 해야한다.

SQL로 안하고, 코드로 바로 DB를 접근하는 방법이 생겼다.

ORM이란 (Object Relational Mapping)
 SQL로 DB를 접근하는게 아니라
 코드로 DB를 접근하는 코드를 치면
 알아서 SQL롤 변환해서 DB에서 필요한 조작을 하게해주는 라이브러리

장점 : 어플리케이션 개발언어를 그대로 사요하게 해준다.
	   가독성이 좋다.

OPM 라이브러리가 되게 많은데,
C#은 다행히도 하나이다.
[Entity Framework]

사실 오늘 배운 SQL은 DB를 이런식으로 다루는구나. 정도의 느낌으로 말한거고,
실제로는 ORM으로 다루는거로 진행할거다.