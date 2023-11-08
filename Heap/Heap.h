#pragma once
//@author Maltseva K.V.
#include <stdexcept>
#include <iostream>
using namespace std;

//куча максимальная
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

    //преобразование массива в кучу макс c продвижением вниз с корневым узлом i
    void heapifyMax(int i, int heapSize)
    {
        int largest = i; // индекс текущего родительского элемента
        int l = 2 * i + 1; // левый потомок
        int r = 2 * i + 2; // правый потомок

        // если левый потомок больше родителя
        if (l < heapSize && heapArr[l] > heapArr[largest])
            largest = l;

        // Если правый потомок больше родителя или левого потомка
        if (r < heapSize && heapArr[r] > heapArr[largest])
            largest = r;

        // Если самый большой элемент не является родителем
        if (largest != i)
        {
            swap(&heapArr[i], &heapArr[largest]);
            heapifyMax(largest, heapSize);
        }
    }
    //void heapifyMax(T array[], int size, int i)
    //{
    //    
    //        int largest = i;//индекс текущего родительского элемента
    //        int l = 2 * i + 1; //левый потомок
    //        int r = 2 * i + 2;//правый потомок
    //        //если левый потомок больше родителя
    //        if (l < size && array[l] > array[largest])
    //            largest = l;
    //        // Если правый потомок больше родителя или левого потомка
    //        if (r < size && array[r] > array[largest])
    //            largest = r;
    //        // Если самый большой элемент не является родителем
    //        if (largest != i)
    //        {// Рекурсивно применяем HeapifyMax к поддереву
    //            swap(&array[i], &array[largest]);
    //            heapifyMax(array, size, largest);
    //        }
    //   
    //}

    //преобразование массива в кучу мин
    void minHeapify(int i)
    {
        int smallest = i; // индекс текущего родительского элемента
        int left = 2 * i + 1; // левый потомок
        int right = 2 * i + 2; // правый потомок

        // Если левый потомок меньше родителя
        if (left < heapSize && heapArr[left] < heapArr[smallest])
            smallest = left;

        // Если правый потомок меньше родителя или левого потомка
        if (right < heapSize && heapArr[right] < heapArr[smallest])
            smallest = right;

        // Если самый маленький элемент не является родителем
        if (smallest != i)
        {
            swap(&heapArr[i], &heapArr[smallest]);
            minHeapify(smallest);
        }
    }

