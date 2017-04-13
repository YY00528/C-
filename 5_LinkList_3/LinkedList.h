#ifndef _LinkedList__H_
#define _LinkedList__H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct Node
{
	int data;
	struct Node* radom; 
	struct Node* next;   // ��һ�����ĵ�ַ
}Node, *PNode;


void InitList(PNode* pHead);//��ʼ������
void PushBack(PNode* pHead, DataType data);//β��
void PopBack(PNode* pHead);//βɾ
void PushFront(PNode* pHead, DataType data);//ͷ��
void PopFront(PNode* pHead);//ͷɾ
PNode Find(PNode* pHead, DataType data);//���ҽ��
void Insert(PNode pos, DataType data);//����ڵ�
PNode BuyNode(DataType data);//�����½ڵ�
void PrintList(PNode pHead);//��ӡ����
//////////////////////////////////////////////
void Erase(PNode* pHead, PNode pos);// ɾ������Posλ�õ�Ԫ��
void Remove(PNode* pHead, DataType data);// ɾ�������е�һ��ֵΪdata��Ԫ��
void RemoveAll(PNode* pHead, DataType data);// ɾ������������ֵΪData��Ԫ��
void Destroy(PNode* pHead);// ��������
int Empty(PNode pHead);// �����Ƿ�Ϊ��
int Size(PNode pHead);// �������н��ĸ���
////////////////////////////////////////ʵ�ֵ������һ����Ŀ
void PrintListFromT2H(PNode pHead);//�����ӡ����
void DeleteNotTail(PNode pos);//ɾ��һ����ͷ����ķ�β���
void InsertNotHead(PNode pHead, PNode pos, DataType data);//����ͷ����ǰ����һ�����
void JosephCircle(PNode* pHead, int M);//������ʵ��Լɪ��
PNode ReverseList(PNode pHead);//��������
void BubbleSort(PNode pHead);//ð������
PNode MergeList(PNode pList1, PNode pList);//�ϲ�������������
PNode FindMidNode(PNode pHead);//ֻ�ܱ���һ������Ѱ���м�Ԫ��
PNode FindLastKNode(PNode pHead, int k);//Ѱ�ҵ�����k�����
//�����Ƿ������
int IsCross(PNode pHead1, PNode pHead2);//�ж����������Ƿ��ཻ
PNode GetCrossNode(PNode pHead1, PNode pHead2);//�ཻ�Ľ���
/////////////////////////////////////9.18����
PNode HasCircle(PNode pHead);//�ж��Ƿ��л�
int GetCirclrLen(PNode pMeetNode);//���ػ��ĳ���
// ��ȡ������ڵ�--��������Ĺ���
PNode GetEnterNode(PNode pHead, PNode pMeetNode);
//�ж��������������Ƿ��ཻ
int IsCrossWithCircle(PNode pHead1, PNode pHead2);
//��������������������ͬ������--��ӡ����
void UnionSet(Node* l1, Node* l2);
//��������ĸ�ֵ--����ʵ��ԭ��ͼ��
//����ʵ�ִ���(��ö�ȥʵ����)
PNode coypComplexList(PNode pHead,PNode* newHead);//���Ƹ�������
#endif//_LinkedList__H_