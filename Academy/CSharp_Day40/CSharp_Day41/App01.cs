using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Serialization;

namespace CSharp_Day41
{
    public class App01
    {
        public class ChampionData
        {
            public int Id { get; set; }
            public string Name { get; set; }
            public List<SkillData> Skills { get; set; } = new List<SkillData>();
        }

        public class SkillData
        {
            public int Id { get; set; }
            public string Name { get; set; }
        }

        public void Run()
        {

            //string json = JsonConvert.SerializeObject(ChampionDatas,Formatting.Indented);

            //Console.WriteLine(json);

            // 저장하는 방법

            //File.WriteAllText("championData.json", json);

            // 반대로
            // Json string을 객체롤 바꾸는 방법
            string championDataJson = File.ReadAllText("championData.json");
            // 디시리얼라이즈
            //List<ChampionData> data = JsonConvert.DeserializeObject<List<ChampionData>>(json) ?? new List<ChampionData>();

            // ------------------------------
            // XML 사용방법
            // ------------------------------

            // # 1. Serialize
            //var serilizer = new XmlSerializer(typeof(List<ChampionData>));
            //using (var stream = new FileStream("championData.xml",FileMode.Create))
            //{
            //    serilizer.Serialize(stream, data);
            //}

            // # 2. Deserialize & Load
            //using (var stream = new FileStream("championData.xml",FileMode.Open))
            //{
            //    var championList = (List<ChampionData>)serilizer.Deserialize(stream) ?? new List<ChampionData>();
            //}

            // ------------------------------
            // EXCEL 사용방법 (엑셀은 절대절대 역으로 파일 Save하는 경우 없음)
            // ------------------------------

            // # 1. Load
            
            List<ChampionData> championExcel = new List<ChampionData>();
            List<SkillData> SkillExcel = new List<SkillData>();
            
            #region ChampionData
            {
                var lines = File.ReadAllLines("ChampionData.csv");

                // 0번째 줄은 필요없는 데이터
                for (int i = 1; i < lines.Length; i++)
                {
                    //ChampionData championData = new ChampionData();
                    //championData.Id = lines[i];
                    Console.WriteLine($"lines : {lines[i]}");

                    //Split => 뒤에오는 아규먼트로 그 문자열을 분리하여 배열로 나타낸다.
                    var colums = lines[i].Split(",");

                    Console.WriteLine($"colums[0] : {colums[0]}");
                    Console.WriteLine($"colums[1] : {colums[1]}");

                    ChampionData championData = new ChampionData();
                    championData.Id = int.Parse(colums[0]);
                    championData.Name = colums[1];
                    championExcel.Add(championData);
                }
            }
            #endregion

            // 스킬데이터도 엑셀로만들어보고
            // 로드하는거까지 실습.

            #region SkillData
            {
                var lines1 = File.ReadAllLines("SkillData.csv");

                for (int i = 1; i < lines1.Length; i++)
                {
                    Console.WriteLine($"lines1 : {lines1[i]}");

                    var colums = lines1[i].Split(",");

                    Console.WriteLine($"colums[0] : {colums[0]}");
                    Console.WriteLine($"colums[1] : {colums[1]}");

                    SkillData SkillData = new SkillData();
                    SkillData.Id = int.Parse(colums[0]);
                    SkillData.Name = colums[1];
                    SkillExcel.Add(SkillData);
                }
            }
            #endregion
        }
    }
}



