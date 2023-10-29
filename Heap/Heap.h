#pragma once
//@author Maltseva K.V.
#include <stdexcept>
#include <iostream>
using namespace std;

//���� ������������
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
   
    void heapifyMax(int i)
    {
        int largest = i; // ������ �������� ������������� ��������
        int l = 2 * i + 1; // ����� �������
        int r = 2 * i + 2; // ������ �������

        // ���� ����� ������� ������ ��������
        if (l < heapSize && heapArr[l] > heapArr[largest])
            largest = l;

        // ���� ������ ������� ������ �������� ��� ������ �������
        if (r < heapSize && heapArr[r] > heapArr[largest])
            largest = r;

        // ���� ����� ������� ������� �� �������� ���������
        if (largest != i)
        {
            swap(&heapArr[i], &heapArr[largest]);
            heapifyMax(largest);
        }
    }
    //void heapifyMax(T array[], int size, int i)
    //{
    //    
    //        int largest = i;//������ �������� ������������� ��������
    //        int l = 2 * i + 1; //����� �������
    //        int r = 2 * i + 2;//������ �������
    //        //���� ����� ������� ������ ��������
    //        if (l < size && array[l] > array[largest])
    //            largest = l;
    //        // ���� ������ ������� ������ �������� ��� ������ �������
    //        if (r < size && array[r] > array[largest])
    //            largest = r;
    //        // ���� ����� ������� ������� �� �������� ���������
    //        if (largest != i)
    //        {// ���������� ��������� HeapifyMax � ���������
    //            swap(&array[i], &array[largest]);
    //            heapifyMax(array, size, largest);
    //        }
    //   
    //}

    //�������������� ������� � ���� ���
    void minHeapify(int i)
    {
        int smallest = i; // ������ �������� ������������� ��������
        int left = 2 * i + 1; // ����� �������
        int right = 2 * i + 2; // ������ �������

        // ���� ����� ������� ������ ��������
        if (left < heapSize && heapArr[left] < heapArr[smallest])
            smallest = left;

        // ���� ������ ������� ������ �������� ��� ������ �������
        if (right < heapSize && heapArr[right] < heapArr[smallest])
            smallest = right;

        // ���� ����� ��������� ������� �� �������� ���������
        if (smallest != i)
        {
            swap(&heapArr[i], &heapArr[smallest]);
            minHeapify(smallest);
        }
    }

public:
    // ����������� 
    Heap(int maxsize) : heapSize(0), maxHeapSize(maxsize) {
        if (maxHeapSize <= 0)
        {
            throw invalid_argument("������������ ������ ���� ������ ���� ������ ����");
        }
        heapArr = new T[maxHeapSize];
    }

    // ����������
    ~Heap() {
        delete[] heapArr;
    }

    // ������ ��� heapSize
    int GetHeapSize() const {
        return heapSize;
    }

    // ������ ��� maxHeapSize
    int GetMaxHeapSize() const {
        return maxHeapSize;
    }
    //������� ������ ��������
    void Insert(T newNum)
    { //���� ������ ���� ������ ��� ����� ���� 
        if (heapSize >= maxHeapSize)
        {
            // ������������ ������ ���� ���������
            int newMaxSize = maxHeapSize * 2; // ���������� ������� � ��� ���� 
            //������������� ������
            T* newHeapArr = new T[newMaxSize];

            // ����������� ������������ ��������� � ����� ���� ������
            for (int i = 0; i < heapSize; i++)
            {
                newHeapArr[i] = heapArr[i];
            }

            // ������������ ������� ����� ������
            delete[] heapArr;

            // ���������� ��������� �� ����� ���� ������ � ������������� ������� ����
            heapArr = newHeapArr;
            maxHeapSize = newMaxSize;
        
            // ���� ��� �����, ���������� �������� ������ ���������
            //throw invalid_argument("��������� ������������ ������ ����");
        }
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
                heapifyMax( i);
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
           // cout<<"������� �� ������ � ����"<<endl;
            return;
        }
        //���� ������� ������
        //���������� ��������
        swap(&heapArr[i], &heapArr[heapSize - 1]);
        //������ ���� �����������
        heapSize--;
        //����� �������� ���������� �������������� � ���� ����
        for (int j = heapSize / 2 - 1; j >= 0; j--)
        {
            heapifyMax(j);
        }
    }
    //����� �������� � ����
    int Find(const T& value) const
    { //�������� �� ��������� ����
        for (int i = 0; i < heapSize; i++)
        {//���� �������� = ��������
            if (heapArr[i] == value)
                //������� ������ 
                //���������� ��� ������
                return i;
        }
        return -1; // ������� �� ������
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


