#include "pch.h"
#include "Data.h"

/*
{
	"id": 100001,
	"name": "Monster1",
	"hp": 1000,
	"moveSpeed": 100,
	"resourceName": "FB_EnemyShip1"
}
*/
void MonsterData::FromJson(string json)
{
	Document document;
	//1. DOM 객체 생성
	document.Parse(json.c_str());

	assert(document.HasParseError() == false);

	this->Id = document["id"].GetInt64();
	this->Hp = document["hp"].GetFloat();
	this->MoveSpeed = document["moveSpeed"].GetFloat();
	this->Name = document["name"].GetString();
	this->ResourceName = document["resourceName"].GetString();
}

string MonsterData::ToJson()
{
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);

	writer.StartObject();	// {
	writer.Key("id");		// "id" : 
	writer.Int64(this->Id);	//        id,
	writer.Key("hp");
	writer.Double(this->Hp);
	writer.Key("moveSpeed");
	writer.Double(this->MoveSpeed);
	writer.Key("name");
	writer.String(this->Name.c_str());
	writer.Key("resourceName");
	writer.String(this->ResourceName.c_str());
	writer.EndObject();		// }

	return string(buffer.GetString());
}