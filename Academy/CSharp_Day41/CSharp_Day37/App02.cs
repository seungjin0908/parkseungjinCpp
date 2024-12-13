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
            // 논리연산
            // 비교연산

            // 연산자 세트들 배우는데

            // ++, -- , +=, *, / , %, -, +, &&, ||, ==, != , <, >=

            // 굳이 안하겠습니다. (C++과 완전 동일)

            // if문도 완전동일
            int a = 3;
            int b = 4;

            if (a < b)
            {
                Console.WriteLine("a가 b보다 작습니다.");
            }
            else if (b < a)
            {
                Console.WriteLine("b가 a보다 작습니다.");
            }
            else
            {
                Console.WriteLine("a와 b가 같습니다.");
            }

            // 랜덤
            // rand()
            Random random = new Random();
            int rand = random.Next(0, 3);   // 0, 1, 2
            Console.WriteLine($"random : {rand}");

            //가위바위보 만들기.
            //출력배웠고
            //변수출력배웠고
            //입력배웠고
            //랜덤배운

            // 가위바위보 만들기 실습
            // 15분 드리겠습니다.

            // C#동안에는 숙제 웬만해선 안낼거에요
            // Windows API 포트폴리오 만드는데에 집중해주세요.


            // 반복문도 다를게없습니다.
        }
    }
}
