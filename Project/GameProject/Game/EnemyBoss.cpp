#include "EnemyBoss.h"
#include "Bullet1.h"

EnemyBoss::EnemyBoss(const CVector2D& pos) : Base(eType_EnemyBoss) {
	m_img.Load("Image/Enemy.png");
	m_pos = pos;
	//半径設定
	m_rad = 16;
	//表示サイズ
	m_img.SetSize(32, 32);
	//画像の中心に設定
	m_img.SetCenter(16, 16);
}

void EnemyBoss::Update() {
	m_cnt++;
	//速度
	const int move_speed = 50;
	//右
	if (m_pos.x <= 200)
		m_pos.x += move_speed;
	//左
	if (m_pos.x >= 1080)
		m_pos.x -= move_speed;
	
	//弾
	if (m_cnt >= 30) {
		//SOUND("SE_Hit01")->Play();
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(55), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(45), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(10), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(0), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-10), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-45), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-55), 4));
		m_cnt = 0;
	}
}

void EnemyBoss::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void EnemyBoss::Collision(Base* b)
{
}
