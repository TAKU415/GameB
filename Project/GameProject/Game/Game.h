#pragma once

#include "../Base/Base.h"

class Game : public Base {
public:
	int m_cnt;
public:
	Game();
	~Game();
	void Update();
};