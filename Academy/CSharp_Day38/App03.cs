using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day38
{
    public class App03
    {
        int _number = 0;

        // 프로퍼티는 본체는 함수
        // 함수이기때문에 네이밍 컨벤션은 파스칼케이스
        public int Number
        {
            get
            {
                return _number;
            }
            set
            {
                _number = value;
            }
        }

        // 프로퍼티 기능
        public int Variable { get; private set; } = 0;


        public int Variable2
        {
            get
            {
                return Variable + 1;
            }
        }

        public void Run()
        {
            this.Number = 3;

            Console.WriteLine($"Number : {_number}");
            Console.WriteLine($"Number : {Number}");

            Variable = 2;
            Console.WriteLine($"Variable : {Variable}");
        }

    }
}
