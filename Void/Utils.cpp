#include "Utils.h"

void Utils::InitConsole()
{
	FILE* f;
	AllocConsole();
	freopen_s(&f, "CONOUT$", "w", stdout);
}

void Utils::ExitConsole()
{
	fclose(stdout);
	FreeConsole();
}

void Utils::Unload(HMODULE hModule)
{
	Utils::ExitConsole();
	Sleep(200);
	FreeLibraryAndExitThread(hModule, 0);
}

bool Utils::Killcheck()
{
	return (GetAsyncKeyState(VK_END) & 1);
}
