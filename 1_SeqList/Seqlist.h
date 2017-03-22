#ifndef _Sqlist__H_
#define _Sqlist__H_
#define MAX_SIZE 100
#define DataType int

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SeqList
{
	DataType array[MAX_SIZE];
	int size;     // ��¼��ЧԪ�صĸ���
}SeqList,*PSeqList;

//typedef struct SeqList SeqList;


void InitSeqList(PSeqList psq);//��ʼ��˳���	
void PushBack(PSeqList psq, DataType data);//ͷ��
void PopBack(PSeqList psq);//ͷɾ
void PushFront(PSeqList psq, DataType data);//β��
void PopFront(PSeqList psq);//βɾ
void Insert(PSeqList psq, int pos, DataType data);//�������
void Erase(PSeqList psq, int pos);//���±�ɾ��
int Find(PSeqList psq, DataType data);//����
void Remove(PSeqList psq, DataType data);//ɾ����һ�����ҵ�������
void RemoveAll(PSeqList psq, DataType data);//ɾ�����в��ҵ�������
int Empty(PSeqList psq);//�п�
void PrintSeqList(PSeqList psq);//��ӡ

#endif//_Sqlist__H_