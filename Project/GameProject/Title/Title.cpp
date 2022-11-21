#include "Title.h"
#include "../Game/Game.h"
#include "../Game/Game1.h"

Title::Title():Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_img = COPY_RESOURCE("Title",CImage);
	m_img.SetSize(1280,720);
	title_flag = false;
}

Title::~Title()
{
	//�^�C�g���j�����ɃQ�[���V�[���ֈڍs
	//Base::Add(new Game());
}

void Title::Update()
{
	if (title_flag) {
		//�{�^��2(X)�Ń^�C�g���j��
		if (PUSH(CInput::eButton2)) {
			//m_kill = true;
			SetKill();
			Base::KillAll();
			Base::Add(new Game(true));
		}

		//�{�^��1(Z)�Ń^�C�g���j��
		if (PUSH(CInput::eButton1)) {
			//m_kill = true;
			SetKill();
			Base::KillAll();
			Base::Add(new Game1(true));
		}
	}
	else {
		title_flag = true;
	}

}

void Title::Draw()
{
	m_img.Draw();
	//�����\��
	
m_title_text.Draw(780, 256, 255, 0, 0, "Title(����)");
//m_title_text.Draw(650, 512, 255, 0, 0, "Push X Main(Hard)");
//m_title_text.Draw(650, 452, 255, 0, 0, "Push Z Tutorial");
}
