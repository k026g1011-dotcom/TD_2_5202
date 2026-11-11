#include "Components.h"
#include <Novice.h>
Components::Components()
{
	m_symbolsGh = Novice::LoadTexture("./resources/Images/Symbols.png");
	m_noteGh = Novice::LoadTexture("./resources/Images/Note.png");
}
int Components::GetSymbolsGh()
{
	return m_symbolsGh;
}
int Components::GetNoteGh()
{
	return m_noteGh;
}