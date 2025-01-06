using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Solution92342
{
    int _maxDifference = 0; //현재 가장 큰차이가 나는 점수
    int[] _best = new int[11]; 
    int[] _info = new int[11];

    public int[] solution(int n, int[] info)
    {
        int[] answer = new int[] { };
        _maxDifference = 0;
        _best = new int[11];
        _info = info;

        //DFS 를 바로 진행합니다.

        //1. Stack에 Node를 Push 한다.
        //2. while(Stack.Count > 0)
        //   Stack.Pop 후에
        //   해당 노드로 다시 갈수있는 길들을 모두 추가한다.
        //   끝나는 조건에서 best인지 체크하고 해당 값을 산출해낸다.

        Stack<Node> stack = new Stack<Node>();
        stack.Push(new Node(10, n, new int[11]));

        while(stack.Count > 0)
        {
            Node node = stack.Pop();

            // 도착했는지 체크
            // - 현재 Node가 더이상 갈곳이 없는지.
            if(node.index == 0 || node.arrowsRemain == 0)
            {
                if(node.index == 0)
                {
                    node.ryan[10] += node.arrowsRemain;
                }

                // 이게 Best인지 체크
                CalulateBestNode(node);
                continue;
            }

            if(node.arrowsRemain < 0)
            {
                Console.WriteLine("ERROR!!");
            }

            // 쏘는길로 갈수있는지 체크
            if (CanGo(node))
            {
                int[] newRyan = new int[11];
                Array.Copy(node.ryan, newRyan, 11);
                int newArrowsRemain = node.arrowsRemain - (_info[10 - node.index] + 1);
                // 점수 쏘기. (어피치가 쏜것보다 1개 더많이)
                newRyan[10 - node.index] = _info[10 - node.index] + 1;

                // Stack에 추가
                stack.Push(new Node(node.index - 1, newArrowsRemain, newRyan));
            }

            stack.Push(new Node(node.index - 1, node.arrowsRemain, node.ryan));

        }

        if(_maxDifference == 0)
        {
            return new int[] { -1 };
        }

        return _best;
    }


    public void CalulateBestNode(Node node)
    {
        // _maxDifference, _best 두개 값과 비교하여 현재 노드가 더 상황이 좋은지 체크

        // 점수 계산

        //node.ryan, _info
        // 두배열을 검사해서 기존 점수차이 보다 많이 나면 저장.

        int ryanScore = 0;
        int appeachScore = 0;

        // 점수계산
        for (int i = 0; i < 11; i++)
        {
            // 둘다 0점을 쐈으면 그 점수는 무효
            if (_info[i] == 0 && node.ryan[i] == 0) continue;

            //라이언이 어피치보다 많이 쐈으면
            if (node.ryan[i] > _info[i])
            {
                //라이언이 점수 획득
                ryanScore += (10 -i);
            }
            else
            {
                appeachScore += (10 -i);
            }
        }

        int difference = ryanScore - appeachScore;

        if(difference < 0)
        {
            return;
        }

        if(_maxDifference < difference)
        {
            // 점수 갱신
            _maxDifference = difference;
            Array.Copy(node.ryan, _best, 11);
        }
        else if(_maxDifference == difference)
        {
            // 같으면 낮은점수를 더 많이 쐈던쪽으로 리턴
            for(int i = 10; i >= 0; i--)
            {
                if (_best[i] < node.ryan[i])
                {
                    // 점수 갱신하고 break;
                    Array.Copy(node.ryan, _best, 11);
                    break;
                }
               else if (node.ryan[i] < _best[i])
                {
                    break;
                }
            }
        }


    }

    public bool CanGo(Node node)
    {
        // 쐈을때 남은 화살 갯수가 음수가 아닌지?
        int newArrowsRemain = node.arrowsRemain - (_info[10 - node.index] + 1);

        if(newArrowsRemain < 0)
        {
            return false;
        }

        return true;
    }

    public class Node
    {
        public int index;           //현재 몇점쏘고있는지
        public int arrowsRemain;    //남은 화살수
        public int[] ryan;          //현재 전광판

        public Node(int index, int arrowsRemain, int[] ryan)
        {
            this.index = index;
            this.arrowsRemain = arrowsRemain;
            this.ryan = ryan;
        }
    }



}