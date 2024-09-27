#include"MyVector.h"

template<class T>
void MyVector<T>::reverse(size_t n)
{
    if(n > capacity())
    {
        T* temp = new T[n];
        size_t oldSize = size();
        if(_start)
        {
            for (size_t i = 0; i < oldSize; i++)
                temp[i] = _start[i];
            delete[] _start;
        }

        _start = temp;
        _finish = temp + oldSize;
        _end_of_storage = temp + n;
    }
}

template<class T>
void MyVector<T>::resize(size_t n, T val)
{
    if(n > capacity())  reverse(n);
    if(n > size())
    {
        while(_finish < _start + n)
        {
            *_finish = val;
            ++_finish;
        }
    }
    else
        _finish = _start + n;
}

template<class T>
void MyVector<T>::push_back(const T& val)
{
    if(_finish == _end_of_storage)
    {
        size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
        reverse(newcapacity);
    }

    *_finish = val;
    _finish++;
}

template<class T>
void MyVector<T>::pop_back()
{
    assert(!empty);
    --_finish;
}

template<class T>
void MyVector<T>::swap(MyVector<T>& val)
{
    std::swap(_start, val._start);
    std::swap(_finish, val._finish);
    std::swap(_end_of_storage, val._end_of_storage);
}

template<class T>
T* MyVector<T>::insert(iterator pos,const T& val)
{
    assert(pos <= _finish);
    assert(pos >= _start);

    if(_finish == _end_of_storage)
    {
        int len = pos - _start;
        size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
        reverse(newcapacity);
        pos = _start + len;
    }

    iterator end = _finish - 1;
    while(end >= pos)
    {
        *(end + 1) = *(end);
        --end;
    }
    *pos = val;
    ++_finish;

    return pos;
}

template<class T>
T* MyVector<T>::erase(iterator pos)
{
    assert(pos <= _finish);
    assert(pos >= _start);

    iterator begin = pos + 1;
    while(begin < _finish)
    {
        *(begin - 1) = *begin;
        ++begin;
    }
    --_finish;
    return pos;
}