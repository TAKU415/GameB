#include "Game.h"
#include "Bullet1.h"
#include "Player.h"
#include "EnemyBoss.h"
#include "EnemyMob.h"
#include "Effect.h"
#include "GameData.h"
#include "UI.h"
#include "../Title/Title.h"

Game::Game() :Base(eType_Scene)
{
	m_cnt = 0;
	Base::Add(new Player(CVector2D(640,600)));
	Base::Add(new EnemyBoss(CVector2D(640, 100)));
	Base::Add(new UI());
}

void Game::Update()
{
	//�J�E���g
	m_cnt++;
	if (m_cnt >= 180) {
		Base::Add(new EnemyMob(CVector2D(1000, 200)));
		Base::Add(new EnemyMob(CVector2D(640, 200)));
		Base::Add(new EnemyMob(CVector2D(200, 200)));
		m_cnt = 0;
	}

	if (GameData::s_score >= 5000 || GameData::s_score <= 0) {
		SetKill();
	}

	//�v���C���[���S�@�{�^���P�ŃQ�[���V�[���I��
	//if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		//m_kill = true;
	//}
}

Game::~Game()
{
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	//�^�C�g���V�[����
	Base::Add(new Title());
}