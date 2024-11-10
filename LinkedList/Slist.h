#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int SLTDataType;
typedef struct SListNode
{
    int data;
    struct SListNode* next;
}SLTNode;
void SListPrint(SLTNode*phead);
void SListPushBack(SLTNode**phead,SLTDataType x);
void SListPushFront(SLTNode**phead,SLTDataType x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);
SLTNode*SListFind(SLTNode * phead,SLTDataType x);
void SListInsert(SLTNode**pphead,SLTNode*pos,SLTDataType x);
void SListErase(SLTNode**pphead,SLTNode*pos);
void SListDestroy(SLTNode**pphead);