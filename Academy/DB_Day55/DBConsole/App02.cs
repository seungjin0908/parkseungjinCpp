using DB.Tables;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata.Internal;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBConsole
{
    // PlayerGenerate 매크로
    partial class App02
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
                    Level = _rand.Next(1, 100),
                    Gold = _rand.Next(10000, 1000000),
                    Name = nameList[_rand.Next(nameList.Count)]
                });

                Managers.Db.SaveChanges();

                Console.WriteLine("Insert Succes!");
            }


        }
    }
}
