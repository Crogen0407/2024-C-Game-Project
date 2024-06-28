#include "UIManager.h"

void DrawGamePanel()
{
	GotoPos(0, 0);

	std::cout << ReadFile("UI/GamePanel.txt");
}

void DrawCharacter(std::string characterName)
{
}

void DrawBackground(std::string backgroundName)
{
}
