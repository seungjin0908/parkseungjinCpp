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

            Managers.Db.TblPlayers.First().TblPlayerItems.Clear();
        }
    }
}
