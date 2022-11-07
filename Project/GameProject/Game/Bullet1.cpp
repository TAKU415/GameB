#include "Bullet1.h"
#include "Effect.h"
#include "Gamedata.h"

Bullet1::Bullet1(int Type, const CVector2D& pos, float ang, float speed)
	: Base(Type)
{
	if (Type == eType_Player_Attack) {
		m_img = COPY_RESOURCE("Bullet", CImage);
	}
	else if(Type == eType_EnemyBoss_Attack) {
		m_img = COPY_RESOURCE("Bullet2", CImage);
	}
	else if (Type == eType_NPC_Attack) {
		m_img = COPY_RESOURCE("Bullet3", CImage);
	}
	else {
		m_img = COPY_RESOURCE("Bullet2", CImage);
	}
	m_pos = pos;
	m_ang = ang;
	m_speed = speed;
	//�摜�̒��S�ɐݒ�
	m_img.SetCenter(16, 16);
}




void Bullet1::Update() {
	//�e�̑���
		m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
		m_pos += m_vec;
	if (m_pos.y > 720 || m_pos.y < 0 || m_pos.x < 0 || m_pos.x > 1280) {
		SetKill();
	}
}

void Bullet1::Draw() {
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
}

void Bullet1::Collision(Base* b) {

	//�Ώۂ̃I�u�W�F�N�g�̎�ނɂ���ĕ���
	switch (b->m_type) {

	case eType_Player:

		//�~���m�̔���i�����A�Ώۂ��j
		if (m_type == eType_EnemyBoss_Attack && Base::CollisionCircle(this, b)) {
			SOUND("SE_Bomb")->Play();
			SetKill();
			Base::Add(new Effect(b->m_pos));
			GameData::s_score -= 100;
		}

		if (m_type == eType_Enemy_Attack && Base::CollisionCircle(this, b)) {
			SOUND("SE_Bomb")->Play();
			SetKill();
			Base::Add(new Effect(b->m_pos));
			GameData::s_score -= 5;
		}

		if (m_type == eType_NPC_Attack && Base::CollisionCircle(this, b)) {
			//SOUND("SE_Bomb")->Play();
			SetKill();
			//Base::Add(new Effect(b->m_pos));
			GameData::s_score += 100;
		}

		break;

	case eType_EnemyBoss:

		//�~���m�̔���i�����A�Ώۂ��j
		if (m_type == eType_Player_Attack && Base::CollisionCircle(this, b)) {
			SOUND("SE_Bomb")->Play();
			//b->SetKill();
			SetKill();
			Base::Add(new Effect(b->m_pos));
			GameData::s_score1 -= 100;
		}
		break;

	case eType_EnemyMob:

		//�~���m�̔���i�����A�Ώۂ��j
		if (m_type == eType_Player_Attack && Base::CollisionCircle(this, b)) {
			SOUND("SE_Bomb")->Play();
			b->SetKill();
			SetKill();
			Base::Add(new Effect(b->m_pos));
			//GameData::s_score1 -= 50;
		}
		break;
		
	}

}