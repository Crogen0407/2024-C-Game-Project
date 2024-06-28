#include "stringExtension.h"

std::vector<std::string> splitString(const std::string& str, char delimiter)
{
	std::vector<std::string> ret;
	std::string token;
	std::stringstream ss(str);
	while (getline(ss, token, delimiter))
	{
		ret.push_back(token);
	}
	return ret;
}
