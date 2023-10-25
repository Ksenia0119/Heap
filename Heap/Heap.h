#pragma once
//@author Maltseva K.V.
#include <iostream>
using namespace std;
template <typename T>
class Heap
{
private:
    T* heapArr;       // ��������� �� ������
    int maxHeapSize;      // ������������ ������ ����
    int heapSize;       // ������� ������ ����
    
//����� ���������� ���� ���������
    void swap(T* a, T* b)
    {
        T temp = *b;
        *b = *a;
        *a = temp;
    }
    //�������������� ������� � ���� ����
    void heapifyMax(T array[], int size, int i)
    {
        
            int largest = i;//������ �������� ������������� ��������
            int l = 2 * i + 1; //����� �������
            int r = 2 * i + 2;//������ �������
            //���� ����� ������� ������ ��������
            if (l < size && array[l] > array[largest])
                largest = l;
            // ���� ������ ������� ������ �������� ��� ������ �������
            if (r < size && array[r] > array[largest])
                largest = r;
            // ���� ����� ������� ������� �� �������� ���������
            if (largest != i)
            {// ���������� ��������� HeapifyMax � ���������
                swap(&array[i], &array[largest]);
                heapifyMax(array, size, largest);
            }
       
    }

    //�������������� ������� � ���� ���
    void minHeapify(T array[], int size, int i)
    {
        int smallest = i;//������ �������� ������������� ��������
        int left = 2 * i + 1;//����� �������
        int right = 2 * i + 2;//������ �������
        // ���� ����� ������� ������ ��������
        if (left < size && array[left] < array[smallest])
            smallest = left;
        // ���� ������ ������� ������ �������� ��� ������ �������
        if (right < size && array[right] < array[smallest])
            smallest = right;
        // ���� ����� ��������� ������� �� �������� ���������
        if (smallest != i)
        {// ���������� ��������� minHeapify � ���������
            swap(&array[i], &array[smallest]);
            minHeapify(array, size, smallest);
        }
    }

public:
    // ����������� 
    Heap(int maxsize) : heapSize(0), maxHeapSize(maxsize) {
        heapArr = new T[maxHeapSize];
    }

    // ����������
    ~Heap() {
        delete[] heapArr;
    }
    //������� ������ ��������
    void Insert(T newNum)
    {
        //���� ������ ����=0,���� �����
        if (heapSize == 0)
        {//����� ������� ���������� � ������ ����
            heapArr[0] = newNum;
            //������ ������������� �� 1
            heapSize += 1;
        }
        else
        { //����� ����� ������� ����������� � ����� ����
            heapArr[heapSize] = newNum;
            //������ ������������� �� 1
            heapSize += 1;
            //���� �������������� ������� � ���� ����
            //���� ����������� ��� ������� ������������� ��������, 
            // ������� � ���������� �������� � �������� � ����� ����.
            for (int i = heapSize / 2 - 1; i >= 0; i--)
            {//�������������� ������� � ����
                heapifyMax(heapArr, heapSize, i);
            }
        }
    }
    //�������� ��������
    void deleteNode(T num)
    {
        int i;
        //�������� �� ��������� ����
        for (i = 0; i < heapSize; i++)
        {//���������� ������� � ��������� �������
            //���� ������� ������,���� �����������
            //  � ������ ����������� � ���������� i 
            if (num == heapArr[i])
                break;
        }
        //���� ������ i ����� ������� ����,�� ������� � ���� �� �������
        if (i == heapSize)
        {
            cout<<"������� �� ������ � ����";
        }
        //���� ������� ������
        //���������� ��������
        swap(&heapArr[i], &heapArr[heapSize - 1]);
        //������ ���� �����������
        heapSize--;
        //����� �������� ���������� �������������� � ���� ����
        for (int j = heapSize / 2 - 1; j >= 0; j--)
        {
            heapifyMax(heapArr, heapSize, j);
        }
    }
    //������� ������ ����
    int Size() const {
        return heapSize;
    }

    // �������� �� �������
    bool IsEmpty() const {
        return heapSize == 0;
    }
    //������ ���� 
    void printHeap()
    {
      
        for (int i = 0; i < heapSize; ++i)
        {
           cout << heapArr[i] << " ";
        }
        cout << endl;
    }

};


