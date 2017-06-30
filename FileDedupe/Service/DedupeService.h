#ifndef DEDUPE_SERVICE_H
#define DEDUPE_SERVICE_H

#include <string>
#include <map>
#include "ListFileService.h"

class DedupeServiceDelegate
{
public:
	virtual void DedupeBegin(const std::wstring &path) = 0;
	virtual void DedupeComplete() = 0;
	virtual void DedupeFound(const std::wstring &file, const std::wstring &dupWith) = 0;
};

class DedupeService : public ListFileServiceDelegate
{
public:
	typedef std::map<std::string, std::wstring> FileInfoMap;

	DedupeService()
		: _delegate(NULL) {}

	void SetDelegate(DedupeServiceDelegate &dedupeServiceDelegate) { _delegate = &dedupeServiceDelegate; }

	void Dedupe(const std::wstring &path);

	void ListBegin(const std::wstring &path);
	void ListComplete();
	void ListFile(const std::wstring &fileName);
	void ListDirectory(const std::wstring &dirName);

private:
	DedupeServiceDelegate *_delegate;
	FileInfoMap _infoMap;
};

#endif
