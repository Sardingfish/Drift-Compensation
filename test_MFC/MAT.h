#if !defined(CHDADJ_MAT_H__INCLUDED_)                    // MAT.h �ļ�
#define CHDADJ_MAT_H__INCLUDED_    //VC: 2016:10:15Version Code:2016.1
//********************************************************************
//***************************�����ඨ��*****************   (lines:850)
//********************************************************************
#include <stdlib.h>
#include <math.h>                                  // ��ѧ�⺯��
#include <stdio.h>
#include <string.h>                                // �ַ���������
#include<iostream>                               // ����/�����
#include<fstream>                                // �ļ���
using namespace std;
#if !defined PI
#define PI 3.14159265358979312                     // Բ����
#endif
#if !defined UNK
#define UNK (-PI*PI*PI)                            // ����δ֪��
#endif
#if !defined rou
#define rou (180.*60.*60./PI)                      // 1���ȶ�Ӧ������
#endif
//**********************************************************************
double setf(double a, int t)                       // ����a��С��λ��Ϊt
{
   double b=fabs(a);                               // ����a�ľ���ֵ          
    for(int i=0;i<t;i++)
	   b*=10;                                      // ��b����10��t�η�
    if(b-floor(b)>0.5) b=floor(b)+1;               // ��b��С��ȡ��
    else b=floor(b);
    for(int i=0;i<t;i++)
	   b/=10;                                      // ��b����10��t�η�
    if(a<0) b=-b;                                  // aΪ�����Ĵ���
     return b;
}
//******************************************************************** 
class MAT                                                    // ������        
{   
  public:                                       //���г�Ա����
	MAT();                                      //��ʼ��δ֪�������ľ���	
	MAT(int hang,int lie);                      //��ʼ����֪�������ľ���
    MAT( MAT &S);                               //�������캯��
	MAT(int hl);                                //���������ξ���  
	~MAT();                                     //��������	
	
	void SetRow(int h);                         //���þ�������   
	void SetRank(int l);                        //���þ������� 
	void SetRR(int h,int l);                    //���þ����С�����

	int GetRow();                               //���ؾ�������   
	int GetRank();                              //���ؾ�������   
    void GetRR(int &row,int &rank);             //���ؾ��������������

	void SetElem(int h,int l,double m);         //���þ���h,lλ�õ�Ԫ��
	double& GetElem(int h, int l);              //���ؾ���h,lλ�õ�Ԫ��

	void SetALL();                              //���������������Ԫ��ֵ
	void SetI();                                //���õ�ǰ����Ϊ��λ��
    void Set1();                                //���õ�ǰ��������Ԫ��Ϊ1
	void Set0();                                //���õ�ǰ��������Ԫ��Ϊ0
	bool CheckI();                              //�жϵ�ǰ�����Ƿ�Ϊ��λ��

    void print();                               //����Ļ��ʾ����

	MAT & operator = ( MAT &other);             //�þ���Ծ���ֵ	
	bool operator ==(MAT &A);                   //�ж����������Ƿ���ͬ
    MAT & operator +=(MAT &other);              //�������ĺ͵��ڲ���
	MAT operator + (MAT &B);                    //�����������
	MAT operator - (MAT &B);                    //�����������
    MAT operator * (MAT &B);                    //�����������
    friend MAT operator * (double A,MAT &B);    //���˾�������
    MAT operator * (double B);                  //�����������
    MAT operator / (double B);                  //�������������
    friend ostream & operator <<(ostream &ou,MAT &A);   //�������
    friend istream & operator >>(istream &in,MAT &A);   //�������
    double & operator () (int h,int l);                 //����h�С�l��λ�õ�Ԫ��	

	MAT inverse();                //���㷽������󣨼���ʧ�ܷ���0��0�ľ���
 	MAT T();                      //����ת��
    int R();                      //����������          
    double hl();                  //�����������ʽֵ   
	double Trace();               //�������ļ�

