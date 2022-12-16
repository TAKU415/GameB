#include "Player.h"
#include "Bullet1.h"
#include "GameData.h"

Player::Player(const CVector2D& pos) : Base(eType_Player) {
	m_img.Load("Image/Player.png");
	
	m_pos = pos;
	//半径設定
	m_rad = 3;
	//表示サイズ
	m_img.SetSize(40, 70);
	//画像の中心に設定
	m_img.SetCenter(20, 35);
}

void Player::Update() {
	//m_pos_old = m_pos;
	m_cnt++;
	m_cnt1++;
	//速度
	const int move_speed = 4;
	//右
	if (HOLD(CInput::eRight) && m_pos.x <= 1280 - 20)
		m_pos.x += move_speed;
	//左
	if (HOLD(CInput::eLeft)&& m_pos.x >= 0 + 20)
		m_pos.x -= move_speed;
	//上
	if (HOLD(CInput::eUp)&& m_pos.y >= 0 + 35)
		m_pos.y -= move_speed;
	//下
	if (HOLD(CInput::eDown) && m_pos.y <= 720 - 35)
		m_pos.y += move_speed;

	//マウスのベクトル
	CVector2D vec = CInput::GetMousePoint() - m_pos;
	//回転値を逆算
	m_ang = atan2(vec.x, vec.y);

	//弾
	if (HOLD(CInput::eMouseL)) {
		if (m_cnt1 >= 120) {
			//SOUND("SE_Hit01")->Play();
			//if (m_pos.y > +100 || m_pos.y < 0 || m_pos.x < 0 || m_pos.x > +100) {
			Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(12), 4));
			Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(9), 4));
			Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(6), 4));
			Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(3), 4));
			Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(0), 4));
			Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(-3), 4));
			Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(-6), 4));
			Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(-9), 4));
			Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(-12), 4));
			//	SetKill();
			//}
			m_cnt1 = 0;
		}
	}

	//Bossを取得
	Base* b = Base::FindObject(eType_EnemyBoss);
	//弾（Bossがいれば）
	if (b) {
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (HOLD(CInput::eButton5)) {
			if (m_cnt >= 20) {
				//SOUND("SE_Hit01")->Play();
				//Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(20), 4));
				//if (GameData::s_score1 <= 3000) {
				//	Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(5), 4));
				//}
				Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(0), 4));
				//if (GameData::s_score1 <= 3000) {
				//	Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(-5), 4));
				//}
				//Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang + DtoR(-20), 4));
				m_cnt = 0;
			}
		}
	}
}

void Player::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void Player::Collision(Base* b) {
	if (Base::CollisionCircle(this, b)) {
		//m_pos = m_pos_old;
	}
}