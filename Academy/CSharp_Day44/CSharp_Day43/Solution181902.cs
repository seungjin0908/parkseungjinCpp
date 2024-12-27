using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Solution181902
{
    public int[] solution(string my_string)
    {
        int[] answer = new int[] { };


        // 1. list 공간 확보 (52칸) 
        List<int> list = new List<int>();
        for (int i = 0; i < 52; i++)
        {
            list.Add(0);
        }

        // 2. mystring을 읽으면서 list에 값하나씩 추가하기
        for (int i = 0; i < my_string.Length; i++)
        {
            //대문자인가?
            char c = my_string[i];
            if('a' <= c && c <= 'z')
            {
                //소문자 문자 사용 증가
                list[26 + c - 'a']++;
            }
            else
            {
                list[c - 'A']++;
            }
        }

        return list.ToArray();
    }
}