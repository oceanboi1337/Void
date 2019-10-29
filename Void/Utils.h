#pragma once
#include <Windows.h>
#include <cstdio>

namespace Utils {
	void InitConsole();
	void ExitConsole();
	void Unload(HMODULE hModule);

	bool Killcheck();
}