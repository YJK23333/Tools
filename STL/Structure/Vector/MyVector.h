#ifndef MYVECTOR_H
#define MYVECTOR_H

#include<cassert>


template<class T>
class MyVector
{
    typedef T* iterator;
    typedef const T* const_iterator;
public:
    MyVector() : 
        _start(nullptr),
        _finish(nullptr),
        _end_of_storage(nullptr)
    {}

    ~MyVector()
    {
        if(_start)
        {
            delete[] _start;
            _start = _finish = _end_of_storage = nullptr;
        }
    }

    MyVector(size_t n, const T& val = T()) :
        _start(nullptr),
        _finish(nullptr),
        _end_of_storage(nullptr)
    {
        reverse(n);
        for (size_t i = 0; i < n; i++)
            push_back(val);
    }

    MyVector(const MyVector<T>& val) :
        _start(nullptr),
        _finish(nullptr),
        _end_of_storage(nullptr)
    {
        MyVector<T> temp(val.begin(), val.end());
        swap(temp);
    }

    explicit MyVector(int n, const T& val = T()) :
        _start(nullptr),
        _finish(nullptr),
        _end_of_storage(nullptr)
    {
        reverse(n);
        for(int i = 0 ; i < n ; i++)
            push_back(val);
    }

    template<class InputIterator>
    MyVector(InputIterator first, InputIterator last)
    {
        while(first != last)
        {
            push_back(*first);
            first++;
        }
    }

    MyVector<T>& operator=(MyVector<T> val)
    {
        swap(val);
        return *this;
    }

public:
    iterator begin()    { return _start; }
    iterator end()      { return _finish; }
    const_iterator begin()  const   { return _start; }
    const_iterator end()    const   { return _finish; }

    T& operator[](size_t pos)   { assert(pos < size()); return _start[pos]; }
    const T& operator[](size_t pos) const   { assert(pos < size()); return _start[pos]; }
    bool empty()    const   { return _finish = _start; }
    size_t size()   const   { return _finish - _start; }
    size_t capacity()   const   { return _end_of_storage - _start; }
    void clear()    { _finish - _start; }

    void reverse(size_t n);
    void resize(size_t n, T val = T());
    void push_back(const T& val);
    void pop_back();
    void swap(MyVector<T>& val);

    iterator insert(iterator pos,const T& val);
    iterator erase(iterator pos);

private:
    iterator _start;
    iterator _finish;
    const_iterator _end_of_storage;

};

#endif