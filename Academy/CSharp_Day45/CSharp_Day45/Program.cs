namespace CSharp_Day45
{
    public class Program
    {
        static void Main(string[] args)
        {
            //Solution92335 solution92335 = new Solution92335();
            //Console.WriteLine(solution92335.solution(437674, 3));
            //Console.WriteLine(solution92335.solution(110011, 10));

            Solution118667 solution118667 = new Solution118667();
            Console.WriteLine(solution118667.solution(new int[] {3,2,7,2}, new int[] { 4,6,5,1}));
            Console.WriteLine(solution118667.solution(new int[] {1, 2, 1, 2}, new int[] { 1, 10 ,1, 2}));
            Console.WriteLine(solution118667.solution(new int[] { 1, 1 }, new int[] { 1, 5 }));
        }
    }
}
