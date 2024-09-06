#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

enum RockScissorPaper
{
	scissor,
	rock,
	paper,
	end
};

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

void main()
{
	// 과제 2 : 플레이어와 몬스터 가위바위보
	Player player = {};   // 플레이어 스탯
	player.playerHp = 100;
	player.playerAttack = 20;
	player.PrintInfo(player);

	Moster moster = {};   // 몬스터 스탯
	moster.mosterHp = 100;
	moster.mosterAttack = 20;
	moster.PrintInfo(moster);


	cout << "가위 바위 보 중에서 하나를 선택해 주세요" << endl;
	player.player = rand() % 3;
	moster.moster = rand() % 3;

	srand(time(NULL));
	while (player.playerHp >= 0 && moster.mosterHp >= 0)
	{
		if (player.player == (int)RockScissorPaper::scissor && moster.moster == (int)RockScissorPaper::paper)
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
			cout << "플레이어가 한대 때렸습니다." << player.playerAttack << endl;
			moster.mosterHp -= player.playerAttack;
		}
		else if (player.player == (int)RockScissorPaper::rock && moster.moster == (int)RockScissorPaper::paper)
		{
			cout << "몬스터가 한대 때렸습니다." << moster.mosterAttack << endl;
			player.playerHp -= moster.mosterAttack;
		}
		else if (player.player == (int)RockScissorPaper::paper && moster.moster == (int)RockScissorPaper::rock)
		{
			cout << "플레이어가 한대 때렸습니다." << player.playerAttack << endl;
			moster.mosterHp -= player.playerAttack;
		}
		else if (player.player == (int)RockScissorPaper::paper && moster.moster == (int)RockScissorPaper::scissor)
		{
			cout << "몬스터가 한대 때렸습니다." << moster.mosterAttack << endl;
			player.playerHp -= moster.mosterAttack;
		}
	}
}

//숙제1.
// 그동안 만든것중에서
// 원하는거 1개 (오늘실습포함)
// GotoXY를 활용해서 꾸미기 

//숙제2.
// 오늘 실습한거 (몬스터와 플레이어 가위바위보)
// 시간내로 못하신분들 모두

//숙제3.
// 학생부 시스템
//1) 영어, 수학, 국어 성적 입력하게 끔해주고
//2) 입력을 모두했으면, 학생의 평균점수를 확인해주는 프로그램
// Gotoxy 써서 이쁘게하면 좋습니다.

//숙제4.
// 다마고치 / 스네이크게임 / 테트리스 게임중에 만들수있으신 분 한정해서 만들어와주세요.
// 기존게임과 달리 (사용자가 입력해야만 게임 진행)
// 리얼타임 게임