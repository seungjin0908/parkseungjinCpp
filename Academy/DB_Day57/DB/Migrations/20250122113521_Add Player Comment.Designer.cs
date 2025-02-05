﻿// <auto-generated />
using DB;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Infrastructure;
using Microsoft.EntityFrameworkCore.Metadata;
using Microsoft.EntityFrameworkCore.Migrations;
using Microsoft.EntityFrameworkCore.Storage.ValueConversion;

#nullable disable

namespace DB.Migrations
{
    [DbContext(typeof(SbsDbContext))]
    [Migration("20250122113521_Add Player Comment")]
    partial class AddPlayerComment
    {
        /// <inheritdoc />
        protected override void BuildTargetModel(ModelBuilder modelBuilder)
        {
#pragma warning disable 612, 618
            modelBuilder
                .HasAnnotation("ProductVersion", "8.0.3")
                .HasAnnotation("Relational:MaxIdentifierLength", 64);

            MySqlModelBuilderExtensions.AutoIncrementColumns(modelBuilder);

            modelBuilder.Entity("DB.Tables.TblPlayer", b =>
                {
                    b.Property<int>("Id")
                        .ValueGeneratedOnAdd()
                        .HasColumnType("int")
                        .HasComment("Id");

                    MySqlPropertyBuilderExtensions.UseMySqlIdentityColumn(b.Property<int>("Id"));

                    b.Property<int>("Gold")
                        .HasColumnType("int")
                        .HasComment("현재 보유 골드");

                    b.Property<int>("Level")
                        .HasColumnType("int")
                        .HasComment("레벨");

                    b.Property<string>("Name")
                        .IsRequired()
                        .HasColumnType("longtext")
                        .HasComment("이름");

                    b.HasKey("Id");

                    b.ToTable("TblPlayer");
                });
#pragma warning restore 612, 618
        }
    }
}
