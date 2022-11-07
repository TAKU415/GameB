#include "Title.h"
#include "../Game/Game.h"

Title::Title():Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_img = COPY_RESOURCE("Title",CImage);
}

Title::~Title()
{
	//^CgjόΙQ[V[ΦΪs
	Base::Add(new Game());
}

void Title::Update()
{
		//{^5Ε^Cgjό
		if (PUSH(CInput::eButton5)) {
			m_kill = true;
		}

		
	}

void Title::Draw()
{
	m_img.Draw();
	//Ά\¦
	
m_title_text.Draw(780, 256, 255, 255, 255, "V[eBO");
m_title_text.Draw(800, 512, 255, 255, 255, "Push SPACE");
m_title_text.Draw(0, 656, 255, 255, 255, "Β:GU");
m_title_text.Draw(0, 606, 255, 255, 255, "Τ:PlayerU");
m_title_text.Draw(0, 556, 255, 255, 255, "");
}
