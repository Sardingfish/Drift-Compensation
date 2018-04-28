#include "stdafx.h"
#include "Quadratic_polynomial_model.h"
#include "MAT.h"



QPModel::QPModel(void)
{
}

QPModel::~QPModel(void)
{
}

void QPModel::GetClkFile(CClockFile cf)
{
	clkfile=cf;
}

void QPModel::ComputeCoefficient()
{
	t0=0;
	clkfile.GetInterval();

	MAT alpha(3,1);
	MAT X(clkfile.number,1);
	MAT T(clkfile.number,3);

	for(int i=0;i<clkfile.number;i++)
	{
		X(i,0)=clkfile.cdata.at(i).dClkBias;

		T(i,0)=1;

		T(i,1)=int((clkfile.cdata.at(i).Toc.day*86400+clkfile.cdata.at(i).Toc.hour*3600+clkfile.cdata.at(i).Toc.minute*60+clkfile.cdata.at(i).Toc.second)
			-(clkfile.cdata.at(0).Toc.day*86400+clkfile.cdata.at(0).Toc.hour*3600+clkfile.cdata.at(0).Toc.minute*60+clkfile.cdata.at(0).Toc.second))
			/clkfile.interval-t0;
        
		T(i,2)=0.5*pow(T(i,1),2);
	}  

	alpha=(T.T()*T).inverse()*T.T()*X;

	a0=alpha(0,0);
	a1=alpha(1,0);
	a2=alpha(2,0);

}

double QPModel::GetClkBias(CommonTime time)
{
	ComputeCoefficient();
	double bias;
	bias=a0+a1*(((time.day*86400+time.hour*3600+time.minute*60+time.second)-(clkfile.cdata.at(0).Toc.day*86400+clkfile.cdata.at(0).Toc.hour*3600+clkfile.cdata.at(0).Toc.minute*60+clkfile.cdata.at(0).Toc.second))/(clkfile.interval))
		+0.5*a2*pow((((time.day*86400+time.hour*3600+time.minute*60+time.second)-(clkfile.cdata.at(0).Toc.day*86400+clkfile.cdata.at(0).Toc.hour*3600+clkfile.cdata.at(0).Toc.minute*60+clkfile.cdata.at(0).Toc.second))/(clkfile.interval)),2);
return bias;
}