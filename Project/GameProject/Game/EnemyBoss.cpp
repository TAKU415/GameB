#include "EnemyBoss.h"
#include "Bullet1.h"

EnemyBoss::EnemyBoss(const CVector2D& pos) : Base(eType_EnemyBoss) {
	m_img.Load("Image/EnemyBoss.png");
	m_pos = pos;
	//���a�ݒ�
	m_rad = 23;
	//�\���T�C�Y
	m_img.SetSize(32, 41);
	//�摜�̒��S�ɐݒ�
	m_img.SetCenter(16, 20);
}

void EnemyBoss::Update() {
	m_cnt++;

	//���x
	const int move_speed = 2;
	//�E
	if (m_pos.x > 200 && HOLD(CInput::eLeft))
		m_pos.x += move_speed;
	//��
	if (m_pos.x < 1080 && HOLD(CInput::eRight))
		m_pos.x -= move_speed;
	
	//�e
	if (m_cnt >= 30) {
		//SOUND("SE_Hit01")->Play();
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(55), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(45), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(10), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(0), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-10), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-45), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-55), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(80), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(120), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(180), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-120), 4));
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
