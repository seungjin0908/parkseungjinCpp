using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBConsole
{
    public class App01
    {
        public void Run()
        {
            //Read
            //var playerList = Managers.Db.TblPlayers.ToList();
            //foreach (var p in playerList)
            //{
            //    Console.WriteLine($"----------------------");
            //    Console.WriteLine($"Id : {p.Id}");
            //    Console.WriteLine($"Name : {p.Name}");
            //    Console.WriteLine($"Gold : {p.Gold}");
            //    Console.WriteLine($"----------------------");
            //}

            //Create
            // => Async 함수는 비동기함수
            // => 동기함수들은 그 함수가 실행이 끝날때까지 주스레드가 대기하지만,
            //    비동기함수는 대기하지 않고, 다른 코드를 실행할수있게 해준다.
            // => 보통 로컬에서 일어나지 않는 행위들은 Async함수를 보통 만듭니다.
            //Managers.Db.TblPlayers.Add(new DB.Tables.TblPlayer()
            //{
            //    Name = "백수영",
            //    Level = 1,
            //    Gold = 100000
            //});


            //Update
            //var player = playerList.First();
            //player.Level = 100;
            //Managers.Db.TblPlayers.Update(player);

            //Delete
            //var player = playerList.First();
            //Managers.Db.TblPlayers.Remove(player);

            //이걸해야 정상적으로 DB에 반영이 됩니다.
            //Managers.Db.SaveChanges();
        }
    }
}
