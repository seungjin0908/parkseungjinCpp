using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day39
{
    // Dictionary
    // 코딩테스트와 많이 연관있습니다.
    public class App06
    {
        public void Run()
        {
            // Dictionary
            //   => map

            Dictionary<string, int> myDict = new Dictionary<string, int>();

            //데이터 넣는 1번째 방법
            myDict.Add("banana", 3);

            //데이터 넣는 2번째 방법
            myDict["banana"] = 3;

            //이런키가 존재하나요?
            // 얘는 자주써도 상관없습니다. O(LogN)
            if (myDict.ContainsKey("banana"))
            {
            }

            //이런값이 존재하나요?
            // O(N)
            if (myDict.ContainsValue(3))
            {
                
            }

            //myDict.Remove

            foreach (var element in myDict)
            {
            }

            //매니저에서 대부분 map으로 관리했죠.
            Console.WriteLine(myDict["banana"]);


            // 타입추론 자료형
            var AA = myDict["banana"];

            // C++에서 auto

            // 새로운 언어 배울때
            // 빠르게 익숙해지는 법

            // 어떤 언어던 콘솔창이 없는 언어 없습니다.

            // 가위 바위 보   << 새로운언어 배울때 10분 배워보고 바로 만들어봐요.
            // 숫자야구, 업다운

            // 하이로우세븐 같은 카드게임
            // 섯다
            // 이런게임 클래스화를 제대로해서
            // 제대로해서 한번 익혀두면
            // 그언어를 한동안은 어느정도 마스터해서 쓸수있게 됩니다.

            // 고급문법은 사실 편의문법이지 필수문법은 아니에요.
        }
    }
}