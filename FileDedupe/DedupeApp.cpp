#include <iostream>
#include "DedupeApp.h"
#include "Service/DedupeService.h"
#include "Service/DedupeMessageOutputService.h"

void DedupeApp::ShowUsage()
{
	std::cout << "Usage: FileDedupe <Path to Dedupe>" << std::endl;
	std::cout << std::endl;
	std::cout << "For example, the following command line:" << std::endl;
	std::cout << "    FileDedupe D:\\Aloha" << std::endl;
	std::cout << "Will move all duplicated files to D:\\Aloha\\Dedupe" << std::endl;
	std::cout << std::endl;
}

int DedupeApp::Main(int argc, wchar_t *argv[])
{
	if (argc != 2)
	{
		ShowUsage();
		return 1;
	}

	DedupeService dedupeService;
	DedupeMessageOutputService output;

	dedupeService.SetDelegate(output);
	dedupeService.Dedupe(argv[1]);

	return 0;
}
