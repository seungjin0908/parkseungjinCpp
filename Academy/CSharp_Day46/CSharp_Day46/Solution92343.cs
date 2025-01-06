using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Solution92343
{
    public int solution(int[] info, int[,] edges)
    {
        int answer = 0;

        //Edge 정보를 알수있는 Dictionary
        //<노드번호, 해당 노드에서 갈수있는 노드 리스트>
        Dictionary<int, List<int>> tree = new Dictionary<int, List<int>>();

        for(int i = 0; i < edges.GetLength(0); i++)
        {
            int from = edges[i, 0];
            int to = edges[i, 1];

            if (false == tree.ContainsKey(from))
            {
                tree[from] = new List<int>();
            }

            tree[from].Add(to);
        }



        Stack<Node> stack = new Stack<Node>();
        stack.Push(new Node(0, 0, 0, new List<int>() { 0 }));

        while (stack.Count > 0)
        {
            Node node = stack.Pop();

            int sheepCount = node.sheepCount;
            int wolfCount = node.wolfCount;

            // 도착해서 처리할내용들 처리하기
            if (info[node.currentNode] == 0)
            {
                sheepCount++;
            }
            else
            {
                wolfCount++;
            }

            //양 최대 갯수 갱신
            answer = Math.Max(answer, sheepCount);

            // 도착했는지 체크
            // - 현재 Node가 더이상 갈곳이 없는지.
            if(wolfCount > sheepCount)
            {
                continue;
            }

            List<int> nextNodes = new List<int>(node.path);
            //현재 노드를 지우고 갈수있는길 추가
            nextNodes.Remove(node.currentNode);

            if (tree.ContainsKey(node.currentNode))
            {
                foreach(int i in tree[node.currentNode])
                {
                    nextNodes.Add(i);
                }
            }


            //갈수있는길 모두 추가
            foreach(int nextNode in nextNodes)
            {
                stack.Push(new Node(nextNode, sheepCount, wolfCount, nextNodes));
            }

        }
        return answer;
    }

    public class Node
    {
        public int currentNode;
        public int sheepCount;
        public int wolfCount;
        public List<int> path; // 내가 방문했던곳을 알아야. 다음 방문지를 선정할수있습니다.

        public Node(int currentNode, int sheepCount, int wolfCount, List<int> path)
        {
            this.currentNode = currentNode;
            this.sheepCount = sheepCount;
            this.wolfCount = wolfCount;
            this.path = path;
        }
    }
}
