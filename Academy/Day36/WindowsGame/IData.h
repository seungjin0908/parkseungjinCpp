#pragma once
// 인터페이스
// 함수만 있는 클래스를 인터페이스라고 한다.

class IData
{
public:
	virtual void FromJson(string json) = 0; // JSON => 객체로
	virtual string ToJson() = 0;			// 객체 => JSON
};