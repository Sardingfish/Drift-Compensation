#include "stdafx.h"
#include "ClockFile.h"

CClockFile::CClockFile(void)
{
}

CClockFile::~CClockFile(void)
{
}

void CClockFile::GetClkBiasNumber()
{
	number=cdata.size();

}

void CClockFile::GetInterval()
{
	GetClkBiasNumber();
	if(number>=3)
	{
	double itl1,itl2,itl3;
	int mid=number/2;

	itl1=86400*(cdata.at(1).Toc.day-cdata.at(0).Toc.day)+3600*(cdata.at(1).Toc.hour-cdata.at(0).Toc.hour)
		+60*(cdata.at(1).Toc.minute-cdata.at(0).Toc.minute)+(cdata.at(1).Toc.second-cdata.at(0).Toc.second);

	itl2=86400*(cdata.at(mid+1).Toc.day-cdata.at(mid).Toc.day)+3600*(cdata.at(mid+1).Toc.hour-cdata.at(mid).Toc.hour)
		+60*(cdata.at(mid+1).Toc.minute-cdata.at(mid).Toc.minute)+(cdata.at(mid+1).Toc.second-cdata.at(mid).Toc.second);

	itl3=86400*(cdata.at(number).Toc.day-cdata.at(number-1).Toc.day)+3600*(cdata.at(number).Toc.hour-cdata.at(number-1).Toc.hour)
		+60*(cdata.at(number).Toc.minute-cdata.at(number-1).Toc.minute)+(cdata.at(number).Toc.second-cdata.at(number-1).Toc.second);

	if((itl1==itl2)&&(itl2==itl3))
	interval=itl1;

	}

}