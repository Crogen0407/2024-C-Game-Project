#include <Windows.h>
#include <conio.h>
#include "UIManager.h"
#include "GameData.h"

std::vector<std::string> split(std::string str, char Delimiter) {
	std::istringstream iss(str);             // istringstream에 str을 담는다.
	std::string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

	std::vector<std::string> result;

	// istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
	while (getline(iss, buffer, Delimiter)) {
		result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
	}

	return result;
}


int main()
{
	FullScreen();
	DrawGamePanel();
	CursorVis(false, 1);


	std::vector<std::string> talkVec = ReadTalkTextFile("TalkText/TalkText.txt");
	int currentTalkIndex = 0;

	while (currentTalkIndex < talkVec.size())
	{
		Sleep(1000);
		std::string nameText = split(talkVec[currentTalkIndex], ',')[0];
		std::string talkText = split(talkVec[currentTalkIndex], ',')[1];
		int currentCharIndex = 0;
		while (talkText.size() > currentCharIndex)
		{
			GotoPos(10 + currentCharIndex*2, 71);
			if (talkText[currentCharIndex] == '\\')
			{
				Sleep(100);
			}
			else
			{
				std::cout << talkText[currentCharIndex];
			}
			++currentCharIndex;
			Sleep(20);
		}

		while(1)
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

		++currentTalkIndex;;

		//기존 글자 없애기
		system("cls");
		DrawGamePanel();
	}
}