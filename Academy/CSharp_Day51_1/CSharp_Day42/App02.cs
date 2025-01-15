using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day42
{
    public class App02
    {
        List<int> _cards = new List<int>();
        int _money = 10000;
        int _currentCardNum = 4;
        //하이로우세븐
        public void Run()
        {
            // 수도 코드

            // 52장 트럼프 카드를 세팅한다
            // 카드를 섞는다
            // 4장을 오픈하고 한장을 숨김처리해서 보여준다
            // 사용자가 베팅 및 하이 / 로우 / 세븐을 고른다
            // 숨김처리한 카드를 보여주고 베팅 결과를 알려준다
            // 카드가 한장씩 밀린다

            //int[] card = new int[52];

            // 52장 트럼프 카드를 세팅한다
            for (int i = 0; i < 52; i++)
            {
                _cards.Add(i);
            }


            // 카드를 섞는다
            Random random = new Random();
            for (int i = 0; i < 10000; i++)
            {
                int index1 = random.Next(_cards.Count);
                int index2 = random.Next(_cards.Count);

                int temp = _cards[index1];
                _cards[index1] = _cards[index2];
                _cards[index2] = temp;
            }


            while (0 < _money || _currentCardNum == 52)
            {
                // 4장을 오픈하고 한장을 숨김처리해서 보여준다
                foreach (var item in _cards.Skip(_currentCardNum - 4).Take(4))
                {
                    DrawCard(item);
                    Console.Write("\t");
                }

                // 1장만 XX 처리
                Console.WriteLine("XX");

                Console.WriteLine($"베팅 금액을 알려주세요. 현재 금액 : {_money}");
                bool isBetSuccess = false;
                int bet = 0;
                while (isBetSuccess == false)
                {
                    string value = Console.ReadLine() ?? "";
                    bet = int.Parse(value);

                    if (bet < 0 || _money < bet)
                    {
                        isBetSuccess = false;
                    }
                    else
                    {
                        isBetSuccess = true;
                    }
                }

                Console.WriteLine($"하이 로우 세븐을 알려주세요.");
                string choice = "";

                while (false == (choice == "하이" || choice == "로우" || choice == "세븐"))
                {
                    choice = Console.ReadLine() ?? "";
                }

                int cardNum = _cards[_currentCardNum] % 13 + 1;

                _money -= bet;
                switch (choice)
                {
                    case "하이":
                        if (7 < cardNum)
                        {
                            _money += bet * 2;
                        }
                        break;
                    case "로우":
                        if (cardNum < 7)
                        {
                            _money += bet * 2;
                        }
                        break;
                    case "세븐":
                        if (cardNum == 7)
                        {
                            _money += bet * 10;
                        }
                        break;
                    default:
                        break;
                }

                _currentCardNum++;
            }
            Console.WriteLine($"게임이 종료되었습니다. 현재 금액 : {_money}");
        }

        private void DrawCard(int cardNum)
        {
            switch(cardNum / 13)
            {
                case 0:
                    Console.Write("♤");
                    break;
                case 1:
                    Console.Write("◆");
                    break;
                case 2:
                    Console.Write("♥");
                    break;
                case 3:
                    Console.Write("♧");
                    break;
                default:
                    Console.Write("○");
                    break;
            }
            switch(cardNum % 13)
            {
                case 0:
                    Console.Write("A");
                    break;
                case 10:
                    Console.Write("J");
                    break;
                case 11:
                    Console.Write("Q");
                    break;
                case 12:
                    Console.Write("K");
                    break;
                default:
                    Console.Write($"{cardNum % 13 + 1}");
                    break;
            }
        }
    }
}
