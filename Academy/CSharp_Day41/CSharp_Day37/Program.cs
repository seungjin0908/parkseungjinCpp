//C++과 똑같은 기능을하는 namespace입니다.
namespace CSharp_Day37
{
    //C#문법에 class 앞에 private, protected public internal 넷중에 하나를 적어줘야해요.
    // public => 외부에서 모두 사용가능
    // internal => 이 코드내에서 모두 사용가능.
    public class Program
    {
        //프로그램의 시작점 Main이라고 했습니다.
        // 사실 C++에서도 문자열 배열 형태로 되어있는 args를 받았어야했는데 제가 안받은거에요.
        static void Main()
        {
            Console.WriteLine("Hello, World!");
            // => printf 나 cout 같은 콘솔 출력을 담당하는 함수
            // => #include <iostream>

            // WriteLine도 아니고 ConsoleWriteLine도아니고
            // 왜 Conosle이지?


            // C#은 다 클래스기반이기때문에
            // Console이라는 클래스의
            // WriteLine이라는 스태틱 메서드를 사용하는것.


            //App app = new App();
            //app.Run();
            // -> 없습니다.
            // 생성은 무조건 new
            // 자료형 변수명 = 값
            // 값은 무조건
            // new 자료형(); (클래스한정)

            App02 app02 = new App02();
            app02.Run();
        }
    }
}
