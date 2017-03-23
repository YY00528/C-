#include "Seqlist.h"
/**
	 ˳����ڴ��е�ַ����
             ���Ȳ��ɱ��
             ֧��������� ������O(1)�ڲ���Ԫ��
             ��������Ҫ��������Ԫ�ص� ����������/ɾ��Ԫ�صĳ���
*/
void menu()
{
	printf("************************************************\n");
	printf("*                                              *\n");
	printf("*     1. ͷ�巨��������                        *\n");//0
	printf("*     2. ͷɾ��ɾ������                        *\n");//1
	printf("*     3. β�巨��������                        *\n");
	printf("*     4. βɾ��ɾ������                        *\n");
	printf("*     5. ����λ�ò�������                      *\n");
	printf("*     6. ����λ��ɾ������                      *\n");
	printf("*     7. �������ݷ����±�                      *\n");
	printf("*     8. ɾ����һ�����ҵ�������                *\n");
	printf("*     9. ɾ�����в��ҵ�������                  *\n");
	printf("*     10.�п�                                  *\n");
	printf("*     11.��ӡ˳���                            *\n");
	printf("*     12.ð������                              *\n");
	printf("*     13.ѡ������                              *\n");
	printf("*     14.���ֲ���                              *\n");
	printf("*     15.����˳���Ԫ�ظ���                    *\n");
	printf("*     16.���˳���                            *\n");
	printf("*     17.�˳�                                  *\n");
	printf("*                                              *\n");
	printf("************************************************\n");
	printf("��ѡ��->");
}

int main()
{
	SeqList seq; 
	PSeqList psq=&seq;
	char ch='y';
	int  flag=0;
	DataType data=0;
	int pos=0;
	InitSeqList(psq);//��ʼ��˳���	
	while(ch=='y')
	{
		menu();
		scanf("%d",&flag);
		switch(flag)
		{
		case 1:
				printf("���������ݣ�");
				scanf("%d",&data);
				PushBack(psq,data);
				PrintSeqList(psq);
				break;
		case 2:
				PopBack(psq);
				PrintSeqList(psq);
				break;
		case 3:
				printf("���������ݣ�");
				scanf("%d",&data);
				PushFront(psq,data);
				PrintSeqList(psq);
				break;
		case 4:
				PopFront(psq);
				PrintSeqList(psq);
				break;
		case 5:
				printf("�������±꣺");
				scanf("%d",&pos);
				printf("���������ݣ�");
				scanf("%d",&data);
				Insert(psq,pos,data);
				PrintSeqList(psq);
				break;
		case 6:
				printf("�������±꣺");
				scanf("%d",&pos);
				Erase(psq, pos);
				PrintSeqList(psq);
				break;
		case 7:
				printf("���������ݣ�");
				scanf("%d",&data);
				printf("%d\n",Find(psq,data));
				PrintSeqList(psq);
				break;
		case 8:
				printf("���������ݣ�");
				scanf("%d",&data);
				Remove(psq,data);
				PrintSeqList(psq);
				break;
		case 9:
				printf("���������ݣ�");
				scanf("%d",&data);
				RemoveAll(psq,data);
				PrintSeqList(psq);
				break;
		case 10:
				if(Empty(psq))
					printf("˳���Ϊ��\n");
				else
					printf("˳���Ϊ��\n");
		case 11:
				PrintSeqList(psq);
				break;
		case 12:
				BubbleSort(psq,ASC);
				PrintSeqList(psq);
				break;
		case 13:
				SelectSort(psq,DESC);
				PrintSeqList(psq);
				break;
		case 14:
				printf("�����������ҵ����ݣ�");
				scanf("%d",&data);
				printf("�ݹ�%d\n",BinarySearchRecursion(0,psq->size-1,psq,data));	
				printf("�ǵݹ�%d\n",BinarySearch(psq,data));				
				break;
		case 15:
				printf("˳����й���%d��Ԫ��\n",BinarySearch(psq,data));
				break;
		case 16:
				Clear(psq);
				break;
		case 17:
				ch=0;
				break;
		default:
				printf("�������󣡣�����������\n");
		}
	}
	DestroySeqList(psq);
	return 0;
}