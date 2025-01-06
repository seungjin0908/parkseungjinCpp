#include "pch.h"
#include "DataManager.h"


void DataManager::Init()
{
	ifstream ifs(L"../Resources/Day48/Data/MosterData.json");

	assert(ifs.is_open());

	stringstream buffer;
	buffer << ifs.rdbuf();
	string json = buffer.str();
	
	Document document;
	document.Parse(json.c_str());

	assert(document.HasParseError() == false);

	assert(document.IsArray());
	GenericArray<false, Value> array = document.GetArray();

	for (SizeType i = 0; i < array.Size(); i++)
	{
		StringBuffer buffer;
		Writer<StringBuffer> writer(buffer);
		array[i].Accept(writer);

		MosterData data;
		data.FromJson(buffer.GetString());

		assert(_mosterDatas.contains(data.Id) == false);
		_mosterDatas[data.Id] = data;
	}

	for (auto monster : _mosterDatas)
	{
		string json = monster.second.ToJson();
		cout << "---추가된 몬스터---" << endl;
		cout << json << endl;
	}
}
void DataManager::Release()
{

}
