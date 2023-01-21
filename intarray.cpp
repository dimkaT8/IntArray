#include "intarray.h"
#include <iostream>
using namespace std;

template<class T>
IntArray<T>::IntArray(int length)
{
    _length = length;
    try
    {
        bad_length(length);
        _data = new T[length]{};
    }
    catch (MyException &exc)
    {
        cout << "An array exception occurred (" << exc.what() << " " << length  << " )" <<endl;
    }
    // добавим std::exception , вдруг памяти не хватит !
    catch (exception &exc)
    {
        cout << "Some other std::exception occurred (" << exc.what() << " )" << endl;
    }
}

template<class T>
void IntArray<T>::clear()
{
    delete[] _data;
    _data = nullptr;
    _length = 0;
}

template<class T>
void IntArray<T>::reallocate(int newLength)
{
    clear();

    if (newLength <= 0) return;

   // _data = new int[newLength];
    _data = new T[newLength];
    _length = newLength;
}

template<class T>
void IntArray<T>::resize(int newLength)
{
    if (newLength == _length) return;
    if (newLength <= 0)
    {
        clear();
        return;
    }
   // int* data{ new int[newLength] };
    T* data{ new T[newLength] };
    if (_length > 0)
    {
        int elementsToCopy{ (newLength > _length) ? _length : newLength };
        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = _data[index];
    }
    delete[] _data;
    _data = data;
    _length = newLength;
}

template<class T>
void IntArray<T>::insert(T value, int index)
{
    try
    {
        bad_range(index);
    }
    catch (MyException &exc)
    {
        cout << "An array exception occurred (" << exc.what() << " " << index  << " )" <<endl;
    }

    //int* data{ new int[_length+1] };

    T* data{ new T[_length+1] };
    for (int before{ 0 }; before < index; ++before)
        data[before] = _data[before];

    data[index] = value;

    for (int after{ index }; after < _length; ++after)
        data[after+1] = _data[after];

    delete[] _data;
    _data = data;
    ++_length;
}

template<class T>
void IntArray<T>::remove(int index)
{
    try
    {
        bad_range(index);
    }
    catch (MyException &exc)
    {
        cout << "An array exception occurred (" << exc.what() << " " << index  << " )" <<endl;
    }

    if (_length == 1)
    {
        clear();
        return;
    }
    //int* data{ new int[_length-1] };
    T* data{ new T[_length-1] };
    for (int before{ 0 }; before  < index; ++before)
        data[before] = _data[before];
    for (int after{ index+1 }; after < _length; ++after)
        data[after-1] = _data[after];
    delete[] _data;
    _data = data;
    --_length;
}

template<class T>
int IntArray<T>::find(const T num)
{
    for(int i{ 0 }; i < _length ; i++)
    {
        if( num == _data[i] ) return i ;
    }
    return -1;
}

template<class T>
void IntArray<T>::bad_range(const int index)
{
    if((index < 0) || (index > _length)) throw MyException(" Invalid index");
}

template<class T>
void IntArray<T>::bad_length(const int length)
{
    if(length < 1) throw MyException(" Invalid index");
}

template<class T>
IntArray<T>::IntArray(const IntArray& a)
{
    reallocate(a.size());

    for (int index{ 0 }; index < _length; ++index)
        _data[index] = a._data[index];
}