	MAT ChildMAT(int row1,int rank1,int row2,int rank2);  
	                              //����row1-row2��rank1-rank2���Ӿ���
	MAT ChildMAT(int row,int rank);
	                              //����(row,rank)Ԫ�ص��Ӿ���
    MAT _row(int i);              //ȥ����i�й����¾���
    MAT _rank(int i);             //ȥ����i�й����¾���
	MAT _row_rank(int i,int j);   //ȥ����i�к͵�j�й����¾���
	
  private:                        //˽�г�Ա���� 
    int row;                      //���������
	int rank;                     //���������
    double *elem;                 //����Ԫ�أ�һά��̬���飩
	
	MAT inverse1();               //������������ͨ�������ֱ�ӱ任��
	void SetRR();                 //����row��rank��ֵ���þ������������Ԫ�ظ�ֵΪ0
	bool exrow(int,int);          //�������������Ԫ��
	bool exrank(int,int);	      //�������������Ԫ��
};

//********************************************************************
//*************************�������Ա��������*************************
MAT & MAT:: operator +=(MAT &other)               //�������͵��ڲ���
{
      *this=*this+other;               // ��ǰ����=��ǰ����+other����
	  return *this;                    // ���ص�ǰ����
}
//********************************************************************
MAT MAT::_row(int ii)                           //ȥ����ii�й����¾���
{
	if(ii<0 || ii>row-1) 
	{
	  cout<<"MAT::_row(int ii)���󣺸���������ii����ԭ���������"<<endl;
	  return MAT(0,0);
	}
    MAT C(row-1,rank);                                 //�¾���������1
	for(int i=0;i<row;i++)
	  for(int j=0;j<rank;j++)
	  {
	    if(i<ii)
			C(i,j)=(*this)(i,j);
		else if(i==ii) 
			continue;                                 //ɾ����ii��Ԫ�� 
		else
			C(i-1,j)=(*this)(i,j);
	  }
	return C;
}
//********************************************************************
MAT MAT::_rank(int ii)                          //ȥ����ii�й����¾���
{
	if(ii<0 || ii>rank-1) 
	{
	  cout<<"MAT::_rank(int ii)���󣺸�������ii����ԭ���������"<<endl;
	  return MAT(0,0);
	}
     MAT C(row,rank-1);
	 for(int i=0;i<rank;i++)
	  for(int j=0;j<row;j++)
	  {
	    if(i<ii)
			C(j,i)=(*this)(j,i);
		else if(i==ii) 
			continue;                                 //ɾ����ii��Ԫ��
		else
			C(j,i-1)=(*this)(j,i);
	  }
	return C;
}
//********************************************************************
inline MAT MAT::_row_rank(int i,int j)    //ȥ����i�С���j�й����¾���
{
   MAT C=_row(i);                         // ɾ����i��Ԫ��                     
   return C._rank(j);                     // ɾ����j��Ԫ��
}
//********************************************************************
ostream & operator<<(ostream &ou,MAT& A)// �����������壨�����������
 {
    for(int i=0;i<A.row;i++)
	 {
		    ou<<"   ";
		   for(int j=0;j<A.rank;j++)
		    { 
			  if(fabs(A(i,j))>1E-10) 
			    ou<<" "<<A(i,j);                       // ���һ��Ԫ��
			  else 
			    ou<<" "<<0;  
		    }
		    ou<<endl;                                          // ����  
	 }
	ou<<endl;
   return ou;                                      // �������������
 }
//********************************************************************
 istream & operator >>(istream &in,MAT &A)               // ������ȡ��
 {
    for(int i=0;i<A.GetRow();i++)
     for(int j=0;j<A.GetRank();j++)  
	   in>>A(i,j);                                      // �������Ԫ��
	return in;                                          // ����������
 }
