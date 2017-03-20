#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
class TLesson
{
	friend class Student_arr;//ѧ���γ�����
public:
	void inputLesson();//����
	void inputLesson(ifstream&lin);//�������
	void printLesson();//��ӡ�γ�
	void printLesson(ofstream&lout);//�������
private:
	int  Sno;//ѧ��
	int  Lno;//�γ̴���
	char Lname[100];//�γ�����
	char Lnote[100];//�γ�����
	int  Ltime;//��ѧʱ
	int  Lgrade;//ѧ��
	int  Ldata;//����ѧ��
	int  Lperson;//ѡ������
};
void TLesson::inputLesson()
{
	cout<<"�γ̱��:";cin>>Lno;
	cout<<"�γ�����:";cin>>Lname;
	cout<<"�γ�����:";cin>>Lnote;
	cout<<"��ѧʱ:";cin>>Ltime;
	cout<<"ѧ��:";cin>>Lgrade;
	cout<<"����ѧ��:";cin>>Ldata;
	cout<<"ѡ������:";cin>>Lperson;
}
void TLesson::inputLesson(ifstream&lin)
{
	lin>>Lname>>Lnote>>Ltime>>Lgrade>>Ldata>>Lperson;
}
void TLesson::printLesson()
{
	cout<<Lno<<setw(10)<<Lname<<setw(12)<<Lnote<<setw(10)<<Ltime<<setw(10)<<Lgrade<<setw(10)<<Ldata<<setw(10)<<Lperson<<setw(10)<<endl;
}
void TLesson::printLesson(ofstream&lout)
{
	lout<<Lno<<setw(5)<<Lname<<setw(10)<<Lnote<<setw(5)<<Ltime<<setw(5)<<Lgrade<<setw(5)<<Ldata<<setw(5)<<Lperson<<setw(5)<<endl;
}


























//#include<iostream>
//#include<fstream>
//#include<stdlib.h>
//#define MAXSIZE 100;
//using namespace std;
//class TLesson
//{
//public:
//	void Lesson();//��ʼ��
//	void searchLesson(int Lno,char Lname[]);//��ѯ�γ�
//	void insertLesson(int Lno,char Lname[],char Lnote[],int Ltime,int Lgrade,int data,int Lperson);//��ӿγ�
//	void deletLesson();//ɾ���γ�
//	void printLesson();//��ӡ�γ�
//	void reviseLesson();//�޸Ŀγ���Ϣ
//private:
//	int Lno;//�γ̴���
//	char Lname[100];//�γ�����
//	char Lnote[100];//�γ�����
//	int  Ltime;//��ѧʱ
//	int  Lgrade;//ѧ��
//	int  Ldata;//����ѧ��
//	int  Lperson;//ѡ������
//};
//void TLesson::searchLesson(int Lno,char Lname[])//��ѯ�γ�
//{}
//void TLesson::insertLesson(int Lno,char Lname[],char Lnote[],int Ltime,int Lgrade,int data,int Lperson)//��ӿγ�
//{
//	fstream outfile;
//	outfile.open("Lesson.txt",ios::out);
//	if(!outfile)
//	{
//		cout<<"Lesson.txt cannot open!\n";
//		abort();
//	}
//	outfile<<"this is a Lesson manage system\n";
//	outfile<<"Lno\t"<<"Lname\t"<<"Lnote\t"<<"Ltime\t"<<"Lgrade\t"<<"Ldata\t"<<"Lperson\t"<<endl;
//	outfile<<Lno<<"\t"<<Lname<<"\t"<<Lnote<<"\t"<<Ltime<<"\t"<<Lgrade<<"\t"<<Ldata<<"\t"<<Lperson<<endl;
//	cout<<"Write OK!"<<endl;
//	outfile.close();
//}
//void TLesson::deletLesson()//ɾ���γ�
//{}
//void TLesson::printLesson()//��ӡ�γ�
//{
//	fstream infile;
//	infile.open("Lesson.txt",ios::in);
//	if(!infile)
//	{
//		cout<<"Lesson.txt cannot open!\n";
//		abort();
//	}
//	char s[80];
//	while(!infile.eof())
//	{
//		infile.getline(s,sizeof(s));
//		cout<<s<<endl;
//	}
//	cout<<"Read OK!"<<endl;
//	infile.close();
//}
//void TLesson::reviseLesson()//�޸Ŀγ���Ϣ
//{}