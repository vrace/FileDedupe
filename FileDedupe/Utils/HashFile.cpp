#include <stdio.h>
#include <stdlib.h>
#include "HashFile.h"
extern "C"
{
#include "sha256/sha256.h"
}

namespace
{
	const int READ_BUF_SIZE = 1000;
}

std::string HashFile(const std::wstring &filename)
{
	FILE *fp;

	fp = _wfopen(filename.c_str(), L"rb");
	
	if (!fp)
		return std::string();

	sha256_context context;
	sha256_starts(&context);

	char buf[READ_BUF_SIZE];
	while (!feof(fp))
	{
		int bytesRead = (int)fread(buf, 1, READ_BUF_SIZE, fp);
		if (bytesRead > 0)
			sha256_update(&context, (uint8*)buf, bytesRead);
	}
	fclose(fp);

	uint8 digest[32];
	sha256_finish(&context, digest);

	for (int i = 0; i < 32; i++)
		sprintf(buf + i * 2, "%02x", digest[i]);

	return std::string(buf);
}
