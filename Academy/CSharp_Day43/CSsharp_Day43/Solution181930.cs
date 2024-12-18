using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Solution181930
{
    public int solution(int a, int b, int c)
    {
        int answer = 0;

        // 1. 아래 케이스 중에서 현재 케이스를 골라내기
        int currentCase = GetCase(a, b, c);

        // 2. 케이스에 따라 공식 수행하기
        answer = ExecuteFormula(currentCase, a, b, c);

        return answer;
    }

    public int GetCase(int a, int b, int c)
    {
        // 1. 아래 케이스 중에서 현재 케이스를 골라내기
        //  1) 세숫자가 모두 다른지 판별
        //  2) 2개만 같은지 판별
        //  3) a,b,c가 같은지 판별

        // 코딩테스트할때 자주하는 착각
        //  - 이렇게하면 퍼포먼스 떨어지는거아니야?
        //  - i++ 이라고 적어도 될거를 ++i 라고 적는 경우가 있습니다.
        //  - 퍼포먼스는 시간복잡도로만 따지면됩니다.
        //  - 시간복잡도는 input값에 따라서 for문 길이가 달라지게되는데,
        //  - 그 for문을 몇번돌게되는가? (이중포문이냐? 삼중포문이냐?)


        if(a == b && b == c)
        {
            return 3;
        }
        
        if(a == b || b == c || a == c)
        {
            return 2;
        }

        return 1;
    }

    //공식 수행하기
    public int ExecuteFormula(int currentCase, int a, int b, int c)
    {
        // 2. 케이스에 따라 공식 수행하기
        //  1) a + b + c
        //  2) (a + b + c) × (a2 + b2 + c2 )
        //  3) (a + b + c) × (a2 + b2 + c2 ) × (a3 + b3 + c3 )

        switch(currentCase)
        {
            case 1:
                return a + b + c;
            case 2:
                return (a + b + c) * (a * a + b * b + c * c);
            case 3:
                return (a + b + c) * (a * a + b * b + c * c) * (a * a * a + b * b * b + c * c * c);
            default:
                return a + b + c;
        }
    }
}