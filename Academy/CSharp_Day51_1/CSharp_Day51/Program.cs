using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day51
{
    public class Program
    {
        static void Main(string[] args)
        {
            Solution214289 sol = new Solution214289();

            // 40 
            Console.WriteLine(sol.solution(28, 18, 26, 10, 8, new int[] { 0, 0, 1, 1, 1, 1, 1}));
            // 25
            Console.WriteLine(sol.solution(-10, -5, 5, 5, 1, new int[] { 0, 0, 0, 0, 0, 1, 0 }));
            // 20
            Console.WriteLine(sol.solution(11, 8, 10, 10, 1, new int[] { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1 }));
            // 60
            Console.WriteLine(sol.solution(11, 8, 10, 10, 100, new int[] { 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1 }));
        }
    }
}
