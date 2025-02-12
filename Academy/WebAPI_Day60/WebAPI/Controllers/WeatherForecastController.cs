using DB;
using DB.Migrations;
using DB.Tables;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using System.Xml.Linq;
using WebAPI.Dtos;

namespace WebAPI.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class WeatherForecastController : ControllerBase
    {
        private static readonly string[] Summaries = new[]
        {
            "Freezing", "Bracing", "Chilly", "Cool", "Mild", "Warm", "Balmy", "Hot", "Sweltering", "Scorching"
        };

        private readonly ILogger<WeatherForecastController> _logger;
        private readonly SbsDbContext _db;

        public WeatherForecastController(ILogger<WeatherForecastController> logger, SbsDbContext db)
        {
            _logger = logger;
            _db = db;
        }

        [HttpGet("GetWeatherForecast")]
        public IEnumerable<WeatherForecast> Get()
        {
            return Enumerable.Range(1, 5).Select(index => new WeatherForecast
            {
                Date = DateOnly.FromDateTime(DateTime.Now.AddDays(index)),
                TemperatureC = Random.Shared.Next(-20, 55),
                Summary = Summaries[Random.Shared.Next(Summaries.Length)]
            })
            .ToArray();
        }

        [HttpGet("GetPlayerList")]
        public async Task<ResDtoGetPlayerList> GetPlayerList([FromQuery]
        ReqDtoGetPlayerList request)
        {
            ResDtoGetPlayerList rv = new();

            var list = await _db.TblPlayers.Select(player => new
            ResDtoGetPlayerListChild()
            {
                Gold = player.Gold,
                Name = player.Name,
                PlayerId = player.Id
            }).ToListAsync();

            rv.List = list;

            return rv;
        }

        [HttpGet("GetInventory")]
        public async Task<ResDtoGetPlayerList> GetInventory([FromQuery]
        ReqDtoGetInventory request)
        {
            Res
        }

        
        [HttpGet("Sell")]
        public async Task<ResDtoGetPlayerList> Sell([FromQuery] ReqDtoSell request)
        {
            //// 1. TradeItems 에 등록
            //var tradeItemEntity = _db.TblPlayerItems
            //    // 내가 올린 것 중에
            //    .Where(tradeItem => tradeItem.SellPalyerId == request.PlayerId)
            //    // 지금 올리려는 아이템이
            //    .where(tradeItem => tradeItem.ItemId == request.ItemId);

            // 1 TradeItems 에 등록
            _db.TblTradeItems.Add(new TblTradeItem()
            {
                BuyerPlayerId = null,
                SellerPlayerId = request.PlayerId,
                ListedPrice = request.Price,
                ItemId = request.ItemId,
            });

            // 2. 내 PlayerItems에서 제외
            var playerItemEntity = await _db.TblPlayerItems

                // 내 아이템중에
                .Where(playerItem => playerItem.OwnerPlayerId == request.PlayerId)
                // 내가 올린 아이템을
                .Where(playerItem => playerItem.ItemId == request.ItemId)
                // 가지고 와라.
                .FirstOrDefaultAsync();

            // 존재한다면
            if(playerItemEntity != null)
            {
                playerItemEntity.Count--;
            }

            // 이제 더이상 존재하지 않는다면
            if(playerItemEntity.Count == 0)
            {
                // Remove
                _db.TblPlayerItems.Remove(playerItemEntity);
            }
            else
            {
                // Update
                _db.TblPlayerItems.Update(playerItemEntity);
            }

            await _db.SaveChangesAsync();

            return rv;
        }

        

        [HttpGet("Buy")]
        public async Task<ResDtoBuy> Buy([FromQuery] ReqDtoBuy request)
        {
            ResDtoBuy rv = new ();

            // 1. 돈이 있는지 체크한다.
            var tradeItemEntity = await _db.TblTradeItems
                // 해당 제품을 가지고온다.
                .Where(tradeItem => tradeItem.Id == request.TradeItemId)
                .FirstOrDefaultAsync();

            if(tradeItemEntity == null)
            {
                rv.IsSucces =false;
                rv.Message = "비정상적인 접근입니다. 다시 시도해주세요.";

                return rv;
            }

            if(buyPlayerEntity.Gold < tradeItemEntity.ListedPrice)
            {
                rv.IsSucces = false;
                rv.Message = "가진 돈보다 비싼 제품입니다. 구매할 수 없습니다.";

                return rv;
            }

            // 2. 구매자 Gold 감소
            buyPlyerEntity.Gold -= tradeItemEntity.ListedPrice;
            _db.TblPlayers.Update(buyPlayerEntity);

            // 3. PlayerItem에서 Count 하나 추가하거나, Entity Add
            var playerItemEntity = await _db.TblPlayerItems
                .Where()

            // 이게 첫 
        }

    }
}