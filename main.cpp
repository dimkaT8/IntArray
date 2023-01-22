#include "intarray.h"

int main()
{
    // если при создании массива длинна массива будет меньше 1
    //IntArray array(0); // " An array exception occurred ( Invalid index 0 ) "
    IntArray<int> array(15);
    for (int i{ 0 }; i<15; ++i) array[i] = i;
    array.resize(13);
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

    IntArray<double> arrayd(15);
    for (int i{ 0 }; i<15; ++i) arrayd[i] = i + 0.6;
    arrayd.resize(13);
    arrayd.insert(15, 5);
    arrayd.remove(3);
    arrayd.push_back(60);
    arrayd.push_front(30);
    for (int i{ 0 }; i < arrayd.size(); ++i) cout << arrayd[i] << ' ';
    cout << endl;
    cout << " " << arrayd.find(15) << endl;

    IntArray<string> arrays(15);
    for (int i{ 0 }; i<15; ++i) arrays[i] = "str-" + to_string(i + 0.6);
    arrays.resize(13);
    arrays.insert("str-15", 5);
    arrays.remove(3);
    arrays.push_back("str-60");
    arrays.push_front("str-30");
    for (int i{ 0 }; i < arrays.size(); ++i) cout << arrays[i] << ' ';
    cout << endl;
    cout << " " << arrays.find("str-15") << endl;
    return 0;
}
