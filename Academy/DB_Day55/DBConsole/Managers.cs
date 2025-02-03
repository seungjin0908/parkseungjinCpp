using DB;
using DB.Migrations;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata;
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
                    if(_instance==null)
                    {
                        _instance = new Managers();
                        Init();
                    }

                    return _instance;
                }
            }
            static Managers _instance = null;

            private SbsDbContext _db;
            public static SbsDbContext Db { get {
                => Instance._db; }

            static void Init()
            {
                _instance._db = new SbsDbContext    ();
            }
    }


    public class AAAManager
    {
        private static AAAManager _instance = null;

        public static AAAManager Instance
        {
            get
            {
                if (_instance == null)
                {
                    Init();
                }
                return _instance;
            }
        }

    }

}
