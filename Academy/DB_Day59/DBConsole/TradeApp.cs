using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBConsole
{
    public enum AppState
    {
        Login,  // 로그인 화면
        Lobby,  // 로비화면 (로그인하고 첫장면)
        Buy,    // 구매화면
        Sell,   // 판매화면
        Inventory, // 인벤토리화면
    }



    public class TradeApp
    {

        // 1. 어떤 계정으로 로그인할건지 UserId를 적게끔
        // 2. 선택창 보여주기 ( 1. 구매하기, 2. 판매하기, 3. 내 아이템 리스트 보기)

        // [구매하기 동작]
        // 1. 판매중인 TradeItem 리스트 보여주기
        // 2. 내 골드 보여주기
        // 3. 몇번을 구매할건지 입력하기 / 취소하기

        // [판매하기 동작]
        // 1. 판매가능한 아이템 리스트 보여주기
        // 2. 얼마에 올릴건지 적기

        // [내 아이템 리스트 보여주기]
        // UserItems에서 내 아이템 보여주기

        AppState _appState = AppState.Login;
        public void Run()
        {
            while (true)
            {
                switch (_appState)
                {
                    case AppState.Login:
                        LoginScene();
                        break;

                    case AppState.Lobby:
                        LobbyScene();
                        break;

                    case AppState.Buy:
                        BuyScene();
                        break;
                    case AppState.Sell:
                        SellScene();
                        break;
                    case AppState.Inventory:
                        InventoryScene();
                        break;
                }
            }
        }

        private void InventoryScene()
        {
            Console.Clear();
            Console.WriteLine($"[{nameof(InventoryScene)}]");
            Console.WriteLine("0 : 로비로 돌아가기");

            var itemList = 
                Managers.Db.TblPlayerItems
                    .Where(item => item.OwnerPlayerId == Managers.User.Id)
                    .OrderBy(item => item.Id)
                    .ToList();

            Console.WriteLine("----------------------------");
            foreach(var item in itemList)
            {
                Console.WriteLine($"[{item.Id}] {Managers.Item.Items[item.ItemId].Name}, {item.Count}개");
            }
            Console.WriteLine("----------------------------");
            var input = Console.ReadLine();
            int selected = int.Parse(input ?? "");

            switch (selected)
            {
                case 0:
                    _appState = AppState.Lobby;
                    return;
            }

        }

        private void SellScene()
        {
            Console.Clear();
            Console.WriteLine($"[{nameof(SellScene)}]");
            Console.WriteLine("0 : 로비로 돌아가기");


            var itemList =
                Managers.Db.TblPlayerItems
                    .Where(item => item.OwnerPlayerId == Managers.User.Id)
                    .OrderBy(item => item.Id)
                    .ToList();

            Console.WriteLine("판매할 Item Id를 입력해주세요.");
            Console.WriteLine("----------------------------");
            foreach (var item in itemList)
            {
                Console.WriteLine($"[{item.Id}] {Managers.Item.Items[item.ItemId].Name}, {item.Count}개");
            }
            Console.WriteLine("----------------------------");



            var input = Console.ReadLine();
            int selected = int.Parse(input ?? "");

            switch (selected)
            {
                case 0:
                    _appState = AppState.Lobby;
                    return;
            }


            // 1. 실제로 가지고있는지 체크
            var playerItemEntity = itemList.Where(item => item.Id == selected).First();
            if (playerItemEntity == null)
            {
                Console.WriteLine("잘못 입력했습니다.");
                return;
            }
            // 2. 몇개 등록할건지 체크
            Console.Write("얼마에 등록하시겠습니까?");
            input = Console.ReadLine();
            int price = int.Parse(input ?? "");
            if(price <= 0)
            {
                Console.WriteLine("잘못 입력했습니다.");
                return;
            }

            // 3. TradeItems에 등록
            Managers.Db.TblTradeItems.Add(new DB.Tables.TblTradeItem()
            {
                BuyerPlayerId = null,
                SellerPlayerId = Managers.User.Id,
                ListedPrice = price,
                ItemId = playerItemEntity.ItemId,
            });

            // 4. 내꺼에서 제외
            var dbItem = 
                Managers.Db.TblPlayerItems
                    .Where(x => x.Id == selected && x.OwnerPlayerId == Managers.User.Id)
                    .First();

            dbItem.Count--;

            if(dbItem.Count == 0)
            {
                Managers.Db.TblPlayerItems.Remove(dbItem);
            }
            else
            {
                Managers.Db.TblPlayerItems.Update(dbItem);
            }

            Managers.Db.SaveChanges();
            _appState = AppState.Lobby;
        }

        private void BuyScene()
        {
            Console.Clear();
            Console.WriteLine($"[{nameof(BuyScene)}]");
            Console.WriteLine("0 : 로비로 돌아가기");


            var sellItemList = Managers.Db.TblTradeItems.Where(tradeItem =>
                tradeItem.BuyerPlayerId == null &&  // 산사람이 없어야하고
                DateTime.Now < tradeItem.ExpirationDate);    // 만료시간이 지금보다 짧아야한다.

            Console.WriteLine("구매할 Id를 입력해주세요.");
            Console.WriteLine("----------------------------");
            foreach (var item in sellItemList)
            {
                Console.WriteLine($"[{item.Id}] {Managers.Item.Items[item.ItemId].Name}, {item.ListedPrice}원");
            }
            Console.WriteLine("----------------------------");

            // 1. 무엇을 구매할건지 Id 받기 (TblTradeItem 의 Id)
            var input = Console.ReadLine();
            int selected = int.Parse(input ?? "");
            switch (selected)
            {
                case 0:
                    _appState = AppState.Lobby;
                    return;
            }

            // 2. 돈이 있는지 체크
            var tradeItemEntity = Managers.Db.TblTradeItems.Where(playerItem => playerItem.Id == selected).FirstOrDefault();

            if(tradeItemEntity == null)
            {
                Console.WriteLine("해당 아이템을 찾을 수 없습니다.");
                return;
            }

            if(Managers.User.Gold < tradeItemEntity.ListedPrice)
            {
                Console.WriteLine("내가 가진 골드보다 비쌉니다.");
                return;
            }

            // 3. 구매프로세스
            // - User의 돈을 뻇는다.
            
            var playerEntity = Managers.Db.TblPlayers.Where(player => player.Id == Managers.User.Id).FirstOrDefault();
            if(playerEntity == null)
            {
                Console.WriteLine("ERROR : 플레이어가 존재하지 않습니다.");
                return;
            }
            playerEntity.Gold -= tradeItemEntity.ListedPrice;
            Managers.Db.TblPlayers.Update(playerEntity);

            Managers.User.Gold -= tradeItemEntity.ListedPrice;

            // - DB에서 TradeItem 하나 없애기.
            tradeItemEntity.BuyerPlayerId = Managers.User.Id;
            tradeItemEntity.ExpirationDate = DateTime.Now;

            Managers.Db.TblTradeItems.Update(tradeItemEntity);


            // - DB에서 나한테 아이템 하나 추가
            //아이템이 존재한다면, 카운트 1증가 Update
            //아이템을 첫득템이라면, Entity Add
            if (Managers.Db.TblPlayerItems.Any(playerItem => playerItem.OwnerPlayerId == Managers.User.Id && playerItem.ItemId == tradeItemEntity.ItemId))
            {
                var playerItemEntity = Managers.Db.TblPlayerItems.Where(playerItem => playerItem.OwnerPlayerId == Managers.User.Id && playerItem.ItemId == tradeItemEntity.ItemId).First();

                playerItemEntity.Count++;
                Managers.Db.TblPlayerItems.Update(playerItemEntity);
            }
            else
            {
                Managers.Db.TblPlayerItems.Add(new DB.Tables.TblPlayerItem()
                {
                    ItemId = tradeItemEntity.ItemId,
                    Count = 1,
                    OwnerPlayerId = Managers.User.Id
                });
            }

            var sellPlayerEntity = Managers.Db.TblPlayers.Where(player => player.Id == tradeItemEntity.SellerPlayerId).FirstOrDefault();
            if (sellPlayerEntity == null)
            {
                Console.WriteLine("ERROR : 플레이어가 존재하지 않습니다.");
                return;
            }
            sellPlayerEntity.Gold += tradeItemEntity.ListedPrice;
            Managers.Db.TblPlayers.Update(sellPlayerEntity);

            Managers.Db.SaveChanges();
            _appState = AppState.Lobby;
        }

        private void LoginScene()
        {
            Console.Clear();
            Console.WriteLine($"[{nameof(LoginScene)}]");
            //  1. UserList 보여주기
            var userList = Managers.Db.TblPlayers.ToList();
            Console.WriteLine("로그인할 플레이어 번호를 입력해주세요.");
            Console.WriteLine("---------------------");
            foreach (var player in userList)
            {
                Console.WriteLine($"[{player.Id}] {player.Name}");
            }
            Console.WriteLine("---------------------");

            // 2. User 고르기
            var input = Console.ReadLine();
            int selectedUserId = int.Parse(input ?? "");

            var user = userList.Where(user => user.Id == selectedUserId).FirstOrDefault();

            if(user == null)
            {
                Console.WriteLine("없는 계정입니다.");
                return;
            }

            Console.Clear();

            // 3. 실제 로그인 처리 / 로그인 완료시 로비로 이동
            Managers.User.Login(user.Id, user.Name, user.Gold);
            _appState = AppState.Lobby;
        }

        private void LobbyScene()
        {
            Console.Clear();
            Console.WriteLine($"[{nameof(LobbyScene)}]");
            Console.WriteLine("---------------------");
            Console.WriteLine($"Id : {Managers.User.Id}");
            Console.WriteLine($"Name : {Managers.User.Name}");
            Console.WriteLine($"Gold : {Managers.User.Gold}");
            Console.WriteLine("---------------------");

            Console.WriteLine("액션을 선택해주세요.");

            Console.WriteLine(" 1. 판매하기");
            Console.WriteLine(" 2. 구매하기");
            Console.WriteLine(" 3. 인벤토리 보기");
            Console.WriteLine(" 4. 로그아웃");

            var inputStr = Console.ReadLine();
            int input = int.Parse(inputStr ?? "0");

            switch (input)
            {
                case 1: // 판매하기
                    _appState = AppState.Sell;
                    break;
                case 2: // 구매하기
                    _appState = AppState.Buy;
                    break;
                case 3: // 인벤토리 보기
                    _appState = AppState.Inventory;
                    break;
                case 4: // 로그아웃
                    Managers.User.Logout();
                    _appState = AppState.Login;
                    break;
            }

        }
    }
}
