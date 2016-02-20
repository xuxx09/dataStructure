#include <iostream>
#include <stdlib.h>
#include "LinearList.h"
/**
 *ģ�庯�����ܽ���ͷ�ļ��ͺ�������ķ���
 */
const int defaultSize = 100;
template <class T>
class SeqList: public LinearList<T>
{
protected:
    T* data;
    int maxSize;
    int last;
    void reSize(int newSize);
public:
    SeqList(int sz = defaultSize);
    SeqList(SeqList<T>& L);
    ~SeqList()
    {
        delete[] data;
    }
    int Size()const
    {
        return maxSize;
    }
    int Length()const
    {
        return last+1;
    }
    int Search(T& x)const;
    int Locate(int i)const;
    bool getData(int i, T& x)const
    {
        if(i>0 && i<=last+1)
        {
            x = data[i-1];
            return true;
        }
        else
            return false;
    }
    void setData(int i, T& x)const
    {
        if(i>0 && i<=last+1)
        {
            data[i-1] = x;
        }
    }
    bool Insert(int i, T& x);
    bool Remove(int i, T& x);
    bool IsEmpty()const
    {
        return (last == -1) ? true : false;
    }
    bool IsFull()const
    {
        return (last == maxSize - 1) ? true : false;
    }
    void input();
    void output();
};


template <class T>
SeqList<T>::SeqList(int sz)
{
    if(sz > 0)
    {
        maxSize = sz;
        last = -1;
        data = new T[maxSize];
        if(data== NULL)
        {
            std::cerr<<"�洢�������"<<std::endl;
            exit(1);
        }
    }
}

template <class T>
SeqList<T>::SeqList(SeqList<T>& L)
{
    maxSize = L.Size();
    last = L.Length()-1;
    T value;
    data = new T[maxSize];
    if(data == NULL)
    {
        std::cerr<<"�洢�������"<<std::endl;
        exit(1);
    }
    for(int i = 1; i <= last+1; i++)
    {
        L.getData(i, value);
        data[i-1] = value;
    }
}

template <class T>
void SeqList<T>::reSize(int newSize)
{
    if(newSize <= 0)
    {
        std::cerr<<"��Ч�������С"<<std::endl;
        return;
    }
    if(newSize != maxSize)
    {
        T* newarray = new T[newSize];
        if(newarray == NULL)
        {
            std::cerr<<"�洢�������"<<std::endl;
            exit(1);
        }
        int n = last + 1;
        T* srcptr = data;
        T* desptr = newarray;
        while(n--) *desptr++ = *srcptr++;
        delete[] data;
        data = newarray;
        maxSize = newSize;
    }
}

/**
 *�����Ͷ�λ
 */
template <class T>
int SeqList<T>::Search(T& x) const
{
    for(int i = 0; i <= last; i++)
    {
        if(data[i] == x) return i+1;
    }
    return 0;
}

template <class T>
int SeqList<T>::Locate(int i)const
{
    if(i >= 1 && i <= last+1)
        return i;
    else return 0;
}

/**
 *�����ɾ������
 */
template <class T>
bool SeqList<T>::Insert(int i, T& x)
{
    if(last == maxSize-1)
        return false;
    if(i < 0 || i > last + 1)
        return false;
    for(int j = last; j>=i; j--)
    {
        data[j+1] = data[j];
    }
    data[i] = x;
    last++;
    return true;
}

template <class T>
bool SeqList<T>::Remove(int i, T& x)
{
    if(last == -1)
        return false;
    if(i < 1 || i > last+1)
        return false;
    x = data[i-1];
    for(int j=i; j <= last; j++)
        data[j-1] = data[j];
    last--;
    return true;
}

/**
 *������������͸�ֵ����
 */
template <class T>
void SeqList<T>::input()
{
    std::cout<<"��ʼ����˳������������Ԫ�ظ����� ";
    while(1)
    {
        std::cin>>last;
        if(last <= maxSize-1) break;
        std::cout<<"����Ԫ�ظ����������󣬷�Χ���ܳ���"<<maxSize-1<<std::endl;
    }
    for(int i = 0; i <= last; i++)
    {
        std::cin>>data[i];
        std::cout<< i+1 <<std::endl;
    }
}

template <class T>
void SeqList<T>::output()
{
    std::cout<<"˳���ǰԪ�����λ��Ϊ��"<<last <<std::endl;
    for(int i = 0; i <= last; i++)
    {
        std::cout<<"#"<<i+1<<": "<<data[i]<<std::endl;
    }
}


