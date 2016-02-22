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
    /*void Sort() 	//对当前的表排序*/
end LinearList
```
* 线性表：顺序表
> 顺序表的存储表示有两种：静态存储和动态存储
    * 静态存储
    ```
    #define MaxSize 100
    typedef int T;

    typedef struct
    {
    	T data[MaxSize];
	int n;
    }SeqList;
    ```
    * 动态存储
    ```
    typedef int T;
    typedef struct
    {
        T* data;
	int MaxSize, n;
    }SeqList;
    ```
* 文件组织 
    * **LinearList.h**定义了一个纯虚类，定义了线性表的接口。
    * **SeqList.h**定义了顺序表实现。
    * **SeqApply.h**定义了顺序表的集合并和交操。
    * **main.cpp**定义了测试函数。

* 线性表：单链表

> 简化的操作：用struct定义LinkNode类
在List中封装头指针first，这样属于该List的所有LinkNode实例都成为List实例的私有成员，从而保证不被外界直接访问。

```
struct LinkNode
{
    int data;
    LinkNode* Link;
};

class List
{
private:
    LinkNode* first;
public:
    //链表的操作；
    ...
};

```
/**
 *在单链表(a1, a2, a3, ..., an)中对ai位置上插入一个新的元素x，有以下三种情况。
 *(1)若ai是第一个元素，这应该插入第一个节点之前：
 *    newNode->link = first; first = newNode;
 *(2)若ai所在结点不是第一个节点，也不是最后一个结点：
 *    newNode->link = current->next; current->next = newNode;
 *(3)若ai是最后一个结点后面的结点：
 *    newNode->link = current->next; current->next = newNode;
 */
bool List::Insert(int i, int& x)
{
    //若是插入第一个节点或者头指针为NULL；
    if(first == NULL || i == 0)
    {
        LinkNode* newNode = new LinkNode(x);
        if(newNode == NULL)
        {
            cerr<<"存储分配错误！"<<endl;
            return false;
        }
        newNode->next = first->next;
        first = newNode;
    }
    else
    {
        LinkNode* current = first;
        for(int k = 1; k < i; k++)
        {
            if(current == NULL) break;
            else current = current->link;
        }
        if(current == NULL)
        {
            cerr<<"无效的插入位置！"<<endl;
            return false;
        }
        else
        {
            LinkNode *newNode = new LinkNode(x);
            if(newNode == NULL)
            {
                cerr<<"存储分配错误！"<<endl;
                return false;
            }
            newNode->link = current->link;
            current->link = newNode;
        }
    }
    return true;
}

/**
 *单链表的删除算法，分为两种情况：
 *(1) 在链表第一个结点处删除。
 *    del = first; first = first->link; delete del;
 *(2) 中间和最后的结点处进行删除。这里current指向要删除结点之前的一个结点。
 *    del = current->link; current->link = del->link; delete del;
 */

bool List::Remove(int i, int& x)
{
    LinkNode *del, *current;
    if(i<=1)
    {
        del = first;
        first = first->link;
    }
    else
    {
        current = first;
        for(int k = 1; k < i-1; k++)
        {
            if(current == NULL) break;
            else
            {
                current = current->link;
            }
        }
        if(current == NULL)
        {
            cerr<<"无效的删除位置！"<<endl;
            return false;
        }
        del = current->link;
        current->link = del->link;
    }
    x = del->data;
    delete del;
    return true;
}
```
