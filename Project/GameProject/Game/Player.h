#pragma once
#include "../Base/Base.h"
class Player : public Base {
private:
	CImage m_img;
	int m_cnt;
	int m_cnt1;
	float m_ang;
	//float m_pos_old;

public:
	Player(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};
