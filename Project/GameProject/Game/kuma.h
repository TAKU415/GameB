#pragma once
#include "../Base/Base.h"

class kuma : public Base {
private:
	int m_state;
	int m_cnt;
	float m_ang;
	CImage m_img;

public:
	kuma(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};