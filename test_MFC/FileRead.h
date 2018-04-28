#pragma once

#include "ClockFile.h"
#include <CString>

class CFileRead
{
public:
	CFileRead(void);
	~CFileRead(void);
	void ReadClkFile();
	CClockFile GetClkFile();
	void GetcFileName(char* filepath);
	char* Substr(const char* s,int n1,int n2);

private:
	CString cfilename;
	CClockFile cfile;

};