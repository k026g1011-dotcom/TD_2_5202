#include "CreditsMenu.h"
#include "Game.h"
#include <Novice.h>
CreditsMenu::CreditsMenu() :GameMenu()
{

}
CreditsMenu::CreditsMenu(Game* game) :GameMenu(game)
{
    m_nextButton = ClickableComponent(ButtonType::StartButton, Vector2Int(900, 500), 256, 128, Novice::LoadTexture("./resources/images/Ui/BackButton.png"));
    SetBackGroundGh(Novice::LoadTexture("./resources/images/Ui/Credits.png"));
    
}
void CreditsMenu::ClickReceived()
{
    if (GetSelectedButton() != nullptr)
    {
        switch (GetSelectedButton()->GetId())
        {
        case ButtonType::StartButton:
            //GetGame()->GetAudioPlayer()->Play(Music::StartButton);
            //GetGame()->GetUi()->ShowLevelSelectMenu();
            GetGame()->GetUi()->CloseCurrentMenu();
            GetGame()->GetUi()->ShowTitleMenu();
            break;
        }
    }
   
}
void CreditsMenu::HoveredByMouse(Vector2Int mousePos)
{
    if (m_nextButton.IsIntersect(mousePos))
    {
        SetSelectedButton(&m_nextButton);
        m_nextButton.SetSelected(true);
    }
    else
    {
        SetSelectedButton(nullptr);
        m_nextButton.SetSelected(false);
    }
}
void CreditsMenu::Update()
{
    GameMenu::Update();
    /*    int mouseX;
        int mouseY;
        Novice::GetMousePosition(&mouseX, &mouseY);
        HoveredByMouse(Vector2Int(mouseX, mouseY));*/
}
void CreditsMenu::Draw()
{
    Novice::ConsolePrintf("DRAWING TitleMenu");

    GameMenu::Draw();
    /*    Novice::DrawQuad(
            128, 128,
            1151, 128,
            128, 255,
            1151, 255,
            0, 0,
            1024, 128,
            m_titleGh, WHITE);*/
            //m_startButton.Draw();
}
void CreditsMenu::RegisterComponents()
{
    GameMenu::RegisterComponents();
    RegisterClickableComponent(&m_nextButton);
    SetSelectedButton(&m_nextButton);
}