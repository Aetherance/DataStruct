#include"Slist.h"
SLTNode*BuyListNode(SLTDataType x)
{
    SLTNode * newnode = (SLTNode*)malloc(sizeof(SLTDataType));
    if(newnode == NULL)exit(-1);
    newnode->data = x;
    newnode->next = NULL;//尾标
    return newnode;
}

void SListPrint(SLTNode*phead)
{
    SLTNode* cur = phead;
    while(cur != NULL)
    {
        printf("%d->",cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

//尾插 
//要让原来的尾指向新节点，新的尾指向NULL
void SListPushBack(SLTNode**phead,SLTDataType x)
{
    SLTNode*newnode = BuyListNode(x);

    //每次先新建一个节点，如果没有头节点，就让newnode成为头节点
    if(*phead == NULL)
        *phead = newnode;
    //不可以一上来就找尾 因为可能解引用空指针造成段错误
    else 
    {
        SLTNode*tail = *phead;
        //找到tail
        while(tail->next!=NULL)
            tail = tail->next;
    tail->next = newnode;

    }
}

void SListPushFront(SLTNode**phead,SLTDataType x)
{
    SLTNode * newnode = BuyListNode(x);
    //头插 让新节点的指针指向头 再让头指向新节点
    newnode->next = *phead;
    *phead = newnode;
}
void SListPopBack(SLTNode** pphead)
{
    //要分类讨论
    if(*pphead == NULL)return;//一个都没有
    if((*pphead)->next == NULL)//只有一个
    {
        free (*pphead);
        *pphead = NULL;
    }
    else
    {
        SLTNode * prev = NULL;;
        SLTNode * tail = *pphead;
        while(tail->next != NULL)
        {
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        prev->next = NULL;
        tail->next = NULL;
    }
}
void SListPopFront(SLTNode**pphead)
{
    if(*pphead == NULL)return;
    SLTNode*head = *pphead;
    *pphead = (*pphead)->next;
    free(head);
}

SLTNode*SListFind(SLTNode * phead,SLTDataType x)
{
    SLTNode* cur = phead;
    while(cur)
    {
        if(cur->data == x)
            return cur;
        else
            cur = cur->next;

    }
    return NULL;
}//find在找的同时还有改的能力
void SListInsert(SLTNode**pphead,SLTNode*pos,SLTDataType x)
{   
    if(pos == *pphead)
    {
        //第一个要特判为头插
        SListPushFront(pphead,x);
        return;
    }
    SLTNode*newnode = BuyListNode(x);
    SLTNode*posPrev = *pphead;
    while(posPrev->next != pos)
        posPrev = posPrev->next;
    posPrev->next = newnode;
    newnode->next = pos;

}
//单链表适合在pos后边插 效率有很大差距  这也是单链表天生的缺陷 此时就要用到双向链表 这个网址怎么进入？
void SListErase(SLTNode**pphead,SLTNode*pos)
{
    //pos位于头的时候 相当于头删
    if(pos == *pphead)
    {
        SListPopFront(pphead);
        return;
    }
    SLTNode*FrontPos = *pphead;
    while (FrontPos->next!=pos)
        FrontPos = FrontPos->next;
    FrontPos->next = pos->next;
    free(pos);
    
}

void SListDestroy(SLTNode**pphead)
{
    if(pphead == NULL)return;
    SLTNode*tail = *pphead;
    while(tail!=NULL)
    {
        SLTNode* temp = tail;
        tail = tail->next;
        free(temp);
    }
    *pphead = NULL;

}
