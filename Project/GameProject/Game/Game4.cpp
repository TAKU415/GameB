#include "Game4.h"
#include "Bullet1.h"
#include "Player.h"
#include "EnemyBoss.h"
#include "EnemyBoss2.h"
#include "EnemyMob.h"
#include "EnemyMob2.h"
#include "kuma.h"
#include "Effect.h"
#include "GameData.h"
#include "Field.h"
#include "UI.h"
#include "../Title/Result.h"

Game4::Game4(bool tuto) :Base(eType_Scene)
{
	m_cnt = 0;
	Base::Add(new Field());

	Base::Add(new Player(CVector2D(640, 600)));
	//if (GameData::s_score <= 6000) {
		Base::Add(new EnemyBoss(CVector2D(640, 100)));
	//}
	//if (GameData::s_score <= 3000) {
		Base::Add(new EnemyBoss2(CVector2D(640, 100)));
	//}

	Base::Add(new EnemyMob2(CVector2D(1140, 10)));
	Base::Add(new EnemyMob2(CVector2D(1040, 10)));
	Base::Add(new EnemyMob2(CVector2D(940, 10)));
	Base::Add(new EnemyMob2(CVector2D(840, 10)));
	Base::Add(new EnemyMob2(CVector2D(740, 10)));
	Base::Add(new EnemyMob2(CVector2D(640, 10)));
	Base::Add(new EnemyMob2(CVector2D(540, 10)));
	Base::Add(new EnemyMob2(CVector2D(440, 10)));
	Base::Add(new EnemyMob2(CVector2D(340, 10)));
	Base::Add(new EnemyMob2(CVector2D(240, 10)));
	Base::Add(new EnemyMob2(CVector2D(140, 10)));

	Base::Add(new kuma(CVector2D(200, 130)));
	//Base::Add(new kuma(CVector2D(640, 230)));
	Base::Add(new kuma(CVector2D(1040, 130)));
	Base::Add(new UI());
	m_is_tuto = tuto;
}

void Game4::Update()
{
	//カウント
	m_cnt++;
	if (m_cnt >= 150) {
		//Base::Add(new EnemyMob(CVector2D(1080, 200)));
		Base::Add(new EnemyMob(CVector2D(640, 200)));
		//Base::Add(new EnemyMob(CVector2D(200, 200)));
		m_cnt = 0;
		//m_is_tuto = tuto;
	}

	if (GameData::s_score1 <= 0 || GameData::s_score <= 0) {
		SetKill();
	}

	//プレイヤー死亡　ボタン１でゲームシーン終了
	//if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		//m_kill = true;
	//}
}

Game4::~Game4()
{
	//全てのオブジェクトを破棄
	Base::KillAll();
	//リザルト画面へ
	Result::finish_game = 4;
	Base::Add(new Result(m_is_tuto));
}