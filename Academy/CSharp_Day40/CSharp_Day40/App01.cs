using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp_Day40
{
    public class App01
    {
        public delegate void Notify(string msg);

        public void Run()
        {
            Notify notify = WriteLog;
            notify += ShowAlert;

            notify("플레이어가 보스룸으로 이동하였습니다.");
        }

        public void WriteLog(string message)
        {
            Console.WriteLine(message);
        }

        public void ShowAlert(string message)
        {
            Console.WriteLine($"-----[{message}]-----");
        }
    }
}
