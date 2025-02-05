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
    [Table("TblPlayer")]
    public partial class TblPlayer
    {
        [Key] // (컬럼명이 Id인건 알아서 Primary Key라고 인식함)
        [Comment("Id")]
        public int Id { get; set; }

        [Required] // NOT NULL 옵션
        [Comment("이름")]
        public string Name { get; set; }

        [Comment("레벨")]
        public int Level { get; set; }

        [Comment("현재 보유 골드")]
        public int Gold { get; set; }

        //플레이어가 1:N 으로 PlayerItem을 들고있음.
        [InverseProperty("OwnerPlayerIdNavigation")]
        public virtual ICollection<TblPlayerItem> TblPlayerItems { get; set; } = new List<TblPlayerItem>();

        [InverseProperty("BuyerPlayerIdNavigation")]
        public virtual ICollection<TblTradeItem> BuyItems { get; set; } = new List<TblTradeItem>();

        [InverseProperty("SellerPlayerIdNavigation")]
        public virtual ICollection<TblTradeItem> SellItems { get; set; } = new List<TblTradeItem>();
    }
}
