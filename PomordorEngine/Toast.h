#pragma once

#include "Core.h"
#include <string>

namespace Pome {

	class Toast
	{
	private:
		static void Init();

	public:
		static void ToastMessage(const std::string& Title, const std::string& Message, float duration = 5.0f, const std::string& iconPath = "");

	private:
		static bool s_isInitiated;

		friend void EngineInit();
	};

}
