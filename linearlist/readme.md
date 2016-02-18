## 线性表
> 线性结构是简单且常用的数据结构，而线性表是一种典型的线性结构。
在程序中存储数据，最简单，最有效的方法是把它们存放在一个线性表中，只有当需要组织和搜索大量数据时，才考虑使用更复杂的数据结构。

* 线性表的抽象数据类型
```
ADT LinearList is
Objects: n(>=0)个原子表项的一个有限序列，每个表项的数据类型为T。
Function:
    create()	//创建一个空线性表
    int Length()	//计算表长度
    int search(T& x) 	//搜索函数：找x在表中的位置，返回表项位置
    int Locate(int i) 	//定位函数：返回第i个表项在表中位置
    bool getData(int i, T& x)	//取第i个表项的值
    void setDate(int i, T& x)	//用x修改第i个表项的值
    bool Insert(int i, T& x)	//插入x在表中第i个表项之后，函数返回成功标志
    bool Remove(int i, T& x)	//删除表中第i个表项，通过x返回删除表项的值，函数返回成功标志
    bool IsEmpty()	//判断表是否为空
    bool IsFull()	//判断表是否满
    void CopyList(List<T>& L) 	//将L复制到当前的表中
    void Sort() 	//对当前的表排序
end LinearList
```
    
