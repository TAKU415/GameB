#include "kuma.h"
#include "Bullet1.h"

kuma::kuma(const CVector2D& pos) : Base(eType_kuma) {
	m_img.Load("Image/EBoss2.png");
	m_pos = pos;
	//���a�ݒ�
	m_rad = 16;
	//�\���T�C�Y
	m_img.SetSize(44, 64);
	//�摜�̒��S�ɐݒ�
	m_img.SetCenter(22, 32);
}

void kuma::Update() {
	m_cnt++;
	//if (m_cnt >= 60) {
	//	m_pos.y += 50;
	//	m_cnt = 0;
	//}
	//if (m_pos.y > 720) {
	//	SetKill();
	//}
	//�v���C���[���擾
	//Base* b = Base::FindObject(eType_Player);
	//�e�i�v���C���[������΁j
	//if (b) {
	//	CVector2D vec = b->m_pos - m_pos;
	//	m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 30) {
			//SOUND("SE_Hit01")->Play();
			Base::Add(new Bullet1(eType_kuma_Attack, m_pos, m_ang + DtoR(108), 4));
			Base::Add(new Bullet1(eType_kuma_Attack, m_pos, m_ang + DtoR(36), 4));
			Base::Add(new Bullet1(eType_kuma_Attack, m_pos, m_ang + DtoR(180), 4));
			Base::Add(new Bullet1(eType_kuma_Attack, m_pos, m_ang + DtoR(-36), 4));
			Base::Add(new Bullet1(eType_kuma_Attack, m_pos, m_ang + DtoR(-108), 4));
			m_cnt = 0;
		}
}


void kuma::Draw() {
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
}

void kuma::Collision(Base* b)
{
}