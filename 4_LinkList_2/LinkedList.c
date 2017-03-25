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
			new_node->next=NULL;
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
			count_node->next=new_node;
			new_node->next=NULL;
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
	else if(!(*pHead)->next)
	{
		free((*pHead));
		*pHead=NULL;
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
	if(NULL==*pHead)
	{
		return NULL;
	}
	while(count_node)
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
	if(NULL==pos)
	{
		printf("δ�ҵ��˽ڵ㣡\n");
		return;
	}
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
	new_node->data=data;
	return new_node;
}
void PrintList(PNode pHead)//��ӡ����
{
	PNode count_node=pHead;
	if(count_node!=NULL)
	{
		if(count_node->next==NULL)
			printf("%d->",count_node->data);
		else
		{
			while(count_node)
			{
				printf("%d->",count_node->data);
				count_node=count_node->next;
			}
		}
		printf("NULL");
	}
	else
	{
		printf("��ѡ����Ϊ!!\n");
	}
	printf("\n");
	return ;
}
//////////////////////////////////////////////
void Erase(PNode* pHead, PNode pos)// ɾ������Posλ�õ�Ԫ��
{
	PNode count_node=*pHead;
	//PNode pre_count_node=pos;
	if(NULL==pos)
	{
		printf("δ�ҵ��˽ڵ㣡\n");
		return;
	}
	if(*pHead==pos)
	{
		*pHead=pos->next;
		free(pos);
		return;
	}
	else
	{
		while(count_node->next!=pos&&count_node!=NULL)
		{
			count_node=count_node->next;
		}
	}
	
	if(NULL==count_node)
	{
		printf("δ�ҵ��˽ڵ㣡\n");
		return;
	}
	else if(count_node->next==pos)
	{
		count_node->next=pos->next;
		free(pos);
	}
}
void Remove(PNode* pHead, DataType data)// ɾ�������е�һ��ֵΪdata��Ԫ��
{
	PNode Pos=Find(pHead,data);
	Erase(pHead,Pos);
}
void RemoveAll(PNode* pHead, DataType data)// ɾ������������ֵΪData��Ԫ��
{
	PNode Pos=Find(pHead,data);
	Erase(pHead,Pos);
	while(Pos=Find(pHead,data))
	{
		Erase(pHead,Pos);
	}
}
void Destroy(PNode* pHead)// ��������
{
	while(*pHead!=NULL)
	{
		PopFront(pHead);
	}
}
int Empty(PNode pHead)// �����Ƿ�Ϊ��
{
	if(pHead!=NULL)
	{
		return 0;
	}
	else
	{
		return 1;//Ϊ��
	}
}
int Size(PNode pHead)// �������н��ĸ���
{
	int LinkedList_size=1;
	PNode count_node=pHead;
	while(count_node->next)
	{
		count_node=count_node->next;
		LinkedList_size++;
	}
	return LinkedList_size;
}