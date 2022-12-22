#include "Title.h"
#include "../Game/Game.h"
#include "../Game/Game1.h"
#include "../Game/Game2.h"
#include "../Game/Game4.h"

Title::Title():Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_img = COPY_RESOURCE("Title",CImage);
	//表示サイズ
	m_img.SetSize(1280,720);
	title_flag = false;
}

Title::~Title()
{
	//タイトル破棄時にゲームシーンへ移行
	//Base::Add(new Game());
}

void Title::Update()
{
	if (title_flag) {
		//ボタン2(C)でタイトル破棄～ゲームシーンへ
		if (PUSH(CInput::eButton3)) {
			SetKill();
			Base::KillAll();
			Base::Add(new Game(true));
		}
		//ボタン1(Z)でタイトル破棄～ゲームシーンへ
		if (PUSH(CInput::eButton1)) {
			SetKill();
			Base::KillAll();
			Base::Add(new Game1(true));
		}
		//ボタン3(X)でタイトル破棄～ゲームシーンへ
		if (PUSH(CInput::eButton2)) {
			SetKill();
			Base::KillAll();
			Base::Add(new Game2(true));
		}
		//ボタン4(V)でタイトル破棄～ゲームシーンへ
		if (PUSH(CInput::eButton4)) {
			SetKill();
			Base::KillAll();
			Base::Add(new Game4(true));
		}
	}
	else {
		title_flag = true;
	}

}

void Title::Draw()
{
	//召喚
	m_img.Draw();
	//文字表示
	m_title_text.Draw(780, 256, 255, 0, 0, "BARRAGE GAME(仮)");
}
