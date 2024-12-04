using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day38
{
    public class App05
    {
        public void Run()
        {
            // C#에서는 배열을 그렇게 많이쓰진않는다.

            // C++
            // int arr[5] ={};

            // 변수선언 공식
            // 자료형 변수명 = 값;

            // C#에서의 배열 선언
            // 자료형 변수명 = 값

            int[] arr = new int[10];
            arr[0] = 1;
            arr[1] = 2;
            //...
            int[] arr2 = new int[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

            int[] arr3 = new int[10];

            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = i;
            }

            // 이차원, 삼차원배열은 어떻게 쓰지??
            int[,] arr4 = new int[10, 10];
            for(int i = 0; i < arr.GetLength(0); i++)
            {
                for(int j = 0; j < arr.GetLength(1); j++)
                {
                    arr4[i, j] = i * 10 + j;
                }
            }

            // 배열은 언제쓰냐??
            // 코딩테스트에서 주로 리턴할때 배열써달라고한다.

            // 그때밖에 안썼다.
            // 실제로 코딩테스트 볼때도 내부구현은 배열로 안했다.

            // 배열을 다루는 다른방법


            // C++ 에서의 벡터는
            // C#에서 List
            List<int> arrList = new List<int>();

            for(int i = 0; i < 10; i++)
            {
                //arr.List().push_back();
                arrList.Add(i);
            }

            for(int i = 0;i < 10; i++)
            {
                Console.WriteLine(arrList[i]);
            }

            arrList.Clear();

        }
    }
}
