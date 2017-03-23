#ifndef _Sqlist__H_
#define _Sqlist__H_
#define INITSIZE 3
#define EXPORTSIZE 2
#define DataType int

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct SeqList
{
	DataType *array;
	int size;     // ��¼��ЧԪ�صĸ���
	int capacity;//�ռ��ܴ�С
}SeqList,*PSeqList;
typedef enum
{
	DESC,
	ASC
}SORT;
//typedef struct SeqList SeqList;


void InitSeqList(PSeqList psq);//��ʼ��˳���
//////////////////////////////////////////////////////////////////��������////////////////////////////
int CheckCapacity(PSeqList psq);//���ռ�
void DestroySeqList(PSeqList psq);//����˳���
void BubbleSort(PSeqList psq,SORT s);//ð������
void SelectSort(PSeqList psq,SORT s);//ѡ������
int BinarySearch(PSeqList psq, DataType data);//���ֲ���
////////////�ݹ�ʵ�ֶ��ֲ���
int BinarySearchRecursion(int left,int right,PSeqList psq, DataType data);//���ֲ���
int Size(PSeqList psq);//����˳���Ԫ�ظ���
void Clear(PSeqList psq);//���˳���
//////////////////////////////////////////////////////////////////
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