#include "EnemyMob.h"
#include "Bullet1.h"

EnemyMob::EnemyMob(const CVector2D& pos) : Base(eType_EnemyMob) {
	m_img.Load("Image/kuma.png");
	m_pos = pos;
	//半径設定
	m_rad = 16;
	//表示サイズ
	m_img.SetSize(64, 64);
	//画像の中心に設定
	m_img.SetCenter(32, 32);
}

void EnemyMob::Update() {
	m_cnt++;
	if (m_cnt >= 60) {
		m_pos.y += 50;
		m_cnt = 0;
	}
	if (m_pos.x > 720) {
		SetKill();
	}
	
	//プレイヤーを取得
	Base* b = Base::FindObject(eType_Player);
	//弾（プレイヤーがいれば）
	if(b){
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 59) {
			//SOUND("SE_Hit01")->Play();
			Base::Add(new Bullet1(eType_Enemy_Attack, m_pos, m_ang, 2));
			//Base::Add(new Bullet1(eType_Enemy_Attack, m_pos, m_ang, 4));
		}
	}
}

void EnemyMob::Draw() {
	m_img.SetPos(m_pos);
	//m_img.SetAng(m_ang);
	m_img.Draw();
}

void EnemyMob::Collision(Base* b)
{
}
