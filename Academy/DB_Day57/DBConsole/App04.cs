using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBConsole
{
    // 조회해보는 앱
    public class App04
    {
        public void Run()
        {
            // 플레이어마다 어떤 아이템을 가지고있는지 조회
            //Read
            //var playerList = Managers.Db.TblPlayers.ToList();

            var playerList = Managers.Db.TblPlayers
                .Include(x => x.TblPlayerItems)         // 앞으로 TblPlayers를 조회할때, TblPlayerItem까지 같이 포함하도록 해주세요.
                .ToList();


            foreach (var p in playerList)
            {
                Console.WriteLine($"===============================");
                Console.WriteLine($"Id : {p.Id}");
                Console.WriteLine($"Name : {p.Name}");
                Console.WriteLine($"Gold : {p.Gold}");
                Console.WriteLine($"ItemList");

                foreach(var item in p.TblPlayerItems)
                {
                    Console.WriteLine($"----------------------");
                    Console.WriteLine($" -Id : {item.Id}");
                    Console.WriteLine($" -ItemId : {item.ItemId}");
                    Console.WriteLine($" -Count : {item.Count}");
                    Console.WriteLine($"----------------------");
                }
                Console.WriteLine($"===============================");
                Console.WriteLine();
            }
        }
    }
}
