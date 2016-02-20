#ifndef LINEARLIST_INCLUDE_LINEARLIST_H_
#define LINEARLIST_INCLUDE_LINEARLIST_H_

/**
 *头文件定义了线性表的抽象基类
 */
//enum bool{false, true};
template <class T>
class LinearList
{
public:
    virtual int Size()const = 0;
    virtual int Length()const = 0;
    virtual int Search(T& x)const = 0;
    virtual int Locate(int i)const = 0;
    virtual bool getData(int i, T& x)const = 0;
    virtual void setData(int i, T& x)const = 0;
    virtual bool Insert(int i, T& x) = 0;
    virtual bool Remove(int i, T& x) = 0;
    virtual bool IsEmpty() const = 0;
    virtual bool IsFull() const = 0;
    virtual void input() = 0;
    virtual void output() = 0;
};

#endif // LINEARLIST_INCLUDE_LINEARLIST_H_
