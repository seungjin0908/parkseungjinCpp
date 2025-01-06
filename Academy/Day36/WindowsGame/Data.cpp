#include "pch.h"
#include "Data.h"

void MosterData::FromJson(string json)
{
	Document document;
	// 1. DOM 객체 생성
	document.Parse(json.c_str());

	assert(document.HapParseError() == false);

	this->Id = document["id"].GetInit64();
	this->Hp = document["hp"].GetFloat();
	this->MoveSpeed = document["MoveSpeed"].GetFloat();
	this->Name = document["name"].GetString();
	this->ResourceName = document["ResourceName"].GetString();
}

string MosterData::ToJson()
{
	StringBuffer buffer;
	Writer<StringBuffer> witer(buffer);

	writer.StartObject();
	writer.Key("id");
	writer.Int64(this->Id);

}
