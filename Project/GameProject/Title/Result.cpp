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
	//左クリックでタイトルへ
	if (PUSH(CInput::eMouseL)) {
		GameData::s_score = 300;
		GameData::s_score1 = 6000;
		//finish_game = 2;
		SetKill();
	};
	//スペースキーでRestart
	//if (PUSH(CInput::eButton5)) {
	//	GameData::s_score = 300;
	//	GameData::s_score1 = 5300;
	//	//finish_game = 0;
	//	SetKill();
	//};
}

void Result::Draw() {
	m_img.SetSize(1280, 720);
	//m_img.SetSize(1920, 1080);
	m_img.Draw();
	//m_result_text.Draw(100, 700, 255, 0, 0, "マウス左クリック：終了");
	if (GameData::s_score <= 0 && GameData::s_score1 > 0) {
		//m_result_text.Draw(780, 256, 255, 0, 0, "GameOver");
		m_img.Load("Image/GameOver.png");
		//m_img.SetSize(1280, 720);
	}
	if (GameData::s_score1 <= 0 && GameData::s_score > 0 && GameData::s_score < 300) {
		//m_result_text.Draw(780, 256, 0, 0, 255, "Clear");
		m_img.Load("Image/Clear.png");
	}
	if (GameData::s_score1 <= 0 && GameData::s_score == 300) {
		//m_result_text.Draw(780, 256, 255, 255, 0, "Perfect");
		m_img.Load("Image/Perfect.png");
	}
}