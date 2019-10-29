#define NOMINMAX
#include <Windows.h>
#include <iostream>

#include "Offsets.h"
#include "Structures.h"
#include "Utils.h"
#include "Engine.h"

using namespace hazedumper::netvars;
using namespace hazedumper::signatures;

using namespace Structures;

HMODULE _hModule;

void MainThread()
{
	Utils::InitConsole();
	Engine::GetModules();

	do {

	} while (!Utils::Killcheck());
	
	Utils::Unload(_hModule);
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH) {
		_hModule = hModule;
		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MainThread, NULL, NULL, NULL);
	}
	return TRUE;
}