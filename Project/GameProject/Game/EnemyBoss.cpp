#include "EnemyBoss.h"
#include "Bullet1.h"
#include "GameData.h"

EnemyBoss::EnemyBoss(const CVector2D& pos) : Base(eType_EnemyBoss) {
	m_img.Load("Image/Boss.png");
	m_pos = pos;
	//���a�ݒ�
	m_rad = 23;
	//�\���T�C�Y
	m_img.SetSize(64, 64);
	//�摜�̒��S�ɐݒ�
	m_img.SetCenter(32, 32);
}

void EnemyBoss::Update() {
	m_cnt++;

	//���x
	const int move_speed = 4;
	//�E
	if (HOLD(CInput::eLeft) && m_pos.x <= 1280 - 32) {
		m_pos.x += move_speed;
	}
	//��
	if (HOLD(CInput::eRight) && m_pos.x >= 0 + 32) {
		m_pos.x -= move_speed;
	}
	//��
	//if (/*m_pos.y > 220 && */ HOLD(CInput::eDown))
	//	m_pos.y -= move_speed;
	//��
	//if (/*m_pos.y < 520 && */ HOLD(CInput::eUp))
	//	m_pos.y += move_speed;

	//�e
	if (m_cnt >= 30) {
		//SOUND("SE_Hit01")->Play();
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(65), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(55), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(45), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(30), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(20), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(10), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(0), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-10), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-20), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-30), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-45), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-55), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-65), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(80), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(100), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(120), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(140), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(160), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(180), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-160), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-140), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-120), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-100), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-80), 4));
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
