using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSsharp_Day43
{
    public class App02
    {
        public void Run()
        {
            string a = "12345";

            a.MyFunction();


            int b = 3;

            Console.WriteLine(b.IsBetween(2, 6));
            Console.WriteLine(b.IsBetween(10, -3));
            Console.WriteLine(b.IsBetween(10, 13));


            // 데이터 파싱하시는 방법에대해서 자기만의 함수로 Extensions 묶어서 다니는사람도 있고

            // 여러가지 잡다한 함수들을 묶어서 가지고 다니시는 분들 
        }
    }
}
