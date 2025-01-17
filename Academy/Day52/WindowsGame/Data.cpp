#include "pch.h"
#include "Data.h"

#pragma region MonsterData
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

#pragma endregion


#pragma region TowerData
/*
{
	"id": 100001,
	"name": "Tower1",
	"damage": 500,
	"attackSpeed": 0.1,
	"attackRange": 200,
	"resourceName": "FB_DrillTank",
	"bulletSpeed" : 100
  }
*/
void TowerData::FromJson(string json)
{
	Document document;
	//1. DOM 객체 생성
	document.Parse(json.c_str());

	assert(document.HasParseError() == false);

	this->Id = document["id"].GetInt64();
	this->Name = document["name"].GetString();
	this->Damage = document["damage"].GetFloat();
	this->AttackSpeed = document["attackSpeed"].GetFloat();
	this->AttackRange = document["attackRange"].GetFloat();
	this->BulletSpeed = document["bulletSpeed"].GetFloat();
	this->ResourceName = document["resourceName"].GetString();
}

string TowerData::ToJson()
{
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);

	writer.StartObject();	// {
	writer.Key("id");		// "id" : 
	writer.Int64(this->Id);	//        id,
	writer.Key("name");
	writer.String(this->Name.c_str());
	writer.Key("damage");
	writer.Double(this->Damage);
	writer.Key("attackSpeed");
	writer.Double(this->AttackSpeed);
	writer.Key("attackRange");
	writer.Double(this->AttackRange);
	writer.Key("bulletSpeed");
	writer.Double(this->BulletSpeed);
	writer.EndObject();		// }

	return string(buffer.GetString());
}

#pragma endregion


#pragma region WaveOptionData
/*
{
  "waveTime": 10,
  "buildTime": 10,
  "startPoint": {
	"x": 40,
	"y": 25
  },
  "finishPoint": {
	"x": 5,
	"y": 3
  }
}
*/
void WaveOptionData::FromJson(string json)
{
	Document document;
	//1. DOM 객체 생성
	document.Parse(json.c_str());

	assert(document.HasParseError() == false);

	this->WaveTime = document["waveTime"].GetFloat();
	this->BuildTime = document["buildTime"].GetFloat();
	this->StartPoint.x = document["startPoint"]["x"].GetInt();
	this->StartPoint.y = document["startPoint"]["y"].GetInt();
	this->FinishPoint.x = document["finishPoint"]["x"].GetInt();
	this->FinishPoint.y = document["finishPoint"]["y"].GetInt();
}

string WaveOptionData::ToJson()
{
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);

	writer.StartObject();	// {
	writer.Key("waveTime");
	writer.Double(this->WaveTime);
	writer.Key("buildTime");
	writer.Double(this->BuildTime);

	writer.Key("startPoint");	// "startPoint" : 
	{
		writer.StartObject();	// {
		writer.Key("x");
		writer.Int(this->StartPoint.x);
		writer.Key("y");
		writer.Int(this->StartPoint.y);
		writer.EndObject();
	}

	writer.Key("finishPoint");	// "finishPoint" : 
	{
		writer.StartObject();	// {
		writer.Key("x");
		writer.Int(this->FinishPoint.x);
		writer.Key("y");
		writer.Int(this->FinishPoint.y);
		writer.EndObject();
	}

	writer.EndObject();		// }

	return string(buffer.GetString());
}

#pragma endregion

