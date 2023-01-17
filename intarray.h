
#pragma once
#include <iostream>
using namespace std;


class IntArray
{
private:
    int _length{};
    int* _data{};
public:
    IntArray(int length);
    /// размер массива
    int size() const { return _length; }
    /// очистить массив
    void clear();
    /// изменить размер массива все элемены удаляются
    void reallocate(int newLength);
    /// изменить размер массива с сохранением элементов
    void resize(int newLength);
    /// записать в ячейку число
    void insert(int value, int index);
    /// удалить ячейку с индексом
    void remove(int index);
    /// вставить элемент в начало массива
    void push_front(int value) { insert(value, 0);}
    /// вставить элемент в конец массива
    void push_back(int value) { insert(value, _length);}
    /// найти число в массиве и вывести индекс найденного числа
    int find(const int num);
    /// проверка к пренадлежности к диапазону массива
    void bad_range(const int index);
    void bad_length(const int length);
    IntArray(const IntArray& a);

    ~IntArray(){delete[] _data;};

    int& operator[](int index)
    {
        try
        {
            bad_range(index);
        }
        catch (const char* exception)
        {
            cout << " Ошибка : число " << index << exception;
        }
        return _data[index];
    }

    IntArray& operator=(const IntArray& a)
    {
        if (&a == this)
            return *this;
        reallocate(a.size());
        for (int index{ 0 }; index < _length; ++index)
            _data[index] = a._data[index];
        return *this;
    }

};


