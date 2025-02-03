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
        [Comment("이름")]
        public string Name { get; set; }


    }
}
