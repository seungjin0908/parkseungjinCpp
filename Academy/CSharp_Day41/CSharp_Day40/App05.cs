using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static CSharp_Day40.App05;





namespace CSharp_Day40
{
    public class App05
    {
        public void Print<T>(T value)
        {
            Console.WriteLine(value);
        }



        public void Run()
        {
            int a = 3;
            Print(a);

            float b = 2.3f;
            Print(b);

            PriorityQueue<int> priorityQueue = new PriorityQueue<int>();

        }
    }

    public class PriorityQueue<T>
    {
        public List<T> value = new List<T>();
    }

    public interface IRepository<T>
    {
        public void Create(T item);
        public T Read(int id);
        public void Update(T item);
        public void Delete(T item);
    }

    public class Repository<T> : IRepository<T>
        where T : class, new()
    {
        public void Create(T item) => Console.WriteLine(item);
        public T Read(int id) => default(T) ?? new();
        public void Update(T item) => Console.WriteLine(item);
        public void Delete(T item) => Console.WriteLine(item);
    }
}
