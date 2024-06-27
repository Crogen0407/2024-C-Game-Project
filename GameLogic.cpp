#include "GameLogic.h"
#include<Windows.h>
#include<fstream>                       

void FrameSync(unsigned int _Framerate)
{
	clock_t oldtime = clock();
	clock_t curtime;

	while (true)
	{
		curtime = clock();
		if (curtime - oldtime > 1000 / _Framerate)
		{
			oldtime = curtime;
			break;
		}
	}

}