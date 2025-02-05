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
        Inventory,  // 인벤토리화면
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
            // 어떤 계정으로 로그인할건지 UserId를 적게끔
            LoginScene();

        }

        private void LoginScene()
        {
            // 1. UserList 보여주기
            var userList = Managers.Db.TblPlayers.ToList();
            Console.WriteLine("로그인할 플레이어 번호를 입력해주세요");
            Console.WriteLine("----------------------");
            foreach (var player in userList)
            {
                Console.WriteLine($"[{player.Id}]{player.Name}");
            }
            Console.WriteLine("----------------------");

            var inputStr = Console.ReadLine();
            int selectedUserId = int.Parse(inputStr ?? "");

            var user = userList.Where(user => user.Id == selectedUserId).FirstOrDefault
                ();

            if (user == null)
            {
                Console.WriteLine("잘못입력함. 프로그램 종료");
                Environment.Exit(0);
            }

            Console.Clear();



            Console.WriteLine("----------------------");
            Console.WriteLine("접속한 계정 : ");
            Console.WriteLine($"Id : {user.Id}");
            Console.WriteLine($"Name : {user.Name}");
            Console.WriteLine($"Gold : {user.Gold}");
            Console.WriteLine("----------------------");

            Console.WriteLine("액션을 선택해주세요.");

            Console.WriteLine(" 1. 판매하기");
            Console.WriteLine(" 2. 구매하기");
            Console.WriteLine(" 3. 인벤토리 보기");
            Console.WriteLine(" 4. 로그아웃");

            var inputStr = Console.ReadLine();
            int input = int.Parse(inputStr ?? "0");

            switch (input)
            {
                case 1:
                    _appState = AppState.Sell;
                    break;
                case 2:
                    _appState = AppState.Buy;
                    break;
                case 3:
                    _appState = AppState.Inventory;
                    break;
                case 4:
                    Managers.user.Login();
                    _appState = AppState.Login;
                    break;
            }
        }
    }
}
