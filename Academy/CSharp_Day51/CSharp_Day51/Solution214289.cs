using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day51
{
    public class Solution214289
    {
        public int solution(int temperature,int t1,int t2,int a, int b, int[] onboard)
        {
            int answer = 0;

            // 우리가 배운 모든 알고리즘을 대입해 보았을때 다 안통한다.

            // 1. 탐욕(greedy) 접근
            // => 현재의 최선이 곧 미래의 최선
            //    : 내가 가장 현재에서 최선을 이어가면 결과값도 결국엔 최선의 선택지인 문제

            // 얘는 중간에 손님이 탑승하는경우에서 실패하기때문에 불가능한 알고리즘

            // 2. 완전탐색 (DFS. BFS)
            // => 이렇게하면 값은 찾아진다.
            //    경우의 수가 너무 많아지고,
            //    [중복 연산]이 많아진다.

            // 순수하게 DP문제 파악하는 방법
            // 1. 시계열 데이터, 수열(점화식) 느낌.

            // DP 문제를 어떻게 접근할것인가?
            //===================================
            // 1. DP 배열 세팅
            //===================================
            // 1. DP배열을 세팅
            // Dynamic Programming
            // 점화식 문제

            // f(n) = n + f(n);
            // 단, n이 0이하면 f(n)은 0
            // f(1) = 1 + 0;
            // f(2) = 2 + 1;

            // int[] dp = new int[100000];

            // DP의 접근은
            // 모든 경우의 수를 계산한다.
            // 다만, 중복계산은 이미 한번 계산한거를 가져온다.

            // => 그래서 핵심은 모든 경우의 수를 배열세팅을 할수있도록 만들어주는것.

            // dp[분] << 현재 지나간 시간
            // dp[분] << 모든 경우의 수를 모두 추적할수있는가?
            //       << 현재온도를 DP에 저장을 해놔야 나중에 중복연산을 피할수있다.
            // dp[분][온도]
            // dp[0][10] << 0분 지났을때 10도인 상황에서 전력 소모값.

            // dp[분][온도][에어컨on off 유무]
            //              모든 경우의수를 담을수있는 배열을 만들어준다.

            // 1000 * 50 * 2
            //  => 100000
            // 시간복잡도 100000번

            // 배열 1000짜리 두번곱하면
            // 1,000,000 까지도 웬만하면 문제없다.

            int N = onboard.Length;

            int MIN_TEMP = -10;
            int MAX_TEMP = 40;
            int OFFSET = 0;
            int temperture = 0;
            int range = MAX_TEMP - MIN_TEMP + 1;

            int[,,] dp = new int[N + 1, range, 2];
            //==========================
            // 2. DP 배열 초기화
            //==========================
            for(int i = 0;i<dp.GetLength(0);i++)
            {
                for(int j = 0;j<dp.GetLength(1);j++)
                {
                    dp[i, j, 0] = int.MaxValue;
                    dp[i, j, 1] = int.MaxValue;
                }
            }


            //==========================
            // 3. DP 시작값 세팅
            //==========================
            // dp[0,0,0] 0분에 온도는(-10) 에어컨 off

            // 0분에 시작온도 에어컨 off인 상황에서의 전력소모값
            // dp[0,temperture + OFFSET, 0]
            dp[0, temperture + OFFSET, 0] = 0;

            //==========================
            // 4. DP 알고리즘 루프 시작
            //==========================
            for(int i=0;i<=N;i++)
            {
                for(int t=0;t<range;t++)
                {
                    for(int ac=0;ac<2;ac++)
                    {
                        // dp[i,t,ac] 값을 채워주기만하면 끝.
                        if (dp[i, t, ac] == int.MaxValue) continue;

                        int currentTemp = t + MIN_TEMP;

                        // 수도코드
                        // 1. i분에 승객이 탑승중이면
                        // 1-1. 온도 제약확인후 튕겨내기.

                        // 2. i + 1분 계산
                        //    경우의 수가 에어컨이 꺼져있을때
                        //             에어컨을 키는방법
                        //             에어컨 끄는걸 유지하는 방법

                        //   경우의 수가 에어컨켜져있을때
                        //            에어컨을 켜는걸 유지하는 방법
                        //            에어컨을 끄는방법

                        // 승객이 타있을때
                        if (onboard[i] == 1)
                        {
                            if(false == (t1 <= currentTemp && currentTemp <= t2))
                            {
                                dp[i, t, ac] = int.MaxValue;
                                continue;
                            }
                        }

                        // 에어컨이 꺼져있을때
                        if(ac==0)
                        {
                            // 에어컨을 키는 방법
                            {

                            }

                            // 에어컨을 끄는 방법
                            {

                            }
                        }
                        // 에어컨이 켜져있을때
                        else
                        {

                        }
                    }
                }
            }
            return answer;
        }
    }

    // 에어컨을 껐을때 다음 온도
    // nowT : 지금 온도
    // outT : 실외 온도
    interface NextAirconOff(int nowT, int outT )
    {
      
    }
}
