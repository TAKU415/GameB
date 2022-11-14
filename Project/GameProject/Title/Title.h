#pragma once

#include "../Base/Base.h"

class Title : public Base {
private:
	//画像オブジェクト
	CImage m_img;

	//文字表示オブジェクト
	CFont m_title_text;

	bool title_flag;

public:
	Title();
	~Title();
	void Update();
	void Draw();
};