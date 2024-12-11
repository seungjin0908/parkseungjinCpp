## delegate 와 event

### Delegate 
 - 행동을 정의
 - (함수 포인터)
 ```csharp
// Delegate
// 함수포인터 자료형 정의를 위한 키워드

public delegate void Notify(string message)

// Notify 자료형이 생기고
// void 함수형(string 매게변수)
// 인 함수들은 함수포인터로 쓸수있는거에요.

public void MainLogic()
{
    Notify notify = WriteLog;
    notify("플레이어가 보스룸으로 이동하였습니다.");
}

public void WriteLog(string message)
{
    // 로그적는 기능.
}
 ```
        

### Event
 - 상태 변화를 알려줄 때
 - (Pub/Sub)
```csharp
 // 선언
 public event Action<int> OnHealthChanged;

 //네이밍 컨벤션은 보통
 //On~~

 public void ChangeCharacterHpUI(int health)
 {
    // ui 변경 로직
 }

 //추가
 OnHealthChanged += ChangeCharacterHpUI;

 //삭제
 OnHealthChanged -= ChangeCharacterHpUI;

 //실행
 OnHealthChanged?.Invoke(값);

```

### Lambda
```
  (C++에도 있습니다.)
  보통 C++에서는 회사자체에서 문법이 너무 기괴해서 아예 쓰지말라고 하는경우가 많습니다.


  람다가 무엇인가?
   => 1회용 함수
   => 짧은 함수
   이런것들을 매번 함수정의하고 함수선언하고 사용하는게 너무 귀찮다.

   그냥 즉각적으로 함수를 만들고 해소하고싶다.

   무명함수

```
```csharp
   //람다 사용법

   public int Plus(int num1, int num2)
   {
       return num1 + num2;
   }


   //Action과 유사합니다.
   //Func < 리턴자료형이 있어요.
   Func<int, int, int> plus = 
        (num1, num2) => (num1 + num2);

```


#### 참고사항
```
 C++ 에서는 안물어본다 했잖아요.
 최소한 신입면접때는.

 C# Unity에서는 살짝 얘기가 달라집니다.
 Event에 대해서는 알아야합니다.
```

```
 함수포인터같은 delegate와 같은 경우,
 어떤 프레임워크가 만들어져있고 그 룰을 따라가는거 까지는 공부하면 할수있어요.

 그런데 지금 딱 delegate배우고, 
 바로 unity 프로젝트에 바로 적용한다?

 좋은 구조가 잘 안나옵니다.

 웬만하면 회사가서 한번 어떤식으로 사용하는지 보고
 따라하시는게 좋아요.

 잘못쓰면 괜히 코드 진입장벽만 높아지는데,
 잘쓰기가 어려워요.
```