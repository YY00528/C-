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
	void inputLesson1(ifstream&lin);//�����������
	void printLesson();//��ӡ�γ�
	void printLesson2();//c����
	void printLesson1(ofstream&lout);//�����������
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
	//cout<<"ѡ������:";cin>>Lperson;
}
void TLesson::inputLesson1(ifstream&lin)//�����������
{
	lin>>Lname>>Lnote>>Ltime>>Lgrade>>Ldata;//>>Lperson
}
void TLesson::printLesson()
{
	cout<<setw(10)<<Lno<<setw(10)<<Lname<<setw(12)<<Lnote<<setw(10)<<Ltime<<setw(10)<<Lgrade<<setw(10)<<Ldata<<setw(10)<<Lperson<<setw(10)<<endl;
}
void TLesson::printLesson2()
{
	cout<<setw(10)<<Sno<<setw(10)<<Lno<<setw(10)<<Lname<<setw(12)<<Lnote<<setw(10)<<Ltime<<setw(10)<<Lgrade<<setw(10)<<Ldata<<setw(10)<<endl;
}
void TLesson::printLesson1(ofstream&lout)//�����������
{
	lout<<Lno<<setw(10)<<Lname<<setw(10)<<Lnote<<setw(5)<<Ltime<<setw(5)<<Lgrade<<setw(5)<<Ldata<<setw(5)<<Lperson<<setw(5)<<endl;
}
class TStudent
{
	friend class Student_arr;//ѧ���γ�����
public:
	void inputStudent();//����
	void inputStudent1(ifstream&lin);//�����������
	void printStudent();//��ӡѧ����Ϣ
	void printStudent1(ofstream&lout);//�����������
private:
	int Snum;//ѧ��
	char Sname[20];//����
	char Ssex[2];//�Ա�
	int  Sage;//����
	char dept[20];//ϵ��
	int  classno;//�༶
	char phonenum[20];//��ϵ��ʽ
};
void TStudent::inputStudent()
{
	cout<<"ѧ��:";cin>>Snum;
	cout<<"����:";cin>>Sname;
	cout<<"�Ա�:";cin>>Ssex;
	cout<<"����:";cin>>Sage;
	cout<<"ϵ��:";cin>>dept;
	cout<<"�༶:";cin>>classno;
	cout<<"��ϵ��ʽ:";cin>>phonenum;
}
void TStudent::inputStudent1(ifstream&lin)
{
	lin>>Snum>>Sname>>Ssex>>Sage>>dept>>classno>>phonenum;
}
void TStudent::printStudent()
{
	cout<<setw(10)<<Snum<<setw(10)<<Sname<<setw(12)<<Ssex<<setw(10)<<Sage<<setw(10)<<dept<<setw(10)<<classno<<setw(10)<<phonenum<<endl;
}
void TStudent::printStudent1(ofstream&lout)
{
	lout<<Snum<<" "<<Sname<<" "<<Ssex<<" "<<Sage<<" "<<dept<<" "<<classno<<" "<<phonenum<<" "<<endl;
}
class Student_arr//������
{
	friend class TStudent;
	friend class TLesson;
public:
	Student_arr()
	{
		int i=0;
		LS=0;
		lin.open("Student.txt",ios::in);
		pb=new TStudent[30];//����ѧ������
		//while(!lin.eof())
		for(i=0;i<0;i++)
		{
			//lin.getline((pb+i),sizeof(pb));
			//i++;
			//LS++;
			lin>>(pb+i)->Snum;
			if((pb+i)->Snum==-1)
				break;
			else{
				(pb+i)->inputStudent1(lin);
				LS++;
			}
		}
		lin.close();
	}
	Student_arr(int a)
	{
		int i;
		L=0;
		lin.open("Lesson.txt",ios::in);
		p=new TLesson[30];//����γ�����
		for(i=0;i<0;i++)
		{
			lin>>(p+i)->Lno;
			if((p+i)->Lno==-1)
				break;
			else{
				(p+i)->inputLesson1(lin);
				L++;
			}
		}
		lin.close();
	}
	Student_arr(int a,int b)
	{
		int i;
		L=0;
		lin.open("S_Lesson.txt",ios::in);
		p=new TLesson[30];//����ѧ��ѡ�ογ�����
		for(i=0;i<0;i++)
		{
			lin>>(p+i)->Sno;
			if((p+i)->Sno==-1)
				break;
			else{
				lin>>(p+i)->Lno;
				(p+i)->inputLesson1(lin);
				L++;
			}
		}
		lin.close();
	}
	void Print();//���ѧ������
	void Print1();//����γ�����
	void Print2();//���ѡ������
	void lessonInsert();//¼��γ���Ϣ
	void studentInsert();//¼��ѧ����Ϣ
	void search_by_grade();//��ѧ�ֲ�ѯ
	void search_by_Lname();//���γ�����ѯ
	TLesson search_by_Lno();//���γ̺Ų�ѯ
	void search_sdudent_by_Snum();//��ѧ�Ų�ѯѧ��
	void search_sdudent_by_Sname();//��������ѯѧ��
	void search_by_Sno(Student_arr&c);////��ѧ����ѯ��ѡ�޵Ŀγ�
	int  total_grade(int i);//����ĳѧ������ѧ�� 
	void  choose(Student_arr&a,Student_arr&b,Student_arr&c);//ʵ��ѡ�ι���
	void deleteLesson(Student_arr&c);//ɾ���γ̼�¼
	void deleteStudent(Student_arr&b,Student_arr&c);//ɾ��ѧ����¼
	void reviseLesson();//�޸Ŀγ̼�¼
	void reviseLesson(int);//�޸Ŀγ̼�¼
	void reviseStudent();//�޸�ѧ����¼
	int  GetLS()//��ȡѧ����
		{return LS;}
	int  GetL()//��ȡ�γ���
		{return L;}
	void sdudent_save();//����student�ļ�
	void Lesson_save();//����lesson�ļ�
	void S_L_save();//����ѡ����Ϣ�ļ�
private:
		int L,LS;//����
		ifstream lin;//������
		ofstream lout;//�����
		TLesson  *p;//�γ������ַ
		TStudent *pb;//ѧ�������ַ
};
void Student_arr::Print()//���ѧ������
{
	int i;
	//cout<<setw(10)<<Snum<<setw(10)<<Sname<<setw(12)<<Ssex<<setw(10)<<Sage<<setw(10)<<dept<<setw(10)<<classno<<setw(10)<<phonenum<<endl;
	cout<<setw(10)<<"ѧ��"<<setw(10)<<"����"<<setw(12)<<"�Ա�"<<setw(10)<<"����"<<setw(10)<<"ϵ��"<<setw(10)<<"�༶"<<setw(10)<<"��ϵ��ʽ"<<endl;
	for(i=0;i<LS;i++)
		(pb+i)->printStudent();
}
void Student_arr::Print1()//����γ�����
{
	int i;
	//cout<<setw(10)<<Lno<<setw(10)<<Lname<<setw(12)<<Lnote<<setw(10)<<Ltime<<setw(10)<<Lgrade<<setw(10)<<Ldata<<setw(10)<<Lperson<<setw(10)<<endl;
	cout<<setw(10)<<"�γ̴���"<<setw(10)<<"�γ�����"<<setw(12)<<"�γ�����"<<setw(10)<<"��ѧʱ"<<setw(10)<<"ѧ��"<<setw(10)<<"����ѧ��"<<setw(10)<<"ѡ������"<<endl;
	for(i=0;i<L;i++)
		(p+i)->printLesson();
}
void Student_arr::Print2()//���ѡ������
{
	int i;
	cout<<setw(10)<<"ѡ��ѧ��"<<setw(10)<<"�γ̴���"<<setw(10)<<"�γ�����"<<setw(12)<<"�γ�����"<<setw(10)<<"��ѧʱ"<<setw(10)<<"ѧ��"<<setw(10)<<"����ѧ��"<<endl;
	for(i=0;i<L;i++)
		(p+i)->printLesson2();
}
void Student_arr::lessonInsert()//¼��γ���Ϣ
{
	int i=0,flag=0;
	(p+L)->inputLesson();//������Ϣ¼�룬����¼�����Ϣ��������ĩβ
	(p+L)->Lperson=0;
	for(i=0;i<L;i++)
	if(((p+i)->Lno==((p+L)->Lno))||(strcmp((p+i)->Lname,((p+L)->Lname))==0)){
		(p+i)->printLesson();
		flag=1;
	}
	if(flag!=1){
		L++;
		cout<<"��ӳɹ�����\n";
	}
	else if(1==flag)
		cout<<"�Ѵ�������ӵĿγ�,���ʧ�ܣ���\n";
}
void Student_arr::studentInsert()//¼��ѧ����Ϣ
{
	int i=0,flag=0;
	(pb+LS)->inputStudent();//������Ϣ¼�룬����¼�����Ϣ��������ĩβ
	for(i=0;i<LS;i++)
		if((pb+i)->Snum==((pb+LS)->Snum)){
			(pb+i)->printStudent();
			flag=1;
		}
	if(flag!=1){
		LS++;
		cout<<"��ӳɹ�����\n";
	}
	else if(1==flag)
		cout<<"�Ѵ�������ӵ�ѧ��,���ʧ�ܣ���\n";
}
void Student_arr::search_by_grade()//��ѧ�ֲ�ѯ�γ�
{
	int k,i;
	cout<<"������ѧ��ֵ��";
	cin>>k;
	for(i=0;i<L;i++)
		if((p+i)->Lgrade==k){
			(p+i)->printLesson();
			return;
		}
	cout<<"δ�ҵ�������"<<endl;
}
void Student_arr::search_by_Lname()//���γ�����ѯ
{
	int i;
	char k[20];
	cout<<"������γ�����";
	cin>>k;
	for(i=0;i<L;i++)
		if(strcmp((p+i)->Lname,k)==0){
			(p+i)->printLesson();
			return;
		}
	cout<<"δ�ҵ�������"<<endl;
}
TLesson Student_arr::search_by_Lno()//���γ̺Ų�ѯ
{
	int k,i;
	cout<<"������γ̺ţ�";
	cin>>k;
	for(i=0;i<L;i++)
		if((p+i)->Lno==k){
			(p+i)->printLesson();
			return *(p+i);
		}
	cout<<"δ�ҵ�������"<<endl;
}
void Student_arr::search_by_Sno(Student_arr&c)//��ѧ����ѯ��ѡ�޵Ŀγ�
{
	int k,i;
	TLesson *b=c.p;
	cout<<"�����������ѯ��ѧ����ѧ�ţ�";
	cin>>k;
	cout<<setw(10)<<"ѧ��"<<setw(10)<<"����"<<setw(12)<<"�Ա�"<<setw(10)<<"����"<<setw(10)<<"ϵ��"<<setw(10)<<"�༶"<<setw(10)<<"��ϵ��ʽ"<<endl;
	for(i=0;i<LS;i++)
		if((pb+i)->Snum==k){
			(pb+i)->printStudent();
		}
	cout<<setw(10)<<"ѡ��ѧ��"<<setw(10)<<"�γ̴���"<<setw(10)<<"�γ�����"<<setw(12)<<"�γ�����"<<setw(10)<<"��ѧʱ"<<setw(10)<<"ѧ��"<<setw(10)<<"����ѧ��"<<endl;
	for(i=0;i<c.L;i++)
		if((b+i)->Sno==k){
			(b+i)->printLesson2();
		}
}
void Student_arr::search_sdudent_by_Snum()//��ѧ�Ų�ѯѧ��
{
	int k,i;
	cout<<"�����������ѯ��ѧ�ţ�";
	cin>>k;
	cout<<setw(10)<<"ѧ��"<<setw(10)<<"����"<<setw(12)<<"�Ա�"<<setw(10)<<"����"<<setw(10)<<"ϵ��"<<setw(10)<<"�༶"<<setw(10)<<"��ϵ��ʽ"<<endl;
	for(i=0;i<LS;i++)
		if((pb+i)->Snum==k){
			(pb+i)->printStudent();
			return;
		}
	cout<<"δ�ҵ�������"<<endl;
}
void Student_arr::search_sdudent_by_Sname()//��������ѯѧ��
{
	int i;
	char k[20];
	cout<<"�����������ѯ��ѧ��������";
	cin>>k;
	cout<<setw(10)<<"ѧ��"<<setw(10)<<"����"<<setw(12)<<"�Ա�"<<setw(10)<<"����"<<setw(10)<<"ϵ��"<<setw(10)<<"�༶"<<setw(10)<<"��ϵ��ʽ"<<endl;
	for(i=0;i<LS;i++)
		if(strcmp((pb+i)->Sname,k)==0){
			(pb+i)->printStudent();
			return;
		}
	cout<<"δ�ҵ�������"<<endl;
}
int Student_arr::total_grade(int i)//����ĳѧ������ѧ��
{
	int k,j=0;
	for(k=0;k<L;k++)
		if(p[k].Sno==i)
			j=j+p[k].Lgrade;
	return j;
}
void  Student_arr::choose(Student_arr&a,Student_arr&b,Student_arr&c)//ѡ�ι���ʵ��
{
	int i,k,j,fflag=0,m;
	char flag='y';
	TLesson l1;
	cout<<"���������ѧ�ţ�";
	cin>>j;
	for(i=0;i<=a.LS;i++)
	if((a.pb+i)->Snum==j){
		fflag=1;
	}
	if(0==fflag){
		cout<<"ѧ���������󣡣���\n";
		return ;
	}
	while(flag=='y'||flag=='Y')
	{
		cout<<"�γ��б�\n";
		b.Print1();
		l1=b.search_by_Lno();//ѡ��
		l1.Sno=j;//��ѧ����������
		i=0;
		do{
			if(((c.p+i)->Lno==l1.Lno)&&((c.p+i)->Sno==l1.Sno))
				{
					cout<<"����ѡ�޹��˿γ̣�������ѡ�������γ�\n";
					return;
				}
			i++;
		}while(i<=c.L);
		c.p[L]=l1;//���ڵ�����γ�����
		L++;
		k=total_grade(j);
		cout<<"��ǰѧ��Ϊ"<<k<<endl;;
		cout<<"����ѡ��������y����������n��";
		cin>>flag;
		if('y'!=flag&&'Y'!=flag&&'n'!=flag&&'N'!=flag)return;
		b.reviseLesson(l1.Lno);
	}
	return ;
}
void Student_arr::deleteLesson(Student_arr&c)//ɾ���γ̼�¼
{
	int k,i,j,m,flag=0;
	cout<<"����������ɾ���Ŀγ̺ţ�";
	cin>>k;
	for(i=0;i<L;i++){
		if((p+i)->Lno==k){
			for(j=i;j<L-1;j++)
			{
				*(p+j)=*(p+j+1);
			}
			L--;
			for(j=0;j<=c.L+1;j++)
			{
				if(((c.p+j)->Lno)==k)
				{
					for(m=0;m<c.L+1;m++)
					{
						*(c.p+j+m)=*(c.p+j+m+1);
					}
					c.L--;
				}
			}
			for(j=0;j<=c.L+1;j++)
			{
				if(((c.p+j)->Lno)==k)
				{
					for(m=0;m<c.L+1;m++)
					{
						*(c.p+j+m)=*(c.p+j+m+1);
					}
					c.L--;
				}
			}
			flag=1;
		}
	}
	if(1==flag){
		cout<<"ɾ���ɹ�����\n";
		return ;
	}
	else if(0==flag)
		cout<<"��¼Ϊ�գ���\n";
}
void Student_arr::deleteStudent(Student_arr&b,Student_arr&c)//ɾ��ѧ����¼
{
	int k,i,j,m,n;
	cout<<"����������ɾ��ѧ����¼��ѧ�ţ�";
	cin>>k;
	for(i=0;i<LS;i++)
		if((pb+i)->Snum==k){
			for(j=i;j<LS-1;j++)
			{
				*(pb+j)=*(pb+j+1);
			}
			LS--;
			for(j=0;j<=c.L;j++)
			{
				if((c.p+j)->Sno==k)
				{
					for(n=0;n<b.L;n++)
						if(((b.p+n)->Lno)==((c.p+i)->Lno)){
							(b.p+n)->Lperson--;
						}
					for(m=0;m<c.L;m++)
					{
						*(c.p+m)=*(c.p+m+1);
					}
					j=0;
					c.L--;
				}
			}
			for(j=0;j<=c.L;j++)
			{
				if((c.p+j)->Sno==k)
				{
					for(n=0;n<b.L;n++)
						if(((b.p+n)->Lno)==((c.p+i)->Lno)){
							(b.p+n)->Lperson--;
						}
					for(m=0;m<c.L;m++)
					{
						*(c.p+m)=*(c.p+m+1);
					}
					j=0;
					c.L--;
				}
			}
			cout<<"ɾ���ɹ�����\n";
			return;
		}
	cout<<"��¼Ϊ�գ���\n";
}
void Student_arr::reviseLesson()//�޸Ŀγ̼�¼
{
	int k,i,j,flag=0;
	cout<<"�����������޸ĵĿγ̺ţ�";
	cin>>k;
	for(i=0;i<L;i++)
		if((p+i)->Lno==k){
			(p+L)->inputLesson();
			for(j=0;j<L;j++)
			if(((p+j)->Lno==((p+L)->Lno))||(strcmp((p+j)->Lname,((p+L)->Lname))==0)){
				(p+j)->printLesson();
				flag=1;
			}
			if(flag!=1){
				*(p+i)=*(p+L);
				cout<<"�޸ĳɹ�����\n";
			}
			else if(1==flag)
				cout<<"�Ѵ������޸ĵĿγ�,�޸�ʧ�ܣ���\n\n";
			return ;
		}
	cout<<"��¼Ϊ�գ���\n";
}
void Student_arr::reviseLesson(int k)//�޸Ŀγ�ѡ������
{
	int i;
	for(i=0;i<L;i++)
		if((p+i)->Lno==k){
			(p+i)->Lperson++;
			return ;
		}
}
void Student_arr::reviseStudent()//�޸�ѧ����¼
{
	int k,i,j,flag=0;
	cout<<"�����������޸�ѧ����¼��ѧ�ţ�";
	cin>>k;
	for(i=0;i<LS;i++)
		if((pb+i)->Snum==k){
			(pb+LS)->inputStudent();
			for(j=0;j<LS;j++)
				if((pb+j)->Snum==((pb+LS)->Snum)){
					(pb+j)->printStudent();
					flag=1;
				}
			if(flag!=1){
				*(pb+i)=*(pb+LS);
				cout<<"�޸ĳɹ�����\n";
			}
			else if(1==flag)
				cout<<"�Ѵ������޸ĵ�ѧ����Ϣ,�޸�ʧ�ܣ���\n";
			return;
		}
	cout<<"��¼Ϊ�գ���\n";
}
void Student_arr::sdudent_save()//����student�ļ�
{
	int i,k=-1;
	lout.open("student.txt",ios::out);
	if(!lout)
	{
		cout<<"student.txt cannot open!\n";
		abort();
	}
	lout<<"//student�ļ�\n";
	for(i=0;i<LS;i++)
		(pb+i)->printStudent1(lout);
	lout<<k;
	lout.close();
}
void Student_arr::Lesson_save()//����lesson�ļ�
{
	int i,k=-1;
	lout.open("lesson.txt",ios::out);
	if(!lout)
	{
		cout<<"lesson.txt cannot open!\n";
		abort();
	}
	lout<<"//lesson�ļ�\n";
	for(i=0;i<L;i++)
		(p+i)->printLesson1(lout);
	lout<<k;
	lout.close();
}
void Student_arr::S_L_save()//����ѡ����Ϣ�ļ�
{
	int i,k=-1;
	lout.open("S_L.txt",ios::out);
	if(!lout)
	{
		cout<<"S_L.txt cannot open!\n";
		abort();
	}
	
	for(i=0;i<L;i++){
		lout<<(p+i)->Sno<<" ";
		(p+i)->printLesson1(lout);
	}
	lout<<k;
	lout.close();
}
int main ()
{
	Student_arr a,b(1),c(1,2);
	int i,j,k=1;
	cout<<"-------------------------ѧ��ѡ�޿γ̹���ϵͳ-------------------------"<<endl;
	for(;k==1;)
	{
		cout<<"1.�༭����\n";
		cout<<"2.��ѯ����\n";
		cout<<"3.��ʾ����\n";
		cout<<"4.�༭����\n";
		cout<<"5.ɾ������\n";
		cout<<"6.ѡ�ι���\n";
		cout<<"7.ͳ�ƹ���\n";
		cout<<"8.�˳�ϵͳ\n";
		cout<<"��ѡ��";
		cin>>i;
		switch (i)
		{
		case 1:cout<<"---------------------�༭����---------------------\n";
			cout<<"1.��ӿγ���Ϣ\n2.���ѧ����Ϣ\n";
			   cout<<"��ѡ��";
			   cin>>j;
			   if(1==j){
					   cout<<"��ӿγ���Ϣ\n";
					   b.lessonInsert();
			   }
			   else if(2==j){
					   cout<<"���ѧ����Ϣ\n";
					   a.studentInsert();
			   }
			   else
				   cout<<"�������󣡣���";
			   break;
		case 2:cout<<"---------------------��ѯ����-----------------------\n";
			   cout<<"1.�γ���Ϣ��ѯ\n2.ѧ����Ϣ��ѯ\n";
			   cout<<"��ѡ��";
			   cin>>j;
			   if(1==j){
					   cout<<"1.��ѧ�ֲ�ѯ\n2.���γ�����ѯ\n3.���γ̺Ų�ѯ\n4.��ѧ����ѯ��ѡ�޵Ŀγ�\n";
					   cout<<"��ѡ��";
					   cin>>j;
					   if(j==1){
						   cout<<"��ѧ�ֲ�ѯ\n";
						   b.search_by_grade();
					   }
					   else if(j==2){
						   cout<<"���γ�����ѯ\n";
					       b.search_by_Lname();
					   }
					   else if(j==3){
						   cout<<"���γ̺Ų�ѯ\n";
						   b.search_by_Lno();
					   }
					   else if(j==4){
						   cout<<"��ѧ����ѯ��ѡ�޵Ŀγ�\n";
						   a.search_by_Sno(c);
					   }
					   else
						   cout<<"�������󣡣���";
					   }
			   else if(2==j){
					   cout<<"1.��ѧ�Ų�ѯ\n2.��������ѯ\n";
					   cout<<"��ѡ��";
					   cin>>j;
					   if(1==j){
								cout<<"��ѧ�Ų�ѯѧ����Ϣ\n";
								a.search_sdudent_by_Snum();
					   }
					   else if(2==j){
								cout<<"��������ѯ\n";
								a.search_sdudent_by_Sname();
					   }
			   }
			   else
				   cout<<"�������󣡣���";
			   break;
		case 3:cout<<"---------------------��ʾ����-----------------------\n";
			   cout<<"1.��ʾ���пγ���Ϣ\n2.��ʾ����ѧ����Ϣ\n3.��ʾ����ѡ����Ϣ\n4.��ʾ������Ϣ\n";
			   cout<<"��ѡ��";
			   cin>>j;
			   if(1==j){
					   b.Print1();
			   }
			   else if(2==j){
					   a.Print();
			   }
			   else if(3==j){
					   c.Print2();
			   }
			   else if(4==j){
				       b.Print1();
					   a.Print();
					   c.Print2();
			   }
			   else
				   cout<<"�������󣡣���";
			   break;
		case 4:cout<<"---------------------�༭����-----------------------\n";
			   cout<<"1.�޸Ŀγ���Ϣ\n2.�޸�ѧ����Ϣ\n";
			   cout<<"��ѡ��";
			   cin>>j;
			   if(1==j){
					   b.reviseLesson();
			   }
			   else if(2==j){
					   a.reviseStudent();
			   }
			   else
				   cout<<"�������󣡣���";
			   break;
		case 5:cout<<"---------------------ɾ������-----------------------\n";
			   cout<<"1.ɾ���γ���Ϣ\n2.ɾ��ѧ����Ϣ\n";
			   cout<<"��ѡ��";
			   cin>>j;
			   if(1==j){
					   b.deleteLesson(c);
			   }
			   else if(2==j){
					   a.deleteStudent(b,c);
			   }
			   else
				   cout<<"�������󣡣���";
			   break;
		case 6:c.choose(a,b,c);
			   break;
		case 7:cout<<"---------------------ͳ�ƹ���-----------------------\n";
			   cout<<"��ǰѧ��������"<<a.GetLS()<<endl;
			   cout<<"��ǰ�γ�����"<<b.GetL()<<endl;
			   b.Print1();
			   break;
		case 8:k=0;break;
		default:cout<<"�������󣡣�\n";
		}
	}
	a.sdudent_save();
	b.Lesson_save();
	c.S_L_save();
	return 0;
}