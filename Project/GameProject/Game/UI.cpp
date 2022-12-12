#include "UI.h"
#include "GameData.h"
#include "Game.h"
#include "Game1.h"
#include "Game2.h"
#include "Game4.h"

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

	Game* g = dynamic_cast<Game*>(Base::FindObject(eType_Scene));
		if (g) {
			if (g->m_is_tuto) {
				m_text.Draw(0, 720 - (32 * 6), 255, 255, 255, "}EX¶&SPACE:U");
				if (GameData::s_score1 <= 300) {
					m_text.Draw(0, 720 - (32 * 7), 255, 0, 0, "uTHANK YOU FOR PLAYv");
				}
			}
		}

	Game1* h = dynamic_cast<Game1*>(Base::FindObject(eType_Scene));
	if (h) {
		if (h->m_is_tuto) {
			m_text.Draw(0, 720 - (32 * 5), 255, 255, 255, "A:¶Ú®");
			m_text.Draw(0, 720 - (32 * 4), 255, 255, 255, "D:EÚ®");
			m_text.Draw(0, 720 - (32 * 3), 255, 255, 255, "W:ãÚ®");
			m_text.Draw(0, 720 - (32 * 2), 255, 255, 255, "S:ºÚ®");
			m_text.Draw(0, 720 - (32 * 6), 255, 255, 255, "}EX¶&SPACE:U");
		}
	}

	Game2* i = dynamic_cast<Game2*>(Base::FindObject(eType_Scene));
	if (i) {
		if (i->m_is_tuto) {
			m_text.Draw(0, 720 - (32 * 5), 255, 255, 255, "A:¶Ú®");
			m_text.Draw(0, 720 - (32 * 4), 255, 255, 255, "D:EÚ®");
			m_text.Draw(0, 720 - (32 * 3), 255, 255, 255, "W:ãÚ®");
			m_text.Draw(0, 720 - (32 * 2), 255, 255, 255, "S:ºÚ®");
			m_text.Draw(0, 720 - (32 * 6), 255, 255, 255, "}EX¶&SPACE:U");
		}
	}
	Game4* j = dynamic_cast<Game4*>(Base::FindObject(eType_Scene));
	if (j) {
		if (j->m_is_tuto) {
			m_text.Draw(0, 720 - (32 * 6), 255, 255, 255, "}EX¶&SPACE:U");
			if (GameData::s_score1 <= 300) {
				m_text.Draw(0, 720 - (32 * 7), 255, 0, 0, "uTHANK YOU FOR PLAYv");
			}
		}
	}
}