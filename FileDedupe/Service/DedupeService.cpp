#include "DedupeService.h"

void DedupeService::Dedupe(const std::wstring &path)
{
	ListFileService listFileService;

	listFileService.SetDelegate(*this);
	listFileService.List(path);
}

void DedupeService::ListBegin(const std::wstring &path)
{
	_delegate->DedupeBegin(path);
}

void DedupeService::ListComplete()
{
	_delegate->DedupeComplete();
}

void DedupeService::ListDirectory(const std::wstring &dirName)
{

}

void DedupeService::ListFile(const std::wstring &fileName)
{
	// TODO: is it really a dup?
	_delegate->DedupeFound(fileName, L"<dummy>");
}
