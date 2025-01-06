#pragma once

struct MosterData : IData
{
	// 데이터는 무조건 Id를 가져야한다.
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
