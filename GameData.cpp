#include "GameData.h"
#include <vector>

std::vector<std::string> ReadFileForVector(std::string filePath)
{
	std::ifstream readFile(filePath);
	std::vector<std::string> res;
	res.clear();
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			std::string str;
			getline(readFile, str);
			res.push_back(str);
		}
	}

	return res;
}

std::string ReadFile(std::string filePath)
{
	std::ifstream readFile(filePath);
	std::stringstream ss;
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			std::string str;
			getline(readFile, str);
			ss << str << std::endl;
		}
	}

	return ss.str();
}

std::vector<std::string> ReadTalkTextFile(std::string filePath)
{
	std::ifstream readFile(filePath);

	std::vector<std::string> v;
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			std::string str;
			getline(readFile, str);
			v.push_back(str);
		}
	}

	return v;
}