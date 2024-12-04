using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day38
{
    public enum ERockScissorPaper
    {
        Scissor=0,
        Rock=1,
        Paper=2,

        count
    };

    public class App01
    {
        public void Run()
        {
            Console.WriteLine("가위바위보 시작");

            Console.WriteLine("가위(0),바위(1),보(2) 중에 원하는걸 골라주세요");

            string input = Console.ReadLine() ?? "";
            // ?? 연산자 => default값, 지정
            // 앞에결과가 null이면, 뒤에 결과로 받아준다.

            int playerHand = 0;
            int comHand = 0;

            string a = " Trim ";

            switch (input.Trim())
            {
                case "가위":
                    playerHand = (int)ERockScissorPaper.Scissor;
                    break;
                case "바위":
                    playerHand = (int)ERockScissorPaper.Rock;
                    break;
                case "보":
                    playerHand = (int)ERockScissorPaper.Paper;
                    break;
                default:
                    playerHand = (int)ERockScissorPaper.Scissor;
                    break;
            }

            Random random = new Random();

            comHand = random.Next((int)ERockScissorPaper.count);

            // 출력
            switch (playerHand)
            {
                case (int)ERockScissorPaper.Scissor:
                    Console.WriteLine("가위");
                    break;
                case (int)ERockScissorPaper.Rock:
                    Console.WriteLine("바위");
                    break;
                case (int)(ERockScissorPaper.Paper):
                    Console.WriteLine("보");
                    break;
                default:
                    break;
            }

        }
    }
    
}
