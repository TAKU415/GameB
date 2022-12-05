#pragma once

#include "../Base/Base.h"

class Game2 : public Base {
public:
	int m_cnt;
	CFont m_result_text;
public:
	Game2(bool tuto);
	~Game2();
	void Update();
	bool m_is_tuto;
};