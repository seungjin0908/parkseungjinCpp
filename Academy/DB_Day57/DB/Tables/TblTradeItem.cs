using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DB.Tables
{
    [Comment("경매장에 올라간 아이템을 저장하는 Table")]
    [Table("TblTradeItem")]
    public partial class TblTradeItem
    {
        [Key] // (컬럼명이 Id인건 알아서 Primary Key라고 인식함)
        [Comment("Id")]
        public int Id { get; set; }

        [Required]
        [Comment("누가 올렸는지")]
        public int SellerPlayerId { get; set; }  // 판매자 ID

        [Required]
        [Comment("언제 마감인지")]
        public DateTime ExpirationDate { get; set; }  // 마감 시간

        [Comment("누가 샀는지")]
        public int? BuyerPlayerId { get; set; }  // 구매자 ID (nullable)

        [Required]
        [Comment("언제 올렸는지")]
        [SqlDefaultValue("DATE_ADD(NOW(), INTTERVAL 24 HOUR)")]
        public DateTime CreatedAt { get; set; }  // 등록 시간

        [Comment("얼마에 올렸는지")]
        public int ListedPrice { get; set; }  // 등록 가격


        [ForeignKey("SellerPlayerId")]
        public virtual TblPlayer? SellerPlayerIdNavigation { get; set; }

        [ForeignKey("BuyerPlayerId")]
        public virtual TblPlayer? BuyerPlayerIdNavigation { get; set; }
    }

}
