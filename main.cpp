#include <iostream>

template <typename T>
class SmartPointer
{
public:
    SmartPointer()
    {
    }

    // SmartPointer(const SmartPointer<T>& ptr) : m_ptr(ptr)
    // {
    // }

    SmartPointer(T* ptr) : m_ptr(ptr)
    {   
    }


    SmartPointer<T>& operator=(const SmartPointer<T>& obj)
    {
        delete m_ptr;
        m_ptr = obj.m_ptr;
    }

    SmartPointer<T>& operator=(T* ptr)
    {
        delete m_ptr;
        m_ptr = ptr;
    }

    ~SmartPointer()
    {
        delete m_ptr;
    }
    
    T operator*()
    {
        return *m_ptr;
    }

    T operator*() const
    {
        return *m_ptr;
    }

    T* operator->()
    {
        return m_ptr;
    }

    T* operator->() const
    {
        return m_ptr;
    }

private:
    T* m_ptr = nullptr;

};

class A
{
public:
    int x = 10;
    int y = 50;
};

int main()
{   
    SmartPointer<int> ptr(new int(5));
    SmartPointer<int> ptr1(new int(10));

    std::cout<<*ptr<<std::endl;

    ptr = ptr1;

    std::cout<<*ptr<<std::endl;

    ptr = new int(100);

    std::cout<<*ptr<<std::endl;

    SmartPointer<A> obj = new A();
    std::cout<<obj->x<<std::endl;

    return 0;
}