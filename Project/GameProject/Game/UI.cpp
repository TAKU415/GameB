#include "UI.h"
#include "GameData.h"
#include "Game.h"

UI::UI() :Base(eType_UI) {
	m_img = COPY_RESOURCE("UI", CImage);
}

void UI::Draw() {
	int score = GameData::s_score;
	for (int i = 0; i < 5; i++, score /= 10) {
		int s = score % 10;
		m_img.SetRect(16 * s, 16, 16 * s + 16, 32);
		m_img.SetSize(24, 24);
		m_img.SetPos(120 - 24 * i, 0);
		m_img.Draw();
	}

	int score1 = GameData::s_score1;
	for (int i = 0; i < 5; i++, score1 /= 10) {
		int s = score1 % 10;
		m_img.SetRect(16 * s, 16, 16 * s + 16, 32);
		m_img.SetSize(24, 24);
		m_img.SetPos(500 - 24 * i, 0);
		m_img.Draw();
	}

}