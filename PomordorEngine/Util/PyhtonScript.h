#include "FileSystem/IFile.h"
class PythonScript : public IFile
{
public:
	bool CreateToastScript(const std::string& _title, const std::string& _msg, float _duartion, const std::string& _iconPath);
	bool GetScript(std::string& _str) const;
	bool GetData(void* _data, size_t _size) const override;
	bool SetData(void* _data, size_t _size) override;
	const std::string& GetScriptName() const;

private:
	std::string m_Script;
	std::string m_ScriptName;
};