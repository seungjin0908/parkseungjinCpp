using System;
using System.Collections.Generic;
using System.Linq;

public class Solution92335
{
    //수도코드
    //문제에서 물어보는 내용 : 
    // N을 K진수로 변환했을때, P 조건에 만족하는 숫자들중에 소수는 몇개인가?

    // 1. N을 K진수로 변환
    //  => N을 K로 변환하는 알고리즘
    // 2. 변환한 수중에 P 조건에 만족하는 숫자들을 가져온다.
    //  => P조건에 만족하는 숫자들을 뽑아내는 알고리즘
    // 3. 그 중에 소수는 몇개인지?
    //  => 그 수가 소수인지 판별해주는 알고리즘

    // 시간복잡도가 너무 높다.

    public int solution(int n, int k)
    {
        int answer = 0;

        string number = ConvertKDigit(n, k);

        List<string> pNumbers = ConditionP(number);

        foreach (string pNumber in pNumbers)
        {
            if(IsPrime(pNumber))
            {
                answer++;
            }
        }

        return answer;
    }

    /// <summary>
    /// N을 K진수로 변환해주는 함수
    /// </summary>
    /// <param name="n"></param>
    /// <param name="k"></param>
    /// <returns></returns>
    public string ConvertKDigit(int n, int k)
    {
        string result = "";
        while( n > 0)
        {
            result = $"{(n % k)}{result}";
            n /= k;
        }

        return result;
    }

    /// <summary>
    /// P조건 대로 나누기.
    /// </summary>
    /// <param name="number"></param>
    /// <returns></returns>
    public List<string> ConditionP(string number)
    {
        // 그냥 0이들어간 문자열로 끊어달라는 소리입니다.

        var pNumbers = number.Split('0');

        return pNumbers.Where(n => false == string.IsNullOrEmpty(n)).ToList();
    }

    public bool IsPrime(string n)
    {
        long value = long.Parse(n);
        if (value < 2) return false;

        for(long i = 2; i * i <= value; i++)
        {
            if (value % i == 0) return false;
        }

        return true;
    }
}

