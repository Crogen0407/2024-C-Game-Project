#include "GameScene.h"
#include "TitleScene.h"

int main()
{
	if (!TitleScene())
	{
		return 0;
	}
	else
	{
		OnGameScene();
	}
}