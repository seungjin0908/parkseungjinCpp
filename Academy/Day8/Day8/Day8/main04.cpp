#include <iostream>

using namespace std;

enum RockScissorPaper
{
	scissor,
	rock,
	paper,
	end
};

// 구조체는
// 변수 + 함수들을 묶어놓는 기능

// 1. 구조체 정의
struct Player
{
	int player = 0;
	int playerHp = 0;
	int playerAttack = 0;

	void PrintInfo(Player)
	{
		cout << "플레이어 Hp : " << this->playerHp << endl;
		cout << "플레어어 Attack : " << this->playerAttack << endl;
	}
};

struct Moster
{
	int moster = 0;
	int mosterHp = 0;
	int mosterAttack = 0;

	void PrintInfo(Moster)
	{
		cout << "몬스터 Hp : " << this->mosterHp << endl;
		cout << "몬스터 Attack : " << this->mosterAttack << endl;
	}
};
// float mosterHp
// float mosterAttack


void main()
{
	// 2. 구조체

	// 자료형부터 넘어가야함.

	// int, float, __int64, char, bool
	// 기본자료형

	// 사용자 정의 자료형

	// 기본자료형
	//  -> 언어에서 기본적으로 제공해주는 자료형
	//     (정수, 실수, 문자열, 참 거짓 등)

	// 사용자 정의 자료형
	//  -> 직접 자료형을 만드는거임.
	//     (enum, struct, class)
	//  -> 말이 사용자 정의 자료형이지
	//      그냥 정수형 아님??

	Player player = {};   // 플레이어 스탯
	player.playerHp = 100;
	player.playerAttack = 20;
	player.PrintInfo(player);

	Moster moster = {};   // 몬스터 스탯
	moster.mosterHp = 100;
	moster.mosterAttack = 20;
	moster.PrintInfo(moster);


	srand(time(NULL));
	while (player.playerHp >= 0 && moster.mosterHp >= 0)
	{
		if (player.player == (int)RockScissorPaper::scissor && moster.moster==(int)RockScissorPaper::paper)
		{
			cout << "플레어어가 한대 때렸습니다." << player.playerAttack << endl;
			moster.mosterHp -= player.playerAttack;
		}
		else if (player.player == (int)RockScissorPaper::scissor && moster.moster == (int)RockScissorPaper::rock)
		{
			cout << "몬스터가 한대 때렸습니다." << moster.mosterAttack << endl;
			player.playerHp -= moster.mosterAttack;
		}
		else if (player.player == (int)RockScissorPaper::rock && moster.moster == (int)RockScissorPaper::scissor)
		{

		}
	}


	// 실습
	//
	// 플레이어, 몬스터
	// 각각의 스탯이 존재함.
	// 플레이어와 몬스터가 가위바위보를 함.
	// 이긴쪽이 한대 때림.
	// 그래서 한쪽이 죽을때까지 가위바위보를 함.
	// 플레이어가 승리했는지, 패배했는지 문구 띄워주는 게임을 실습
}