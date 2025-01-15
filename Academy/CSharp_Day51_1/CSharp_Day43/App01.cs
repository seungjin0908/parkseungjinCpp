using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSsharp_Day43
{
    public class App01
    {
        // Tuple 자료형
        public void Run()
        {
            // 구조체를 쉽게 사용하는 방법

            // Unity 에서 사용하는 Tuple 방식

            //자료형 변수명 = 값;
            (int, int) myVariable = (3, 4);

            Console.WriteLine($"Item1 : {myVariable.Item1}");
            Console.WriteLine($"Item2 : {myVariable.Item2}");

            // .Net Framework 4점대까지 가능

            // .Net Core에서 업데이트됨
            (int level, int exp) expData = (3, 4);
            Console.WriteLine($"level : {expData.level}");
            Console.WriteLine($"exp : {expData.exp}");

            // 주로 사용할때,
            // C++에서는 함수로 값을 전달해서 함수안에서 값을 변환해서 받고 싶을떄 보통 포인터를 사용하죠
            // C#에서는 out 혹은 ref 라는 키워드가 있긴하지만,
            // 순수하게 return 받고싶을때

            (int, string) a = Plus(3, 4);
            Console.WriteLine($" a = {a.Item1} ");
            Console.WriteLine($" a = {a.Item2} ");

        }

        (int, string) Plus(int num1, int num2)
        {
            return (num1 + num2, $"{num1} + {num2} = {num1+num2}");
        }
    }
}
