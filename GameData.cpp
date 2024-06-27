#include "GameData.h"

std::string ReadFile(std::string filePath)
{
	std::ifstream readFile(filePath);
	std::stringstream ss;

	if (readFile.is_open())
	{
		if (readFile.fail())
			return "";
		ss << readFile.rdbuf() << std::endl;;
	}

	return ss.str();
}