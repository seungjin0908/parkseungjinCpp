using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System;

public class Solution118666
{
    // 수도코드 
    // 1. 투표별로 루프
    //      2. 각 투표별로 해당하는 성격유형 지표 점수를 올려줍니다.
    // 3. 각 지표별로 어떤게 더 높은지 판단(둘이 동일하다면, 사전순)해서 하나씩 고르기.
    //   (R vs T), (C vs F), (J vs M), (A vs N)
    /*
     *  지표 번호	성격 유형
        1번 지표	라이언형(R), 튜브형(T)
        2번 지표	콘형(C), 프로도형(F)
        3번 지표	제이지형(J), 무지형(M)
        4번 지표	어피치형(A), 네오형(N)
     */

    Dictionary<char, int> _surveyDataDict = new Dictionary<char, int>();

    public void Init()
    {
        _surveyDataDict['R'] = 0;
        _surveyDataDict['T'] = 0;
        _surveyDataDict['C'] = 0;
        _surveyDataDict['F'] = 0;
        _surveyDataDict['J'] = 0;
        _surveyDataDict['M'] = 0;
        _surveyDataDict['A'] = 0;
        _surveyDataDict['N'] = 0;
    }

    public void IncreasesCorresponding(string survey, int choice)
    {
        if(choice == 4)
        {
            return;
        }

        if(choice < 4)
        {
            if(choice == 1)
            {
                _surveyDataDict[survey[0]] += 3;
            }
            else if (choice == 2)
            {
                _surveyDataDict[survey[0]] += 2;
            }
            else if (choice == 3)
            {
                _surveyDataDict[survey[0]] += 1;
            }
        }
        else
        {
            if (choice == 5)
            {
                _surveyDataDict[survey[1]] += 1;
            }
            else if (choice == 6)
            {
                _surveyDataDict[survey[1]] += 2;
            }
            else if (choice == 7)
            {
                _surveyDataDict[survey[1]] += 3;
            }
        }
    }

    public string solution(string[] survey, int[] choices)
    {
        StringBuilder answerBuilder = new StringBuilder();

        //0. 초기화 해준다.
        Init();


        //1. 투표별로 루프
        for (int i = 0; i < survey.Length; i++)
        {
            //2. 각 투표별로 해당하는 성격유형 지표 점수를 올려줍니다.
            IncreasesCorresponding(survey[i], choices[i]);
        }

        //A B C D E F G H I J K L M N O P Q R S T U V W X Y Z


        //3. 각 지표별로 어떤게 더 높은지 판단(둘이 동일하다면, 사전순)해서 하나씩 고르기.
        if (_surveyDataDict['R'] < _surveyDataDict['T'])
        {
            answerBuilder.Append("T");
        }
        else
        {
            answerBuilder.Append("R");
        }

        if (_surveyDataDict['C'] < _surveyDataDict['F'])
        {
            answerBuilder.Append("F");
        }
        else
        {
            answerBuilder.Append("C");
        }

        if (_surveyDataDict['J'] < _surveyDataDict['M'])
        {
            answerBuilder.Append("M");
        }
        else
        {
            answerBuilder.Append("J");
        }

        if (_surveyDataDict['A'] < _surveyDataDict['N'])
        {
            answerBuilder.Append("N");
        }
        else
        {
            answerBuilder.Append("A");
        }

        return answerBuilder.ToString();
    }
}