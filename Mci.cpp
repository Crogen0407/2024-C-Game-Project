#include <Windows.h>
#include <mmsystem.h>
#include <Digitalv.h>
#include <string>
#include "mci.h"
#pragma comment(lib, "winmm.lib")

UINT Bgmid;
UINT Effectid;

void PlayBgm(LPCWSTR _soundname, int _volume)
{
	mciSendCommand(Bgmid, MCI_CLOSE, NULL, (DWORD)NULL); // RAII

	// OPEN
	MCI_OPEN_PARMS openBgm;

	// mp3: mpegvideo, wav: waveaudio, avi: avivideo
	openBgm.lpstrDeviceType = TEXT("mpegvideo");
	openBgm.lpstrElementName = _soundname;

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openBgm);
	Bgmid = openBgm.wDeviceID;

	std::wstring msg = L"setaudio " + std::wstring(_soundname) +
		L" volume to " + std::to_wstring(_volume);
	mciSendString(msg.c_str(), NULL, NULL, NULL);

	// PLAY
	MCI_PLAY_PARMS playBgm;
	mciSendCommand(Bgmid, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR)&playBgm);
	//// 일시정지
	//mciSendCommand(Bgmid, MCI_PAUSE, MCI_NOTIFY, (DWORD_PTR)&playBgm);
	//// 다시시작
	mciSendCommand(Bgmid, MCI_RESUME, NULL, NULL);
	//// 닫기
	//mciSendCommand(Bgmid, MCI_CLOSE, NULL, NULL);

}

void PlayEffect(LPCWSTR _soundname)
{
	// PLAY
	MCI_PLAY_PARMS playEffect;
	if (Effectid != 0)  
	{
		mciSendCommand(Effectid, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)&playEffect);
		mciSendCommand(Effectid, MCI_CLOSE, NULL, (DWORD)NULL); // RAII
		Effectid = 0;
	}
	// OPEN
	MCI_OPEN_PARMS openEffect;
	// mp3: mpegvideo, wav: waveaudio, avi: avivideo
	openEffect.lpstrDeviceType = TEXT("mpegvideo");
	openEffect.lpstrElementName = _soundname;
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openEffect);
	Effectid = openEffect.wDeviceID;


	mciSendCommand(Effectid, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&playEffect);
	while (mciSendCommand(Effectid, MCI_STATUS, MCI_STATUS_MODE, (DWORD_PTR)&playEffect))
	{
		break;
	}
}