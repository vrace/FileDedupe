#include "DedupeService.h"

DedupeService::DedupeService()
	: _delegate(NULL)
{

}

void DedupeService::Dedupe(const std::wstring &path)
{
	if (_delegate)
		_delegate->DedupeBegin(path);

	// TODO:
	if (_delegate)
		_delegate->DedupeFound(L"a.txt", L"b.txt");

	if (_delegate)
		_delegate->DedupeComplete();
}
