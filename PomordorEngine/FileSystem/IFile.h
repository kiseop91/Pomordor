#pragma once
class IFile
{
protected:

	virtual bool GetData(void* _data, size_t _size) const = 0;
	virtual bool SetData(void* _data, size_t _size) = 0;
};