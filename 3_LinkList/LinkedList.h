#ifndef _LinkedList__H_
#define _LinkedList__H_

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct Node
{
	int data;
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
#endif//_LinkedList__H_