using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day37
{
    public class App
    {
        //C++에서는
        /*
        public:
        public void Run()
        이게 아래와 같이 변경
        */
        public void Run()
        {
            Console.WriteLine("안녕하세요.");
            // 파일도
            // h
            // hpp
            // cpp 이렇게 다양한데
            // C#은 CS하나이다.
            // cs는 csharp 약자이다.


            // 1. 출력은 어떻게하는 것인가?
            // 2. 변수는 어떻게 사용하나?
            // 3. 변수 출력은 어떻게 하나?

            int a = 1;
            float b = 1.4f;
            bool c = false;
            string d = "안녕하세요.";

            //
            object e = 4;

            // C++ 같은 경우에는 기본 자료형 뒤에 . 을 해봐도 쓸 수 있는 함수가 없었다.
            // C#에는 기본적으로 모든 변수에 공통 함수들이 있다.
            /*
             * ToString
             * Equals
             * 
             * 공통함수들은 override할 수 있다.
             * Equals 는 그냥 ==으로 체크하면 되는거 아닌가?
             * == 같은 경우에는 포인터는 값을 체크하는게 아니라, 주솟값을 체크했었다.
             * 
             * ToString 은 기본적으로 모든 변수는
             * 문자열로 변환할 수 있다. C#에서는
             */

            // 공통함수들은 왜있냐?
            // object 자료형

            // C#은 다 클래스기반, 구조체기반
            //  + 모든 자료형은 object를 상속받는다.

            // object는 Class이다.
            // 기본자료형들은 Struct 이다.


            // 변수출력
            //string name = "박승진";
            //Console.WriteLine($"이름 : {name}");


            // 실습
            // int, float, bool, string 변수 활용해서 출력하기
            // 3줄이상
            string name1 = "박승진";
            Console.WriteLine($"이름 : {name1}");

            float b1 = 3.14f;
            Console.WriteLine($"소숫점 : {b1}");

            int a1 = 10;
            Console.WriteLine($"숫자 : {a1}");

            bool c1 = false;
            Console.WriteLine($"질문 : {c1}");

            // 콘솔출력은 다배움
            // 입력
            // scanf,cin
            string? input = Console.ReadLine();

            Console.WriteLine($"입력한 값은 : {input}");
            // int나 이런 실제로 사용할 자료형으로 받았는데

            // C++과 다르게 string을 일반값으로 변환하는게 되게 편하다.

            int inputValue = int.Parse(input);
            Console.WriteLine($"Parse된 Input 값 : {inputValue}");

            // float.Parse
            // bool.Parse
            // DateTime.Parse
        }
    }
}