//********************************************************************
inline MAT::MAT()                                 //����δ֪�����ľ���	
{
       row=rank=0;                                   //������������Ϊ0
       elem=new double;                              //����Ϊ��̬����
	   *elem=0;                                      //�ñ�����ֵΪ0
}
//********************************************************************
inline MAT::~MAT()                                          //��������	
{  
   if(row+rank>0)
   delete [] elem;                             // �ͷž���Ԫ�ض�̬����
   else delete elem;
   elem=NULL;
}
//********************************************************************
bool MAT::operator ==(MAT &A)                  // �������Ƿ���ȵ��ж� 
{
  if(row!=A.row || rank!=A.rank)	
	 return false;                         // �������������������
  for(int i=0;i<row;i++)
    for(int j=0;j<rank;j++)
	  if(fabs(GetElem(i,j)-A(i,j))>1E-12)
			  return false;                // Ԫ�ز������������
	  return true;                         // �������������
}
//********************************************************************
inline int MAT::GetRow()                                //���ؾ�������   
{
	 return row;                                   // ���ص�ǰ��������
}
//********************************************************************
inline int MAT::GetRank()                               //���ؾ�������   
{
   return rank;                                    // ���ص�ǰ��������
}
//********************************************************************
inline void MAT::GetRR(int &row,int &rank)         // ���ؾ����С�����
{
    row=this->row;                                 // �õ���ǰ��������
	rank=this->rank;                               // �õ���ǰ��������
} 
//********************************************************************
double MAT::Trace()                                    // �������ļ�
{
    if( row!=rank ) return UNK;                  // �Ƿ������������
	double S=0;                                  // ���巵������
	for(int i=0;i<row;i++)
	S+=GetElem(i,i);                             // ����Խ���Ԫ��֮��
	return S;
}
//********************************************************************
void MAT::SetRR()                                      // ���þ������
{
   delete [] elem;                             // �ͷž���Ԫ�ض�̬����
   elem=NULL;
   elem = new double[row*rank];                // �¿����ڴ�ռ�
   Set0();                                     // �¾���Ԫ��ȫ����Ϊ��
}  
//********************************************************************
inline void MAT::SetRow(int h)                          //���þ�������   
{
	row=h;                                              //������ֵ
	SetRR();                                            //���·���ռ�
}
//********************************************************************
inline void MAT::SetRank(int l)                         //���þ������� 
{
	rank=l;                                             //������ֵ
    SetRR();                                            //���·���ռ�
}
//********************************************************************
void MAT::SetRR(int row,int rank)                   //���þ����С�����
{
	this->row=row; 
	this->rank=rank;                                   // �����С�����
	SetRR();                                           // �����ڴ�ռ�
}
//********************************************************************	
class node{              //����ࣨ�ھ���������㺯��inverse1()��ʹ�ã�
     public:  
        int dat1;                                      //����������1 
		int dat2;                                      //����������2
   		node(int d1=0,int d2=0);
};
// ********node���Ա��������*****************************************
inline node::node(int d1,int d2)
{
	dat1=d1;
	dat2=d2;
}
//********************************************************************	
class stack{               //ջ�ࣨ�ھ���������㺯��inverse1()��ʹ�ã�
   public:
	node *SZ;                                       //����ջ�����ָ��                               
	stack(){i=0;SZ=new node[1];}
	~stack(){delete []SZ;SZ=NULL;}
	void push(int,int);                                 //����ѹ�뺯��
    node pop();                                         //���嵯������
	int i;
};
// ********stack���Ա��������****************************************
void stack::push(int t1,int t2)
{   
	node New_node(t1,t2);        // �����½ڵ�
    node *LS=new node[i];
    for(int j=0;j<i;j++)
		LS[j]=SZ[j];
	delete []SZ;                 // ɾ��ԭ�ڵ�����
	SZ=NULL;
    SZ=new node[i+1];            // �����½ڵ�����
	for(int j=0;j<i;j++)
	  {
		  SZ[j]=LS[j];	             // ����ԭ�ڵ�����
	}
	delete []LS;
	LS=NULL;
	SZ[i]=New_node;              // �����½ڵ�
    i++;
}
//********************************************************************
node stack::pop()
{
    if(i) 
	{
		i--;
		return SZ[i];
	}
    return node(0,0);   
}
//********************************************************************	
double & MAT::GetElem(int h,int l)                 // ���ؾ���Ԫ�ص�ֵ
{
    if(h>row-1 || h<0 )
	{
	  cout<<" MAT::GetElem(int h, int l)����: ��������h���ޣ�"<<endl;
	  exit(1);	
	}
	if(l>rank-1 || l<0 )
	{
	  cout<<" MAT::GetElem(int h, int l)����: ��������l���ޣ�"<<endl;
	  exit(1);
	}
	return elem[l+h*rank];  
}
//**********************************************************************	
double & MAT:: operator () (int h,int l)          //���ؾ����Ӧλ��Ԫ�� 
{
    return GetElem(h,l);                         // ����h��l��Ӧλ��Ԫ��
}
//**********************************************************************
void MAT::SetElem(int h,int l,double m)                   //���þ���Ԫ��
{   
    GetElem(h,l)=m;                              // h��l��Ӧλ��Ԫ�ظ�ֵ
}
//**********************************************************************	
void MAT::SetALL()                                //���������������Ԫ��
{
    cout<<"����("<<row<<"*"<<rank<<")����Ԫ��:"<<endl;
    for(int i=0;i<row*rank;i++)
     cin>>elem[i];                              //����Ļ��һ�������Ԫ��
}
//**********************************************************************	
bool MAT::CheckI()                                  //�жϾ����Ƿ�λ�� 
{ 
	if(row!=rank)
		return false;                                      // �Ƿ����ж�            
	for(int i=0;i<row;i++)
     for(int j=0;j<rank;j++)
	 { 
	   if(i==j && fabs(GetElem(i,j)-1)>1E-10) 
		   return false;                               // ����Ԫ�����ж�
	   if(i!=j && fabs(GetElem(i,j))>1E-10) 
		   return false;                                  // ��Ԫ��1�ж�
	 } 
   return true;
}
//**********************************************************************	
MAT & MAT::operator = ( MAT &other)                    // ����Ծ���ֵ
{	
//1 ����Ը�ֵ
		if(this == &other)
			return *this;
//2 �ͷ�ԭ�е��ڴ���Դ
  if(row+rank>0)
     delete [] elem;                              // �ͷž���Ԫ�ض�̬����
  else
     delete elem;                                      // �ͷ�ԭ�ڴ�ռ�
  elem=NULL;
		row=other.row;
		rank=other.rank;
//3 �����µ��ڴ���Դ������������
	elem = new double[row*rank];
		for(int i=0;i<row*rank;i++)
	    	elem[i]=other.elem[i];                      //����Ԫ��ֵ����		
//4 ���ص�ǰ����
	return *this;
}	
//**********************************************************************	
void MAT::Set1()                                   //���þ�������Ԫ��Ϊ1
{
	for(int i=0;i<row*rank;i++)
	  elem[i]=1;                                   //����Ԫ��ֵ������Ϊ1              
}
//**********************************************************************	
void MAT::Set0()                                   //���þ�������Ԫ��Ϊ0
{
	for(int i=0;i<row*rank;i++)
	  elem[i]=0;
}
//**********************************************************************	
void MAT::SetI()                                      //���þ���Ϊ��λ��
{
	if(row!=rank)
	{
		cout<<"MAT::SetI()���󣺵�ǰ����Ƿ���"<<endl;
	    exit(1);
	}
	for(int i=0;i<row;i++)
	  for(int j=0;j<rank;j++)
		if(i==j)
			SetElem(i,j,1);                            //�Խ���Ԫ����Ϊ1
		else 
			SetElem(i,j,0);                          //�ǶԽ���Ԫ����Ϊ0
}
//**********************************************************************	
void MAT::print()                                      // �������Ļ���
{
	cout<<endl;                                                  // ����
		for(int i=0;i<row;i++)
		{
		    cout<<"   ";
		   for(int j=0;j<rank;j++)
		   	{ 
			  if(fabs(GetElem(i,j))>1E-10) 
			    cout<<" "<<GetElem(i,j);                  // ���һ��Ԫ��
			  else 
			    cout<<" "<<0;  
		    }
		    cout<<endl;                                          // ����  
		}
	cout<<endl;
}
//**********************************************************************	
MAT::MAT( MAT &S)                                   //������ʼ�����캯��
{
     row=S.row;
     rank=S.rank;                                        // ������ȸ�ֵ
       elem=new double[row*rank];                      // �������ڴ�ռ�
        for(int i=0;i<row*rank;i++)
	     elem[i]=S.elem[i];                              // ����Ԫ�ظ�ֵ
}		
//**********************************************************************	
MAT::MAT(int hang,int lie)                        //����ȷ���������ľ���
{
   	row=hang;
   	rank=lie;                                                // ȷ������
	elem=new double[hang*lie];                       // ����Ԫ�ض�̬����
    Set0();                                          // ����Ԫ�ظ�ֵΪ0
}
//**********************************************************************	
MAT::MAT(int hl)                                             // ���巽��
{
    elem=new double[hl*hl]; 
  	SetRR(hl,hl);
}
//**********************************************************************	
bool MAT::exrow(int row1,int row2)                  //�������������Ԫ��
{   
	if(row1<0 || row1>row)
    { 
	  cout<<"MAT::exrow(int row1,int row2) ����::������row1���ޣ�"<<endl;
	  return false;
	}
    if(row2<0 || row2>row) 
	{
	  cout<<"MAT::exrow(int row1,int row2) ����::������row2���ޣ�"<<endl;
      return false;
	}
	if(row1==row2) 
	  return true;
    for(int i=0;i<rank;i++) 
	{ 
	  double ex=GetElem(row1,i); 
      SetElem(row1,i,GetElem(row2,i));      
      SetElem(row2,i,ex);
   }
  return true;
}
//**********************************************************************	
bool MAT::exrank(int rank1,int rank2)               //�������������Ԫ��
{
	if(rank1<0 || rank1>rank)
	{
	  cout<<"MAT::exrank() ����::����rank1���ޣ�"<<endl;
	  exit(1);
	}
 	if(rank2<0 || rank2>rank) 
	{
	  cout<<"MAT::exrank() ����::����rank2���ޣ�"<<endl;
	  exit(1);
	}
	if(rank1==rank2) 
		return true;
    for(int i=0;i<row;i++) 
   {
	  double ex=GetElem(i,rank1);
      SetElem(i,rank1,GetElem(i,rank2));      
      SetElem(i,rank2,ex);
   }
    return true;
}
//**********************************************************************	
MAT MAT::T()                             //����ת�ã�����ֵΪת�ú����
{
	MAT C(rank,row);                                 // ����ת�ý������
	 for(int i=0;i<row;i++)
       for(int j=0;j<rank;j++)
	  	 C(j,i)=GetElem(i,j);                        // ����ת�þ����ֵ
	   return C;
}
//**********************************************************************	
MAT MAT::operator + (MAT &B)                      //������ͣ����غ;���
{   
    if(row!=B.GetRow() || rank!=B.GetRank())
	{ 
		cout<<"MAT::������Ӽ�����������������ͬ!"<<endl;
		return MAT(0,0);
	}
	MAT C(row,rank);                             //�������������
	for(int i=0;i<row*rank;i++)
	{
		C.elem[i]=this->elem[i]+B.elem[i];       //�����ӦԪ�����
	}
	return C;                                    //���ؽ������
}
//**********************************************************************	
MAT MAT::operator - (MAT &B)          // ����������Ĳ���󣨷��ز����
{
	if(row!=B.GetRow() || rank!=B.GetRank())
	{ 
		cout<<"MAT::��������������������������ͬ!"<<endl;
		return MAT(0,0);
	}
	MAT C(row,rank);                              //�������������
	for(int i=0;i<row*rank;i++)
	{
			C.elem[i]=this->elem[i]-B.elem[i];    //Ԫ�����
	}
	return C;                                     //���ؼ�����
}
//**********************************************************************	
MAT MAT::operator * (MAT &B)               // ������˼��㣬���ػ�����
{ 
   if(this->rank!=B.GetRow()) 
   {
	 cout<<"MAT::������˴���:����������������������! "<<endl;
     return MAT(0,0);
   }
	int Crow=this->row;
	int Crank=B.GetRank();
	int Brow=B.GetRow();
	MAT C(Crow,Crank);                                //�������������
 	C.Set0();
	for(int i=0;i<Crow;i++)
	 for(int j=0;j<Crank;j++)
	  for(int k=0;k<Brow;k++)
	  {
		C(i,j)+=this->GetElem(i,k)*B(k,j);            //����˻�����Ԫ��
	  }                                       	     
	return C;                                             //���ؽ������
}
//**********************************************************************	
MAT operator * (double A,MAT &B)           // ���˾�����㣬���ؽ������
{ 
	int Crow=B.GetRow();
	int Crank=B.GetRank();
	MAT C(Crow,Crank); 
	for(int i=0;i<(Crow*Crank);i++) 
	{
		C.elem[i]=A*B.elem[i];
	}
	return C;
}
//**********************************************************************	
MAT MAT::operator * (double B)              //����������㣬���ؽ������
{   
	 MAT A(row,rank);
  	 A=B*(*this); 
	 return A;
}
//**********************************************************************	
MAT MAT::operator / (double B)           // ������������㣬���ؽ������
{   
	if(B==0) 
	{
		cout<<"MAT::����������������ݴ��� :����Ϊ0��"<<endl;
	    return MAT(0,0);
	}
 	MAT C(row,rank); 
	 for(int i=0;i<(row*rank);i++) 
	 {
		C.elem[i]=this->elem[i]/B;
	 }
	 return C;
}
//**********************************************************************	
MAT MAT::inverse()                      //���б任����������㣬��������
{
  if(row!=rank || row==0)                             //�жϾ����Ƿ���
   { 
	 cout<<" MAT::inverse() ����: ��������Ƿ��� "<<endl;
	 return MAT(0,0);             // �������棬����0��
   }
   if(row>5)                         
    return inverse1();            //�������ϴ󣬲��þ���ֱ�ӱ任������
    MAT C(row,row);             
    C.SetI();	                  //���嵥λ��
	MAT A=*this;                  //����任����
	double MAXX,b;
	int h,m, i,j,k;
	m=row;
	for(i=0;i<m;i++)
	{  
		MAXX=0;
		   h=0;
		  if(fabs(A(i,i))<1E-10 && i<m-1)          // ������ԪΪ��Ĵ���
		  {
			  for(int l=i+1;l<m;l++)
			 if(fabs(A(l,i))>MAXX) 
			 { 
				 MAXX=fabs(A(l,i));       
                 h=l;                      // �ҵ���Ԫ��Ӧ�����Ԫ������
			 }
			 if(h!=i)
			  for(int k1=0;k1<m;k1++)
			  {
                A(i,k1)+=A(h,k1);
			    C(i,k1)+=C(h,k1);
			  }
		  }
	       if(fabs(A(i,i))<1E-13)                    // ��ԪΪ��
		   {
		     cout<<" MAT::inverse()����: ����������� ! "<<endl;
		     return MAT(0,0);                        // �������棬����0��
		   }
		b=A(i,i);	                       
		for(j=0;j<m;j++)                             // �����б任������
		{
			A(i,j)/=b;
			C(i,j)/=b;
        }
		for(j=0;j<m;j++)	   
		{  
			b=A(j,i);
			for(k=0;k<m;k++)
			if(i!=j) 
			{
				A(j,k)-=b*A(i,k);
				C(j,k)-=b*C(i,k);
			}
		}
	} 
    return C; 
}
//**********************************************************************	
MAT MAT::inverse1()                  // ����ֱ�ӱ任�����棬�����ٶȽϿ�
{
    MAT C=*this;                                     // ��������������
	stack exrow;
	for(int i=0;i<row;i++)
	{ 
	  int h=i;
	  double b=fabs(C(i,i));
		if(i<row-1)
		{
		  for(int j=i;j<row;j++)
		   if(fabs(C(j,i))>b)
		   {
		       h=j;
			   b=fabs(C(j,i));
		   }
		  if(h!=i)
		  {
			  C.exrow(h,i);
			  exrow.push(h,i);
		  }
		}  
    	if(fabs(C(i,i))<1E-13) 
		{
			cout<<"MAT::inverse1()����: ����������� !  \n";
			return MAT(0,0);          // �������棬����0��
		}
		double a=1/C(i,i);
		C(i,i)=a;
	   for(int j=0;j<row;j++)
        if(j!=i)
		{
			C(j,i)=-a*C(j,i);
		}
	   for(int j=0;j<row;j++)
	   {
		for(int k=0;k<row;k++)
		{
		 if(i!=k && j!=i)
		 {				
		   C(j,k)=C(j,k)+C(j,i)*C(i,k);			
		 }
		}
	   }
  		for(int j=0;j<row;j++)
		{
         if(j!=i)
		 {
			C(i,j)=a*C(i,j);
		 }
		}
	} 
    while(exrow.i)
    {
	    node p=exrow.pop();
		C.exrank(p.dat1,p.dat2);
	};
 	return C;
}
//**********************************************************************
int MAT::R()                                  //���������ȣ������ȵ�ֵ          
{    // ������������ͨ���б任��Ϊ�Խ�����ʽ��Ȼ�����Խ���Ԫ�ط������
   MAT C;
  if(row>rank) C=this->T();
   else C=*this;
   int row=C.GetRow();   
   int rank=C.GetRank();
  
   double b,js(0);
   int h,Z(row),i,j,k;
	for(i=0;i<row;i++)
     {
		h=i;
		b=fabs(C(i,i));

		  if(b<1E-8)                                 //����ԪΪ��Ĵ���
		    for(int l=i+1;l<row;l++)
			 if(fabs(C(l,i))>b)
			 {
		        h=l;
				b=fabs(C(l,i));
             }
			if(h!=i) C.exrow(h,i);
	       	if(fabs(C(i,i))<1E-12) 
			{ 
				Z--;
				continue;
			} 
	        for(j=i+1;j<row;j++)
			{
			   b=C(j,i)/C(i,i);
	           for(k=0;k<rank;k++) 
			   {
			     C(j,k)-=b*C(i,k);                         // �����б任
			   }
			}
	  }
	return Z;	 
}	  
//**********************************************************************	
double MAT::hl()                        //�����������ʽ����������ʽ��ֵ  
{      // ������������ͨ���б任��Ϊ�Խ�����ʽ��Ȼ�����Խ���Ԫ�صĳ˻�
  if(row!=rank) 
  { 
	  cout<<"����ʽ���㺯��MAT::hl(MAT &A)���󣺼������Ƿ���"<<endl;
      return UNK;
  }
  MAT C=(*this);
  double b;
  int i,j,k;
	for(i=0;i<row;i++)
      for(j=i+1;j<row;j++)
      { 
		  if(fabs(C(i,i))<1E-8)               //����ԪΪ��Ĵ���
		    for(int l=i+1;l<row;l++)          //��ԪΪ��ʱ����������Ԫ��
			 if(C(l,i)!=0)                    //����Ԫ�ض�Ӧ�м�����Ԫ��
			 {
				 for(int k1=0;k1<rank;k1++)
                   C(i,k1)+=C(l,k1);
			        break;
			 }
		   if(fabs(C(i,i))<1E-12)             //�������Ԫ��Ϊ��
		   {  
			  return 0;						  //������ʽֵΪ��			  
		   }
		    b=C.GetElem(j,i)/C(i,i);          //����j�ж���Ԫ�ı���
	        for(k=0;k<rank;k++) 
			if(i!=j) 
			{
			  C(j,k)-=b*C(i,k);               //�����ݷ���Ԫλ�ñ�Ϊ��
			}
	  }
	  b=1.0;
	  for(i=0;i<row;i++) b*=C(i,i);           //����Խ���Ԫ�س˻�
      return b;
}
//**********************************************************************
MAT MAT::ChildMAT(int row1,int rank1,int row2,int rank2)    
// ��B(row1,rank1)~rank(row2,rank2)�����¾���
{
    if(row1<0 || row1>row)
	{
		cout<<"MAT::ChildMAT() ���� : ��ʼ����row1���ޣ� "<<endl;
	    return MAT(0,0);
	}
    if(row2<0 || row2>row) 
	{
		cout<<"MAT::ChildMAT() ���� : ��ֹ����row2���ޣ� "<<endl;
	    return MAT(0,0);
	}
    if(rank1<0 || rank1>rank) 
	{
		cout<<"MAT::ChildMAT() ���� : ��ʼ����rank1���ޣ� "<<endl;
	    return MAT(0,0);
	}
    if(rank2<0 || rank2>rank) 
	{
		cout<<"MAT::ChildMAT() ���� : ��ֹ����rank2���ޣ� "<<endl;
	    return MAT(0,0);
	}
    if(row1>row2) 
	{
		cout<<"MAT::ChildMAT() ���� : ��ʼ����row1>��ֹ����row2��"<<endl;
		return MAT(0,0);
	}
    if(rank1>rank2) 
	{
		cout<<"MAT::ChildMAT() ���� : ��ʼ����rank1>��ֹ����rank2��"<<endl;
		return MAT(0,0);
	}
	int row;
	row=row2-row1+1;
	int rank;
	rank=rank2-rank1+1;
	MAT C(row,rank);
	for(int i=row1;i<row+row1;i++)
		for(int j=rank1;j<rank+rank1;j++)
			C.SetElem(i-row1,j-rank1,GetElem(i,j));
	return C;
}

