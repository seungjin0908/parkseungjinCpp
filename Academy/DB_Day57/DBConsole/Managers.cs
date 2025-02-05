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
        public static User user { get => Instance._user; }

        static void Init()
        {
            _instance._db = new SbsDbContext();
            _instance._user = new User();
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
