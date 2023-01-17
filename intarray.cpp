#include "intarray.h"
#include <iostream>
using namespace std;

IntArray::IntArray(int length)
{
   _length = length;
   try
   {
       bad_length(length);
   }
   catch (const char* exception)
   {
       cout << " Ошибка : число " << length << exception << endl;
   }
   if (length > 0)
       _data = new int[length]{};
}

void IntArray::clear()
{
    delete[] _data;
    _data = nullptr;
    _length = 0;
}

void IntArray::reallocate(int newLength)
{
    clear();

    if (newLength <= 0) return;

    _data = new int[newLength];
    _length = newLength;
}

void IntArray::resize(int newLength)
{
    if (newLength == _length) return;
    if (newLength <= 0)
    {
        clear();
        return;
    }
    int* data{ new int[newLength] };
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

void IntArray::insert(int value, int index)
{
    try
    {
        bad_range(index);
    }
    catch (const char* exception)
    {
        cout << " Ошибка : число " << index << exception;
    }
    int* data{ new int[_length+1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = _data[before];

    data[index] = value;

    for (int after{ index }; after < _length; ++after)
        data[after+1] = _data[after];

    delete[] _data;
    _data = data;
    ++_length;
}

void IntArray::remove(int index)
{
    try
    {
        bad_range(index);
    }
    catch (const char* exception)
    {
        cout << " Ошибка : число " << index << exception << endl;
    }

    if (_length == 1)
    {
        clear();
        return;
    }
    int* data{ new int[_length-1] };
    for (int before{ 0 }; before  < index; ++before)
        data[before] = _data[before];
    for (int after{ index+1 }; after < _length; ++after)
        data[after-1] = _data[after];
    delete[] _data;
    _data = data;
    --_length;
}

int IntArray::find(const int num)
{
    for(int i{ 0 }; i < _length ; i++)
    {
        if( num == _data[i] ) return i ;
    }
    return -1;
}

void IntArray::bad_range(const int index)
{
    if(index < 0) throw " меньше 0 \n";
    if(index > _length) throw " больше длинны массива \n";

}

void IntArray::bad_length(const int length)
{
    if(length < 1) throw " меньше 1 \n";
}

IntArray::IntArray(const IntArray& a)
{
    reallocate(a.size());

    for (int index{ 0 }; index < _length; ++index)
        _data[index] = a._data[index];
}


