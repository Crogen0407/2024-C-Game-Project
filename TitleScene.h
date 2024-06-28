#pragma once
enum class MENU
{
	START,
	STORY,
	SAVE,
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