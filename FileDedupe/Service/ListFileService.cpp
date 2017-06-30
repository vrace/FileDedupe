#include "ListFileService.h"
#include <Windows.h>

void ListFileService::List(const std::wstring &path)
{
	_delegate->ListBegin(path);
	ListImpl(path);
	_delegate->ListComplete();
}

void ListFileService::ListImpl(const std::wstring &path)
{
	WIN32_FIND_DATA wfd;
	HANDLE hf;

	std::wstring wtf = path + L"\\*";

	hf = FindFirstFile(wtf.c_str(), &wfd);
	while (hf != INVALID_HANDLE_VALUE)
	{
		if (wfd.cFileName[0] != '\0' && wfd.cFileName[0] != '.')
		{
			std::wstring found = path + L"\\" + wfd.cFileName;

			if ((wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				_delegate->ListDirectory(found);
				ListImpl(found);
			}
			else
			{
				_delegate->ListFile(found);
			}
		}

		if (!FindNextFile(hf, &wfd))
		{
			FindClose(hf);
			hf = INVALID_HANDLE_VALUE;
		}
	}
}
