#include "Game1.h"
#include "Bullet1.h"
#include "Player.h"
#include "EnemyBoss2.h"
#include "EnemyMob.h"
#include "EnemyMob2.h"
#include "Effect.h"
#include "GameData.h"
#include "Field.h"
#include "UI.h"
#include "../Title/Result.h"

Game1::Game1(bool tuto) :Base(eType_Scene)
{
	m_cnt = 0;
	Base::Add(new Field());
	
	Base::Add(new Player(CVector2D(640, 600)));
	Base::Add(new EnemyBoss2(CVector2D(640, 100)));
	
	Base::Add(new EnemyMob2(CVector2D(1140, 0)));
	//Base::Add(new EnemyMob2(CVector2D(1040, 10)));
	Base::Add(new EnemyMob2(CVector2D(940, 0)));
	//Base::Add(new EnemyMob2(CVector2D(840, 10)));
	Base::Add(new EnemyMob2(CVector2D(740, 0)));
	//Base::Add(new EnemyMob2(CVector2D(640, 10)));
	Base::Add(new EnemyMob2(CVector2D(540, 0)));
	//Base::Add(new EnemyMob2(CVector2D(440, 10)));
	Base::Add(new EnemyMob2(CVector2D(340, 0)));
	//Base::Add(new EnemyMob2(CVector2D(240, 10)));
	Base::Add(new EnemyMob2(CVector2D(140, 0)));
	
	Base::Add(new UI());
	m_is_tuto = tuto;
}

void Game1::Update()
{
	//カウント
	m_cnt++;
	if (m_cnt >= 193) {
		//Base::Add(new EnemyMob(CVector2D(1000, 200)));
		//Base::Add(new EnemyMob(CVector2D(640, 200)));
		//Base::Add(new EnemyMob(CVector2D(200, 200)));
		m_cnt = 0;
		//m_is_tuto = tuto;
	}

	if (GameData::s_score1 <= 0 || GameData::s_score <= 0) {
		SetKill();
	}

}

Game1::~Game1()
{
	//全てのオブジェクトを破棄
	Base::KillAll();
	//リザルト画面へ
	Result::finish_game = 1;
	Base::Add(new Result(m_is_tuto));
}