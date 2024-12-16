using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day37
{
    public class App
    {
        //c++에서는
        /*
        public:
            void Run();
        이게 아래와같이 변경
        */
        public void Run()
        {
            Console.WriteLine("안녕하세요.");

            // 파일도
            // h
            // hpp
            // cpp 이렇게 다양한데
            // C#은 cs하나입니다.
            // cs는 csharp 약자에요.


            // 1. 출력은 어떻게하는 것인가?
            // 2. 변수는 어떻게 사용하나?
            // 3. 변수 출력은 어떻게 하냐?

            int a = 1;
            float b = 1.4f;
            bool c = false;
            string d = "안녕하세요.";

            //
            object e = 4;

            // C++같은 경우에는 기본 자료형 뒤에 . 을 해봐도 쓸수있는 함수가 없었습니다.
            // C#에는 기본적으로 모든 변수에 공통 함수들이 있습니다.
            /*
             * ToString
             * Equals
             * 
             * 공통함수들은 저희가 override할 수 있습니다.
             * Equals 는 그냥 ==으로 체크하면 되는거 아니에요?
             * == 같은 경우에는 포인터는 값을 체크하는게 아니라, 주솟값을 체크했었죠.
             * 
             * ToString 은 기본적으로 모든 변수는 
             * 문자열로 변환할수 있습니다. C#에서는.
             */

            // 공통함수들은 왜있냐??
            // object 자료형

            // C#은 다 클래스기반, 구조체기반
            //  + 모든 자료형은 object를 상속받습니다.

            // Object는 Class입니다.
            // 기본자료형들은 Struct 입니다.


            // 변수출력
            string name = "백수영";
            Console.WriteLine($"이름 : {name}");


            // 실습
            // int, float, bool, string 변수 활용해서 출력하기
            // 3줄이상


            int number = 10;
            Console.WriteLine($"내가 제일 좋아하는 숫자는 {number} 입니다.");

            float pi = 3.14f;
            Console.WriteLine($"원주율은 {pi} 입니다.");

            string myString = $"{pi} 랑 {number} 등등";

            // 콘솔출력은 다배움
            // 입력
            // scanf, cin
            string? input = Console.ReadLine();

            Console.WriteLine($"입력한 값은 : {input}");
            // int나 이런 실제로 사용할 자료형으로 받았는데

            // C++과 다르게 string을 일반값으로 변환하는게 되게 편합니다.

            int inputValue = int.Parse( input );
            Console.WriteLine($"Parse된 Input 값 : {inputValue}");

            //float.Parse
            //bool.Parse
            //DateTime.Parse
        }
    }
}
