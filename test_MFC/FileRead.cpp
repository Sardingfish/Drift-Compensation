#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "FileRead.h"
using namespace std;

void ReadClkFile();
CClockFile GetClkFile();
void GetcFileName(char* filepath);
char* Substr(const char* s,int n1,int n2);

CFileRead::CFileRead(void)
{
}

CFileRead::~CFileRead(void)
{
}

void CFileRead::GetcFileName(char* filepath)
{   
	 cfilename =filepath;
}

void CFileRead::ReadClkFile()
{
	const char*  c_filename;
	c_filename = (LPSTR)(LPCTSTR)cfilename;   //.c_str();
	fstream file;
	file.open(c_filename ,ios::in|ios::out); 
		if(!file)  cout<<"clk文件打开错误!";
while(!file.eof ())      //判断是否为文件尾
{
CData cd;
char str[MAX_CHAR]; 
file.getline(str,MAX_CHAR,'\n');
//str只能是数组 不能是字符指针，atoi功能:把字符串转换成长整型数;atof功能:把字符串转换成浮点数
if(!strcmp("AS C",Substr(str,0,3)))    //strcomp判断是否相等，若是返回0
{
	cd.PRN=atoi(Substr(str,4,5));
	cd.Toc.year=atoi(Substr(str,8,11));
	cd.Toc.month=atoi(Substr(str,13,14));
	cd.Toc.day=atoi(Substr(str,16,17));
	cd.Toc.hour=atoi(Substr(str,19,20));
	cd.Toc.minute=atoi(Substr(str,22,23));
	cd.Toc.second=atof(Substr(str,25,33));

	if(cd.Toc.year >=80)  cd.Toc.year=1900+cd.Toc.year;
    if((cd.Toc.year>=0)&&(cd.Toc.year<80))   cd.Toc.year=2000+cd.Toc.year;

	cd.dClkBias=atof(Substr(str,40,58));  //cout<<cd.dClkBias<<endl;

	cfile.cdata.push_back(cd);

}

}

file.close();

}

CClockFile CFileRead::GetClkFile()
{
	return cfile;


}


char* CFileRead::Substr(const char *s, int n1, int n2)
{   char *sp;
	sp=new char[n2-n1+2]; //考虑到了‘/0’ 
	int i,j=0; 
	for (i=n1; i<=n2; i++) 
	{ 
		sp[j++]=s[i]; 
	} 
	sp[j]=0;//在字符串最后加上/0 确保sp为一个字符串而不是字符数组 
	return sp;

}