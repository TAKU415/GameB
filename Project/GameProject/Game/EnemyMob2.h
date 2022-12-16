#pragma once
#include "../Base/Base.h"

class EnemyMob2 : public Base {
private:
	int m_state;
	int m_cnt;
	float m_ang;
	CImage m_img;

public:
	EnemyMob2(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};