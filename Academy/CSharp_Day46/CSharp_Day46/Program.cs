using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day46
{
    public class Program
    {
        static void Main(string[] args)
        {
            //Solution92342 sol = new Solution92342();
            //Console.WriteLine(String.Join(",", sol.solution(5, new int[] { 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 })));
            //Console.WriteLine(String.Join(",", sol.solution(1, new int[] { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 })));
            //Console.WriteLine(String.Join(",", sol.solution(9, new int[] { 0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1 })));
            //Console.WriteLine(String.Join(",", sol.solution(10, new int[] { 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3 })));

            Solution92343 sol = new Solution92343();
            Console.WriteLine(String.Join(",", sol.solution(new int[] { 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1 }, new int[,] { { 0, 1 }, { 1, 2 }, { 1, 4 }, { 0, 8 }, { 8, 7 }, { 9, 10 }, { 9, 11 }, { 4, 3 }, { 6, 5 }, { 4, 6 }, { 8, 9 } })));

            Console.WriteLine(String.Join(",", sol.solution(new int[] { 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0 }, new int[,] { { 0, 1 }, { 0, 2 }, { 1, 3 }, { 1, 4 }, { 2, 5 }, { 2, 6 }, { 3, 7 }, { 4, 8 }, { 6, 9 }, { 9, 10 } })));
        }
    }
}
