using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBConsole
{
    public class User
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Gold { get; set; }

        public void Login(int Id, string Name, int Gold)
        {
            this.Id = Id;
            this.Name = Name;
            this.Gold = Gold;
        }

        public void Logout()
        {
            this.Id = 0;
            this.Name = "";
        }
    }
}
