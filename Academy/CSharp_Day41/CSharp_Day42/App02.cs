using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day42
{
    public class App02
    {

        // 하이로우세븐
        public void Run()
        {
            List<int> card=new List<int>();
            for (int i = 0; i <52;i++)
            {
                card.Add(i);
            }

            Random random= new Random();
            for (int i = 0;i <10000;i++)
            {
                int index1=random.Next(card.Count);
                int index2=random.Next(card.Count);

                int temp=card[index1];
                card[index1] = card[index2];
                card[index2] = temp;
            }

            foreach (var item in card.Take(4))
            {
                DrawCard(item);
                Console.WriteLine("\t");
            }

            Console.WriteLine("XX");

            Console.WriteLine($"베팅해주세요. 현재 금액 : {}"
        }

        private void DrawCard(int cardNum)
        {
            switch (cardNum / 13)
            {
                case 0:
                    Console.WriteLine("A");
                    break;
                case 1:
                    Console.WriteLine("B");
                    break;
                case 2:
                    Console.WriteLine("C");
                    break;
                case 3:
                    Console.WriteLine("D");
                    break;
                case 4:
                    Console.WriteLine("E");
                    break;
                case 5:
                    Console.WriteLine("F");
                    break;
                case 6:
                    Console.WriteLine("H");
                    break;
                case 7:
                    Console.WriteLine("I");
                    break;
                    case 8:


                default:
                    break;
            }
        }
    }
}
