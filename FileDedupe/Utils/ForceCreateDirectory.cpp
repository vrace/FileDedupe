#include <sstream>
#include <Windows.h>
#include "ForceCreateDirectory.h"

namespace
{
	const wchar_t PATH_DELIMS[] = L"\\/";
}

void ForceCreateDirectory(const std::wstring &path)
{
	ForceCreateDirectoryForFile(path);
	CreateDirectory(path.c_str(), NULL);
}

void ForceCreateDirectoryForFile(const std::wstring &path)
{
	for (std::wstring::size_type pos = path.find_first_of(PATH_DELIMS);
		pos != std::wstring::npos;
		pos = path.find_first_of(PATH_DELIMS, pos + 1))
	{
		std::wstring sub = path.substr(0, pos);
		CreateDirectory(sub.c_str(), NULL);
	}
}
