#include "Title.h"
#include "../Game/Game.h"
#include "../Game/Game1.h"
#include "../Game/Game2.h"
#include "../Game/Game4.h"

Title::Title():Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_img = COPY_RESOURCE("Title",CImage);
	//�\���T�C�Y
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
		//�{�^��2(C)�Ń^�C�g���j���`�Q�[���V�[����
		if (PUSH(CInput::eButton3)) {
			SetKill();
			Base::KillAll();
			Base::Add(new Game(true));
		}
		//�{�^��1(Z)�Ń^�C�g���j���`�Q�[���V�[����
		if (PUSH(CInput::eButton1)) {
			SetKill();
			Base::KillAll();
			Base::Add(new Game1(true));
		}
		//�{�^��3(X)�Ń^�C�g���j���`�Q�[���V�[����
		if (PUSH(CInput::eButton2)) {
			SetKill();
			Base::KillAll();
			Base::Add(new Game2(true));
		}
		//�{�^��4(V)�Ń^�C�g���j���`�Q�[���V�[����
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
	//����
	m_img.Draw();
	//�����\��
	m_title_text.Draw(780, 256, 255, 0, 0, "BARRAGE GAME(��)");
}
