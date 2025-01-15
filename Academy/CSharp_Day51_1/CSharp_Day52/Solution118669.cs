using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// C# 버전에 따라 우선순위큐가 있을수도있고 없을수도있습니다.
class PriorityQueue<T> where T : IComparable<T>
{
    private List<T> _arr = new List<T>();

    public T Peek()
    {
        if (_arr.Count <= 0)
        {
            throw new InvalidOperationException("배열이 비어있습니다.");
        }
        return _arr[0];
    }

    public bool Empty()
    {
        return _arr.Count == 0;
    }

    private void Swap(int index1, int index2)
    {
        T temp = _arr[index1];
        _arr[index1] = _arr[index2];
        _arr[index2] = temp;
    }

    public void Pop()
    {
        //1. 루트와 마지막노드를 스왑해준다.
        Swap(0, _arr.Count - 1);

        //2. 스왑후에 마지막 노드를 삭제한다.
        _arr.RemoveAt(_arr.Count - 1);

        // 위에서부터 도장깨기
        int index = 0;

        // * validation check
        if (_arr.Count() == 0)
            return;

        while (true)
        {
            //왼쪽인덱스가 없다면 (왼쪽 인덱스가 사이즈보다 더 크다면)
            //  -> 자식이 더이상 없다면
            if (_arr.Count - 1 < GetLeftChildIndex(index))
            {
                break;
            }

            // 1. 왼쪽노드만 있을때 
            //  -> 오른쪽 인덱스가 사이즈보다 더크면
            if (_arr.Count - 1 < GetRightChildIndex(index))
            {
                // 왼쪽이랑만 비교하면 됩니다.
                int leftNodeIndex = GetLeftChildIndex(index);
                T leftNode = _arr[leftNodeIndex];

                //CompareTo 결과값 3개
                // -1 : 왼쪽이 더 작다. (함수호출한쪽이 더작다)
                // 0 : 둘이 같다.
                // 1 : 오른쪽이 더 크다. (매게변수쪽이 더크다)

                //자식이 더크면
                if (0 < _arr[index].CompareTo(leftNode))
                {
                    // 스왑을 해준다.
                    this.Swap(leftNodeIndex, index);

                    // 인덱스를 그에 맞게 세팅해준다.
                    index = GetLeftChildIndex(index);
                }
                else
                {
                    break;
                }
            }
            // 2. 오른쪽노드도 있을때
            else
            {
                //왼쪽 노드와 오른쪽 노드중에 큰거랑 비교한다.
                int leftNodeIndex = GetLeftChildIndex(index);
                T leftNode = _arr[leftNodeIndex];
                int rightNodeIndex = GetRightChildIndex(index);
                T rightNode = _arr[rightNodeIndex];

                //자식이 더크면
                if (0 < rightNode.CompareTo(leftNode))
                {
                    if (0 < _arr[index].CompareTo(leftNode))
                    {
                        // 스왑을 해준다.
                        this.Swap(leftNodeIndex, index);

                        // 인덱스를 그에 맞게 세팅해준다.
                        index = GetLeftChildIndex(index);
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (0 < _arr[index].CompareTo(rightNode))
                    {
                        // 스왑을 해준다.
                        this.Swap(rightNodeIndex, index);

                        // 인덱스를 그에 맞게 세팅해준다.
                        index = GetRightChildIndex(index);
                    }
                    else
                    {
                        break;
                    }
                }
            }

        }
    }


    public void Push(T data)
    {
        // 1. 마지막에 데이터를 추가한다.
        _arr.Add(data);

        // 아래서부터 위로 도장깨기를 한다.
        int index = _arr.Count - 1;

        while (true)
        {
            if (index <= 0) break;

            // 부모노드와 현재 노드를 비교한다.
            int parentNodeIndex = GetParentIndex(index);
            T parentNode = _arr[parentNodeIndex];
            T currentNode = _arr[index];

            // 부모가 자식보다 작으면 
            if (0 < parentNode.CompareTo(currentNode))
            {
                //스왑해준다.
                this.Swap(parentNodeIndex, index);

                index = GetParentIndex(index);
            }
            else
            {
                break;
            }
        }
    }

    private int GetParentIndex(int index)
    {
        int rv = (index - 1) / 2;

        return rv;
    }

    private int GetLeftChildIndex(int index)
    {
        int rv = (index * 2) + 1;
        return rv;
    }

    private int GetRightChildIndex(int index)
    {
        int rv = (index * 2) + 2;
        return rv;
    }
};


public class Solution118669
{
    public class Edge
    {
        //To (From 은 Graph 변수에 인덱스로 존재)
        public int Node { get; set; }

