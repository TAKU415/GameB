#pragma once
#include "../Base/Base.h"

class UI : public Base {
public:
	CImage m_img;
	CFont m_text;
public:
	UI();
	void Draw();
};