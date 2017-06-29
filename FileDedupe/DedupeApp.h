#ifndef DEDUPE_APPLICATION_H
#define DEDUPE_APPLICATION_H

#include <wchar.h>

class DedupeApp
{
public:
	int Main(int argc, wchar_t *argv[]);

private:
	void ShowUsage();
};

#endif
