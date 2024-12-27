namespace CSharp_Day44
{
    public class Program
    {
        static void Main(string[] args)
        {
            //Solution118666 solution118666 = new Solution118666();
            //Console.WriteLine(solution118666.solution(new string[] { "AN", "CF", "MJ", "RT", "NA" }, new int[] { 5, 3, 2, 7, 5 }));
            //Console.WriteLine(solution118666.solution(new string[] { "TR", "RT", "TR" }, new int[] { 7, 1, 3 }));

            Solution150370 solution150370 = new Solution150370();
            Console.WriteLine(String.Join(", ", solution150370.solution("2022.05.19", new string[] { "A 6", "B 12", "C 3" }, new string[] { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" })));
            Console.WriteLine(String.Join(", ", solution150370.solution("2020.01.01", new string[] { "Z 3", "D 5" }, new string[] { "2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z" })));

        }
    }
}
