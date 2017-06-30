#ifndef LIST_FILE_SERVICE_H
#define LIST_FILE_SERVICE_H

#include <string>

class ListFileServiceDelegate
{
public:
	virtual void ListBegin(const std::wstring &path) = 0;
	virtual void ListComplete() = 0;
	virtual void ListFile(const std::wstring &fileName) = 0;
	virtual void ListDirectory(const std::wstring &dirName) = 0;
};

class ListFileService
{
public:
	ListFileService()
		: _delegate(NULL) {}

	void SetDelegate(ListFileServiceDelegate &delegate) { _delegate = &delegate; }
	void List(const std::wstring &path);

private:
	void ListImpl(const std::wstring &path);

private:
	ListFileServiceDelegate *_delegate;
};

#endif
