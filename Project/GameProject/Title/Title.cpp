#include "Title.h"
#include "../Game/Game.h"

Title::Title():Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_img = COPY_RESOURCE("Title",CImage);
}

Title::~Title()
{
	//�^�C�g���j�����ɃQ�[���V�[���ֈڍs
	Base::Add(new Game());
}

void Title::Update()
{
		//�{�^��5�Ń^�C�g���j��
		if (PUSH(CInput::eButton5)) {
			m_kill = true;
		}

		
	}

void Title::Draw()
{
	m_img.Draw();
	//�����\��
	
m_title_text.Draw(780, 256, 255, 255, 255, "�V���[�e�B���O");
m_title_text.Draw(800, 512, 255, 255, 255, "Push SPACE");
}
