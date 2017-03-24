#include "LinkedList.h"

void InitList(PNode* pHead)//��ʼ������
{
	if(*pHead)
	{
		*pHead=NULL;
	}
	return ;
}
void PushBack(PNode* pHead, DataType data)//β��
{
	PNode new_node=NULL;
	PNode count_node=*pHead;
	if(!*pHead)
	{
		new_node=BuyNode(data);
		if(new_node!=NULL){
			*pHead=new_node;
		}
		else{
			printf("�ռ䲻�㣬����ʧ�ܣ�\n");
			return;
		}
	}
	else
	{
		while(count_node->next)
		{
			count_node=count_node->next;
		}
		new_node=BuyNode(data);
		if(new_node!=NULL){
			count_node=new_node;
		}
		else{
			printf("�ռ䲻�㣬����ʧ�ܣ�\n");
			return;
		}
	}
	return;
}
void PopBack(PNode* pHead)//βɾ
{
	PNode count_node=*pHead;
	if(!*pHead)
	{
		printf("��ѡ����Ϊ�գ�\n");
	}
	else
	{
		while(count_node->next->next)
		{
			count_node=count_node->next;
		}
		free(count_node->next);
		count_node->next=NULL;
	}
	return ;
}
void PushFront(PNode* pHead, DataType data)//ͷ��
{
	PNode new_node=BuyNode(data);
	if(new_node!=NULL){
			new_node->next=*pHead;
			*pHead=new_node;
		}
	else{
			printf("�ռ䲻�㣬����ʧ�ܣ�\n");
			return;
		}
}
void PopFront(PNode* pHead)//ͷɾ
{
	if(!*pHead)
	{
		printf("��ѡ����Ϊ�գ�\n");
	}
	else
	{
		PNode count_node=*pHead;
		count_node=count_node->next;
		free(*pHead);
		*pHead=count_node;
	}
	return;
}
PNode Find(PNode* pHead, DataType data)//���ҽ��
{
	PNode count_node=*pHead;
	while(count_node->next)
	{
		if(count_node->data==data)
		{
			return count_node;
		}
		else
		{
			count_node=count_node->next;
		}
	}
	return NULL;
}
void Insert(PNode pos, DataType data)//����ڵ�
{
	PNode new_node=NULL;
	new_node= BuyNode(data);
	if(new_node!=NULL)
	{
		new_node->next=pos->next;
		pos->next=new_node;
	}
	else
	{
		printf("�ռ䲻�㣬����ʧ�ܣ�\n");
		return;
	}
}
PNode BuyNode(DataType data)//�����½ڵ�
{
	PNode new_node=(PNode)malloc(sizeof(Node));
	return new_node;
}
void PrintList(PNode pHead)//��ӡ����
{
	PNode count_node=pHead;
	while(count_node->next)
	{
		printf("%d ",count_node->data);
		count_node=count_node->next;
	}
	printf("\n");
	return ;
}
//////////////////////////////////////////////
void Erase(PNode* pHead, PNode pos);// ɾ������Posλ�õ�Ԫ��
void Remove(PNode* pHead, DataType data);// ɾ�������е�һ��ֵΪdata��Ԫ��
void RemoveAll(PNode* pHead, DataType data);// ɾ������������ֵΪData��Ԫ��
void Destroy(PNode* pHead);// ��������
int Empty(PNode pHead);// �����Ƿ�Ϊ��
int Size(PNode pHead);// �������н��ĸ���