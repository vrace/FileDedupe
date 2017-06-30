#include "HandleDupFileService.h"
#include <iostream>
#include <string>

void HandleDupFileService::DedupeBegin(const std::wstring &path)
{
	std::wcout << L"Deduping path '" << path << L"'..." << std::endl;
	std::wcout << std::endl;

	_found = 0;
}

void HandleDupFileService::DedupeFound(const std::wstring &file, const std::wstring &dupWith)
{
	std::wcout << file << L" -> " << dupWith << std::endl;
	_found++;
}

void HandleDupFileService::DedupeComplete()
{
	std::wcout << std::endl;
	std::wcout << _found << L" duplicated file(s) found." << std::endl;
}
