#pragma once

#include "../Base/Base.h"

class Title : public Base {
private:
	//�摜�I�u�W�F�N�g
	CImage m_img;

	//�����\���I�u�W�F�N�g
	CFont m_title_text;

	bool title_flag;

public:
	Title();
	~Title();
	void Update();
	void Draw();
};