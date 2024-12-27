using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Solution68644
{
    public int[] solution(int[] numbers)
    {
        int[] answer = new int[] { };

        // numbers에 있는 모든 문자를 서로 한번씩 더해주는 작업을 한다.
        // 그리고 새로운 숫자면 List에 추가해준다.

        //value는 안씀.
        Dictionary<int, int> dict = new Dictionary<int, int>();

        // for( i : 0 ~ numbers )
        //  for( j : i ~ numbers )

        // O(N)
        for (int i = 0; i < numbers.Length; i++)
        {
            // O(N^2)
            for (int j = i + 1; j < numbers.Length; j++)
            {
                int newNumber = numbers[j] + numbers[i];

                dict[newNumber] = 1;
            }
        }

        //dict의 모든 keys 는 한번씩은 다 더해진값
        var keyList = dict.Keys.ToList();

        keyList.Sort();

        return keyList.ToArray();
    }
}