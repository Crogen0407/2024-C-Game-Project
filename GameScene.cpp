#include "GameScene.h"
#include "stringExtension.h"
#include "TextController.h"
#include "UIManager.h"
#include "GameData.h"
#include "Mci.h"

void Render()
{
	int screenWidth = 71;
	FullScreen();
	screenWidth = DrawGamePanel();
	system("cls");

	std::vector<std::string> talkVec = ReadTalkTextFile("TalkText/TalkText.txt");
	int currentTalkIndex = 0;

	while (currentTalkIndex < talkVec.size())
	{
		//���� �ε�
		if (talkVec[currentTalkIndex] == "-")
		{
			Sleep(5000);
		}
		else
		{
			//UI �ٽ� ���
			DrawGamePanel();

			std::vector<std::string> ret = splitString(talkVec[currentTalkIndex], ',');
			std::string nameText = ret[0];
			std::string talkText = ret[1];
			std::string CharacterText = ret[2];
			std::string BGMText = ret[3];
			std::string SFXText = ret[4];

			//ĳ���� ���
			DrawCharacter(CharacterText, screenWidth);

			Sleep(1000);

			//�̸� ���
			RenderNameText(nameText);

			//TalkText ���
			RenderTalkText(talkText);

			//BGM ��� (������ ���� �� ���)
			if (!BGMText._Equal("-"))
				PlayBgm(s2ws("Sound/BGM/" + BGMText).c_str(), 5);

			//SFX ��� (������ ��� ����)
			if (!SFXText._Equal("-"))
				PlayBgm(s2ws("Sound/SFX/" + SFXText).c_str(), 5);

			//�Է� ��ٸ���

			while (1)
			{
				if (_kbhit() > 0)
				{
					int nKey;
					nKey = _getch();
					if (_getch() == 32 || _getch() == 13)
					{
						break;
					}
				}
			}
		}

		

		++currentTalkIndex;;

		//���� ���� ���ֱ�
		system("cls");
	}
}