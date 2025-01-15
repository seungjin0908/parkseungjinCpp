using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Threading.Tasks;
using System.ComponentModel.DataAnnotations;

namespace CSharp_Day42
{
    public struct Vector3
    {
        public float X;
        public float Y;

        public float Distance(Vector3 other)
        {
            float x = X - other.X;
            float y = Y - other.Y;

            return MathF.Sqrt(x * x + y * y);
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

            for (int i = 1; i <= count; i++)
            {
                _players.Add(new Player
                {
                    Id = i,
                    Name = $"Player{i}",
                    Score = random.Next(0, 1000)
                });
            }

        }

        private void TakeSkipTest()
        {
            //점수 순 랭킹 페이지 구현
            var rankingList = _players.OrderByDescending(p => p.Score).ToList();

            for (int i = 0; i < 5; i++)
            {
                var page = rankingList
                            .Skip(i * 10)
                            .Take(10);

                // i 값에 따라서 0 ~ 9 / 10 ~ 19 / 20 ~ 29 / 30 ~ 39 / 40 ~ 49

                foreach(var  p in page)
                {
                    Console.WriteLine($"[{p.Score}] [{p.Name}] [{p.Id}]");
                }
                Console.WriteLine("---------------------");
            }
            
        }

        private void FirstTest()
        {
            // 다른 LINQ 메서드랑 같이사용.
            
            // ex. 자동사냥시 다음 적탐색
            Vector3 myPosition = new Vector3() { X = 5, Y = 5 };
            var firstEnemy = _enemies.OrderBy(e => myPosition.Distance(e.Position)).FirstOrDefault();

            if (firstEnemy != null)
            {
                Console.WriteLine($"다음 적 : {firstEnemy.Name}");
            }
        }

        private void OrderByTest()
        {
            //나와 거리가 가까운 순으로 정렬
            Vector3 myPosition = new Vector3() { X = 5, Y = 5 };
            var sortEnemies = _enemies.OrderBy(e => myPosition.Distance(e.Position));

            foreach (Enemy enemy in sortEnemies)
            {
                Console.WriteLine($"거리 : {myPosition.Distance(enemy.Position)} / 몬스터 이름 : {enemy.Name} / 실제 좌표 : {enemy.Position.X}, {enemy.Position.Y}");
            }

            //OrderByDescding
            Console.WriteLine("--------------------------");
            var sortEnemies2 = _enemies.OrderByDescending(e => myPosition.Distance(e.Position));

            foreach (Enemy enemy in sortEnemies2)
            {
                Console.WriteLine($"거리 : {myPosition.Distance(enemy.Position)} / 몬스터 이름 : {enemy.Name} / 실제 좌표 : {enemy.Position.X}, {enemy.Position.Y}");
            }
        }

        private void AllTest()
        {
            // 적들이 모두 내 곁 (50안)에 있으면 
            Vector3 myPosition = new Vector3() { X = 5, Y = 5 };
            bool condition1 = _enemies.All(e => myPosition.Distance(e.Position) < 50);
            Console.WriteLine(condition1);
        }

        private void AnyTest()
        {
            bool condition1 = _enemies.Any(e => e.Hp > 50);
            Console.WriteLine(condition1);
        }

        private void GenerateEnemy()
        {
            _enemies.Clear();
            _enemies.Add(new Enemy()
            {
                Id = 1,
                Name = "김똥개",
                Position = new Vector3() { X = 1, Y = 1 },
                Hp = 10,
            });

            _enemies.Add(new Enemy()
            {
                Id = 2,
                Name = "슬라임",
                Position = new Vector3() { X = -1, Y = 7 },
                Hp = 20,
            });

            _enemies.Add(new Enemy()
            {
                Id = 3,
                Name = "주황버섯",
                Position = new Vector3() { X = 2, Y = 3 },
                Hp = 30,
            });

            _enemies.Add(new Enemy()
            {
                Id = 4,
                Name = "루시안",
                Position = new Vector3() { X = 12, Y = -3 },
                Hp = 40,
            });

            _enemies.Add(new Enemy()
            {
                Id = 5,
                Name = "John",
                Position = new Vector3() { X = 3, Y = -12 },
                Hp = 50,
            });

            _enemies.Add(new Enemy()
            {
                Id = 6,
                Name = "사탄",
                Position = new Vector3() { X = 4, Y = 4 },
                Hp = 60,
            });

            _enemies.Add(new Enemy()
            {
                Id = 7,
                Name = "미니언",
                Position = new Vector3() { X = 0, Y = 0 },
                Hp = 70,
            });
        }

        private void SelectTest()
        {
            // 같이쓰는 문법
            // 익명 타입
            // 구조체나 클래스를 사용할때
            // 항상 선언을 하고 사용해야하잖아요
            // 어떤 데이터가 있는지 모르니까.
            // 사용과 동시에 선언합니다.

            var newList = _enemies.Select(e => new
            {
                쓰고싶은데이터1 = e.Id,
                쓰고싶은데이터2 = $"이름 : {e.Name}"
            }).ToList();

            foreach(var item in newList)
            {
                Console.WriteLine($"{item.쓰고싶은데이터1}, {item.쓰고싶은데이터2}");
            }

            //쉬는시간갖고 8시에 다시모이겠습니다.
            // 혹시 포트폴리오 만들고있는분 계시면 저한테 쪽지좀 부탁드립니다.
        }

        private void WhereTest()
        {
            // 1. Where
            List<float> list = new List<float>() { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };

            ////Where뒤에 람다식을 적습니다.
            //Func<float, bool> checkConditionFunc = ConditionTest;
            var a = list.Where(l => 2 < l);

            // IEnumerable < 열거형 자료형이라는 인터페이스
            // 형체가 아직없는 형태

            foreach (var element in a)
            {
                Console.WriteLine(element);
            }
        }


    }
}
