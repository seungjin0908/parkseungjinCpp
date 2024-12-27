using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace CSharp_Day46
{
    public int Solution(int[] info, int[,] edges)
    {
        int answer = 0;

        Dictionary<int, List<int>> tree = new Dictionary<int, List<int>>();

        for(int i =0;i<edges.GetLength(0);i++)
        {
            int 
        }
        Stack<Node> stack = new Stack<Node>();
        stack.Push(new Node(0, 0, 0, new List<int>() { 0 }));

        while (stack.Count > 0)
        {
            Node node = stack.Pop();

            int sheepCount = node.sheepCount;
            int wolfCount = node.wolfCount;

            if (info[node.currentNode]==0)
            {
                sheepCount++;
            }
            else
            {
                wolfCount++;
            }

            answer = Math.Max(answer, sheepCount);

            if(wolfCount > sheepCount)
            {
                continue;
            }

            List<int> nextNodes = new List<int>();
            for(int i = 0; i<node.path.Count;i++)
            {
                nextNodes.AddRange(tree[node.path[i]]);
            }
            nextNodes = nextNodes.Distinct().ToList();

            foreach(int nextNode in nextNodes)
            {
                List<int> newList = node.path.ToList();
                newList.Add(nextNode);
                stack.Push(new Node(nextNode,sheepCount,wolfCount,newList));
            }
        }
        return answer;
    }


    public class Node
    {
        public int currentNode;
        public int sheepCount;
        public int wolfCount;
        public List<int> path; // 내가 방문했던곳을 알아야. 다음 방문지를 선정할수있다.

        public Node(int currentNode, int sheepCount, int wolfCount)
    }

}
