using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;


namespace CSharp_Day52
{
    public class Program
    {
        static void Main(string[] args)
        {
            Solution118669 sol = new Solution118669();

            //sol.TestFunction();

            {
                //[[1, 2, 3], [2, 3, 5], [2, 4, 2], [2, 5, 4], [3, 4, 4], [4, 5, 3], [4, 6, 1], [5, 6, 1]]
                int[] rv1 = sol.solution(6, new int[,] { { 1, 2, 3 }, { 2, 3, 5 }, { 2, 4, 2 }, { 2, 5, 4 }, { 3, 4, 4 }, { 4, 5, 3 }, { 4, 6, 1 }, { 5, 6, 1 } }, new int[] { 1, 3 }, new int[] { 5 });

                Console.WriteLine(String.Join(", ", rv1));
            }

            {
                //[[1, 4, 4], [1, 6, 1], [1, 7, 3], [2, 5, 2], [3, 7, 4], [5, 6, 6]]
                int[] rv1 = sol.solution(7, new int[,] { { 1, 4, 4 }, { 1, 6, 1 }, { 1, 7, 3 }, { 2, 5, 2 }, { 3, 7, 4 }, { 5, 6, 6 } }, new int[] { 1 }, new int[] { 2, 3, 4 });

                Console.WriteLine(String.Join(", ", rv1));
            }

            {
                //[[1, 2, 5], [1, 4, 1], [2, 3, 1], [2, 6, 7], [4, 5, 1], [5, 6, 1], [6, 7, 1]]
                int[] rv1 = sol.solution(7, new int[,] { { 1, 2, 5 }, { 1, 4, 1 }, { 2, 3, 1 }, { 2, 6, 7 }, { 4, 5, 1 }, { 5, 6, 1 }, { 6, 7, 1 } }, new int[] { 3, 7 }, new int[] { 1, 5 });

                Console.WriteLine(String.Join(", ", rv1));
            }

            {
                //{{1, 3, 10}, {1, 4, 20}, {2, 3, 4}, {2, 4, 6}, {3, 5, 20}, {4, 5, 6}}
                int[] rv1 = sol.solution(5, new int[,] { { 1, 3, 10 }, { 1, 4, 20 }, { 2, 3, 4 }, { 2, 4, 6 }, { 3, 5, 20 }, { 4, 5, 6 } }, new int[] { 1, 2 }, new int[] { 5 });

                Console.WriteLine(String.Join(", ", rv1));
            }
        }
    }
}
