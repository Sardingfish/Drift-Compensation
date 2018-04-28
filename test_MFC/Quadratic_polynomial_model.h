#pragma once
#include "FileRead.h"

class QPModel
{
public:
	double a0;
	double a1;
	double a2;
	double t0;  //秒为单位


	QPModel(void);
	~QPModel(void);
	void GetClkFile(CClockFile cf);
	void ComputeCoefficient();        //计算系数
	double GetClkBias(CommonTime time); //输入时间，获取该时刻拟合钟差


private:
	CClockFile clkfile;


};