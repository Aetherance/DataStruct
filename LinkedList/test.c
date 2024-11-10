#include "Slist.h"

void TestSL1()
{
    SLTNode * plist = NULL;
    SListPushBack(&plist,1);
    SListPushBack(&plist,2);
    SListPushBack(&plist,3);
    SListPushBack(&plist,4);
    SListPrint(plist);
}
void TestSL2()
{
    SLTNode * plist = NULL;
    SListPushFront(&plist,-4);
    SListPushFront(&plist,-3);
    SListPushFront(&plist,-2);
    SListPushFront(&plist,-1);
    SListPushFront(&plist,0);
    SListPrint(plist);
}
void TestSL3()
{
    SLTNode * plist = NULL;
    SListPushFront(&plist,3);
    SListPushFront(&plist,2);
    SListPushFront(&plist,1);
    SListPrint(plist);

    SListPopBack(&plist);
    SListPopBack(&plist);
    SListPopBack(&plist);
    SListPopBack(&plist);

    SListPrint(plist);
    
}
void TestSL4()
{
    SLTNode * plist = NULL;
    SListPushFront(&plist,3);
    SListPushFront(&plist,2);
    SListPushFront(&plist,1);
    SListPopFront(&plist);
    SListPrint(plist);

    SListPopFront(&plist);
    SListPopFront(&plist);
    SListPrint(plist);
    SListPopFront(&plist);
    SListPopFront(&plist);
    SListPopFront(&plist);
    SListPrint(plist);
    
}
void TestSL5()
{
    SLTNode * plist = NULL;
    SListPushFront(&plist,3);
    SListPushFront(&plist,2);
    SListPushFront(&plist,1);
    SLTNode* pos1 = SListFind(plist,2);
    if(pos1)
    {
        SListInsert(&plist,pos1,30);
    }
    SLTNode* pos2 = SListFind(plist,1);
    if(pos1)
    {
        SListInsert(&plist,pos2,0);
    }
    SListPrint(plist);
}
void TestSL6()
{
    SLTNode* plist = NULL;
    SListPushFront(&plist,3);
    SListPushFront(&plist,2);
    SListPushFront(&plist,1);
    SListPrint(plist);
    SLTNode* pos1 = SListFind(plist,2);
    if(pos1)SListErase(&plist,pos1);
    SListPrint(plist);
    SListDestroy(&plist);




    SListPrint(plist);
}
int main()
{
    TestSL6();
    return 0;
}

