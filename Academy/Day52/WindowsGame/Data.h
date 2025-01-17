#pragma once

#pragma region MonsterData
struct MonsterData : IData
{
	//데이터는 무조건 Id를 가져야합니다.
public:
	int64 Id;
	string Name;
	float Hp;
	float MoveSpeed;
	string ResourceName;

public:
	virtual void FromJson(string json) override;
	virtual string ToJson() override;
};
#pragma endregion

#pragma region TowerData
struct TowerData : IData
{
	//데이터는 무조건 Id를 가져야합니다.
public:
	int64 Id;
	string Name;
	float Damage;
	float AttackSpeed;
	float AttackRange;
	string ResourceName;
	float BulletSpeed;
public:
	virtual void FromJson(string json) override;
	virtual string ToJson() override;
};

#pragma endregion

#pragma region WaveOptionData
struct WaveOptionData : IData
{
public:
	float WaveTime;
	float BuildTime;
	Vector2Int StartPoint;
	Vector2Int FinishPoint;
public:
	virtual void FromJson(string json) override;
	virtual string ToJson() override;
};

#pragma endregion
