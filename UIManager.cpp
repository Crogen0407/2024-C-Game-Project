#include "UIManager.h"
#include "stringExtension.h"

int DrawGamePanel()
{
	GotoPos(0, 0);
	std::string res = ReadFile("UI/GamePanel.txt");
	std::cout << res;

	return splitString(res, '\n')[0].length();
}

void DrawCharacter(std::string characterName)
{
}

void DrawBackground(std::string backgroundName)
{
}
