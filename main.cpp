#include "intarray.h"

int main()
{
    // если при создании массива длинна массива будет меньше 1
    //IntArray array(0); // " An array exception occurred ( Invalid index 0 ) "
    IntArray<int> array(10);

    for (int i{ 0 }; i<10; ++i) array[i] = i;

    array.resize(8);

    array.insert(15, 5);
   // array.insert(15, 15); //" An array exception occurred ( Invalid index 15 ) "

    array.remove(3);
    //array.remove(15);// " An array exception occurred ( Invalid index 15 ) "

    array.push_back(60);
    array.push_front(30);

    for (int i{ 0 }; i < array.size(); ++i) cout << array[i] << ' ';
    cout << endl;

    // найдем в массиве значение 15 и выведем индекс ячейки , если  значения 15 нет выводим -1
    cout << " " << array.find(15) << endl;
    return 0;
}
