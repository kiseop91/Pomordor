#include "pegpch.h"
#include "Toast.h"

namespace Pome {

	bool Toast::s_isInitiated = false;

	const std::string toastScriptName= "toast.py";

	void Toast::Init()
	{
		if (s_isInitiated) return;

		s_isInitiated = true;
	}

	void Toast::ToastMessage(const std::string & title, const std::string & message, float duration, const std::string & iconPath)
	{
		std::ofstream pythonScript(toastScriptName);
		POM_ASSERT(pythonScript.is_open());

		if (duration < 1.0f)
		{
			duration = 1.0f;
		}

	#ifdef _WINDOWS
		pythonScript
			<< "from win10toast import ToastNotifier\n"
			<< "toast = ToastNotifier()\n"
			<< "title = \"" << title << "\"\n"
			<< "message = \"" << message << "\"\n"
			<< "duration = " << duration << "\n"
			;
		if (iconPath.size())
		{
			pythonScript 
				<< "icon_path = \"" << iconPath << "\"\n"
				<< "toast.show_toast(title, message, iconPath, duration)"
				;
		}
		else
		{
			pythonScript 
				<< "toast.show_toast(title, message, None, duration)"
				;
		}
	#endif

		pythonScript.close();
		std::system(toastScriptName.c_str());

		return;
	}
}


