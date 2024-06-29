#include "GameScene.h"
#include "stringExtension.h"
#include "TextController.h"
#include "UIManager.h"
#include "GameData.h"
#include "Mci.h"
#include <string>

void OnGameScene()
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

			//ĳ���� ��� (������ ��� ����)
			if (!CharacterText._Equal("-"))
				DrawCharacter(CharacterText, screenWidth);

			Sleep(1000);

			//�̸� ��� (������ ��� ����)
			if (!nameText._Equal("-"))
				RenderNameText(nameText);

			//TalkText ���
			if (!talkText._Equal("-"))
				RenderTalkText(talkText);

			//BGM ��� (������ ���� �� ���)
			if (!BGMText._Equal("-"))
			{
				std::vector<std::string> bgmRes = splitString(BGMText, '/');
				std::string fileName = bgmRes[0];
				std::string volume = bgmRes[1];
				PlayBgm(s2ws("Sound/BGM/" + fileName).c_str(), std::stoi(volume));
			}

			//SFX ��� (������ ��� ����)
			if (!SFXText._Equal("-"))
			{
				std::vector<std::string> sfxRes = splitString(SFXText, '/');
				std::string fileName = sfxRes[0];
				std::string volume = sfxRes[1];
				PlayEffect(s2ws("Sound/SFX/" + fileName).c_str());
			}

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