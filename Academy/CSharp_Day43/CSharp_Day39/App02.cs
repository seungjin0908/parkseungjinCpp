using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day39
{
    // boxing과 unboxing
    public class App02
    {
        public void Run()
        {
            // object라는 자료형
            int a = 3;
            float b = 4.4f;
            bool c = false;
            string d = "AA";

            object e = null;

            //boxing
            e = a;
            e = 3;
            e = b;
            e = d;

            // 오브젝트 자료형은 모든 자료형을 다 담을수가 있습니다.
            // void*로 강제형변환해서 기억하고 있다가 다른 자료형으로 바꾸는 느낌

            // object 자료형은 기본적으로 class입니다.

            // object 는 그럼 메모리영역이 Heap영역에 있겠구나
            // int, float, bool 이런애들은 분명히 Struct 이고, Stack영역인데?

            Vector3 vector3 = new Vector3();
            e = vector3;


            //unboxing
            Vector3 f = (Vector3)e;


        }
    }

    public struct Vector3
    {
        public float X, Y, Z;
    }
}
