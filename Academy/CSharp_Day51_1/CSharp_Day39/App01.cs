using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day39
{
    public class App01
    {
        // 연산자
        public void Run()
        {
            // 그연산자들 말고
            // C++에서 안다루는 C#만의 연산자들

            // ?, !

            // C++ 에서의 ? 
            // 삼항연산자

            int a = 3;
            int b = 2;

            int c = (a < b) ? a : b;

            // ?? 두개가 오는경우
            // ?. 
            // !. 이렇게 다뤄볼거에요.

            MyClass myClass = new MyClass();

            //C++에서 할떄는
            //클래스안의 함수를 호출할때
            if(myClass != null)
            {
                myClass.Set("10");
            }


            myClass?.Set("10");
            // ?. 앞에 레퍼런스가 null이 아니면 뒤에 함수를 실행한다.
            //    앞에 레퍼런스가 null이면 실행하지 않고 종료한다.

            myClass!.Set("10");
            // !. 은 무엇이냐
            //    myClass가 null이 아님을 내가 확신한다.

            Console.WriteLine(myClass?.A ?? "No Value");
        }
    }

    public class MyClass
    {
        private string _a;

        public string A => _a;

        public void Set(string a)
        {
            _a = a;
        }
    }
}