//**********************************************************************	
MAT MAT::ChildMAT(int row,int rank)        // ����(row,rank)Ԫ�ص��Ӿ���
{
	MAT B=*this;
    if(row<0 || row>B.GetRow()) 
	{
	  cout<<"MAT::ChildMAT(int row,int rank)��������row���ޣ�"<<endl;
		 return MAT(0,0);
	}
    if(rank<0 || rank>B.GetRank()) 
	{
	 cout<<"MAT::ChildMAT(int row,int rank)��������rank���ޣ�"<<endl;
		 return MAT(0,0);
	}
 	MAT C((B.GetRow()-1),(B.GetRank()-1)); 
	for(int i=0;i<row;i++)
	 for(int j=0;j<rank;j++)
	   C.SetElem(i,j,B(i,j));
	for(int i=row+1;i<B.GetRow();i++)
	 for(int j=rank+1;j<B.GetRank();j++)
	  C.SetElem(i-1,j-1,B(i,j));
    for(int i=0;i<row;i++)
	 for(int j=rank+1;j<B.GetRank();j++)
	  C.SetElem(i,j-1,B(i,j));
	for(int i=row+1;i<B.GetRow();i++)
	 for(int j=0;j<rank;j++)
	  C.SetElem(i-1,j,B(i,j));
	return C;		
}
//**********************************************************************
#endif
