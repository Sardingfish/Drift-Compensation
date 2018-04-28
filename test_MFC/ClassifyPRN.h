#pragma once

#include <vector>
#include "ClockFile.h"



class PRNandBias
{
public:
	int PRN;               //卫星号
	int biasnum;           //对应钟差个数
	std::vector<int> loc;  //在cfile中的位置
};




class CfyPRN
{
public:
	CClockFile cfile;
	std::vector<PRNandBias> PRNDataset;   //存储卫星PRN及对应钟差个数及位置信息
	int PRNnum;                           //存储卫星数目

	CfyPRN();
	~CfyPRN();
	void GetPRNNumber();                   //计算每个卫星钟差个数及对应cfile中的位置
	void GetClkFile(CClockFile cf);

};