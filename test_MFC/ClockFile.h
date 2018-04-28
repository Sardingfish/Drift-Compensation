#pragma once

#include <vector>
#include "TimeClass.h"

const int MAX_CHAR =100;//每一行读入的最大字符个数



class CData
{
public:
	int             PRN;
	CommonTime      Toc;
	double          dClkBias;


};

class CClockFile
{
public:
	std::vector<CData> cdata;		
	long number;             //文件中钟差的个数
	double interval;     //钟差时间间隔

	CClockFile(void);
	~CClockFile(void);
	void GetClkBiasNumber();
	void GetInterval();


};

