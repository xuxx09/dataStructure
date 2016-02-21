#include <iostream>
#include "SeqList.h"
#include "SeqApply.h"

using namespace std;

int main()
{
    SeqList<int> la(2);
    la.input();
    SeqList<int> lb(3);
    lb.input();
    Union(la, lb);
    la.output();
    Intersection(la, lb);
    la.output();
    cout << la.Length() << endl;
    return 0;
}
