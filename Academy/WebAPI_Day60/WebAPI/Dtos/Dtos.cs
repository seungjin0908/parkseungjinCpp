namespace WebAPI.Dtos
{
    // GetPlayerList 라우트를 호출할때, 클라이언트에서 추가로 보낼 매게변수들
    public class ReqDtoGetPlayerList
    {
        // 보낼게 없으면 비워두기
    }

    // GetPlayerList 라우트를 호출할때, 서버에서 리턴할 자료형
    public class ResDtoGetPlayerList
    {
        public List<ResDtoGetyPlayerListChild> List { get; set; }

        public class ResDtoGetyPlayerListChild
        {
            public int PlayerId { get; set; }
            public string Name { get; set; }
            public int Gold { get; set; }
        }
    }

    public class ReqDtoGetInventory
    {
        public int PlayerId { get; set; }
    }

    public class ResDtoGetInventory
    {
        public List<ResDtoGetInventoryChild> List { get; set; }

    }
    public class ResDtoGetInventoryChild
    {
        public int PlayerId { get; set; }
        public int ItemId { get; set; }
        public int Count { get; set; }
    }

    public class ReqDtoSell
    {
        public int PlayerId { get; set; }
        public int ItemId { get; set; }
        public int Price { get; set; }
    }

    public class ResDtoSell
    {
        
    }

    public class ReqDtoBuy
    {
        public int BuyPlayerId { get; set; }
        public int TradeItemId { get; set; }
    }

    public class ResDtoBuy
    {
       public bool IsSucces {  get; set; }
       public string Message { get; set; }
    }
}
