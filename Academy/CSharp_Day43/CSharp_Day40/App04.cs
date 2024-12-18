using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day40
{
    public class App04
    {
        public void Run()
        {
            // 게임에서 쓰이는 간단한 예시 한번만 만들어 볼게요.
            // 

            // 메인로직 시작점이라고 가정하고 작업하겠습니다.

            Player player = new Player();
            UIManager uiManager = new UIManager();
            LogSystem logSystem = new LogSystem();

            player.OnPlayerAction -= uiManager.UpdateHUD;
            player.OnPlayerAction += uiManager.UpdateHUD;

            player.OnPlayerAction -= logSystem.Log;
            player.OnPlayerAction += logSystem.Log;

            player.PerformAction(Player.EAction.Jump);
            player.PerformAction(Player.EAction.Move);
            player.PerformAction(Player.EAction.Attack);

            // 왜 좋은코드인지
            // 보통 소규모 프로젝트같은 경우에는 이런 아키텍처를 잘 채용을 안해요.
            // > 모든 포르젝트는 어느정도 규모 있는 프로젝트 <
            // 
            // 어찌됐건 주로 Player부터 만듭니다.
            // 누가 게임을만드는데 UI를 먼저만들고, Log를 만들어요.
            // 그렇게 프로토타입이 탄생하게됩니다.

            // 그럼이제 여기서 UI나 LogSystem, Field 이런내용들을 점차적으로 확대해서 구현해야하는데
            // 이 모든내용들은 사실 
            // 플레이어와 연관이 이겠죠.
            // 그런데 이벤트방식을 채용을안한 아키텍처들은
            // 어찌됐건 그코드를 Player가서 짜야합니다.

            // 플레이어가 무슨 함수를 호출할때마다
            // LogSystem건들고, UISystem건들고, 게임매니저건들고
            // 다 건들게돼요.

            // UISystem에서 Player 객체를 가져옵니다.

            // 속된말로 스파게티코드 이런식으로 부르게되는 코드가 완성되는거에요.

            // 초기화하는곳에 있으면
            // 아 이런사건이 발생할때 이런일들이 발생하구나

            // 모든 로직 중간중간에
            // 이함수 실행될때는 저함수도 같이실행해야해요.
            // 하면 그때부터 생산성이 떨어지는거에요.
        }
    }


    public class Player
    {
        public enum EAction
        {
            Jump,
            Move,
            Attack
        }
        public delegate void PlayerActionHandler(EAction action);
        public event PlayerActionHandler OnPlayerAction;

        public void PerformAction(EAction action)
        {
            switch (action)
            {
                case EAction.Jump:
                    Console.WriteLine("플레이어 점프파워 변경");
                    break;
                case EAction.Move:
                    Console.WriteLine("플레이어 X좌표 변경");
                    break;
                case EAction.Attack:
                    Console.WriteLine("플레이어 공격모드 변경");
                    break;
            }

            OnPlayerAction?.Invoke(action);
        }
    }

    public class UIManager
    {
        public void UpdateHUD(Player.EAction action)
        {
            Console.WriteLine($"HUD Update : {action}");
        }
    }

    public class LogSystem
    {
        public void Log(Player.EAction action)
        {
            Console.WriteLine($"Log : {action}");
        }
    }

}
