#include "pch.h"
#include "DataManager.h"


void DataManager::Init()
{
#pragma region MonsterData
	{
		ifstream ifs(L"../Resources/Day48/Data/MonsterData.json");

		assert(ifs.is_open());

		stringstream buffer;
		buffer << ifs.rdbuf();
		string json = buffer.str();

		Document document;
		document.Parse(json.c_str());

		assert(document.HasParseError() == false);

		assert(document.IsArray());
		GenericArray<false, Value> array = document.GetArray();

		for (SizeType i = 0; i < array.Size(); ++i)
		{
			StringBuffer buffer;
			Writer<StringBuffer> writer(buffer);
			array[i].Accept(writer);

			MonsterData data;
			data.FromJson(buffer.GetString());

			assert(_monsterDatas.contains(data.Id) == false);
			_monsterDatas[data.Id] = data;
		}

		for (auto monster : _monsterDatas)
		{
			string json = monster.second.ToJson();
			cout << "---추가된 몬스터---" << endl;
			cout << json << endl;
		}
	}
#pragma endregion

#pragma region TowerData
	{
		ifstream ifs(L"../Resources/Day48/Data/TowerData.json");

		assert(ifs.is_open());

		stringstream buffer;
		buffer << ifs.rdbuf();
		string json = buffer.str();

		Document document;
		document.Parse(json.c_str());

		assert(document.HasParseError() == false);

		assert(document.IsArray());
		GenericArray<false, Value> array = document.GetArray();

		for (SizeType i = 0; i < array.Size(); ++i)
		{
			StringBuffer buffer;
			Writer<StringBuffer> writer(buffer);
			array[i].Accept(writer);

			TowerData data;
			data.FromJson(buffer.GetString());

			assert(_towerDatas.contains(data.Id) == false);
			_towerDatas[data.Id] = data;
		}

		for (auto tower : _towerDatas)
		{
			string json = tower.second.ToJson();
			cout << "---추가된 타워---" << endl;
			cout << json << endl;
		}
	}
#pragma endregion

#pragma region WaveOptionData
	{
		ifstream ifs(L"../Resources/Day48/Data/WaveOptionData.json");

		assert(ifs.is_open());

		stringstream buffer;
		buffer << ifs.rdbuf();
		string json = buffer.str();

		Document document;
		document.Parse(json.c_str());

		assert(document.HasParseError() == false);

		WaveOptionData data;
		data.FromJson(json.c_str());

		cout << data.ToJson() << endl;

	}
#pragma endregion


}
void DataManager::Release()
{

}