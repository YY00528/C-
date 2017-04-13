#include "LinkedList.h"

void menu()
{
	printf("************************************************\n");
	printf("*                                              *\n");
	printf("*     0. �˳�                                  *\n");
	printf("*     1. ͷ�巨��������                        *\n");//1
	printf("*     2. ͷɾ��ɾ������                        *\n");//1
	printf("*     3. β�巨��������                        *\n");//1
	printf("*     4. βɾ��ɾ������                        *\n");//1
	printf("*     5. ��ӡ����                              *\n");//1
	printf("*     6. ������                              *\n");//1
	printf("*     7. ɾ������Posλ�õ�Ԫ��                 *\n");//1
	printf("*     8. ɾ�������е�һ��ֵΪdata��Ԫ��        *\n");//1
	printf("*     9. ɾ������������ֵΪData��Ԫ��          *\n");//1
	printf("*     10.�������н��ĸ���                    *\n");//1
	printf("*     11.�����Ƿ�Ϊ��                          *\n");//1
	printf("*     12.�����ӡ����                          *\n");
	printf("*     13.ɾ��һ����ͷ����ķ�β���            *\n");
	printf("*     14.����ͷ����ǰ����һ�����              *\n");
	printf("*     15.������ʵ��Լɪ��                    *\n");
	printf("*     16.��������				               *\n");
	printf("*     17.ð������				               *\n");
	printf("*     18.�ϲ�������������                      *\n");
	printf("*     19.Ѱ���м�Ԫ��                          *\n");
	printf("*     20.Ѱ�ҵ�����k�����                     *\n");
	printf("*     21.�ж����������Ƿ��ཻ                  *\n");
	printf("*     22.�ж����������ཻ�Ľ���                *\n");
	printf("*                                              *\n");
	printf("************************************************\n");
	printf("��ѡ��->");
}

int main()
{
	PNode pHead=NULL;
	char ch='y';
	int  flag=0;
	DataType data=0,data1=0;
	int pos=0;
	InitList(&pHead);//��ʼ��˳���	
	while(ch=='y')
	{
		menu();
		scanf("%d",&flag);
		switch(flag)
		{
		case 0:
				ch=0;
				break;
		case 1:
				printf("���������ݣ�");
				scanf("%d",&data);
				PushFront(&pHead,data);
				PrintList(pHead);
				break;
		case 2:
				PopFront(&pHead);
				PrintList(pHead);
				break;
		case 3:
				printf("���������ݣ�");
				scanf("%d",&data);
				PushBack(&pHead,data);
				PrintList(pHead);
				break;
		case 4:
				PopBack(&pHead);
				PrintList(pHead);
				break;
		case 5:
				PrintList(pHead);
				break;
		case 6:
				printf("������Ҫ������λ�����ݣ�\n");
				scanf("%d",&data);
				printf("������Ҫ���������\n");
				scanf("%d",&data1);
				Insert( Find( &pHead,data),data1);
				PrintList(pHead);
				break;
		case 7:
				printf("������Ҫɾ�����λ�����ݣ�\n");
				scanf("%d",&data);
				Erase(&pHead,Find( &pHead,data));
				PrintList(pHead);
				break;
		case 8:
				printf("������Ҫɾ���Ľ������\n");
				scanf("%d",&data);
				Remove(&pHead,data);
				PrintList(pHead);
				break;
		case 9:
				printf("������Ҫɾ���Ľ������\n");
				scanf("%d",&data);
				RemoveAll(&pHead,data);
				PrintList(pHead);
				break;
		case 11:
				if(Empty(pHead))
				{
					printf("����Ϊ�գ�\n");
				}
				else
				{
					printf("����Ϊ�գ�\n");
				}
				break;
		case 10:
				printf("�����й���%d�����\n",Size(pHead));
				break;
		case 12:
				PrintListFromT2H(pHead);
				break;
		case 13:	
				printf("������Ҫɾ�����λ�����ݣ�\n");
				scanf("%d",&data);
				DeleteNotTail(Find( &pHead,data));
				PrintList(pHead);
				break;
		case 14:
				printf("������Ҫ������λ�����ݣ�\n");
				scanf("%d",&data);
				printf("������Ҫ���������\n");
				scanf("%d",&data1);
				InsertNotHead(pHead,Find( &pHead,data),data1);
				PrintList(pHead);
				break;
		case 15:
				JosephCircle(&pHead,3);
				PrintList(pHead);
				break;
		case 16:
				PrintList(ReverseList(pHead));
				break;
		case 17:
				BubbleSort(pHead);
				PrintList(pHead);
				break;
		case 18:
				//PrintList(MergeList(pList1,pList2));
				break;
		case 19:
				PrintList(FindMidNode(pHead));
				break;
		case 20:
				PrintList(FindLastKNode(pHead,3));
				break;
		case 21:
				//printf("%d",IsCross(PNode pHead1, PNode pHead2));
				break;
		case 22:
				//PrintList(PNode GetCrossNode(PNode pHead1, PNode pHead2));
				break;
		default:
				printf("�������󣡣�����������\n");
				break;
		}
	}
	Destroy(&pHead);
	return 0;
}