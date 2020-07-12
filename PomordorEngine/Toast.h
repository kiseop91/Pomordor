#pragma once

#include "Core/Core.h"
#include <string>
class PythonScript;
namespace Pome {

	class Toast
	{
	private:
		static void Init();

	public:
		static int Toast::ToastMessage(const std::string& _fileName);

	private:
		static bool s_isInitiated;
		static bool s_isRunning;

		friend void EngineInit();
	};

}
