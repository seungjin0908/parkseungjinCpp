namespace DBConsole
{
    public class TradeAppWithServer
    {
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

        private async Task InventoryScene()
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

        }

        private async Task SellScene()
        {
            Console.Clear();
            Console.WriteLine($"[{nameof(SellScene)}]");
            Console.WriteLine("0 : 로비로 돌아가기");


            var itemList =
                Managers.Db.TblPlayerItems
                    .Where(item => item.OwnerPlayerId == Managers.User.Id)
                    .OrderBy(item => item.Id)
                    .ToList();

            var newItemList = Managers.Https.GetInventory(new Dtos.ReqDtoGetInventory);

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
            if (price <= 0)
            {
                Console.WriteLine("잘못 입력했습니다.");
                return;
            }

            Managers.https.Sell(new Dtos.)
            _appState = AppState.Lobby;
        }

        private async Task BuyScene()
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

           
            _appState = AppState.Lobby;
        }

        private async Task LoginScene()
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

            if (user == null)
            {
                Console.WriteLine("없는 계정입니다.");
                return;
            }

            Console.Clear();

            // 3. 실제 로그인 처리 / 로그인 완료시 로비로 이동
            Managers.User.Login(user.Id, user.Name, user.Gold);
            _appState = AppState.Lobby;
        }

        private async Task LobbyScene()
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
