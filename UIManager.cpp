#include "UIManager.h"
#include "stringExtension.h"

int DrawGamePanel()
{
	Gotoxy(0, 0);
	std::string res = ReadFile("UI/GamePanel.txt");
	std::cout << res;

	return splitString(res, '\n')[0].length();
}

void DrawCharacter(std::string characterName, int screenWidth)
{
	std::vector<std::string> characterText = ReadFileForVector("Character/" + characterName + ".txt");
	int middlePos = (screenWidth - characterText[0].length()) / 2;
	for (size_t i = 0; i < characterText.size(); ++i)
	{
		Gotoxy(middlePos, 10 + i);
		std::cout << characterText[i];

	}
	Sleep(1000);
}

void DrawBackground(std::string backgroundName)
{
}
