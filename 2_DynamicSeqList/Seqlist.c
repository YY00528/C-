#include "Seqlist.h"
#define TEST

void switchTwoNum(int* x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
void EmptyArr(PSeqList psq)
{
	DataType *p=NULL;
	int i=0;
	assert(psq);
	p=(DataType *)malloc(INITSIZE*sizeof(DataType));
	if(NULL!=p)
	{
		psq->array=p;
		psq->capacity=INITSIZE;
	}
#ifdef TEST
	for(i=0;i<INITSIZE;i++)
	{
		psq->array[i]=i;
	}
#endif
	return ;
}
void InitSeqList(PSeqList psq)//��ʼ��˳���
{
	assert(psq);
	psq->size=0;
	EmptyArr(psq);	
	#ifdef TEST
	psq->size=INITSIZE;
	#endif
}
int CheckCapacity(PSeqList psq)//���ռ�
{
	DataType *p=NULL;
	assert(psq);
	if((psq->size+1)<=psq->capacity)
	{
		return 0;
	}
	p=(DataType*)realloc(psq->array,(sizeof(DataType)*psq->capacity)*EXPORTSIZE);
	if(NULL!=p)
	{
		//free(psq->array);
		psq->array=p;
		psq->capacity*=EXPORTSIZE;
		return 1;
	}
	else
	{
		printf("˳�����������\n");
		return -1;
	}
}
void DestroySeqList(PSeqList psq)//����˳���
{
	assert(psq);
	free(psq->array);
	psq->capacity=0;
	psq->size=0;
}
void BubbleSort(PSeqList psq,SORT s)//ð������
{
	DataType temp;
	int i=0;
	int j=0;
	assert(psq);
	for(i=0;i<psq->size-1;i++)
	{
		if(1==s){
			for(j=0;j<psq->size-i-1;j++)
			{
				if(psq->array[j]>=psq->array[j+1])
				{
					temp=psq->array[j+1];
					psq->array[j+1]=psq->array[j];
					psq->array[j]=temp;
				}
			}
		}
		else if(0==s){
			for(j=psq->size-1;j>i;j--)
			{
				if(psq->array[j-1]<=psq->array[j])
				{
					temp=psq->array[j-1];
					psq->array[j-1]=psq->array[j];
					psq->array[j]=temp;
				}
			}
		}
	}
}
void SelectSort(PSeqList psq,SORT s)//ѡ������
{
	int maxPos=0;
	int minPos=0;
	int begain=0;
	int end=psq->size-1;
	int i=0;	
	assert(psq);
	while(begain<end)
	{
		maxPos=begain;
	    minPos=end;
		for(i=begain;i<=end;i++)
		{
			if(1==s){
				if(psq->array[i]>psq->array[maxPos]) maxPos=i;
				if(psq->array[i]<psq->array[minPos]) minPos=i;
			}
			else if(0==s){
				if(psq->array[i]>psq->array[minPos]) minPos=i;
				if(psq->array[i]<psq->array[maxPos]) maxPos=i;
			}
		}
		if(maxPos==begain)
		{
			maxPos=minPos;
		}
		if(minPos!=begain)
			switchTwoNum(&psq->array[begain],&psq->array[minPos]);
		if(maxPos!=end)
			switchTwoNum(&psq->array[end],&psq->array[maxPos]);
		begain++;
		end--;
	}
}
int BinarySearch(PSeqList psq, DataType data)//���ֲ���
{
	int left=0;
	int right=psq->size-1;
	int retPos=-1;
	assert(psq);
	while(left<=right)
	{
		int mid=left-((left-right)>>1);
		if(psq->array[mid]==data)
		{
			retPos=mid;
			break;
		}
		else if(psq->array[mid]<data)
		{
			left=mid+1;
		}
		else if(psq->array[mid]>data)
		{
			right=mid-1;
		}
	}
	return retPos;
}
////////////�ݹ�ʵ�ֶ��ֲ���
int BinarySearchRecursion(int left,int right,PSeqList psq, DataType data)//���ֲ���
{
	int retPos=-1;
	assert(psq);
	if(left<=right)
	{
		int mid=left-((left-right)>>1);
		if(psq->array[mid]==data)
		{
			retPos=mid;
			return retPos;
		}
		else if(psq->array[mid]<data)
		{
			retPos=BinarySearchRecursion(mid+1,right,psq,data);
		}
		else if(psq->array[mid]>data)
		{
			retPos=BinarySearchRecursion(left,mid-1,psq,data);
		}
	}
	return retPos;
}
int Size(PSeqList psq)//����˳���Ԫ�ظ���
{
	assert(psq);
	return psq->size;
}
void Clear(PSeqList psq)//���˳���
{
	int i=0;
	assert(psq);
	psq->size=0;
	for(i=0;i<psq->capacity;i++)
	{
		psq->array[i]=0;
	}
}
void PushBack(PSeqList psq, DataType data)//ͷ��
{
	int i=0;	
	assert(psq);
	if(-1==CheckCapacity(psq))
	{
		return;
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
	assert(psq);
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
	assert(psq);
	if(-1==CheckCapacity(psq))
	{
		return;
	}
	psq->array[psq->size]=data;	
	psq->size++;		
	return ;
}
void PopFront(PSeqList psq)//βɾ
{
	assert(psq);
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
	assert(psq);
	if(-1==CheckCapacity(psq))
	{
		return;
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
	assert(psq);
	if(Empty(psq))
	{
		printf("˳���Ϊ�գ�����ʧ�ܣ�\n");
		return;
	}
	for(i=pos;i<psq->size-1;i++)
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
	assert(psq);
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
	assert(psq);
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
	assert(psq);
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
		else
			Erase(psq, i);
	}
	return ;
}
int Empty(PSeqList psq)//�п�
{
	int flag=0;
	assert(psq);
	if(psq->size==0)
		flag=1;
	else
		flag=0;
	return flag;
}
void PrintSeqList(PSeqList psq)//��ӡ
{
	int i=0;
	assert(psq);
	for(i=0;i<psq->size;i++)
	{
		printf("%d ",psq->array[i]);
	}
	printf("\n");
}