#pragma once

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <windows.h>
//#ifndef __SeqList_H__
//#define __SeqList_H__
//
//#endif //__SeqList_H__

//���ݽṹ�ǳ�������
//���ݱ�������������

typedef  int  DataType;

#define MAX_SIZE 100

typedef struct SeqList{
	DataType array[MAX_SIZE];
	int size;//�������˳������Ѿ����˵����ݸ���
	         //��ǰ�����±�
}SeqList;

//�ӿں���
//��ʼ��������
//����ɾ���顢��

//��ʼ����������ƣ�
void SeqListInit(SeqList *pSeq)
{
	//1 ��ʼ�� size 
	//2 ������Ҫȥ�������ռ�����һ��(һ��û�б�Ҫ)
	/*memset(pSeq->array, 0, MAX_SIZE * sizeof(DataType));*/
	assert(pSeq != NULL);
	pSeq->size = 0;
}

//����
void SeqListDestroy(SeqList *pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;
}

//��
//β�壨������c++��STLͳһ��
void SeqListPushBack(SeqList *pSeq, DataType data)
{
	assert(pSeq != NULL);
	//������������ˣ�
	if (pSeq->size >= MAX_SIZE)
	{
		printf("����\n");
		assert(0);//ֱ�ӱ���
		return;
	}
	//ͨ�����
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}

//ͷ��
void SeqListPushFront(SeqList *pSeq, DataType data)
{
	assert(pSeq != NULL);
	//������������ˣ�
	if (pSeq->size >= MAX_SIZE)
	{
		printf("����\n");
		assert(0);//ֱ�ӱ���
		return;
	}
	//ͨ�����
	//i����λ��
	for (int i = pSeq->size; i > 0; i--)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	pSeq->array[0] = data;
	pSeq->size++;//�������ص㣬��Ҫ���ǣ�����
}

//���루����λ�ã�
void SeqListInsert(SeqList *pSeq, int pos, DataType data)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);
	//������������ˣ�
	if (pSeq->size >= MAX_SIZE)
	{
		printf("����\n");
		assert(0);//ֱ�ӱ���
		return;
	}
	//һ�����
	//���ݰ���
	for (int i = pSeq->size; i > pos; i--)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	pSeq->array[pos] = data;
	pSeq->size++;
}

//ɾ
//βɾ
void SeqListPopBack(SeqList *pSeq)
{
	assert(pSeq != NULL);
	//������������ˣ�
	if (pSeq->size <= 0)
	{
		printf("����\n");
		assert(0);//ֱ�ӱ���
		return;
	}
	//ͨ�����
	pSeq->size--;
}

//ͷɾ
void SeqListPopFront(SeqList *pSeq)
{
	assert(pSeq != NULL);
	//������������ˣ�
	if (pSeq->size <= 0)
	{
		printf("����\n");
		assert(0);//ֱ�ӱ���
		return;
	}
	//ͨ�����
	for (int i = 0; i < pSeq->size - 1; i++)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--;
}

//ɾ��
void SeqListErase(SeqList *pSeq, int pos)
{
	assert(pSeq);
	assert(pos >= 0 && pos < pSeq->size);
	//�������
	if (pSeq->size <= 0)
	{
		printf("����\n");
		assert(0);
		return;
	}
	//һ�����
	//���ݰ���
	for (int i = pos; i < pSeq->size - 1; i++)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--;
}

//����
//�ҵ���һ�������������±꣬û�ҵ�����-1
int SeqListFind(SeqList *pSeq, DataType data)
{
	//���ֲ��ң�����
	//˳�����
	for (int i = 0; i < pSeq->size; i++)
	{
		if (data == pSeq->array[i])
		{
			return i;
		}
	}
	return -1;
}
//���Ҵ������ĵڶ�����̬ɾ��
//1 ɾ�������ĵ�һ������
void SeqListRemove(SeqList *pSeq, DataType data)
{
	int pos = SeqListFind(pSeq, data);//���ص������ݵ��±�
	if (-1 == pos)
	{
		return;//û�ҵ�����
	}
	SeqListErase(pSeq, pos);
}

//2 ɾ����������������
void SeqListRemoveAll(SeqList *pSeq, DataType data)
{
	/*int pos = 0;
	while (-1 != (pos = SeqListFind(pSeq, data)))
	{
		SeqListErase(pSeq, pos);//�����㷨�ٶ�̫����
	}*/

#if 0
	//�����һ�α���ɾ��
	//�ô���һ�α�����ʱ��ȽϿ�
	//�����������¿ռ䣬�ռ��С��size�й�ϵ
	//��������
	DataType *newArray = (DataType *)malloc(pSeq->size * sizeof(DataType));
	int i, j;
	for (i = 0, j = 0; i < pSeq->size; i++)
	{
		if (data != pSeq->array[i])
		{
			newArray[j] = pSeq->array[i];
			j++;
		}
	}

	for (i = 0; i < j; i++)
	{
		pSeq->array[i] = newArray[i];
	}
	pSeq->size = j;
	//�ͷſռ�
	free(newArray);
#endif

	//������ɾ����ʽ
	int i, j;
	for (i = 0, j = 0; i < pSeq->size; i++)
	{
		if (data != pSeq->array[i])
		{
			pSeq->array[j] = pSeq->array[i];
			j++;
		}
	}
	pSeq->size = j;
}



void SeqListPrint(SeqList *pSeq)
{
	assert(pSeq);
	for (int i = 0; i < pSeq->size; i++)
	{
		printf("%d ", pSeq->array[i]);
	}
	printf("\n");
}

//ʹ�ó���
void Test()
{
	SeqList seqList;
	SeqListInit(&seqList);

	SeqListPushFront(&seqList, 1);
	SeqListPushFront(&seqList, 1);
	SeqListPushFront(&seqList, 1);
	SeqListPushFront(&seqList, 1);
	SeqListPushFront(&seqList, 1);//ͷ��

	//SeqListPushBack(&seqList, 6);//β��
	//SeqListInsert(&seqList, 3, 7);//����

	//SeqListPopFront(&seqList);//ͷɾ
	//SeqListPopBack(&seqList);//βɾ
	//SeqListErase(&seqList, 3);//ɾ��
	SeqListRemoveAll(&seqList, 1);


	SeqListPrint(&seqList);
}
