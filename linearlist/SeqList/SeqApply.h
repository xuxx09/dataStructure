#ifndef LINEARLIST_INCLUDE_SEQAPPLY_H_
#define LINEARLIST_INCLUDE_SEQAPPLY_H_

#include "SeqList.h"

void Union(SeqList<int> & LA, SeqList<int>& LB)
{
    int n = LA.Length(), m =LB.Length(), i, k, x;
    for(i = 1; i <= m; i++)
    {
        LB.getData(i,x);
        k = LA.Search(x);
        if(k == 0)
        {
            LA.Insert(n, x);
            n++;
        }
    }
}

//两个链表的交集
void Intersection(SeqList<int>& LA, SeqList<int>& LB)
{
    int n = LA.Length(), i = 1, k, x;
    while(i <= n)
    {
        LA.getData(i,x);
        k = LB.Search(x);
        if(k == 0)
        {
            LA.Remove(i, x);
            n--;
        }
        else i++;
    }
}

#endif // LINEARLIST_INCLUDE_SEQAPPLY_H_
