#pragma once

#include "../Base/Base.h"

class Game4 : public Base {
public:
	//CImage m_img;
	int m_cnt;
	CFont m_result_text;
public:
	Game4(bool tuto);
	~Game4();
	void Update();
	bool m_is_tuto;
};