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
		//파일 로드
		if (talkVec[currentTalkIndex] == "-")
		{
			Sleep(5000);
		}
		else
		{
			//UI 다시 출력
			DrawGamePanel();

			std::vector<std::string> ret = splitString(talkVec[currentTalkIndex], ',');
			std::string nameText = ret[0];
			std::string talkText = ret[1];
			std::string CharacterText = ret[2];
			std::string BGMText = ret[3];
			std::string SFXText = ret[4];

			//캐릭터 출력 (없으면 출력 안함)
			if (!CharacterText._Equal("-"))
				DrawCharacter(CharacterText, screenWidth);

			Sleep(1000);

			//이름 출력 (없으면 출력 안함)
			if (!nameText._Equal("-"))
				RenderNameText(nameText);

			//TalkText 출력
			if (!talkText._Equal("-"))
				RenderTalkText(talkText);

			//BGM 재생 (없으면 기존 꺼 재생)
			if (!BGMText._Equal("-"))
			{
				std::vector<std::string> bgmRes = splitString(BGMText, '/');
				std::string fileName = bgmRes[0];
				std::string volume = bgmRes[1];
				PlayBgm(s2ws("Sound/BGM/" + fileName).c_str(), std::stoi(volume));
			}

			//SFX 재생 (없으면 재생 안함)
			if (!SFXText._Equal("-"))
			{
				std::vector<std::string> sfxRes = splitString(SFXText, '/');
				std::string fileName = sfxRes[0];
				std::string volume = sfxRes[1];
				PlayEffect(s2ws("Sound/SFX/" + fileName).c_str());
			}

			//입력 기다리기
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

		//기존 글자 없애기
		system("cls");
	}
}