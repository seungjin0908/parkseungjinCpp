using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day40
{
    public class App02
    {
        public event Action<int, int> OnHealthChanged;
        public event Action OnDied;


        public void Run()
        {
            Console.WriteLine("App02");
            OnHealthChanged += WriteHealthLog;
            OnHealthChanged += CheckDied;

            OnDied += ShowPlayerDieAlert;


            OnHealthChanged?.Invoke(100, -10);
        }

        public void WriteHealthLog(int prevHealth, int health)
        {
            Console.WriteLine($"체력 : {prevHealth} => {health}");
        }

        // 지금은 함수지만
        // 프로젝트가 커지다보면 이게 함수가아니라 클래스단위로 갈수도 있어요.
        public void CheckDied(int prevHealth, int health)
        {
            if(prevHealth <= 0)
            {
                return;
            }

            if(health <= 0)
            {
                OnDied?.Invoke();
            }
        }

        public void ShowPlayerDieAlert()
        {
            Console.WriteLine("플레이어 죽었습니다. 게임을 종료합니다.");
        }
    }
}
