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
            Vector3 vector3 = new Vector3(0,0,0);
            CallByValue(vector3);

            Console.WriteLine("구조체 값 변경 함수 호출:");
            Console.WriteLine(vector3.y);
            Console.WriteLine("--------------------------");

            Transform transform = new Transform();
            Console.WriteLine("클래스 값 변경 함수 호출:");
            CallByValue(transform);
            Console.WriteLine(transform.Position.y);
            Console.WriteLine("--------------------------");


            // 생각하는시간 10분
            Console.WriteLine("클래스안의 구조체 값 변경 함수 호출:");
            transform.Position.Set(10, 10, 10);     // 사용 금지.
            Console.WriteLine(transform.Position.y);
            Console.WriteLine("--------------------------");

            //Transform - Heap 영역 (Reference Type)
            //Vector3 - Stack 영역 (Value Type)
            //transorm.Position - 프로퍼티로 get과 set으로 가져오고 있음. (함수로 컨트롤)
            // 프로퍼티는 본질적으로 함수

            //transform.Position.Set(10, 10, 10);
            //transform.Position << 이게 발동
            // transform.Position < get 프로퍼티로 발동
            //      (transorm.Position - Value Type) (Heap 영역안에있는 Value-Type)
            // transform.Position < 값이 복사가 됩니다.
            // 가짜 Position.Set(10, 10, 10);
            // 해주면 당연히 진짜에서는 변화가 없겠죠.



            Console.WriteLine("클래스안의 함수에서 구조체 값 변경 함수 호출:");
            transform.SetPosition(5, 5, 5);
            Console.WriteLine(transform.Position.y);
            Console.WriteLine("--------------------------");


            Console.WriteLine("새로운 변수 대입");
            Vector3 newPosition = transform.Position;
            newPosition.Set(100, 100, 100);
            transform.Position = newPosition;
            Console.WriteLine(transform.Position.y);
            Console.WriteLine("--------------------------");
        }

        public void CallByValue(Vector3 value)
        {
            value.y = 10;
        }

        public void CallByValue(Transform transform)
        {
            Vector3 position = transform.Position;
            position.y = 20;

            transform.Position = position;
        }
    }


    public struct Vector3
    {
        public float x;
        public float y;
        public float z;

        public Vector3(float  x, float y, float z)
        {
            this.Set(x, y, z);
        }

        public void Set(float x, float y, float z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }

    }

    public class Transform
    {
        //public Vector3 Position = new Vector3(0, 0, 0);
        //public Vector3 Position => _position;
        public Vector3 Position
        {
            get
            {
                return _position;
            }
            set
            {
                _position = value;
            }
        }

        private Vector3 _position;

        public void SetPosition(float x, float y, float z)
        {
            Vector3 position = Position;
            position.Set(x, y, z);
            _position = position;
        }
    }
}

// 구조체는 Stack에 생성이되고
// 클래스는 Heap에 생성이 됩니다.

// Stack같은 경우에는 Value Type이기 떄문에 매게변수로 넘겼을때 Value가 넘어가요.
// Heap 같은 경우에는 Reference가 넘어갈수밖에 없습니다. (왜냐하면 포인터처럼 주솟값 자체로 넘어갑니다.)
//      매게변수로 클래스 자료형을 넘기면, 값이 수정이 됩니다.