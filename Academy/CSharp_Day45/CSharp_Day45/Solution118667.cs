using System;
using System.Collections.Generic;
using System.Linq;

public class Solution118667
{
    public int solution(int[] queue1, int[] queue2)
    {
        int answer = -1;

        //1.큐1, 큐2의 합을 구한다.
        //2. for (0 ~큐1 Length + 큐2 Length + 큐1 Length) 하는 동안
        //3.더높은곳 pop, 더 작은곳 insert 진행.
        //4.합이 같아지면 횟수 return.
        //5.for문 탈출하면 - 1 리턴

        //long sum1 = queue1.Sum();
        //long sum2 = queue2.Sum();

        long sum1 = 0;
        long sum2 = 0;
        foreach(int item in queue1)
        {
            sum1 += item;
        }
        foreach (int item in queue2)
        {
            sum2 += item;
        }

        Queue<int> myQueue1 = new Queue<int>(queue1);
        Queue<int> myQueue2 = new Queue<int>(queue2);

        long totalSum = sum1 + sum2;

        if (totalSum % 2 != 0) return -1;

        long targetSum = totalSum / 2;

        int operationMax = Math.Max(queue1.Length * 2 + queue2.Length, queue2.Length * 2 + queue1.Length);
        for (int operation = 0; operation < operationMax; operation++)
        {
            if (sum1 == targetSum) return operation;

            //그리디 알고리즘
            if(targetSum < sum1)
            {
                int moved = myQueue1.Dequeue();
                sum1 -= (long)moved;
                sum2 += (long)moved;
                myQueue2.Enqueue(moved);
            }
            else
            {
                int moved = myQueue2.Dequeue();
                sum2 -= (long)moved;
                sum1 += (long)moved;
                myQueue1.Enqueue(moved);
            }
        }

        return answer;
    }
}