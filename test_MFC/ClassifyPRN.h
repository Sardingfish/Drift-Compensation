#pragma once

#include <vector>
#include "ClockFile.h"



class PRNandBias
{
public:
	int PRN;               //���Ǻ�
	int biasnum;           //��Ӧ�Ӳ����
	std::vector<int> loc;  //��cfile�е�λ��
};




class CfyPRN
{
public:
	CClockFile cfile;
	std::vector<PRNandBias> PRNDataset;   //�洢����PRN����Ӧ�Ӳ������λ����Ϣ
	int PRNnum;                           //�洢������Ŀ

	CfyPRN();
	~CfyPRN();
	void GetPRNNumber();                   //����ÿ�������Ӳ��������Ӧcfile�е�λ��
	void GetClkFile(CClockFile cf);

};