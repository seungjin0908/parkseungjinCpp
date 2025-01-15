using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Solution150370
{
    public struct Privacy
    {
        public int Index;
        public string Date;
        public string Term;
    }


    List<Privacy> _privacyList = new List<Privacy>();
    Dictionary<string, int> _termDict = new Dictionary<string, int>();
    int _today = 0;

    public void Init(string today, string[] terms, string[] privacies)
    {
        for (int i = 0; i < privacies.Length; i++)
        {
            //"2021.05.02 A"
            var temp = privacies[i].Split(" ");

            _privacyList.Add(new Privacy()
            {
                Index = i + 1,
                Date = temp[0],
                Term = temp[1]
            });
        }

        for(int i = 0; i < terms.Length; i++)
        {
            //"A 6"
            var temp = terms[i].Split(" ");
            _termDict[temp[0]] = 28 * int.Parse(temp[1]);
        }

        _today = ConverDateToNumber(today);
    }

    public int ConverDateToNumber(string date)
    {
        //2021.05.02
        var temp = date.Split(".");

        //연도 * 12 + 월 * 28 + 일
        return (int.Parse(temp[0]) * 12 * 28) + int.Parse(temp[1]) * 28 + int.Parse(temp[2]);
    }

    public int[] solution(string today, string[] terms, string[] privacies)
    {
        int[] answer = new int[] { };

        List<int> results = new List<int>();
        //0. Init
        Init(today, terms, privacies);

        //1. 루프
        for (int i = 0; i < _privacyList.Count; i++)
        {
            bool check = CheckPrivacy(_privacyList[i]);
            if(check)
            {
                results.Add(_privacyList[i].Index);
            }
        }


        return results.OrderBy(o => o).ToArray();
    }

    private bool CheckPrivacy(Privacy privacy)
    {
        //수집날짜 + 약관 유효기간 <= 오늘 

        // 수집날짜24,394 + 168
        var collectionDateNumber = ConverDateToNumber(privacy.Date);

        //24,264 159
        //약관 유효기간
        var validityPeriod = _termDict[privacy.Term];

        return collectionDateNumber + validityPeriod <= _today;
    }
}