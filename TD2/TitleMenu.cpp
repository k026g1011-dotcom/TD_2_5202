#include "TitleMenu.h"
#include "Game.h"
#include <Novice.h>
TitleMenu::TitleMenu() :GameMenu()
{

}
TitleMenu::TitleMenu(Game* game)
    :GameMenu(game),
    m_startButton(ButtonType::StartButton, Vector2Int(480, 384), 320, 128, Novice::LoadTexture("./resources/images/Ui/StartButton.png")),
    m_creditsButton(ButtonType::CreditsButton, Vector2Int(480, 510), 320, 128, Novice::LoadTexture("./resources/images/Ui/CreditsButton.png"))
{
    //m_startButton = ClickableComponent(ButtonType::StartButton, Vector2Int(480, 384), 320, 128, Novice::LoadTexture("./resources/images/Ui/StartButton.png"));
    //m_creditsButton = ClickableComponent(ButtonType::CreditsButton, Vector2Int(480, 510), 320, 128, Novice::LoadTexture("./resources/images/Ui/CreditsButton.png"));
    m_startButton.SetDownNeighbor(&m_creditsButton);
    m_startButton.SetUpNeighbor(&m_creditsButton);
    m_creditsButton.SetDownNeighbor(&m_startButton);
    m_creditsButton.SetUpNeighbor(&m_startButton);
    Novice::ConsolePrintf("TitleMenu INIT");
    m_titleGh = Novice::LoadTexture("./resources/images/Ui/Title.png");
    SetBackGroundGh(Novice::LoadTexture("./resources/images/Ui/StartGameBG.png"));
    
}
void TitleMenu::ResetSelectedButton()
{
    SetSelectedButton(&m_startButton);
}
void TitleMenu::ToUpNeighbor()
{
    GameMenu::ToUpNeighbor();
}
void TitleMenu::ToDownNeighbor()
{
    GameMenu::ToDownNeighbor();
}
void TitleMenu::ToLeftNeighbor()
{
    GameMenu::ToLeftNeighbor();
}
void TitleMenu::ToRightNeighbor()
{
    GameMenu::ToRightNeighbor();
}
void TitleMenu::ClickReceived()
{
    GameMenu::ClickReceived();
    if (GetSelectedButton() != nullptr)
    {
        switch (GetSelectedButton()->GetId())
        {
        case ButtonType::StartButton:
            //GetGame()->GetAudioPlayer()->Play(Music::StartButton);
            //GetGame()->GetUi()->ShowLevelSelectMenu();
            GetGame()->GetUi()->CloseCurrentMenu();
            GetGame()->RunStage(1);
            break;
        case ButtonType::CreditsButton:
            //
            GetGame()->GetUi()->CloseCurrentMenu();
            GetGame()->GetUi()->ShowCreditsMenu();
            break;
        }
    }



}
void TitleMenu::HoveredByMouse(Vector2Int mousePos)
{
    if (m_startButton.IsIntersect(mousePos))
    {
        SetSelectedButton(&m_startButton);
        m_startButton.SetSelected(true);
    }
    else
    {
        SetSelectedButton(nullptr);
        m_startButton.SetSelected(false);
    }
}
void TitleMenu::Update()
{
    GameMenu::Update();
    /*    int mouseX;
        int mouseY;
        Novice::GetMousePosition(&mouseX, &mouseY);
        HoveredByMouse(Vector2Int(mouseX, mouseY));*/
}
void TitleMenu::Draw()
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
    Novice::DrawQuad(
        256, 128,
        1023, 128,
        256, 255,
        1023, 255,
        0, 0,
        768, 128,
        m_titleGh, WHITE);
    //m_startButton.Draw();
}
void TitleMenu::RegisterComponents()
{
    GameMenu::RegisterComponents();
    RegisterClickableComponent(&m_startButton);
    RegisterClickableComponent(&m_creditsButton);
}