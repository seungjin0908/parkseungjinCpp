using System;
using System.Collections.Generic;
using System.Linq;
using System.Security;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day38
{
    // 함수

    public class App02
    {


        public void Run()
        {
            // 함수선언은 class안에 있어야한다.

            // C#은 무조건 클래스기반이다.


            // 함수선언 공식
            // 클래스안에서
            // 접근제어자 자료형 함수명(매개변수)
            // {
            //   본문
            // }

            // + 전방선언 이런거 없다.

            Function();

            // this 가능.
            this.Function();

            // 항상 함수배울때마다 같이 배우는게 있다.

            // Call by Value
            // Call by Reference
            // Call by Addres   <- 포인터이기때문에 안 배움.

            // Call by Value
            // 값으로 함수를 호출하는 형식
            // 값복사로 새로운 변수가 만들어진다.
            // 함수안에서 값을 바꿔도 본체의 값은 변하지 않는다.

            // Call by Reference
            // 레퍼런스로 함수를 호출하는 형식
            // 레퍼런스가 이동하는것이기 때문에 이 값을 바꾸면 본체가 바뀐다.

            int value = 1;
            CallByValue(value);
            Console.WriteLine($"[Main] value = {value}");

            CallbyReference(ref value);
            Console.WriteLine($"[Main] value = {value}");

            int value2;
            CallbyReference2(out value2);
            Console.WriteLine($"[Main] value2 = {value}");


        }

        public void Function()
        {
            Console.WriteLine("Function");
        }

        public void CallByValue(int value)
        {
            value++;
            Console.WriteLine($"[CallByValue] value = {value}");
        }

        public void CallbyReference(ref int value)
        {
            value++;
            Console.WriteLine($"[CallByReference] value = {value}");
        }

        public void CallbyReference2(out int value)
        {
            value = 3;
            Console.WriteLine($"[CallByReference2] value = {value}");
        }
    }
}
