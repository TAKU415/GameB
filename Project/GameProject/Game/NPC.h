#pragma once
#include "../Base/Base.h"

class NPC : public Base {
private:
	int m_state;
	int m_cnt;
	float m_ang;
	CImage m_img;

public:
	NPC(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};