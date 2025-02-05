using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace DB.Migrations
{
    /// <inheritdoc />
    public partial class AddForeinkeyOwnerPlayerId : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateIndex(
                name: "IX_TblPlayerItem_OwnerPlayerId",
                table: "TblPlayerItem",
                column: "OwnerPlayerId");

            migrationBuilder.AddForeignKey(
                name: "FK_TblPlayerItem_TblPlayer_OwnerPlayerId",
                table: "TblPlayerItem",
                column: "OwnerPlayerId",
                principalTable: "TblPlayer",
                principalColumn: "Id",
                onDelete: ReferentialAction.Cascade);
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropForeignKey(
                name: "FK_TblPlayerItem_TblPlayer_OwnerPlayerId",
                table: "TblPlayerItem");

            migrationBuilder.DropIndex(
                name: "IX_TblPlayerItem_OwnerPlayerId",
                table: "TblPlayerItem");
        }
    }
}