        public int Cost { get; set; }

        public Edge(int node, int cost)
        {
            Node = node;
            Cost = cost;
        }
    }

    public int[] solution(int n, int[,] paths, int[] gates, int[] summits)
    {
        int[] answer = new int[] { };

        // Log(N)
        //Dictionary<int, List<Edge>> graph = new Dictionary<int, Edge>();

        // 0번째는 비어두고 1번째부터 N까지 사용하기 위해.
        List<Edge>[] graph = new List<Edge>[n + 1];

        for(int i = 1; i <= n; i++)
        {
            graph[i] = new List<Edge>(); ;
        }

        for(int i=0;i<paths.GetLength(0);i++)
        {
            int from = paths[i,0];
            int to = paths[i,1];
            int cost = paths[i,2];

            graph[from].Add(new Edge(to, cost));
            graph[to].Add(new Edge(from, cost));
        }

        // summits
        // 도착지
        // 도착지를 검색하기위해 summits.Count 번을 매번 순회하는건 비효율적이다.
        // O(N)

        // O(LogN) => Dictionary 나 Tree 사용.
        // O(1) => HashSet을 사용하면 된다.

        var summitSet=new HashSet<int>(summits);

        // 비용 : O(1)
        //summitsSet.Contains(0);

        // List(vector)의 Contains 비용 : O(N)
        // Dictionary, BinaryTree의 Contains 비용 : O(LogN)

        // 몇번노드의 비용이 지금 몇이냐?
        var intensity = new int[n + 1];
        for(int i=0;i<intensity.Length;i++)
        {
            intensity[i] = int.MaxValue;
        }

        var pq = new PriorityQueue<PQNode>();
        foreach(int gate in gates)
        {
            pq.Push(new PQNode(gate, 0));
            intensity[gate] = 0;
        }

        while(!pq.Empty())
        {
            var current = pq.Peek();
            pq.Pop();

            int currentNode = current.Id;
            int currentIntensity = current.MaxIntensity;

            // 여기까지 온 길이 여태 저장된 길보다 비싸면 굳이 추가로 계산할 이유가 없다.
            if (intensity[currentNode] < currentIntensity) continue;

            // 지금 온 노드가 summit이면, 이 노드의 계산은 끝내면 된다.
            // Array, List 의 Contains => O(N)
            // HashSet의 Contains => O(1)
            if (summitSet.Contains(currentNode)) continue;

            // 갈 수 있는 길은 모두 다시 추가해준다.
            foreach(var edge in graph[currentNode])
            {
                int newIntensity = Math.Max(edge.Cost, currentIntensity);

                // intensity가 더 싸면 이길로 기억하게끔.
                if(newIntensity < intensity[edge.Node])
                {
                    intensity[edge.Node] = newIntensity;
                    pq.Push(new PQNode(edge.Node, newIntensity));
                }
            }
        }

        int minIntensity = int.MaxValue;
        int minSummit = -1;
        Array.Sort(summits);
        foreach(int summit in summits)
        {
            // 가장싼 산봉우리 번호랑, 비용 기억
            if (intensity[summit] < minIntensity)
            {
                minIntensity = intensity[summit];
                minSummit = summit;
            }
        }


        return new int[] { minIntensity, minSummit };
    }

    //public void TestFunction()
    //{
    //    PriorityQueue<int> priorityQueue = new PriorityQueue<int>();
    //    priorityQueue.Push(1000);
    //    priorityQueue.Push(2000);
    //    priorityQueue.Push(300);
    //    priorityQueue.Push(-300);

    //    priorityQueue.Push(3000);
    //    priorityQueue.Push(1500);
    //    priorityQueue.Push(1501);
    //    priorityQueue.Push(1502);
    //    priorityQueue.Push(1503);
    //    priorityQueue.Push(1504);
    //    priorityQueue.Push(1505);
    //    priorityQueue.Push(1506);


    //    while (false == priorityQueue.Empty())
    //    {
    //        var top = priorityQueue.Peek();
    //        Console.WriteLine(top);
    //        priorityQueue.Pop();
    //    }
    //}

    public class PQNode : IComparable<PQNode>
    {
        public int Id {  get; set; }

        public int MaxIntensity { get; set; }

        public PQNode(int id, int maxIntensity)
        {
            Id = id;
            MaxIntensity = maxIntensity;
        }

        public int CompareTo(PQNode other)
        {
            if (MaxIntensity == other.MaxIntensity) return Id.CompareTo(other.Id);
            return MaxIntensity.CompareTo(other.MaxIntensity);
        }
    }

}