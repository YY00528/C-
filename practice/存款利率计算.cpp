#include<iostream>
#include<stdlib.h> 
#include<cmath>
using namespace std;
int main ()
{
	double money,year,rate,sum;
	int flag=1;
	cout<<"��ӭʹ�����ʼ�����^0^"<<endl; 
	while(flag!=0)
	{
		cout<<"���������"<<endl;
		cin>>money;
		cout<<"�����������ޣ�"<<endl;
		cin>>year;
		cout<<"�����뵱ǰ�����ʣ�"<<endl;
		cin>>rate;
		sum=money*(pow((1+rate),year));
		cout<<"��ϢΪ��"<<sum<<endl;
		cout<<"��Ҫ����������1����������0  ^0^ " <<endl;
		cin>>flag;
		system("cls");
	}
	system("cls");
	cout<<endl;
	cout<<"ллʹ�ã��ټ���"<<endl; 
	return 0;
}
