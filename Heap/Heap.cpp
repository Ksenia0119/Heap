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
        heap.Insert(3);
        heap.Insert(9);
        heap.Insert(2);
        heap.Insert(1);
        heap.Insert(4);
        heap.Insert(5);
        heap.printHeap();
        // Применение пирамидальной сортировки
      /*  heap.heapSort();
        heap.printHeap();
        heap.Insert(15);
        heap.printHeap();*/
        heap.turnamentSort();
        heap.printHeap();
        //// Вывод отсортированных элементов
        //for (int i = 0; i < heap.GetHeapSize(); i++)
        //{
        //    cout << heap.GetHeapArray()[i] << " ";
        //}
       // heap.Insert(12);
        //heap.Insert(8);

       /*       9
               / \
              4     5
              / \ /
            1   3 2*/
            // Печать элементов кучи
       // heap.printHeap();
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

        //Проверка организован ли массив по принципу кучи с помощью функции
        //стандартной библиотеки
        vector<int> vec{ 3,9,2,1,4,5 };

        cout << "Is heap:" << is_heap(vec.begin(), vec.end()) << endl;;//нет

        //записываем в кучу данные из вектора
        Heap<int> heap_from_vector(vec.size());
        for (int i = 0; i < vec.size(); i++) {
            heap_from_vector.Insert(vec[i]);
        }
       // heap_from_vector.printHeap();

       
        //создаем другой вектор в который запишем данные из кучи
        vector<int> vec1(heap_from_vector.GetHeapSize());
        for (int i = 0; i < heap_from_vector.GetHeapSize(); i++) {
            vec1.push_back(heap_from_vector.getElement(i));

        }

        cout << endl;

        //// организует массив по принципу кучи (max heap)
        make_heap(vec.begin(), vec.end());
       
        for (int x : vec)
            cout << x << " ";
        cout << endl;
        //проверим организованы ли массивы по принципу кучи
        cout << "Is heap:"<<is_heap(vec.begin(), vec.end()) <<endl;//да
        cout << "Is heap:" << is_heap(vec1.begin(), vec1.end()) << endl;//да
       // TestInsert();
        //TestSize();
        //TestIsEmpty();
        //TestConstructor();
        //TestFind();

       // TestHeapSort();
       // TestDelete();
       // int arr[] = { 5,9, 8, 2, 1,7 };
       // int size = sizeof(arr) / sizeof(arr[0]);
    
       // Heap<int> myheap(arr, size);
       // myheap.printHeap();
       //myheap.deleteNode(5);
       //myheap.printHeap(); 
       //myheap.printHeap();
    }//перехватываем исключительные ситуации
    catch (invalid_argument& error) {
        // Обработка исключения invalid_argument
        cout << "Ошибка: " << error.what() << endl;
    }
    

    return 0;
}