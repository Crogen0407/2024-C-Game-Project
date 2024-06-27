#pragma once
#include "Component.h"
#include<Windows.h>
#include <iostream>

class UI : public Component
{
public:
	COORD position;
	std::string renderObject;
	COORD GetRenderObjectSize();
};