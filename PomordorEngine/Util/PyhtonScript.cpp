#include "pegpch.h"
#include "Util/PyhtonScript.h"
#include "FileSystem/FileManager.h"

bool PythonScript::CreateToastScript(const std::string& _title, const std::string& _msg, float _duartion, const std::string& _iconPath)
{
#ifdef _WINDOWS
	std::stringstream script;
	script
		<< "from win10toast import ToastNotifier\n"
		<< "toast = ToastNotifier()\n"
		<< "title = \"" << _title << "\"\n"
		<< "message = \"" << _msg << "\"\n"
		<< "duration = " << _duartion << "\n"
		;
	if (_iconPath.size())
	{
		script
			<< "icon_path = \"" << _iconPath << "\"\n"
			<< "toast.show_toast(title, message, iconPath, duration)"
			;
	}
	else
	{
		script
			<< "toast.show_toast(title, message, None, duration)"
			;
	}

	m_Script = script.str();
	m_ScriptName = _title;

	return true;
#endif
}

bool PythonScript::GetScript(std::string& _str) const
{
	_str = m_Script;
	return true;
}

bool PythonScript::GetData(void* data, size_t _size) const
{
	size_t t= m_Script.size();
	data = new char[1000];
	//data = m_Script;
	return true;
}

bool PythonScript::SetData(void * _data, size_t _size)
{
	return false;
}

const std::string & PythonScript::GetScriptName() const
{
	return m_ScriptName;
}

