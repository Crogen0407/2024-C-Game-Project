#pragma once
enum class MENU
{
	START,
	STORY,
	QUIT
};
enum class KEY
{
	NONE,
	UP,
	DOWN,
	SPACE
};
bool TitleScene();
void TitleRender();
void StoryRender();
MENU MenuRender();
KEY KeyController();
void EnterAnimation();