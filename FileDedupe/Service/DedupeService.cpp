#include "DedupeService.h"
#include "../Utils/HashFile.h"

void DedupeService::Dedupe(const std::wstring &path)
{
	ListFileService listFileService;

	listFileService.SetDelegate(*this);
	listFileService.List(path);
}

void DedupeService::ListBegin(const std::wstring &path)
{
	_infoMap.clear();
	_delegate->DedupeBegin(path);
}

void DedupeService::ListComplete()
{
	_delegate->DedupeComplete();
	_infoMap.clear();
}

void DedupeService::ListDirectory(const std::wstring &dirName)
{

}

void DedupeService::ListFile(const std::wstring &fileName)
{
	std::string hash = HashFile(fileName);
	if (hash.empty())
		return;

	FileInfoMap::iterator it = _infoMap.find(hash);

	if (it != _infoMap.end())
	{
		_delegate->DedupeFound(fileName, it->second);
	}
	else
	{
		_infoMap[hash] = fileName;
	}
}
