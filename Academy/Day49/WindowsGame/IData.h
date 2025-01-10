#pragma once
// 인터페이스
// 함수만있는 클래스를 인터페이스라고 부릅니다.

class IData
{
public:
	virtual void FromJson(string json) = 0; // JSON => 객체
	virtual string ToJson() = 0;			// 객체 => JSON
};