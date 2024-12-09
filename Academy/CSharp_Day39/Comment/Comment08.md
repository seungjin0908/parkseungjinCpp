### template (제네릭)

// 사용법만 간단하게 짚겠다.

// 제네릭 메서드
// 제네릭 클래스
// 제네릭 인터페이스

// 제네릭 메서드
public void Print<T>(T value)
{
	// 구현
}

// 제네릭 클래스
public class PriorityQueue<T>
{
	public List<T> value;
}

// 제네릭 인터페이스
public interface IRepository<T>
{
	void Create(T item);
	T Read(int Id);
	void Update(T item);
	void Delete(T item);
}

// 제네릭 인터페이스 사용방법

public class Repository<T> : IRepository<T>
{
	void Crete(T item);
	T Read(int Id);
	void Update(T item);
	void Delete(T item);
}


template에서의 where 키워드

// 제네릭 타입에 구체적인 타입 제약조건을 설정 할 수있는 기능.

// where 키워드로 쓸 수 있는 내용들
	1. where T : class
	=> T는 참조타입이어야함.

	2. where T : struct
	=> T는 값타입 이어야함.

	3. where T : new()
	=> T는 매개변수가 없는 생성자를 가져와야함. (혹은 해당클래스)

	4. where T : <BaseClass>
	=> T는 BaseClass를 상속한 타입이어야함. (혹은 해당클래스)

	5. where T : <BaseInterface>
	=> T는 BaseInterface를 구현해얗마.

	6. where T : not null
	=> T는 null이 될 수가 없는 타입이어야함.

	7. 여러개 조건을 걸고 싶을때.
	=> ,로 여러개 쓰면됨.
	where T : class, new()
