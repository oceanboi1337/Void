#include "Engine.h"
#include "Offsets.h"

using namespace hazedumper::signatures;
using namespace hazedumper::netvars;

DWORD Engine::Modules::Client = NULL;
DWORD Engine::Modules::Engine = NULL;

DWORD Engine::GetLocalPlayer()
{
	return *(DWORD*)(Engine::Modules::Client + dwLocalPlayer);
}

void Engine::GetModules()
{
	Engine::Modules::Client = (DWORD)GetModuleHandle(L"client_panorama.dll");
	Engine::Modules::Engine = (DWORD)GetModuleHandle(L"engine.dll");
}
