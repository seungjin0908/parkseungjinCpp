### template (제네릭)

```csharp
 // 사용법만 간단하게 짚겠습니다.

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

 //제네릭 인터페이스 사용방법

 public class Repository<T> : IRepository<T>
 {
 	void Create(T item);
	T Read(int Id);
	void Update(T item);
	void Delete(T item);
 }

```


```
 template에서의 where 키워드
  
   - 제네릭 타입에 구체적인 타입 제약조건을 설정할수 있는 기능.
   - where 키워드로 쓸수있는 내용들 
      1. where T : class
      => T는 참조타입 이어야함.

      2. where T : struct
      => T는 값타입 이어야함.

      3. where T : new()
      => T는 매게변수가 없는 생성자를 가져야함.

      4. where T : <BaseClass>
      => T는 BaseClass를 상속한 타입이어야함. (혹은 해당클래스)

      5. where T : <BaseInterface>
      => T는 BaseInterface를 구현해야함.

      6. where T : not null
      => T는 null이 될수가 없는 타입어야함.

      7. 여러개 조건을 싶을때.
      => ,로 여러개 쓰면됨.
      ( where T : class, new() )
```