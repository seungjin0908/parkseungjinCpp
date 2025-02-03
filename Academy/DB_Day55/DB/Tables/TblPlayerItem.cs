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
    [Table("TblPlayerItem")]
    public partial class TblPlayerItem
    {
        [Key] // (컬럼명이 Id인건 알아서 Primary Key라고 인식함)
        [Comment("Id")]
        public int Id { get; set; }

        [Comment("Item의 실제 Id")]
        public int ItemId { get; set; }

        [Comment("Item 갯수")]
        public int Count { get; set; }

        [Comment("누가 가졌는지")]
        public int OwnerPlayerId { get; set; }

        //OwnerPlayerId 라는 컬럼을 사용해서, 관계를 맺겠다.
        [ForeignKey("OwnerPlayerId")]
        public virtual TblPlayer? OwnerPlayerIdNavigation { get; set; }
    }
}
