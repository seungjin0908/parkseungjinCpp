using DB.Tables;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata.Conventions.Infrastructure;
using Microsoft.Extensions.Logging;

namespace DB
{
    public class SbsDbContext : DbContext
    {
        public DbSet<TblPlayer> TblPlayers { get; set; }
        public DbSet<TblPlayerItem> TblPlayerItems { get; set; }
        public DbSet<TblTradeItem> TblTradeItems { get; set; }


        static readonly ILoggerFactory _logger = LoggerFactory.Create(builder => { builder.AddConsole(); });

        //DB 접속 정보
        /*
         * Server Host : creams.synology.me
         *  port - 3306
         *  database - SBS_Study_[자기 이름 이니셜]_20250120
         *  User - PAStudy
         *  Password - PAtmxjel22..
         */
        public static string ConnectionString = "server=creams.synology.me; port=3306; database=SBS_Study_BSY_20250120; user=PAStudy; password=PAtmxjel22..";

        public SbsDbContext(DbContextOptions<SbsDbContext> options) : base(options) 
        {
        }

        public SbsDbContext()
        {
        }

        protected override void ConfigureConventions(ModelConfigurationBuilder configurationBuilder)
        {
            configurationBuilder.Conventions.Add(
                servies =>new SqlDefaultValueConvention(
                    servies.GetRequiredService<ProviderConventionSetBuilderDependencies>())
                 
             );
        }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            // DB 접속정보 옵션 지정하는곳
            optionsBuilder.UseLoggerFactory(_logger);

            // 어떤 DB를 쓸건지에 따라 수정필요합니다.
            optionsBuilder.UseMySql(ConnectionString, ServerVersion.AutoDetect(ConnectionString));
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);
        }
    }
}
