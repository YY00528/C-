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
////////////////////////////////////////////�������������
void PrintListFromT2H(PNode pHead)//�����ӡ����
{
	if(NULL==pHead)
	{
		printf("NULL");
	}
	else
	{
		PrintListFromT2H(pHead->next);
		printf("<-%d",pHead->data);
	}
	printf("\n");
	return;
}
void DeleteNotTail(PNode pos)//ɾ��һ����ͷ����ķ�β���
{
	PNode NextNode=pos->next;
	if(NULL==pos->next)
	{
		printf("��ѡ��һ����β���\n");
		return;
	}
	pos->data=NextNode->data;
	pos->next=NextNode->next;
	free(NextNode);
	return;
}
void InsertNotHead(/*PNode pHead, */PNode pos, DataType data)//����ͷ����ǰ����һ�����
{
	PNode NextNode=pos->next;
	PNode NewNode=BuyNode(pos->data);
	if(NULL!=NewNode)
	{
		pos->next=NewNode;
		NewNode->next=NextNode;
		pos->data=data;
	}
	else
	{
		printf("�ռ䲻�㣡��\n");
	}
	return;
}
void JosephCircle(PNode* pHead, int M)//������ʵ��Լɪ��
{
	PNode NextNode=*pHead;
	if(NULL==(*pHead)||NULL==(*pHead)->next)
	{
		return;
	}
	else
	{
		while((*pHead)==(*pHead)->next)
		{
			while(--M)
			{
				NextNode=NextNode->next;
			}
			Erase(pHead,NextNode);
		}
		(*pHead)->next=NULL;
	}
	return; 
}
PNode ReverseList(PNode *pHead)//��������
{
	PNode preNode=*pHead;
	PNode curNode=*pHead;
	PNode nextNode=*pHead;
	if(NULL==(*pHead))
	{
		printf("��ѡ����Ϊ�գ���\n");
		return *pHead;
	}
	else
	{
		curNode=preNode->next;
		if(NULL==curNode)
		{
			return *pHead;
		}
		else
		{
			nextNode=curNode->next;
			if(NULL==nextNode)
			{
				preNode->next=NULL;
				curNode->next=preNode;
				*pHead=curNode;
				return *pHead;
			}
			else
			{
				preNode->next=NULL;
				while(NULL!=nextNode)
				{
					curNode->next=preNode;
					preNode=curNode;
					curNode=nextNode;
					nextNode=nextNode->next;
				}
				curNode->next=preNode;
				*pHead=curNode;
				
			}
		}
	}
	return *pHead;
}
void BubbleSort(PNode pHead)//ð������
{
	int i=0;
	int j=0;
	int temp=0;
	int length=Size(pHead);
	PNode curNode=pHead;
	PNode nextNode=pHead->next;
	for(i=0;i<length-1;i++)
	{
		curNode=pHead;
		nextNode=pHead->next;
		for(j=0;j<length-i-1;j++)
		{
			if(curNode->data>nextNode->data)
			{
				temp=curNode->data;
				curNode->data=nextNode->data;
				nextNode->data=temp;
			}
			curNode=curNode->next;
			nextNode=nextNode->next;
		}
	}
	return;
}
PNode MergeList(PNode pList1, PNode pList2)//�ϲ�������������
{
	PNode newNode=NULL;
	PNode curNode=NULL;
	if(pList1<=pList2)
	{
		newNode=pList1;
		curNode=pList1;
		pList1=pList1->next;
	}
	else
	{
		newNode=pList2;
		curNode=pList2;
		pList2=pList2->next;
	}
	while(pList1&&pList2)
	{
		if(pList1->data<pList2->data)
		{
			curNode->next=pList1;
			curNode=pList1;
			pList1=pList1->next;
		}
		else
		{
			curNode->next=pList2;
			curNode=pList2;
			pList2=pList2->next;
		}
	}
	if(!pList1)
	{
		curNode->next=pList2;
	}
	else
	{
		curNode->next=pList1;
	}
	return;
}
PNode FindMidNode(PNode pHead)//ֻ�ܱ���һ������Ѱ���м�Ԫ��
{
	PNode Pfast=pHead;
	PNode Pslow=pHead;
	if(NULL==pHead)
	{
		printf("��ѡ����Ϊ�գ���\n");
		return NULL;
	}
	else if(NULL==pHead->next)
	{
		return pHead;
	}
	Pfast=pHead->next->next;
	Pslow=pHead;
	while(Pfast->next&&Pfast)
	{
		Pfast=Pfast->next->next;
		Pslow=Pslow->next;
	}
	return Pslow;
}
PNode FindLastKNode(PNode pHead, int k)//Ѱ�ҵ�����k�����,���㿪ʼ����
{
	PNode preNode=pHead;
	PNode tailNode=pHead;
	while(k>0)
	{
		tailNode=tailNode->next;
		k--;
	}
	while(NULL!=tailNode)
	{
		tailNode=tailNode->next;
		preNode=preNode->next;
	}
	return preNode;
}
int IsCross(PNode pHead1, PNode pHead2)//�ж����������Ƿ��ཻ
{
	int length1=Size(pHead1);
	int length2=Size(pHead2);
	int temp=0;
	PNode p1=pHead1;
	PNode p2=pHead2;

	temp=length1-length2;
	if(temp<0)
	{
		int i=0;
		temp=-temp;
		for(i=0;i<temp;i++)
		{
			p2=p2->next;
		}
	}
	else
	{
		int i=0;
		for(i=0;i<temp;i++)
		{
			p1=p1->next;
		}
	}
	while(p1&&p2&&p1!=p2)
	{
		p1=p1->next;
		p2=p2->next;
	}
	if(p1==p2) return 1;
	else return 0;
}
PNode GetCrossNode(PNode pHead1, PNode pHead2)//�ཻ�Ľ���
{
	int length1=Size(pHead1);
	int length2=Size(pHead2);
	int temp=0;
	PNode p1=pHead1;
	PNode p2=pHead2;

	temp=length1-length2;
	if(temp<0)
	{
		int i=0;
		temp=-temp;
		for(i=0;i<temp;i++)
		{
			p2=p2->next;
		}
	}
	else
	{
		int i=0;
		for(i=0;i<temp;i++)
		{
			p1=p1->next;
		}
	}
	while(p1&&p2&&p1!=p2)
	{
		p1=p1->next;
		p2=p2->next;
	}
	if(p1==p2) return p1;
	else return NULL;
}
PNode HasCircle(PNode pHead)
{
	PNode Pfast=pHead;
	PNode Pslow=pHead;
	if(NULL==pHead)
	{
		printf("��ѡ����Ϊ�գ���\n");
		return NULL;
	}
	else if(NULL==pHead->next)
	{
		return pHead;
	}
	Pfast=pHead->next->next;
	Pslow=pHead;
	while(Pfast->next&&Pfast||(Pfast==Pslow))
	{
		Pfast=Pfast->next->next;
		Pslow=Pslow->next;
	}
	return Pslow;
}
int GetCirclrLen(PNode pMeetNode)
{
	int length=2;
	PNode Pcount=pMeetNode->next;
	while(Pcount->next!=pMeetNode)
	{
		Pcount=Pcount->next;
		length++;
	}
	return length;
}
// ��ȡ������ڵ�--��������Ĺ���
//L+X+nR=2(L+X)
//L+X=nR
//L=nR-X
PNode GetEnterNode(PNode pHead, PNode pMeetNode)
{
	PNode Pfast=pMeetNode;
	PNode Pslow=pHead;
	if(NULL==pHead)
	{
		printf("��ѡ����Ϊ�գ���\n");
		return NULL;
	}
	else if(NULL==pHead->next)
	{
		return pHead;
	}
	while(Pfast->next&&Pfast||(Pfast==Pslow))
	{
		Pfast=Pfast->next->next;
		Pslow=Pslow->next;
	}
	return Pslow;
}
int IsCrossWithCircle(PNode pHead1, PNode pHead2)
{
	assert(pHead1,pHead2);
	PNode P1=HasCircle(pHead1);
	PNode P2=HasCircle(pHead2);
	PNode pFast=P1;
	if(!P1||!P2)
	{
		printf("��ѡ����������������\n");
		return -1;
	}
	while(pFast!=P1&&pFast!=P2)
	{
		pFast=pFast->next;
	}
	if(pFast==P1)
	{
		return 0;
	}
	else if(pFast==P2)
	{
		return 1;
	}
	return 2;
}
//��������������������ͬ������--��ӡ����
void UnionSet(Node* pList1, Node* pList2)
{
	PNode pl1=pList1;
	PNode pl2=pList2;
	if(NULL==pList1||NULL==pList2)
	{
		printf("��ѡ����Ϊ�գ���\n");
		return;
	}
	while(pl1!=NULL&&pl2!=NULL)
	{
		if(pl1->data==pl2->data)
		{
			printf("%d ",pl1->data);
			pl1=pl1->next;
			pl2=pl2->next;
		}
		else if(pl1->data>pl2->data)
		{
			pl2=pl2->next;
		}
		else if(pl1->data<pl2->data)
		{
			pl1=pl1->next;
		}	
	}
	return;
}
//��������ĸ�ֵ--����ʵ��ԭ��ͼ��
//����ʵ�ִ���(��ö�ȥʵ����)
PNode coypComplexList(PNode pHead,PNode* newHead)//���Ƹ�������
{
	PNode newNode=NULL;
	PNode curNode=NULL;
	if(NULL==pHead)
	{
		printf("��ѡ��ǿ�����\n");
		return NULL;
	}
	curNode=pHead;
	while(NULL!=curNode)
	{
		newNode=BuyNode(curNode->data);
		if(NULL==newNode)
		{
			printf("�����ڴ�ʧ�ܣ���\n");
			return NULL;
		}
		else
		{
			newNode->next=curNode->next;
			curNode->next=newNode;
			curNode=curNode->next->next;
			//newNode->radom=curNode->radom->next;
		}
	}
	curNode=pHead;
	newNode=curNode->next;
	*newHead=newNode;
	while(NULL!=curNode)
	{
		newNode->radom=curNode->radom->next;
		curNode=curNode->next->next;
		newNode=newNode->next->next;
	}
	newNode=*newHead;
	curNode=pHead;
	while(NULL!=curNode)
	{
		curNode->next=curNode->next->next;
		newNode->next=newNode->next->next;
		curNode=curNode->next;
		newNode=newNode->next;
	}
	return *newHead;
}
/*******************************************************************************
	���ӵ������Ƶ�ʵ��ԭ��
		��Դ�����в����µĽڵ㣬�½ڵ��ֵΪ������ǰһ���ڵ�ĵ�ֵ��������ɺ�
		���½ڵ���radom��ֵ��Ϊǰһ���ڵ���radom->next;��ȫ���½ڵ��radom��ֵ
		�޸���Ϻ������½ڵ��Դ�����з��룬�γ�������newHead�����ء�
*******************************************************************************/