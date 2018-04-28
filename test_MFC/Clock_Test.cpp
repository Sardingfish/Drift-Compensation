#include "stdafx.h"
#include "FileRead.h"
#include "Quadratic_polynomial_model.h"
#include <math.h>

int main(int argc, char* argv[])
{
	CFileRead fileread;
	QPModel qpmodel;
	char* cfilepath="whu19976_00.clk";

	fileread.GetcFileName(cfilepath);
	fileread.ReadClkFile();

	CClockFile clkfile;
	clkfile=fileread.GetClkFile();

	qpmodel.GetClkFile(clkfile);
	qpmodel.ComputeCoefficient();

	FILE *pf;
	pf =fopen("������.txt","w");
//	if(!pf)  MessageBox("�ļ��򿪴���!");
	fprintf(pf,"%f\n%f\n%f",qpmodel.a0,qpmodel.a1,qpmodel.a2);
	fclose(pf);

	return 0;




}