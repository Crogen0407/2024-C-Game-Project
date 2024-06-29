#include "stringExtension.h"
#include <atlbase.h>

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

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}