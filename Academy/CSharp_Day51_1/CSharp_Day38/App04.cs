using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day38
{
    //반복문
    public class App04
    {
        public void Run()
        {
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine($"i = {i}");
            }

            for (int i = 0; false; i++)
            {
                Console.WriteLine($"i = {i}");
            }

            // C 나 C++은 조건식에
            // 0이아닌 수가들어가면 true처리 였지만
            // C#은 boolean 자료형만 받을수있습니다.

            
            while(false)
            {

            }

            do
            {

            } while (false);

            //실습
            // 별찍기
            //*****
            //****
            //***
            //**
            //*

            //*****
            // ****
            //  ***
            //   **
            //    *

            //*
            //**
            //***
            //****
            //*****

            //    *
            //   **
            //  ***
            // ****
            //*****



            for (int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    if(i <= j)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();
            }

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (j <= i)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();
            }

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (j < 5 - i)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();
            }

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (i >= 4 - j)
                    {
                        Console.Write("*");
                    }
                    else
                    {
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();
            }


            // 업다운게임
            // 숫자 컴퓨터가 하나 랜덤으로 고르고
            // (1 ~ 100)
            // 사용자가 숫자계속입력해서
            // UP
            // DOWN
            // 정답
            // 중에 하나 말하도록.
            Console.WriteLine("업다운 게임");

            Random random = new Random();
            int randValue = random.Next(1, 101);

            while (true)
            {
                int userInput = int.Parse(Console.ReadLine() ?? "50");

                if(userInput < randValue)
                {
                    Console.WriteLine($"UP");
                }
                else if (randValue < userInput)
                {
                    Console.WriteLine($"DOWN");
                }
                else
                {
                    Console.WriteLine("정답!");
                    break;
                }

            }

        }
    }
}
