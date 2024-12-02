using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day37
{
    public class App02
    {
        public void Run()
        {
            // 사칙연산

            //int a = 3;
            //int b = 4;

            //if(a<b)
            //{
            //    Console.WriteLine("a가 b보다 작다.");
            //}
            //else if(b<a)
            //{
            //    Console.WriteLine("b가 a보다 작다.");
            //}
            //else
            //{
            //    Console.WriteLine("a와 b가 같다.");
            //}

            // 랜덤
            // rand()
            Random random = new Random();
            int rand = random.Next(0, 3);   // 0, 1, 2
            Console.WriteLine($"random : {rand}");

            int PlayerHand1 = 0; // 가위
            int PlayerHand2 = 1; // 바위
            int PlayerHand3 = 2; // 보

            int ComputerHand1 = 0; // 가위
            int ComputerHand2 = 1; // 바위
            int ComputerHand3 = 2; // 보

            if (PlayerHand1<ComputerHand2)
            {
                Console.WriteLine($"플레이어가 졌습니다.{rand}");
            }
            else if (PlayerHand2< ComputerHand1)
            {
                Console.WriteLine($"플레이어가 이겼습니다.{rand}");
            }
            else if(PlayerHand3 == ComputerHand3)
            {
                Console.WriteLine($"비겼습니다. {rand}");
            }

            // 가위바위보 만들기.
            // 출력배웠고
            // 변수출력배웠고
            // 입력배웠고
            // 랜덤배웠다

            // 가위바위보 만들기 실습

            
        }
    }
}