public:
    // Конструктор 
    //конструктор который принимает массив
    Heap(int maxsize) : heapSize(0), maxHeapSize(maxsize) {
        //проверка на исключительную ситуацию
        //макси размер кучи не может быть <=0
        if (maxHeapSize <= 0)
        {
            throw invalid_argument("Максимальный размер кучи должен быть больше нуля");
        }
        //выделение памяти
        heapArr = new T[maxHeapSize];
    }

    // Конструктор, принимающий массив(макс размер массива=размеру переданного)
    Heap(T* arr, int size) : heapSize(size), maxHeapSize(size)
    {
       
        // Проверка на исключительную ситуацию
        if (maxHeapSize <= 0)
        {
            throw std::invalid_argument("Максимальный размер кучи должен быть больше нуля");
        }
        
        // Выделение памяти
        heapArr = new T[maxHeapSize];

        // Копирование элементов из переданного массива во внутренний массив heapArr
        //чтобы изменения в массиве копированном не отражались на оригинальный массив
        memcpy(heapArr, arr, size * sizeof(T));
        

        // Построение кучи (перегруппировка массива)
        for (int i = heapSize / 2 - 1; i >= 0; i--)
        {
            heapifyMax(i, heapSize);
        }
    }

    


    // Деструктор
    ~Heap() {
        delete[] heapArr;
    }

    // Геттер для heapSize
    int GetHeapSize() const {
        return heapSize;
    }

    // Геттер для maxHeapSize
    int GetMaxHeapSize() const {
        return maxHeapSize;
    }
    T*GetHeapArray() const
    {
        return heapArr;
    }
    //доступ к элементу по индексу
    T getElement(int index) const
    {
        if (index >= 0 && index < heapSize)
        {
            return heapArr[index];
        }
        else
        {
            // Обработка ошибки, если индекс выходит за пределы массива
            throw std::invalid_argument("Индeкс за пределами массива");
        }
    }
    //вставка нового элемента
    void Insert(T newNum)
    { //если размер кучи больше или равен макс 
        if (heapSize >= maxHeapSize)
        {
            // Максимальный размер кучи достигнут
            int newMaxSize = maxHeapSize * 2; // Увеличение размера в два раза 
            //перевыделение памяти
            T* newHeapArr = new T[newMaxSize];

            //// Копирование существующих элементов в новый блок памяти
            //for (int i = 0; i < heapSize; i++)
            //{
            //    newHeapArr[i] = heapArr[i];
            //}
            memcpy(newHeapArr, heapArr, sizeof(T)*maxHeapSize);
            // Освобождение старого блока памяти
            delete[] heapArr;

            // Обновление указателя на новый блок памяти и максимального размера кучи
            heapArr = newHeapArr;
            maxHeapSize = newMaxSize;
        
            // Куча уже полна, невозможно добавить больше элементов
            //throw invalid_argument("Достигнут максимальный размер кучи");
        }
       //если размер кучи=0,куча пуста
       else if (heapSize == 0)
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
                heapifyMax( i, heapSize);
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
           // cout<<"Элемент не найден в куче"<<endl;
            return;
        }
        //если элемент найден
        //обмениваем элементы
        swap(&heapArr[i], &heapArr[heapSize - 1]);
        //размер кучи уменьшается
        heapSize--;
        //после удаления происходит преобразование в кучу макс
        for (int j = heapSize / 2 - 1; j >= 0; j--)
        {
            heapifyMax(j, heapSize);
        }
    }

    //поиск элемента в кучи
    int Find(const T& value) const
    { //проходим по элементам кучи
        for (int i = 0; i < heapSize; i++)
        {//если значение = искомому
            if (heapArr[i] == value)
                //элемент найден 
                //возвращаем его индекс
                return i;
        }
        return -1; // Элемент не найден
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

    // сортировка массива по возрастанию с использованием пирамидальной сортировки
    void heapSort()
    {  // Построение кучи из исходного массива
        for (int i = heapSize / 2 - 1; i >= 0; i--)
        {//преобразование массива в кучу
            heapifyMax(i, heapSize);
        }

        // Извлечение элементов из кучи по одному из корня
        for (int i = heapSize - 1; i > 0; i--) {
            // Перемещаем текущий корень в конец
           swap(&heapArr[0], &heapArr[i]);

            // Вызываем heapifyMax на уменьшенной куче
            heapifyMax(0,i);
        }
    }
    //турнирная сортировка
    void turnamentSort() {

    
        // Внешний цикл по уменьшению размера сортируемой части массива
        for (int i = heapSize - 1; i > 0; i--) {
            // Внутренний цикл по парам элементов
            for (int j = 0; j < i; j += 2) {
                //winnerIdx хранит интекс победителя текущей пары элементов
                //изначально устанавливается в индекс первого элемента пары J
                int winnerIdx = j;

                // Находим индекс победителя в текущей паре элементов
                if (j + 1 < i && heapArr[j + 1] > heapArr[winnerIdx])
                    winnerIdx = j + 1;
                if (heapArr[i] > heapArr[winnerIdx])
                    winnerIdx = i;

                // Если победитель не равен текущему крайнему правому элементу,
                // меняем победителя и текущий крайний правый элемент местами
                if (winnerIdx != i) {
                    swap(&heapArr[i], &heapArr[winnerIdx]);
                }
            }
        }

    }
    
};


