//@author Maltseva K.V.

#include <iostream>
#include "Heap.h" 
#include"HeapTest.h"
int main()
{
    setlocale(LC_ALL, "ru");
    
        // Создание объекта кучи типа int с максимальным размером 10
        Heap<int> heap(10);

        // Вставка элементов в кучу
        heap.Insert(3);
        heap.Insert(9);
        heap.Insert(2);
        heap.Insert(1);
        heap.Insert(4);
        heap.Insert(5);
        heap.Insert(12);
        heap.Insert(8);

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

        TestInsert();
        TestSize();
        TestIsEmpty();

    return 0;
}