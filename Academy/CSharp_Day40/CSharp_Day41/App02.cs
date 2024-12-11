using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day41
{
    public class App02
    {

        public void Run()
        {
            List<int> list = new List<int>();

            for (int i = 0; i < 10; i++)
            {
                list.Add(i);
            }

            // 0 ~ 9 까지 들어가있다.

            // 간단하게 list에서 짝수만 리스트로 다시 뽑아보는 코드를 짜보겠다.


            //------------------------------------------
            //  1번째 방법
            //------------------------------------------
            List<int> newList = new List<int>();

            foreach (int i in list)
            {
                if(i % 2 == 1)
                {
                    newList.Add(i);
                }
            }


            //------------------------------------------
            //  2번째 방법
            //------------------------------------------
            List<int> newList2 =list.Where(i => i % 2 == 1).ToList();
        }
    }
}
