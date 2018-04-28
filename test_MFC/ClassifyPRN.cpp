#include "stdafx.h"
#include "ClassifyPRN.h"

CfyPRN::CfyPRN()
{
}

CfyPRN::~CfyPRN()
{
}

void CfyPRN::GetClkFile(CClockFile cf)
{
	cfile=cf;

}

void CfyPRN::GetPRNNumber()
{
	if(cfile.number!=0)
	{

	for(int i=0;i<14;i++)
	{
		PRNDataset.at(i).PRN=i+1;
		PRNDataset.at(i).biasnum=0;
	}

	for(int i=0;i<cfile.number;i++)
	{
		for(int j=0;j<PRNDataset.size();j++)
		{
			if(cfile.cdata.at(i).PRN==PRNDataset.at(j).PRN)
			{
				PRNDataset.at(j).loc.at(PRNDataset.at(j).biasnum)=i;
				PRNDataset.at(j).biasnum++;
				break;
			}
		
		}
	
	}

	PRNnum=PRNDataset.size();

	}
}

