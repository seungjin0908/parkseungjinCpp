using System;
using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace DB.Migrations
{
    /// <inheritdoc />
    public partial class AddDefaultValue : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AlterColumn<DateTime>(
                name: "ExpirationDate",
                table: "TblTradeItem",
                type: "datetime(6)",
                nullable: false,
                defaultValueSql: "DATE_ADD(NOW(), INTERVAL 24 HOUR)",
                comment: "언제 마감인지",
                oldClrType: typeof(DateTime),
                oldType: "datetime(6)",
                oldComment: "언제 마감인지");

            migrationBuilder.AlterColumn<DateTime>(
                name: "CreatedAt",
                table: "TblTradeItem",
                type: "datetime(6)",
                nullable: false,
                defaultValueSql: "NOW()",
                comment: "언제 올렸는지",
                oldClrType: typeof(DateTime),
                oldType: "datetime(6)",
                oldComment: "언제 올렸는지");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.AlterColumn<DateTime>(
                name: "ExpirationDate",
                table: "TblTradeItem",
                type: "datetime(6)",
                nullable: false,
                comment: "언제 마감인지",
                oldClrType: typeof(DateTime),
                oldType: "datetime(6)",
                oldDefaultValueSql: "DATE_ADD(NOW(), INTERVAL 24 HOUR)",
                oldComment: "언제 마감인지");

            migrationBuilder.AlterColumn<DateTime>(
                name: "CreatedAt",
                table: "TblTradeItem",
                type: "datetime(6)",
                nullable: false,
                comment: "언제 올렸는지",
                oldClrType: typeof(DateTime),
                oldType: "datetime(6)",
                oldDefaultValueSql: "NOW()",
                oldComment: "언제 올렸는지");
        }
    }
}
