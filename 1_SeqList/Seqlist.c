#include "Seqlist.h"
#define TEST

void EmptyArr(DataType arr[],int size)
{
	int i=0;
	for(i=0;i<size;i++)
	{
		arr[i]=0;
	}
#ifdef TEST
	for(i=0;i<10;i++)
	{
		arr[i]=i;
	}
#endif
}
void InitSeqList(PSeqList psq)//��ʼ��˳���
{
	psq->size=0;
	EmptyArr(psq->array,MAX_SIZE);	
	#ifdef TEST
	psq->size=10;
	#endif
}
void PushBack(PSeqList psq, DataType data)//ͷ��
{
	int i=0;
	if(psq->size+1>MAX_SIZE)
	{
		printf("˳�����������\n");
		return ;
	}
	for(i=psq->size;i>0;i--)
	{
		psq->array[i]=psq->array[i-1];
	}
	psq->array[0]=data;
	psq->size++;
	return ;
}
void PopBack(PSeqList psq)//ͷɾ
{
	int i=0;
	if(Empty(psq))
	{
		printf("˳���Ϊ�գ�����ʧ�ܣ�\n");
		return;
	}
	for(i=0;i<psq->size;i++)
	{
		psq->array[i]=psq->array[i+1];
	}
	psq->array[psq->size-1]=0;
	psq->size--;	
	return ;
}
void PushFront(PSeqList psq, DataType data)//β��
{
	if(psq->size+1>MAX_SIZE)
	{
		printf("˳�����������\n");
		return ;
	}
	psq->array[psq->size]=data;	
	psq->size++;		
	return ;
}
void PopFront(PSeqList psq)//βɾ
{
	if(Empty(psq))
	{
		printf("˳���Ϊ�գ�����ʧ�ܣ�\n");
		return;
	}
	psq->array[psq->size]=0;	
	psq->size--;		
	return ;
}
void Insert(PSeqList psq, int pos, DataType data)//�������
{
	int i=0;
	if(psq->size+1>MAX_SIZE)
	{
		printf("˳�����������\n");
		return ;
	}
	for(i=psq->size;i>pos;i--)
	{
		psq->array[i]=psq->array[i-1];
	}
	psq->array[pos]=data;
	psq->size++;
	return ;
}
void Erase(PSeqList psq, int pos)//���±�ɾ��
{
	int i=0;
	if(Empty(psq))
	{
		printf("˳���Ϊ�գ�����ʧ�ܣ�\n");
		return;
	}
	for(i=pos;i<psq->size;i++)
	{
		psq->array[i]=psq->array[i+1];
	}
	psq->array[psq->size-1]=0;
	psq->size--;	
	return ;
}
int Find(PSeqList psq, DataType data)//����
{
	int i=0;
	if(Empty(psq))
	{
		printf("˳���Ϊ�գ�����ʧ�ܣ�\n");
		return;
	}
	for(i=0;i<psq->size;i++)
	{
		if(psq->array[i]==data)
			break;
	}	
	if(i==psq->size)
		i=-1;
	return i;
}
void Remove(PSeqList psq, DataType data)//ɾ����һ�����ҵ�������
{
	if(Empty(psq))
	{
		printf("˳���Ϊ�գ�����ʧ�ܣ�\n");
		return;
	}
	Erase(psq, Find(psq,data));
}
void RemoveAll(PSeqList psq, DataType data)//ɾ�����в��ҵ�������
{
	int i=0;
	if(Empty(psq))
	{
		printf("˳���Ϊ�գ�����ʧ�ܣ�\n");
		return;
	}
	while(i!=-1)
	{
		while(i<psq->size)
		{
			if(psq->array[i]==data)
				break;
			i++;
		}	
		if(i==psq->size)
			i=-1;
		Erase(psq, i);
	}
	return ;
}
int Empty(PSeqList psq)//�п�
{
	int flag=0;
	if(psq->size==0)
		flag=1;
	else
		flag=0;
	return flag;
}
void PrintSeqList(PSeqList psq)//��ӡ
{
	int i=0;
	for(i=0;i<psq->size;i++)
	{
		printf("%d ",psq->array[i]);
	}
	printf("\n");
}