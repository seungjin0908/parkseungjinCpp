## 데이터

### C++에서는 아직 안다룬 내용

C++에서 먼저 배우면, 유니코드, 멀티바이트 이런개념이 없다.

데이터를 다룰때도 저게 귀찮고, 저거 때문에 괜히 본질을 헷갈릴까봐
미뤄왔다.


게임을 만들때, 데이터가 핵심이다.

데이터에따라 다른게임이 될 수도 있다.

스킬 구현도 데이터
유닛스탯 이런건 당연히 데이터

LOL이라는 게임이
이터널리턴이 될 수도 있다.

룰을 조금 바꾸면

프로그래머는 룰을 만드는 사람이지 게임을 만드는 사람이 아니다.

그 룰 위에서 데이터대로 움직이게 하는게 프로그래머 역할


데이터가 무엇인가?

데이터는 기획자가 입력하는 값들이다.

보통 excel로 이루어져있다.

공교롭게도 프로그래밍에서는 Excel을 읽는게 생각보다 느리다.
그래서 꼼수가 Excel로 만든파일을 csv로 바꿀 수 있다.

프로그래밍에서 읽기 쉬운 데이터파일들은 무엇이 있을까?
// CSV (Excel을 ,로 분리한 것)
// XML (이게 무엇인가?)



<book>
	<title> Learning Amazon Web Services </title>
	<author> Mark Wilkins </author>
</book>

=> 

public class book
{
	private string title;
	private string author;
}

json
{
	"title" : "Learning Amazon Web Services",
	"author" : "Mark Wilkins",
	"version" : 3
}
