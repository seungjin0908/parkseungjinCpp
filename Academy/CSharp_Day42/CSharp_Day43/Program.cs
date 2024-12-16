namespace CSharp_Day43
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //App01 app01 = new App01();
            //app01.Run();

            //App02 app02 = new App02();
            //app02.Run();

            Solution sol = new Solution();
            Console.WriteLine(sol.solution(2, 6, 4));
            Console.WriteLine(sol.solution(5, 3, 3));
            Console.WriteLine(sol.solution(4, 4, 4));


            string s = "abc";

            for(int i = 0; i < s.Length; i++)
            {
                char c = s[i];

                if('a'<=c &&  c <= 'z')
                {
                    // 소문자를 대문자로 바꾸는 방법

                    Console.WriteLine(s[i] + ('A' - 'a'));
                }
            }
        }
    }
}
