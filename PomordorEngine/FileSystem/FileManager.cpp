#include "pegpch.h"

#include "Util/PyhtonScript.h"
#include "FileSystem/FileManager.h"

bool FileManager::Save(const PythonScript & s, const std::string & filename)
{
	std::ofstream file(filename);
	if (!file.is_open())
	{
		return false;
	}

	std::string str;
	s.GetScript(str);
#ifdef _WINDOWS
	file << str;
#endif
	return true;
}
