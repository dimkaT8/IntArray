#include <iostream>
#include "intarray.h"
using namespace std;

int main()
{
    // если при создании массива длинна массива будет меньше 1
    // " Ошибка : число 0 меньше 1 "
    IntArray array(10);

    for (int i{ 0 }; i<10; ++i) array[i] = i;

    array.resize(8);

    array.insert(15, 5);// при вводе числа больше длинны массива или меньше 0 " ошибка "

    array.remove(3); // при вводе числа больше длинны массива или меньше 0 " ошибка "

    array.push_back(60);
    array.push_front(30);

    for (int i{ 0 }; i < array.size(); ++i) cout << array[i] << ' ';
    cout << endl;

    // найдем в массиве значение 15 и выведем индекс ячейки , если  значения 15 нет выводим -1
    cout << " " << array.find(15) << endl;
    return 0;
}
