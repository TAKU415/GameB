#pragma once

#include "../Base/Base.h"

class Game1 : public Base {
public:
	int m_cnt;
	CFont m_result_text;
public:
	Game1();
	~Game1();
	void Update();
};