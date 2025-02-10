using DB.Tables;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBConsole
{
    // PlayerItemGenerate 매크로
    public class App03
    {
        Random _rand = new Random();
        public void Run()
        {
            var playerItemList = Managers.Db.TblPlayerItems.ToList();
            Managers.Db.TblPlayerItems.RemoveRange(playerItemList);
            Managers.Db.SaveChanges();

            var PlayerIdList = Managers.Db.TblPlayers.Select(player => player.Id).ToList();

            while (true)
            {
                Thread.Sleep(1000);

                int itemId = _rand.Next(1, 10);
                int ownerPlayerId = PlayerIdList[_rand.Next(PlayerIdList.Count)];

                if (Managers.Db.TblPlayerItems.Any(item => item.ItemId == itemId && item.OwnerPlayerId == ownerPlayerId))
                {
                    Console.WriteLine("아이템이 겹쳐서 취소됩니다");
                    continue;
                }

                Managers.Db.TblPlayerItems.Add(new TblPlayerItem()
                {
                    Count = _rand.Next(1, 1000),
                    ItemId = itemId,
                    OwnerPlayerId = ownerPlayerId
                });

                Managers.Db.SaveChanges();

                Console.WriteLine("Insert Success!");
            }
        }
    }
}
