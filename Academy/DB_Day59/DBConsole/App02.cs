using DB.Tables;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBConsole
{
    // PlayerGenerate 매크로
    public class App02
    {
        Random _rand = new Random();
        List<string> nameList = new List<string>()
        {
            "James", "Mary", "Robert", "Patricia", "John", "Jennifer", "Michael", "Linda",
            "David", "Elizabeth", "William", "Barbara", "Richard", "Susan", "Joseph", "Jessica",
            "Thomas", "Sarah", "Charles", "Karen", "Christopher", "Nancy", "Daniel", "Lisa",
            "Matthew", "Betty", "Anthony", "Sandra", "Mark", "Ashley", "Donald", "Kimberly",
            "Steven", "Emily", "Andrew", "Donna", "Paul", "Michelle", "Joshua", "Dorothy",
            "Kenneth", "Carol", "Kevin", "Amanda", "Brian", "Melissa", "George", "Deborah",
            "Edward", "Stephanie", "Ronald", "Rebecca", "Timothy", "Sharon", "Jason", "Laura",
            "Jeffrey", "Cynthia", "Ryan", "Kathleen", "Jacob", "Amy", "Gary", "Shirley",
            "Nicholas", "Angela", "Eric", "Helen", "Jonathan", "Anna", "Stephen", "Brenda",
            "Larry", "Pamela", "Justin", "Nicole", "Scott", "Samantha", "Brandon", "Katherine",
            "Benjamin", "Christine", "Samuel", "Debra", "Gregory", "Rachel", "Alexander", "Catherine",
            "Frank", "Carolyn", "Patrick", "Janet", "Raymond", "Ruth", "Jack", "Maria",
            "Dennis", "Heather", "Jerry", "Diane", "Tyler", "Julie"
        };

        public void Run()
        {
            var playerList = Managers.Db.TblPlayers.ToList();
            Managers.Db.TblPlayers.RemoveRange(playerList);
            Managers.Db.SaveChanges();

            while(true)
            {
                Thread.Sleep(1000);
                Managers.Db.TblPlayers.Add(new TblPlayer()
                {
                    Level = _rand.Next(1, 100),
                    Gold = _rand.Next(10000, 100000),
                    Name = nameList[_rand.Next(nameList.Count)]
                });

                Managers.Db.SaveChanges();

                Console.WriteLine("Insert Success!");
            }
        }
    }
}
