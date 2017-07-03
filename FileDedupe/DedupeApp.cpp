#include <iostream>
#include "DedupeApp.h"
#include "Service/DedupeService.h"
#include "Service/HandleDupFileService.h"

void DedupeApp::ShowUsage()
{
	std::cout << "Usage: FileDedupe <Path to Dedupe> <Path to store dup files>" << std::endl;
	std::cout << std::endl;
	std::cout << "For example, the following command line:" << std::endl;
	std::cout << "    FileDedupe D:\\Aloha D:\\AlohaDedupe" << std::endl;
	std::cout << "Will move all duplicated files to D:\\AlohaDedupe" << std::endl;
	std::cout << std::endl;
}

int DedupeApp::Main(int argc, wchar_t *argv[])
{
	if (argc != 3)
	{
		ShowUsage();
		return 1;
	}

	DedupeService dedupeService;
	HandleDupFileService output;

	output.SetOutputPath(argv[2]);

	dedupeService.SetDelegate(output);
	dedupeService.Dedupe(argv[1]);

	return 0;
}
