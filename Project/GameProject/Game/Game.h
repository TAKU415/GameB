#pragma once

#include "../Base/Base.h"

class Game : public Base {
public:
	int m_cnt;
	CFont m_result_text;
public:
	Game();
	~Game();
	void Update();
	//bool m_is_tuto;
};