#pragma once
//@author Maltseva K.V.
#include <iostream>
using namespace std;
template <typename T>
class Heap
{
private:
    T* heapArr;       // указатель на массив
    int maxHeapSize;      // максимальный размер кучи
    int heapSize;       // текущий размер кучи
    
//обмен значениями двух элементов
    void swap(T* a, T* b)
    {
        T temp = *b;
        *b = *a;
        *a = temp;
    }
    //преобразование массива в кучу макс
    void heapifyMax(T array[], int size, int i)
    {
        
            int largest = i;//индекс текущего родительского элемента
            int l = 2 * i + 1; //левый потомок
            int r = 2 * i + 2;//правый потомок
            //если левый потомок больше родителя
            if (l < size && array[l] > array[largest])
                largest = l;
            // Если правый потомок больше родителя или левого потомка
            if (r < size && array[r] > array[largest])
                largest = r;
            // Если самый большой элемент не является родителем
            if (largest != i)
            {// Рекурсивно применяем HeapifyMax к поддереву
                swap(&array[i], &array[largest]);
                heapifyMax(array, size, largest);
            }
       
    }

    //преобразование массива в кучу мин
    void minHeapify(T array[], int size, int i)
    {
        int smallest = i;//индекс текущего родительского элемента
        int left = 2 * i + 1;//левый потомок
        int right = 2 * i + 2;//правый потомок
        // Если левый потомок меньше родителя
        if (left < size && array[left] < array[smallest])
            smallest = left;
        // Если правый потомок меньше родителя или левого потомка
        if (right < size && array[right] < array[smallest])
            smallest = right;
        // Если самый маленький элемент не является родителем
        if (smallest != i)
        {// Рекурсивно применяем minHeapify к поддереву
            swap(&array[i], &array[smallest]);
            minHeapify(array, size, smallest);
        }
    }

public:
    // Конструктор 
    Heap(int maxsize) : heapSize(0), maxHeapSize(maxsize) {
        heapArr = new T[maxHeapSize];
    }

    // Деструктор
    ~Heap() {
        delete[] heapArr;
    }
    //вставка нового элемента
    void Insert(T newNum)
    {
        //если размер кучи=0,куча пуста
        if (heapSize == 0)
        {//новый элемент помещается в корень кучи
            heapArr[0] = newNum;
            //размер увеличивается на 1
            heapSize += 1;
        }
        else
        { //иначе новый элемент добавляется в конец кучи
            heapArr[heapSize] = newNum;
            //размер увеличивается на 1
            heapSize += 1;
            //цикл преобразования массива в кучу макс
            //Цикл выполняется для каждого родительского элемента, 
            // начиная с последнего родителя и двигаясь к корню кучи.
            for (int i = heapSize / 2 - 1; i >= 0; i--)
            {//преобразование массива в кучу
                heapifyMax(heapArr, heapSize, i);
            }
        }
    }
    //удаление элемента
    void deleteNode(T num)
    {
        int i;
        //проходим по элементам кучи
        for (i = 0; i < heapSize; i++)
        {//сравниваем искомый с элементом массива
            //если элемент найден,цикл прерывается
            //  и индекс сохраняется в переменную i 
            if (num == heapArr[i])
                break;
        }
        //если индекс i равен размеру кучи,то элемент в куче не нашелся
        if (i == heapSize)
        {
            cout<<"Элемент не найден в куче";
        }
        //если элемент найден
        //обмениваем элементы
        swap(&heapArr[i], &heapArr[heapSize - 1]);
        //размер кучи уменьшается
        heapSize--;
        //после удаления происходит преобразование в кучу макс
        for (int j = heapSize / 2 - 1; j >= 0; j--)
        {
            heapifyMax(heapArr, heapSize, j);
        }
    }
    //текущии размер кучи
    int Size() const {
        return heapSize;
    }

    // проверка на пустоту
    bool IsEmpty() const {
        return heapSize == 0;
    }
    //печать кучи 
    void printHeap()
    {
      
        for (int i = 0; i < heapSize; ++i)
        {
           cout << heapArr[i] << " ";
        }
        cout << endl;
    }

};


