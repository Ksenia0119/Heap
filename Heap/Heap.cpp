//@author Maltseva K.V.

#include <iostream>
#include <algorithm>
#include <vector>
#include "Heap.h" 
#include"HeapTest.h"
int main()
{
    setlocale(LC_ALL, "ru");
    try {
        // Создание объекта кучи типа int с максимальным размером 10
        Heap<int> heap(10);

        // Вставка элементов в кучу
       // heap.Insert(3);
        heap.Insert(9);
        heap.Insert(2);
        heap.Insert(1);
        heap.Insert(4);
        heap.Insert(5);
        heap.Insert(12);
        //heap.Insert(8);

       /*       9
               / \
              4     5
              / \ /
            1   3 2*/
            // Печать элементов кучи
        heap.printHeap();
        // Удаление элемента из кучи
        heap.deleteNode(3);
        heap.deleteNode(12);
        cout<<"Индекс искомого элемента = "<<heap.Find(2) << endl;
        // Печать элементов кучи
        heap.printHeap();

        //размер кучи
        cout << "Размер кучи:" << heap.Size() << endl;

        // Проверка на пустоту кучи
        if (heap.IsEmpty()) {
            cout << "Куча пуста" << endl;
        }
        else {
            cout << "Куча не пуста" << endl;
        }
        cout << endl;
        vector<int> vec{ 9,4,5,2,1 };
        // организует массив по принципу кучи (max heap)
        std::make_heap(vec.begin(), vec.end());

        for (int x : vec)
            cout << x << " ";
        cout << endl;

        TestInsert();
        TestSize();
        TestIsEmpty();
        TestConstructor();
        TestFind();
    }//перехватываем исключительные ситуации
    catch (invalid_argument& error) {
        // Обработка исключения invalid_argument
        cout << "Ошибка: " << error.what() << endl;
    }
    

    return 0;
}