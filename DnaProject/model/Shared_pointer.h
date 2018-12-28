//
// Created by gity on 12/27/18.
//

#ifndef DNAPROJECT_SHARED_POINTER_H
#define DNAPROJECT_SHARED_POINTER_H
#include <stdlib.h>
#include <new>

#ifdef TESTING
#define Test_print(str)  std::cout << str << std::endl
#else
#define Test_print(str)
#endif //TESTING

template <typename T>
class SharePointer
{
public:
    explicit SharePointer(T* ptr = NULL);
    SharePointer(const SharePointer& other);
    ~SharePointer();

    SharePointer& operator=(const SharePointer& other);

    T* operator->() const;
    T& operator*() const;
    bool operator==(const SharePointer& other) const;
    bool operator!=(const SharePointer& other) const;

    T* get() const;
    size_t* get_count() const;
    operator bool() const;

private:
    T* m_ptr;
    size_t* m_count;
};

template <typename T>
SharePointer<T>::SharePointer(T *ptr) try
    : m_ptr(ptr),
    m_count(new size_t(1))
{}
catch(std::bad_alloc& e)
{
    delete ptr;
    throw;
}
template <typename T>
SharePointer<T>::SharePointer(const SharePointer &other)
{
    //Test_print("copy constractor");
    m_ptr = other.m_ptr;
    m_count = other.m_count;
    (*m_count)++;
}

template <typename T>
SharePointer<T>::~SharePointer()
{
    //Test_print("distractor");
    (*m_count)--;
    if(*m_count == 0)
    {
        Test_print("SharePointer :: DTOR - deleted");
        delete m_ptr;
        delete m_count;
    }
    else
    {
        Test_print("SharePointer :: DTOR - not deleted");
    }
}

template <typename T>
SharePointer<T>& SharePointer<T>::operator=(const SharePointer &other)
{
    //Test_print("asigment operator");
    if(m_ptr)
    {
        delete m_ptr;
        delete m_count;
    }

    m_ptr = other.m_ptr;
    m_count = other.m_count;

    (*m_count)++;

    return *this;
}

template <typename T>
T* SharePointer<T>::operator->() const
{
    //Test_print("operator->");
    return m_ptr;
}

template <typename T>
T& SharePointer<T>::operator*() const
{
    //Test_print("operator*");
    return *m_ptr;
}

template <typename T>
bool SharePointer<T>::operator!=(const SharePointer &other) const
{
    //Test_print("operator!=");
    return m_ptr != other.m_ptr || m_count != other.m_count;
}

template <typename T>
bool SharePointer<T>::operator==(const SharePointer &other) const
{
    //Test_print("operator==");
    return m_ptr == other.m_ptr && m_count == other.m_count;
}

template <typename T>
T* SharePointer<T>::get() const
{
    //Test_print("get");
    return m_ptr;
}

template <typename T>
size_t * SharePointer<T>::get_count() const
{
    //Test_print("get");
    return m_count;
}

template <typename T>
SharePointer<T>::operator bool() const
{
    //Test_print("bool operator");
    return m_ptr != NULL;
}
#endif //SHAREPOINTER_SHAREPOINTER_H

