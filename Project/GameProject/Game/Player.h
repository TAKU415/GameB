#pragma once
#include "../Base/Base.h"

class Player : public Base {
private:
	CImage m_img;
	//int m_hp;
	int m_cnt;
	float m_ang;

public:
	Player(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};
