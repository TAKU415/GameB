#include "Title.h"
#include "../Game/Game.h"
#include "../Game/Game1.h"

Title::Title():Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_img = COPY_RESOURCE("Title",CImage);
	m_img.SetSize(1280,720);
}

Title::~Title()
{
	//タイトル破棄時にゲームシーンへ移行
	//Base::Add(new Game());
}

void Title::Update()
{
	if (title_flag) {
		//ボタン5(SPACE)でタイトル破棄
		if (PUSH(CInput::eButton5)) {
			//m_kill = true;
			SetKill();
			Base::KillAll();
			Base::Add(new Game());
		}

		//ボタン5(SPACE)でタイトル破棄
		//if (PUSH(CInput::eButton1)) {
		//	//m_kill = true;
		//	SetKill();
		//	Base::KillAll();
		//	Base::Add(new Game1(true));
		//}
	}

}

void Title::Draw()
{
	m_img.Draw();
	//文字表示
	
m_title_text.Draw(780, 256, 255, 255, 255, "シューティング");
m_title_text.Draw(800, 512, 255, 255, 255, "Push SPACE");
}
