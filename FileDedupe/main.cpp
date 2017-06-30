#include "DedupeApp.h"
#include <locale.h>

int wmain(int argc, wchar_t *argv[])
{
	setlocale(LC_ALL, "zh-CN");
	DedupeApp app;
	return app.Main(argc, argv);
}
