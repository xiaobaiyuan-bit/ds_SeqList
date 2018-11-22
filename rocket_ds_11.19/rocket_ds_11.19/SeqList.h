#pragma once

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <windows.h>
//#ifndef __SeqList_H__
//#define __SeqList_H__
//
//#endif //__SeqList_H__

//数据结构是抽象类型
//数据本身不仅仅是数字

typedef  int  DataType;

#define MAX_SIZE 100

typedef struct SeqList{
	DataType array[MAX_SIZE];
	int size;//保存的是顺序表里已经存了的数据个数
	         //当前可用下标
}SeqList;

//接口函数
//初始化、销毁
//增、删、查、改

//初始化（函数设计）
void SeqListInit(SeqList *pSeq)
{
	//1 初始化 size 
	//2 可能需要去把容器空间清理一下(一般没有必要)
	/*memset(pSeq->array, 0, MAX_SIZE * sizeof(DataType));*/
	assert(pSeq != NULL);
	pSeq->size = 0;
}

//销毁
void SeqListDestroy(SeqList *pSeq)
{
	assert(pSeq != NULL);
	pSeq->size = 0;
}

//增
//尾插（尽量和c++的STL统一）
void SeqListPushBack(SeqList *pSeq, DataType data)
{
	assert(pSeq != NULL);
	//特殊情况（满了）
	if (pSeq->size >= MAX_SIZE)
	{
		printf("满了\n");
		assert(0);//直接崩掉
		return;
	}
	//通常情况
	pSeq->array[pSeq->size] = data;
	pSeq->size++;
}

//头插
void SeqListPushFront(SeqList *pSeq, DataType data)
{
	assert(pSeq != NULL);
	//特殊情况（满了）
	if (pSeq->size >= MAX_SIZE)
	{
		printf("满了\n");
		assert(0);//直接崩掉
		return;
	}
	//通常情况
	//i代表位置
	for (int i = pSeq->size; i > 0; i--)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	pSeq->array[0] = data;
	pSeq->size++;//这里是重点，不要忘记！！！
}

//插入（任意位置）
void SeqListInsert(SeqList *pSeq, int pos, DataType data)
{
	assert(pSeq);
	assert(pos >= 0 && pos <= pSeq->size);
	//特殊情况（满了）
	if (pSeq->size >= MAX_SIZE)
	{
		printf("满了\n");
		assert(0);//直接崩掉
		return;
	}
	//一般情况
	//数据搬移
	for (int i = pSeq->size; i > pos; i--)
	{
		pSeq->array[i] = pSeq->array[i - 1];
	}
	pSeq->array[pos] = data;
	pSeq->size++;
}

//删
//尾删
void SeqListPopBack(SeqList *pSeq)
{
	assert(pSeq != NULL);
	//特殊情况（空了）
	if (pSeq->size <= 0)
	{
		printf("空了\n");
		assert(0);//直接崩掉
		return;
	}
	//通常情况
	pSeq->size--;
}

//头删
void SeqListPopFront(SeqList *pSeq)
{
	assert(pSeq != NULL);
	//特殊情况（空了）
	if (pSeq->size <= 0)
	{
		printf("空了\n");
		assert(0);//直接崩掉
		return;
	}
	//通常情况
	for (int i = 0; i < pSeq->size - 1; i++)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--;
}

//删除
void SeqListErase(SeqList *pSeq, int pos)
{
	assert(pSeq);
	assert(pos >= 0 && pos < pSeq->size);
	//特殊情况
	if (pSeq->size <= 0)
	{
		printf("空了\n");
		assert(0);
		return;
	}
	//一般情况
	//数据搬移
	for (int i = pos; i < pSeq->size - 1; i++)
	{
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--;
}

//查找
//找到第一个遇到的数的下标，没找到返回-1
int SeqListFind(SeqList *pSeq, DataType data)
{
	//二分查找（有序）
	//顺序遍历
	for (int i = 0; i < pSeq->size; i++)
	{
		if (data == pSeq->array[i])
		{
			return i;
		}
	}
	return -1;
}
//查找带出来的第二种形态删除
//1 删除遇到的第一个数据
void SeqListRemove(SeqList *pSeq, DataType data)
{
	int pos = SeqListFind(pSeq, data);//返回的是数据的下标
	if (-1 == pos)
	{
		return;//没找到数据
	}
	SeqListErase(pSeq, pos);
}

//2 删除遇到的所有数据
void SeqListRemoveAll(SeqList *pSeq, DataType data)
{
	/*int pos = 0;
	while (-1 != (pos = SeqListFind(pSeq, data)))
	{
		SeqListErase(pSeq, pos);//这种算法速度太慢了
	}*/

#if 0
	//最好是一次遍历删除
	//好处：一次遍历，时间比较快
	//坏处：开了新空间，空间大小和size有关系
	//开新数组
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
	//释放空间
	free(newArray);
#endif

	//第三种删除方式
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

//使用场景
void Test()
{
	SeqList seqList;
	SeqListInit(&seqList);

	SeqListPushFront(&seqList, 1);
	SeqListPushFront(&seqList, 1);
	SeqListPushFront(&seqList, 1);
	SeqListPushFront(&seqList, 1);
	SeqListPushFront(&seqList, 1);//头插

	//SeqListPushBack(&seqList, 6);//尾插
	//SeqListInsert(&seqList, 3, 7);//插入

	//SeqListPopFront(&seqList);//头删
	//SeqListPopBack(&seqList);//尾删
	//SeqListErase(&seqList, 3);//删除
	SeqListRemoveAll(&seqList, 1);


	SeqListPrint(&seqList);
}
