using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
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
            List<SkillData> skillDatas = new List<SkillData>();
            skillDatas.Add(new SkillData()
            {
                Id = 10001,
                Name = "가렌 Q 스킬 이름"
            });

            skillDatas.Add(new SkillData()
            {
                Id = 10002,
                Name = "가렌 W 스킬 이름"
            });

            skillDatas.Add(new SkillData()
            {
                Id = 10003,
                Name = "가렌 E 스킬 이름"
            });

            skillDatas.Add(new SkillData()
            {
                Id = 10004,
                Name = "가렌 R 스킬 이름"
            });


            List<ChampionData> championDatas = new List<ChampionData>();
            championDatas.Add(new ChampionData()
            {
                Id = 1,
                Name = "가렌",
                Skills = skillDatas
            });

            //---------------------
            //  JSON 사용 방법
            //---------------------

            // # 1. Serialize
            string json = JsonConvert.SerializeObject(championDatas, Formatting.Indented);

            Console.WriteLine(json);

            // # 2. Save
            File.WriteAllText("championData.json", json);

            // # 3. Load
            string championDataJson = File.ReadAllText("championData.json");
            
            // # 4. Deserialize
            List<ChampionData> data = JsonConvert.DeserializeObject<List<ChampionData>>(json) ?? new List<ChampionData>();

            //---------------------------
            // XML 사용방법
            //---------------------------
            
            // # 1. Serialize & Save
            var serializer = new XmlSerializer(typeof(List<ChampionData>));
            using (var stream = new FileStream("championData.xml", FileMode.Create))
            {
                serializer.Serialize(stream, data);
            }

            // # 2. Deserialize & Load
            using (var stream = new FileStream("championData.xml", FileMode.Open))
            {
                var championList = (List<ChampionData>)serializer.Deserialize(stream) ?? new List<ChampionData>();
            }


            //-------------------------------
            // EXCEL 사용방법 (엑셀은 절대절대 역으로 파일 Save하는 경우 없음)
            //-------------------------------
            Dictionary<int, ChampionData> championsExcel = new Dictionary<int, ChampionData>();
            Dictionary<int, SkillData> skillsExcel = new Dictionary<int, SkillData>();

            // # 1. Load
            #region ChampionData
            {
                var lines = File.ReadAllLines("ChampionData.csv");


                //0번째줄은 필요없는 데이터
                for (int i = 1; i < lines.Length; i++)
                {
                    Console.WriteLine($"lines : {lines[i]}");

                    //Split => 뒤에오는 아규먼트로 그 문자열을 분리하여 배열로 나타낸다.
                    var columns = lines[i].Split(",");

                    Console.WriteLine($"columns[0] : {columns[0]}");
                    Console.WriteLine($"columns[1] : {columns[1]}");

                    ChampionData championData = new ChampionData();
                    championData.Id = int.Parse(columns[0]);
                    championData.Name = columns[1];
                    championsExcel[championData.Id] = championData;
                }
            }
            #endregion

            #region SkillData
            {
                var lines = File.ReadAllLines("SkillData.csv");


                //0번째줄은 필요없는 데이터
                for (int i = 1; i < lines.Length; i++)
                {
                    Console.WriteLine($"lines : {lines[i]}");

                    //Split => 뒤에오는 아규먼트로 그 문자열을 분리하여 배열로 나타낸다.
                    var columns = lines[i].Split(",");

                    Console.WriteLine($"columns[0] : {columns[0]}");
                    Console.WriteLine($"columns[1] : {columns[1]}");

                    SkillData skillData = new SkillData();
                    skillData.Id = int.Parse(columns[0]);
                    skillData.Name = columns[1];
                    skillsExcel[skillData.Id] = skillData;
                }
            }
            #endregion


            #region ChampionSkillData
            {
                var lines = File.ReadAllLines("ChampionSkillData.csv");


                //0번째줄은 필요없는 데이터
                for (int i = 1; i < lines.Length; i++)
                {
                    Console.WriteLine($"lines : {lines[i]}");

                    //Split => 뒤에오는 아규먼트로 그 문자열을 분리하여 배열로 나타낸다.
                    var columns = lines[i].Split(",");

                    Console.WriteLine($"columns[0] : {columns[0]}");

                    //ChampionId
                    Console.WriteLine($"columns[1] : {columns[1]}");

                    //SkillId
                    Console.WriteLine($"columns[2] : {columns[2]}");

                    // SkillChampionData 한줄당 챔피언에게 스킬하나씩 넣어주면 됩니다.
                    // 어떤챔피언에 어떤스킬이 추가된다.

                    int championId = int.Parse(columns[1]);
                    int skillId = int.Parse(columns[2]);
                    championsExcel[championId].Skills.Add(skillsExcel[skillId]);
                }
            }
            #endregion

        }
    }
}

