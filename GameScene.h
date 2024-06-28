#pragma once
#include <Windows.h>
#include <conio.h>
#include <string>
#include <sstream>
#include "UIManager.h"
#include "GameData.h"

std::vector<std::string> splitString(const std::string& str, char delimiter);
void Render();