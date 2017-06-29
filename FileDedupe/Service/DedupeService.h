#ifndef DEDUPE_SERVICE_H
#define DEDUPE_SERVICE_H

#include <string>
#include <map>

class DedupeServiceDelegate
{
public:
	virtual void DedupeBegin(const std::wstring &path) = 0;
	virtual void DedupeComplete() = 0;
	virtual void DedupeFound(const std::wstring &file, const std::wstring &dupWith) = 0;
};

class DedupeService
{
public:
	typedef std::map<std::string, std::wstring> FileInfoMap;

	DedupeService();

	void SetDelegate(DedupeServiceDelegate &dedupeServiceDelegate) { _delegate = &dedupeServiceDelegate; }

	void Dedupe(const std::wstring &path);

private:
	DedupeServiceDelegate *_delegate;
	FileInfoMap _infoMap;
};

#endif
