using DB.Tables;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBConsole
{
    // PlayerGenerate 매크로
    partial class App03
    {
        Random _rand = new Random();
        public void Run()
        {
            var playerList = Managers.Db.TblPlayers.ToList();
            Managers.Db.TblPlayers.RemoveRange(playerList);
            Managers.Db.SaveChanges();

            while (true)
            {
                Thread.Sleep(1000);
                Managers.Db.TblPlayers.Add(new TblPlayer()
                {
                    Count = _rand.Next(1, 1000),
                    ItemId = _rand.Next(1, 10),
                    OwnerPlayerId = playerList[_rand.Next(playerList.Count)]
                });

                Managers.Db.SaveChanges();

                Console.WriteLine("Insert Succes!");
            }


        }
    }
}
