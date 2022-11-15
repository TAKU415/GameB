#pragma once

#include "../Base/Base.h"

class Game1 : public Base {
public:
	int m_cnt;
	CFont m_result_text;
public:
	Game1(bool tuto);
	~Game1();
	void Update();
	bool m_is_tuto;
};