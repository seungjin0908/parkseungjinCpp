using DB;
using DB.Migrations;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DBConsole
{
    public class Managers
    {
        static Managers Instance 
        { 
            get 
            { 
                if (_instance == null) 
                {
                    _instance = new Managers();
                    Init();
                }

                return _instance;
            } 
        }
        static Managers _instance = null;

        private SbsDbContext _db;
        public static SbsDbContext Db { get => Instance._db; }

        private User _user;
        public static User User { get => Instance._user; }

        private ItemManager _item = new ItemManager();
        public static ItemManager Item { get => Instance._item; }

        static void Init()
        {
            _instance._db = new SbsDbContext();
            _instance._user = new User();
            _instance._item.Init();
        }
    }


    public class ItemManager
    {
        private Dictionary<int, Item> _items = new Dictionary<int, Item>();
        public IReadOnlyDictionary<int, Item> Items { get {  return _items; } }


        public void Init()
        {
            _items.Add(1, new Item()
            {
                Id = 1,
                Name = "슬라임 조각"
            });

            _items.Add(2, new Item()
            {
                Id = 2,
                Name = "주황버섯"
            });

            _items.Add(3, new Item()
            {
                Id = 3,
                Name = "파란 포자"
            });

            _items.Add(4, new Item()
            {
                Id = 4,
                Name = "냄비 뚜껑"
            });

            _items.Add(5, new Item()
            {
                Id = 5,
                Name = "도란 방패"
            });

            _items.Add(6, new Item()
            {
                Id = 6,
                Name = "도란 검"
            });

            _items.Add(7, new Item()
            {
                Id = 7,
                Name = "도란 반지"
            });

            _items.Add(8, new Item()
            {
                Id = 8,
                Name = "마법의 장화"
            });

            _items.Add(9, new Item()
            {
                Id = 9,
                Name = "지팡이"
            });
        }
    }


    //// 가장 심플한 매니저방식
    //public class AAAManager
    //{
    //    private static AAAManager _instance = null;
    //    public static AAAManager Instance 
    //    {
    //        get 
    //        { 
    //            if (_instance == null) 
    //            { 
    //                Init(); 
    //            } 
    //            return _instance; 
    //        } 
    //    }

    //    static void Init()
    //    {
    //        _instance = new AAAManager();

    //        //해주고싶은 초기화
    //    }
    //}
}
