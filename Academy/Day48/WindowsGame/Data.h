#pragma once

#pragma region MosterData
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
struct MonsterData : IData
{
	//데이터는 무조건 Id를 가져야합니다.
public:
	int64 Id;
	string Name;
	float Damage;
	float AttackSpeed;
	string AttackRange;
	float BulletSpeed;
public:
	virtual void FromJson(string json) override;
	virtual string ToJson() override;
};

#pragma endregion

#pragma region WaveOptionData
struct MonsterData : IData
{
	//웨이브 시간
	// 건물 짓는 시간
	// 시작 위치 ~ 끝 위치
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