#include "Result.h"
#include "Title.h"
#include "../Game/GameData.h"

Result::Result(bool tuto) :Base(eType_Scene), m_result_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	m_img = COPY_RESOURCE("Result", CImage);
	m_is_tuto = tuto;
}

int Result::finish_game = 0;

Result::~Result() {
	if (m_is_tuto/* || finish_game == 2 */ ) {
		Base::Add(new Title());
	}
}

void Result::Update() {
	//SPACE�Ń^�C�g����
	if (PUSH(CInput::eMouseL)) {
		GameData::s_score = 300;
		GameData::s_score1 = 6000;
		//finish_game = 2;
		SetKill();
	}
}

void Result::Draw() {
	//�\���T�C�Y
	m_img.SetSize(1280, 720);
	//����
	m_img.Draw();
	//����1�@GameOver
	if (GameData::s_score <= 0 && GameData::s_score1 > 0) {
		m_img.Load("Image/GameOver.png");
	}
	//����2�@Clear
	if (GameData::s_score1 <= 0 && GameData::s_score > 0 && GameData::s_score < 300) {
		m_img.Load("Image/Clear.png");
	}
	//����3�@Perfect
	if (GameData::s_score1 <= 0 && GameData::s_score == 300) {
		m_img.Load("Image/Perfect.png");
	}
}