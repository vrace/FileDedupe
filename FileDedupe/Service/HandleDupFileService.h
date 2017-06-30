#ifndef HANDLE_DUP_FILE_SERVICE_H
#define HANDLE_DUP_FILE_SERVICE_H

#include "DedupeService.h"

class HandleDupFileService : public DedupeServiceDelegate
{
public:
	HandleDupFileService()
		: _found(0) {}

	void DedupeBegin(const std::wstring &path);
	void DedupeComplete();
	void DedupeFound(const std::wstring &file, const std::wstring &dupWith);

private:
	int _found;
};

#endif
