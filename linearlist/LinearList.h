/**
 *头文件定义了线性表的抽象基类
 */
enum bool{false, true};
template <class T>
class LinearList
{
public:
    LinearList();
    ~LinearList();
    virtual int Size()const = 0;
    virtual int Length()const = 0;
    virtual int Search(T& x)const = 0;
    virtual int Locate(int i)const = 0;
    virtual bool getDate(int i, T& x)const = 0;
    virtual void setDate(int i, T& x)const = 0;
    virtual bool Insert(int i, T& x) = 0;
    virtual bool Remove(int i, T& x) = 0;
    virtual bool IsEmpty()const = 0;
    virtual bool IsFull()const = 0;
    virtual void Sort() = 0;
    virtual void input() = 0;
    virtual void output() = 0;
    virtual LinearList<T> operator=(LinearList<T>& L) = 0;
};

