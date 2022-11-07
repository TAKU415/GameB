#include "NPC.h"
#include "Bullet1.h"

NPC::NPC(const CVector2D& pos) : Base(eType_NPC) {
	m_img.Load("Image/Boss.png");
	m_pos = pos;
	//���a�ݒ�
	m_rad = 16;
	//�\���T�C�Y
	m_img.SetSize(32, 41);
	//�摜�̒��S�ɐݒ�
	m_img.SetCenter(16, 16);
}

void NPC::Update() {
	m_cnt++;
	//if (m_cnt >= 60) {
	//	m_pos.y += 50;
	//	m_cnt = 0;
	//}
	//if (m_pos.y > 720) {
	//	SetKill();
	//}
	//�v���C���[���擾
	Base* b = Base::FindObject(eType_Player);
	//�e�i�v���C���[������΁j
	if (b) {
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 60) {
			//SOUND("SE_Hit01")->Play();
			Base::Add(new Bullet1(eType_NPC_Attack, m_pos, m_ang, 4));
		}
	}
}

void NPC::Draw() {
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
}

void NPC::Collision(Base* b)
{
}