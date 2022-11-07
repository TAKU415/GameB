#include "Player.h"
#include "Bullet1.h"
#include "GameData.h"

Player::Player(const CVector2D& pos) : Base(eType_Player) {
	m_img.Load("Image/Player.png");
	m_pos = pos;
	//���a�ݒ�
	m_rad = 12;
	//�\���T�C�Y
	m_img.SetSize(32, 50);
	//�摜�̒��S�ɐݒ�
	m_img.SetCenter(16, 25);
}

void Player::Update() {
	m_cnt++;
	//���x
	const int move_speed = 4;
	//�E
	if (HOLD(CInput::eRight))
		m_pos.x += move_speed;
	//��
	if (HOLD(CInput::eLeft))
		m_pos.x -= move_speed;
	//��
	if (HOLD(CInput::eUp))
		m_pos.y -= move_speed;
	//��
	if (HOLD(CInput::eDown))
		m_pos.y += move_speed;
	
	//�}�E�X�̃x�N�g��
	CVector2D vec = CInput::GetMousePoint() - m_pos;
	//��]�l���t�Z
	m_ang = atan2(vec.x, vec.y);
	
	//�e
	if (HOLD(CInput::eMouseL) && GameData::s_score <= 100) {
		if (m_cnt >= 4) {
			//SOUND("SE_Hit01")->Play();
			Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang, 4));
			m_cnt = 0;
		}
	}

	//Boss���擾
	Base* b = Base::FindObject(eType_EnemyBoss);
	//�e�iBoss������΁j
	if (b) {
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 40) {
			//SOUND("SE_Hit01")->Play();
			Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(40), 4));
			Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(-20), 4));
			Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(0), 4));
			Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(-20), 4));
			Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(-40), 4));
			m_cnt = 0;
		}
	}

}

void Player::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Player::Collision(Base* b) {
	/*if (Base::CollisionCircle(this, b)) {
		m_pos = m_pos_old;
	}*/
}