#include "pegpch.h"
#include "Toast.h"
#include "Util/PyhtonScript.h"
#include "FileSystem/FileManager.h"
namespace Pome {

	bool Toast::s_isInitiated = false;
	bool Toast::s_isRunning = false;

	void Toast::Init()
	{
		if (s_isInitiated) return;

		s_isInitiated = true;
	}

	int Toast::ToastMessage(const std::string& _fileName)
	{
		if (s_isRunning) return 0;
		s_isRunning = true;

		std::future<bool> test;

		std::thread thread([&](){
			std::string runPythonCmd = "python " + _fileName;
			std::system(runPythonCmd.c_str());
			s_isRunning = false;
		});
		thread.detach();

		return 1;
	}
}


