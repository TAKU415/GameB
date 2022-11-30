#include "Game.h"
#include "Bullet1.h"
#include "Player.h"
#include "EnemyBoss.h"
#include "EnemyMob.h"
#include "kuma.h"
#include "Effect.h"
#include "GameData.h"
#include "Field.h"
#include "UI.h"
#include "../Title/Result.h"

Game::Game(bool tuto) :Base(eType_Scene)
{
	m_cnt = 0;
	Base::Add(new Field());
	Base::Add(new Player(CVector2D(640,600)));
	Base::Add(new EnemyBoss(CVector2D(640, 100)));
	Base::Add(new kuma(CVector2D(240, 130)));
	Base::Add(new kuma(CVector2D(640, 80)));
	Base::Add(new kuma(CVector2D(1040, 130)));
	Base::Add(new UI());
	m_is_tuto = tuto;
}

void Game::Update()
{
	//カウント
	m_cnt++;
	if (m_cnt >= 300) {
		Base::Add(new EnemyMob(CVector2D(1000, 200)));
		//Base::Add(new EnemyMob(CVector2D(640, 200)));
		Base::Add(new EnemyMob(CVector2D(200, 200)));
		m_cnt = 0;
		//m_is_tuto = tuto;

		//if (GameData::s_score <= 1800) {
		//	Base::Add(new NPC(CVector2D(1180, 620)));
		//}

	}

	/*if (GameData::s_score >= 500) {
		m_result_text.Draw(780, 256, 255, 255, 255, "Gameover");
	}*/
	
	if (GameData::s_score1 <= 300 || GameData::s_score <= 0) {
		SetKill();
	}

	//プレイヤー死亡　ボタン１でゲームシーン終了
	//if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		//m_kill = true;
	//}
}

Game::~Game()
{
	//GameData::s_score = 300;
	//GameData::s_score1 = 5300;
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーンへ
	//Base::Add(new Title());
	//リザルト画面へ
	Result::finish_game = 2;
	Base::Add(new Result(m_is_tuto));
}