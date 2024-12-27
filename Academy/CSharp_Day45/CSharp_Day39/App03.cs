using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day39
{
    // 상속과 클래스
    public class App03
    {
        public void Run()
        {
            //Animal animal = new Animal();
            Animal animal = new Dog();

            animal.Init();
            animal.Cry();
        }
    }

    // abstract < 추상 클래스
    public abstract class Animal()
    {
        public abstract void Cry();
        public virtual void Init()
        {
            Console.WriteLine("Animal Init");
        }
    }

    public class Dog : Animal
    {
        public override void Cry()
        {
            Console.WriteLine("멍멍");
        }

        public override void Init()
        {
            base.Init();
            // base.Init()
            // Animal::Init();

            Console.WriteLine("Dog Init");
        }
    }
}
