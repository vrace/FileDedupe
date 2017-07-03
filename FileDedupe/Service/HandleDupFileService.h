#ifndef HANDLE_DUP_FILE_SERVICE_H
#define HANDLE_DUP_FILE_SERVICE_H

#include "DedupeService.h"

class HandleDupFileService : public DedupeServiceDelegate
{
public:
	HandleDupFileService()
		: _found(0) {}

	void SetOutputPath(const std::wstring &outputPath);

	void DedupeBegin(const std::wstring &path);
	void DedupeComplete();
	void DedupeFound(const std::wstring &file, const std::wstring &dupWith);

private:
	std::wstring GetDedupeFileName(const std::wstring &filename) const;

private:
	std::wstring _outputPath;
	std::wstring _root;
	int _found;
};

#endif
