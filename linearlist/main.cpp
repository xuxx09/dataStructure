#include <iostream>
#include "SeqList.h"

using namespace std;

int main()
{
    SeqList<int > l(200);
    cout<<l.Length()<<" "<<l.Size()<<endl;
    return 0;
}
