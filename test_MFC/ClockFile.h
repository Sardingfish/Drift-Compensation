#pragma once

#include <vector>
#include "TimeClass.h"

const int MAX_CHAR =100;//ÿһ�ж��������ַ�����



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
	long number;             //�ļ����Ӳ�ĸ���
	double interval;     //�Ӳ�ʱ����

	CClockFile(void);
	~CClockFile(void);
	void GetClkBiasNumber();
	void GetInterval();


};

