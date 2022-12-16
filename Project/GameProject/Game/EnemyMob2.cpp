#include "EnemyMob2.h"
#include "Bullet1.h"

EnemyMob2::EnemyMob2(const CVector2D& pos) : Base(eType_EnemyMob2) {
	//m_img.Load("Image/EnemyMob.png");
	m_pos = pos;
	//���a�ݒ�
	m_rad = 16;
	//�\���T�C�Y
	m_img.SetSize(44, 44);
	//�摜�̒��S�ɐݒ�
	m_img.SetCenter(22, 22);
}

void EnemyMob2::Update() {
	m_cnt++;
	if (m_cnt >= 60) {
	//	m_pos.y += 50;
		m_cnt = 0;
	}
	//if (m_pos.y > 720) {
	//	SetKill();
	//}

	//Boss���擾
	//Base* b = Base::FindObject(eType_EnemyBoss);
	//�e�i�v���C���[������΁j
	//if (b) {
	//	CVector2D vec = b->m_pos - m_pos;
	//	m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 59) {
			//SOUND("SE_Hit01")->Play();
			Base::Add(new Bullet1(eType_Enemy_Attack2, m_pos, m_ang, 4));
			//Base::Add(new Bullet1(eType_Enemy_Attack2, m_pos, m_ang+DtoR(30), 4));
		}
	//}
}

void EnemyMob2::Draw() {
	//m_img.SetPos(m_pos);
	//m_img.SetAng(m_ang);
	//m_img.Draw();
}

void EnemyMob2::Collision(Base* b)
{
}