#include <iostream>
#include <string>
#include <string.h>
#include <Windows.h>
#include "HandleDupFileService.h"
#include "../Utils/ForceCreateDirectory.h"

void HandleDupFileService::DedupeBegin(const std::wstring &path)
{
	std::wcout << L"Deduping path '" << path << L"'..." << std::endl;
	std::wcout << std::endl;

	_found = 0;
	_root = path;
}

void HandleDupFileService::DedupeFound(const std::wstring &file, const std::wstring &dupWith)
{
	std::wcout << file << L" -> " << dupWith << std::endl;
	_found++;

	std::wstring dest = GetDedupeFileName(file);
	ForceCreateDirectoryForFile(dest);
	MoveFile(file.c_str(), dest.c_str());
}

void HandleDupFileService::DedupeComplete()
{
	std::wcout << std::endl;
	std::wcout << _found << L" duplicated file(s) found." << std::endl;
}

std::wstring HandleDupFileService::GetDedupeFileName(const std::wstring &filename) const
{
	if (_wcsnicmp(_root.c_str(), filename.c_str(), _root.length()) != 0)
		return std::wstring();

	return _outputPath + filename.substr(_root.length());
}

void HandleDupFileService::SetOutputPath(const std::wstring &outputPath) {
	_outputPath = outputPath;
}
