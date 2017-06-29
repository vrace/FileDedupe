#ifndef DEDUPE_MESSAGE_OUTPUT_SERVICE_H
#define DEDUPE_MESSAGE_OUTPUT_SERVICE_H

#include "DedupeService.h"

class DedupeMessageOutputService : public DedupeServiceDelegate
{
public:
	DedupeMessageOutputService()
		: _found(0)
	{
	}

	void DedupeBegin(const std::wstring &path);
	void DedupeComplete();
	void DedupeFound(const std::wstring &file, const std::wstring &dupWith);

private:
	int _found;
};

#endif
