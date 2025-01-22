using DB.Tables;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Logging;

namespace DB
{
    public class SbsDbContext : DbContext
    {
        public DbSet<TblPlayer> TblPlayers { get; set; }
        public DbSet<TblPlayerItem> TblPlayerItems { get; set; }

        static readonly ILoggerFactory _logger = LoggerFactory.Create(builder => { builder.AddConsole(); });

        // DB접속 정보
        /*
         * Server Host : creams.synology.me
         * port - 3306
         * database - SBS_Study_PSJ_20250120
         * User - PAStudy
         * Password - PAtmxje122..
         */ 
        public static string ConnectionString = "Server Host : creams.synology.me; port = 3306; database=SBS_Study_PSJ_20250120; user=PAStudy; Password=PAtmxje122.. ";

        public SbsDbContext(DbContextOptions<SbsDbContext> options) : base(options)
        {

        }

        public SbsDbContext()
        {

        }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            // DB 접속정보 옵션 지정하는곳
            optionsBuilder.UseLoggerFactory(_logger);

            // 어떤 DB를 쓸건지에 따라 수정필요하다.
            optionsBuilder.UseMySql(ConnectionString, ServerVersion.AutoDetect(ConnectionString));
            base.OnConfiguring(optionsBuilder);
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);
        }
    }
}
