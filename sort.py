# -*- coding: cp936 -*-
l = [0,223,4,0]
#插入排序
def InsertSort(lists):
    for i in range(0,len(lists)):
        key = lists[i]
        j = i - 1
        while j >= 0:
            if lists[j] > key:
                lists[j+1] = lists[j]
                j=j-1
            else:
                break
        lists[j+1] = key
    return lists
InsertSort(l)

                
        
    
