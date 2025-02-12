using System;
using Microsoft.EntityFrameworkCore.Metadata;
using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace DB.Migrations
{
    /// <inheritdoc />
    public partial class AddTblTradeItem : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "TblTradeItem",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false, comment: "Id")
                        .Annotation("MySql:ValueGenerationStrategy", MySqlValueGenerationStrategy.IdentityColumn),
                    SellerPlayerId = table.Column<int>(type: "int", nullable: false, comment: "누가 올렸는지"),
                    ExpirationDate = table.Column<DateTime>(type: "datetime(6)", nullable: false, comment: "언제 마감인지"),
                    BuyerPlayerId = table.Column<int>(type: "int", nullable: true, comment: "누가 샀는지"),
                    CreatedAt = table.Column<DateTime>(type: "datetime(6)", nullable: false, comment: "언제 올렸는지"),
                    ListedPrice = table.Column<int>(type: "int", nullable: false, comment: "얼마에 올렸는지")
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_TblTradeItem", x => x.Id);
                    table.ForeignKey(
                        name: "FK_TblTradeItem_TblPlayer_BuyerPlayerId",
                        column: x => x.BuyerPlayerId,
                        principalTable: "TblPlayer",
                        principalColumn: "Id");
                    table.ForeignKey(
                        name: "FK_TblTradeItem_TblPlayer_SellerPlayerId",
                        column: x => x.SellerPlayerId,
                        principalTable: "TblPlayer",
                        principalColumn: "Id",
                        onDelete: ReferentialAction.Cascade);
                },
                comment: "경매장에 올라간 아이템을 저장하는 Table")
                .Annotation("MySql:CharSet", "utf8mb4");

            migrationBuilder.CreateIndex(
                name: "IX_TblTradeItem_BuyerPlayerId",
                table: "TblTradeItem",
                column: "BuyerPlayerId");

            migrationBuilder.CreateIndex(
                name: "IX_TblTradeItem_SellerPlayerId",
                table: "TblTradeItem",
                column: "SellerPlayerId");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "TblTradeItem");
        }
    }
}
