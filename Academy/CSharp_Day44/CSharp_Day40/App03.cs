using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day40
{
    public class App03
    {

        public void Run()
        {
            Func<int, int, int> plus = 
                (num1, num2) => num1 + num2;


            int rv = plus.Invoke(3, 5);
            Console.WriteLine(rv);

            // lambda는 간단함수를 굳이 함수화하기 귀찮아서 만든것.
            // 보통 한줄짜리를 많이 씁니다.

            // plus라는 함수포인터에 값을 넣을건데.
            // 여기에 int, int 매게변수를 갖고 int 자료형을 반환하는 함수를 넣어야합니다.
            // 매게변수에 일단 이름을 지어주는거에요.

            // => 는 그뒤에는 한줄짜리 리턴식이 온다.
            // 그 뒤에 리턴은 내가 지은 매게변수 이름들을 갖고, 어떻게 리턴할지를 정해주는 겁니다.


        }

        public int Plus(int num1, int num2)
        {
            return num1 + num2;
        }
    }
}
