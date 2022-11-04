#pragma once
#include "../Base/Base.h"

class EnemyBoss : public Base {
private:
	int m_state;
	int m_cnt;
	float m_ang;
	CImage m_img;
	//ƒ_ƒ[ƒW”Ô†
	//int m_damage_no;
	//int m_hp=100;

public:
	EnemyBoss(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};
