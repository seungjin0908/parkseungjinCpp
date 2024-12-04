using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day38
{
    public class App06
    {
        public void Run()
        {
            // 클래스 객체 생성
            MyClass myClass = new MyClass();

            // C#은 자동으로 메모리가 관리되는 Managed Language이다.
            // 그렇기 때문에 삭제를 하고싶다고 마음대로 삭제할 수 있지 않다.
            // myClass = null;

            // Garbage Colloction이 참조하고 있지않은 메모리를 알아서 삭제할때
            // 소멸자가 호출된다.

            // 그래서 나온 인터페이스가 있다.
            // 인터페이스가 뭐냐??
            // C++로 따지면 함수만 가지고 있는 클래스이다.

            // myClass.Dispose();


            // 강제로 소멸시키는 방법.
            // 중괄호 동안에만 myClass2가 존재한다.
            // using은 IDisposable 인터페이스와 함께한다.
            using (MyClass myClass2  =new MyClass())
            {

            }


            // C# 클래스의 비밀
            // C# 클래스는 단일상속만 허용한다.  (여러개 하고 싶으면 인터페이스로 받아야함)

            // C++은 멀티상속 가능하다. (굳이 안함.)
            //                        (보통 회사에서 컨벤션으로 막아둠.)

            // C# 클래스는 무조건 힙영역에 메모리가 생성된다.
            // **Class - Heap , Struct - Stack**

            // C++은 new한거는 힙이고, new 안한거는 다 스택이었다.

            // Heap영역은 아까도 봤듯이
            // 메모리 해제시점이 우리가 알 수 없다.
            // GC에 맡겨야한다.

            // Stack은 그냥 스코프 끝나면 알아서 삭제된다.


            // 클래스는 Heap이라고 했다.
            // 기본적으로 Heap은 무조건 포인터라고 생각하면 된다.

            // CallByValue로 호출해도
            // 포인터이기 때문에, 함수 안에서 값이 수정된다.

            MyClass myClass1 = new MyClass();
            CallByValue(myClass1);
        }
    }

    public void CallByValue(MyClass myClass)
    {

    }

    public class MyClass : IDisposable
    {
        public int AAA = 3;
        // 생성자
        public MyClass()
        {

        }
    }



    public class MyClass
    {
        // 생성자
        public MyClass()
        {
            Console.WriteLine("MyClass 생성자 호출");
        }

        ~MyClass()
        {
            Console.WriteLine("MyClass 소멸자 호출");
        }
    }
}
