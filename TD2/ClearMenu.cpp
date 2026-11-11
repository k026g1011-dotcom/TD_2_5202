#include "ClearMenu.h"
#include "Game.h"
ClearMenu::ClearMenu() :GameMenu()
{

}
ClearMenu::ClearMenu(Game* game) :GameMenu(game)
{
    m_timer = 0;
    m_currentFrame = 0;
    m_noiseGh = Novice::LoadTexture("./resources/images/Ui/Noise.png");
    m_titleButton = ClickableComponent(ButtonType::BackButton, Vector2Int(512, 384), 256, 128, Novice::LoadTexture("./resources/images/Ui/NextButton.png"));
    //Novice::ConsolePrintf("LevelSelectMenu INIT");
    m_stageGh = Novice::LoadTexture("./resources/images/Ui/Clear.png");
    SetBackGroundGh(Novice::LoadTexture("./resources/images/Ui/StartGameBG.png"));
    
}
void ClearMenu::ClickReceived()
{
    if (GetSelectedButton() == nullptr)
    {
        return;

    }
    switch (GetSelectedButton()->GetId())
    {
    case ButtonType::BackButton:
        GetGame()->GetAudioPlayer()->Play(Music::Button);
        GetGame()->OnNextStage();
        GetGame()->GetUi()->CloseCurrentMenu();
        break;
    }


}
void ClearMenu::Update()
{
    GameMenu::Update();
    m_timer++;
    if (m_timer > 15)
    {
        m_timer = 0;
        m_currentFrame = (m_currentFrame + 1) % 4;
    }
}
void ClearMenu::Draw()
{

    GameMenu::Draw();
/*    Novice::DrawQuad(
        0, 0,
        1280, 0,
        0, 720,
        1280, 720,
        0 + m_currentFrame * 1280, 0,
        1280, 720,
        m_noiseGh, WHITE);*/
    Novice::DrawQuad(
        320, 128,
        959, 128,
        320, 255,
        959, 255,
        0, 0,
        640, 128,
        m_stageGh, WHITE);
}
void ClearMenu::RegisterComponents()
{
    GameMenu::RegisterComponents();
    RegisterClickableComponent(&m_titleButton);
    SetSelectedButton(&m_titleButton);
}