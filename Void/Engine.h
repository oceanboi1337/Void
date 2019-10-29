#pragma once
#include <Windows.h>

namespace Engine {
	class Modules {
	public:
		static DWORD Client;
		static DWORD Engine;
	};

	DWORD GetLocalPlayer();

	void GetModules();
}