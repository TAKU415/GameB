#pragma once
#include "../Base/Base.h"
class Bullet1 : public Base {
public:
	CImage m_img;
	float m_speed;
	float m_ang;
	//int m_cnt;
	int Type;
public:
	Bullet1(int type, const CVector2D& pos, float ang, float speed);
	void Update();
	void Draw();
	void Collision(Base* b);

};