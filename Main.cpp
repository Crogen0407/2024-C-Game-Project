#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include "TitleScene.h"
#include "console.h"
#include "File.h"

int main() {
	system("mode con:cols=150 lines=50");
	/*if (!TitleScene())
	{
		return 0;
	}
	else
	{
		while (1)
		{
		}
	}*/

	std::ifstream readFile;
	readFile.open("Dialogue.txt");
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			char arr[256];
			readFile.getline(arr, 256);
		}
	}
	readFile.close();
}