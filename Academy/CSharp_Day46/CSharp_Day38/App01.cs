using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day38
{
    public enum ERockScissorPaper
    {
        Scissor = 0,
        Rock = 1,
        Paper = 2,

        Count
    }


    public class App01
    {
        public void Run()
        {
            Console.WriteLine("가위바위보 시작");

            Console.WriteLine("가위, 바위, 보 중에 원하는걸 골라주세요");

            string input = Console.ReadLine() ?? "";
            // ?? 연산자 => default값 지정.
            // 앞에결과가 null이면, 뒤에 결과로 받아준다.

            int playerHand = 0;
            int comHand = 0;

            //string을 다룰때는 항상
            // Trim을 써주시는게 좋습니다.
            // Trim이 뭔데요??
            // 
            string a = " Trim ";
            //a를 출력하면 [ Trim ]
            //a.Trim() => [Trim]
            // Trim은 
            // 탭 / 공백 / 줄띄움 문자를 모두 삭제시킨다.

            //C# 7인가 8에서 새로나온 switch 기능
            playerHand = input.Trim() switch
            {
                "가위" => (int)ERockScissorPaper.Scissor,
                "바위" => (int)ERockScissorPaper.Rock,
                "보" => (int)ERockScissorPaper.Paper,
                _ => (int)ERockScissorPaper.Scissor
            };

            Random random = new Random();

            //Rock Scissor Paper중에 하나를 골라라.
            comHand = random.Next((int)ERockScissorPaper.Count);

            //출력
            Console.Write("플레이어 : ");
            PrintHand((ERockScissorPaper)playerHand);
            Console.Write("\n");


            //출력
            Console.Write("상대방 : ");
            PrintHand((ERockScissorPaper)comHand);
            Console.Write("\n");


            if (playerHand == comHand)
            {
                Console.WriteLine("무승부입니다.");
            }
            else if( (playerHand == (int)ERockScissorPaper.Rock && comHand == (int)ERockScissorPaper.Paper) 
                || (playerHand == (int)ERockScissorPaper.Scissor && comHand == (int)ERockScissorPaper.Rock)
                || (playerHand == (int)ERockScissorPaper.Paper && comHand == (int)ERockScissorPaper.Scissor)
                )
            {
                Console.WriteLine("컴퓨터의 승리입니다.");
            }
            else
            {
                Console.WriteLine("플레이어의 승리입니다.");
            }
        }

        public void PrintHand(ERockScissorPaper hand)
        {
            switch (hand)
            {
                case ERockScissorPaper.Scissor:
                    Console.Write("가위");
                    break;
                case ERockScissorPaper.Rock:
                    Console.Write("바위");
                    break;
                case ERockScissorPaper.Paper:
                    Console.Write("보");
                    break;
                default:
                    Console.Write("가위");
                    break;
            }
        }
    }
}
