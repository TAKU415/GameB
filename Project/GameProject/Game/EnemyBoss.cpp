#include "EnemyBoss.h"
#include "Bullet1.h"
#include "GameData.h"

EnemyBoss::EnemyBoss(const CVector2D& pos) : Base(eType_EnemyBoss) {
	m_img.Load("Image/Boss2.png");
	
	m_pos = pos;
	//半径設定
	m_rad = 25;
	//表示サイズ
	m_img.SetSize(74, 74);
	//画像の中心に設定
	m_img.SetCenter(37, 37);
}

void EnemyBoss::Update() {
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
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(180), 36));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(175), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(170), 35));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(165), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(160), 34));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(155), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(150), 33));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(145), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(140), 32));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(135), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(130), 31));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(125), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(120), 30));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(115), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(110), 29));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(105), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(100), 28));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(95), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(90), 27));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(85), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(80), 26));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(75), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(70), 25));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(65), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(60), 24));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(55), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(50), 23));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(45), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(40), 22));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(35), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(30), 21));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(25), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(20), 20));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(15), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(10), 19));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(5), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(0), 18));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-5), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-10), 17));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-15), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-20), 16));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-25), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-30), 15));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-35), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-40), 14));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-45), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-50), 13));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-55), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-60), 12));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-65), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-70), 11));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-75), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-80), 10));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-85), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-90), 9));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-95), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-100), 8));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-105), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-110), 7));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-115), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-120), 6));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-125), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-130), 5));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-135), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-140), 4));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-145), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-150), 3));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-155), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-160), 2));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-165), 4));
		Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-170), 1));
		//Base::Add(new Bullet1(eType_EnemyBoss_Attack, m_pos, m_ang + DtoR(-175), 4));

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
