using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day46
{
    public class Solution92342
    {
        int _maxDiffence = 0;

        
    }

    public void CaluateBestNode(Node node)
    {
        // _maxDifference, _best 두개 값과 비교하여 현재 노드가 더 상황이 좋은지 체크

        // 점수 계산

        // node.ryan, _info
        // 두배열을 검사해서 기존 점수차이 보다 많이 나면 저장.

        int ryanScore = 0;
        int appeachScore = 0;

        // 점수 계산
        for(int i = 0; i<11; i++)
        {
            // 둘다 0점을 쐈으면 그 점수는 무효
            if (_info[i] == node.ryan[i] == 0) continue;

            // 라이언이 어피치보다 많이 쐈으면
            if(node.ryan[i] > _info[i])
            {
                // 라이언이 점수 획득
                ryanScore += (10 - i);
            }
            else
            {
                appeachScore += (10 - i);
            }
        }

        int difference = ryanScore - appeachScore;

        if (difference < 0)
        {
            return;
        }

        if(_maxDiffence < difference)
        {
            // 점수 갱신
            _maxDiffence = difference;
        }
    }

    public bool CanGo(Node node)
    {
        int newArrowsRemain = node.arrowsRemain - (_info[node.index] + 1);

        if (newArrowsRemain<0)
        {
            return false;  
        }

        return true;
    }
}
