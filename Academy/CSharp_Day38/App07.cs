using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day38
{
    // 구조체
    public class App07
    {
        public void Run()
        {
            Vector3 vector3 = new Vector3(0, 0, 0);
            CallByValue(vector3);
            Console.Write(vector3.y);


            Transform transform = new Transform();
            transform.Position.y = 10;

            Console.WriteLine(transform.Position.y);
            CallByValue(transform);
            Console.WriteLine(transform.Postiton.y);
        }

        public void CallByValue(Vector3 value)
        {
            value.y = 10;
        }

        public void CallByValue(Transform transform)
        {
            transform.Postition.y = 20;
        }
    }


    public struct Vector3
    {
        float x;
        float y;
        float z;

        public Vector3(float x, float y, float z)
        {
            this.x = x; 
            this.y = y; 
            this.z = z;
        }
    }

    public class Transform
    {  

    }


}
