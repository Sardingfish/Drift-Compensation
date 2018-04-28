#pragma once
#include "FileRead.h"

class QPModel
{
public:
	double a0;
	double a1;
	double a2;
	double t0;  //��Ϊ��λ


	QPModel(void);
	~QPModel(void);
	void GetClkFile(CClockFile cf);
	void ComputeCoefficient();        //����ϵ��
	double GetClkBias(CommonTime time); //����ʱ�䣬��ȡ��ʱ������Ӳ�


private:
	CClockFile clkfile;


};