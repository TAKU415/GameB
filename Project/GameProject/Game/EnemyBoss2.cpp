#include "EnemyBoss2.h"
#include "Bullet1.h"
#include "GameData.h"

EnemyBoss2::EnemyBoss2(const CVector2D& pos) : Base(eType_EnemyBoss) {
	m_img.Load("Image/Boss.png");

	m_pos = pos;
	//半径設定
	m_rad = 23;
	//表示サイズ
	//m_img.SetSize(64, 64);
	m_img.SetSize(94, 94);
	//画像の中心に設定
	//m_img.SetCenter(32, 32);
	m_img.SetCenter(47, 47);
}

void EnemyBoss2::Update() {
	m_cnt++;

	//速度
	const int move_speed = 4;
	//右
	if (HOLD(CInput::eLeft) && m_pos.x <= 1280 - 32) {
		m_pos.x += move_speed;
	}
	//左
	if (HOLD(CInput::eRight) && m_pos.x >= 0 + 32) {
		m_pos.x -= move_speed;
	}
	//上
	//if (/*m_pos.y > 220 && */ HOLD(CInput::eDown))
	//	m_pos.y -= move_speed;
	//下
	//if (/*m_pos.y < 520 && */ HOLD(CInput::eUp))
	//	m_pos.y += move_speed;

	//弾
	if (m_cnt >= 30) {
		//SOUND("SE_Hit01")->Play();
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(180), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(170), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(160), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(150), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(140), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(130), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(120), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(110), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(100), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(90), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(80), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(70), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(60), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(50), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(40), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(30), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(20), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(10), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(0), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-10), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-20), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-30), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-40), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-50), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-60), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-70), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-80), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-90), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-100), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-110), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-120), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-130), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-140), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-150), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-160), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack2, m_pos, m_ang + DtoR(-170), 4));

		m_cnt = 0;
	}
}

void EnemyBoss2::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}

void EnemyBoss2::Collision(Base* b)
{
}
