using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day42
{
    public struct Vector3
    {  
        public float X;
        public float Y;

        public float Distance(Vector3 other)
        {
            float x = X = other.X;
            float y = Y = other.Y;

            return MathF.Sqrt( x * y + y * x);
        }
    }

    public class Enemy
    {
        public int Id;
        public string Name;
        public Vector3 Position;
        public int Hp;
    }

    public class Player
    {
        public int Id;
        public string Name;
        public int Score;
    }

    public class App01
    {
        List<Enemy> _enemies = new List<Enemy>();
        List<Player> _players = new List<Player>();
        public void Run()
        {
            GenerateEnemy();
            GenerateDummyPlayers(50);
            //WhereTest();
            //SelectTest();
            //AnyTest();
            //AllTest();
            //OrderByTest();
            //FirstTest();
            //TakeSkipTest();
            MinMaxTest();
        }

        public void MinMaxTest()
        {
            int scoreMax = _players.Max(p => p.Score);
            int scoreMin = _players.Min(p => p.Score);

            Console.WriteLine($"Score Max : {scoreMax} / Score Min : {scoreMin}");
        }

        public void GenerateDummyPlayers(int count)
        {
            var random = new Random();
            var players = new List<Player>();

            for (int i = 0; i < count; i++)
            {
                players.Add(new Player
                {
                    Id = i,
                    Name=$"player{i}",
                    Score = random.Next(0, 1000)
                });

            }

            
        }

        private void TakeSkipTest()
        {
            // 점수 순 랭킹 페이지 구현
            var rankingList = _players.OrderByDescending(p => p.Score).ToList();
            for (int i = 0; i<5; i++)
            {
                var page=
                    _players.OrderByDescending(p => p.Score)
                         .Skip(i * 10)
                         .Take(10);

                // i 값에 따라서 0 ~ 9 / 10 ~ 19 / 20 ~ 29 / 30 ~ 39 / 40 ~ 49

                foreach (var p in page)
                {
                    Console.WriteLine($"[{p.Score}] [{p.Name}] [{p.Id}]");
                }
                Console.WriteLine("----------------------");
            }
        }

        private void FirstTest()
        {

        }

        private void OrderByTest()
        {
            // 나와 거리가 가까운 순으로 정렬
            Vector3 myPosition = new Vector3() { X = 5, Y = 5 };
            var sortEnemies = _enemies.OrderBy(e => myPosition.Distance(e.Position));

            foreach(Enemy enemy in sortEnemies)
            {
                Console.WriteLine($"거리 : {myPosition.Distance(enemy.Position)} / 몬스터 이름 : {enemy.Name} / 실제좌표 : 
                    {enemy.Position.X},{enemy.Position.Y}");
                
            }
        }

        private void AllTest()
        {
            // 적들이 모두 내 곁에 있으면
            Vector3 myPosition = new Vector3() { X = 5, Y = 5 };
            bool condition1 = _enemies.All(e => myPosition.Distance(e.Position) < 50);
        }

        private void AnyTest()
        {
            bool condition1 = _enemies.All(e => e.Hp > 50);
            Console.WriteLine(condition1);
        }

        private void GenerateEnemy()
        {
            _enemies.Clear();
            _enemies.Add(new Enemy()
            { 
                Id =1;
                Name="버섯",
                Position = new Vector3() { X = 0, Y = 0 },
            });

        }

        private void SelectTest()
        {
            // 같이쓰는 문법
            // 익명 타입
            // 구조체나 클래스를 사용할때
            // 항상 선언을 하고 사용해야하는데
            // 어떤 데이터가 있는지 모르니까.
            // 사용과 동시에 선언한다.

            var newList = _enemies.Select(e => new
            {
                쓰고싶은데이터1 = e.Id,
                쓰고싶은데이터2 = $"이름 : {e.Name}"
            }).ToList();

            foreach (var item in newList)
            {
                Console.WriteLine($"{item.쓰고싶은데이터1}, {item.쓰고싶
                    은데이터2}");
            }
        }

        private void WhereTest()
        {
            throw new NotImplementedException();
            // 1. Where
           

            // Where뒤에 람다식을 적는다.
            //Func<float, bool> checkConditionFunc = ConditionTest;
            var a = list.Where(l => 2 < l);

            // IEumerable < 열거형 자료형이라는 인터페이스
            // 형체가 아직 없는 형태

            foreach (var element in a)
            {
                Console.WriteLine(element);
            }
            //bool ConditionTest(float check)
            //{
            //    if (check > 1)
            //    {
            //        return true;
            //    }

            //    return false;
            //}
        }


    }
}
