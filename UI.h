#pragma once
#include<Windows.h>
#include <iostream>

class UI
{
public:
	COORD position;
	std::string renderObject;
	COORD GetRenderObjectSize();
};