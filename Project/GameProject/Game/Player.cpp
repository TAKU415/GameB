#include "Player.h"
#include "Bullet1.h"

Player::Player(const CVector2D& pos) : Base(eType_Player) {
	m_img.Load("Image/Player.png");
	m_pos = pos;
	//半径設定
	m_rad = 12;
	//表示サイズ
	m_img.SetSize(32, 32);
	//画像の中心に設定
	m_img.SetCenter(16, 16);
}

void Player::Update() {
	m_cnt++;
	//速度
	const int move_speed = 4;
	//右
	if (HOLD(CInput::eRight))
		m_pos.x += move_speed;
	//左
	if (HOLD(CInput::eLeft))
		m_pos.x -= move_speed;
	//上
	if (HOLD(CInput::eUp))
		m_pos.y -= move_speed;
	//下
	if (HOLD(CInput::eDown))
		m_pos.y += move_speed;
	
	//マウスのベクトル
	CVector2D vec = CInput::GetMousePoint() - m_pos;
	//回転値を逆算
	m_ang = atan2(vec.x, vec.y);
	
	//弾
	if (HOLD(CInput::eMouseL)) {
		if (m_cnt >= 30) {
			//SOUND("SE_Hit01")->Play();
			Base::Add(new Bullet1(eType_Player_Attack, m_pos, m_ang, 4));
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