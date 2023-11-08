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

    //�������������� ������� � ���� ���� c ������������ ���� � �������� ����� i
    void heapifyMax(int i, int heapSize)
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
            heapifyMax(largest, heapSize);
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
    //����������� ������� ��������� ������
    Heap(int maxsize) : heapSize(0), maxHeapSize(maxsize) {
        //�������� �� �������������� ��������
        //����� ������ ���� �� ����� ���� <=0
        if (maxHeapSize <= 0)
        {
            throw invalid_argument("������������ ������ ���� ������ ���� ������ ����");
        }
        //��������� ������
        heapArr = new T[maxHeapSize];
    }

    // �����������, ����������� ������(���� ������ �������=������� �����������)
    Heap(T* arr, int size) : heapSize(size), maxHeapSize(size)
    {
       
        // �������� �� �������������� ��������
        if (maxHeapSize <= 0)
        {
            throw std::invalid_argument("������������ ������ ���� ������ ���� ������ ����");
        }
        
        // ��������� ������
        heapArr = new T[maxHeapSize];

        // ����������� ��������� �� ����������� ������� �� ���������� ������ heapArr
        //����� ��������� � ������� ������������ �� ���������� �� ������������ ������
        memcpy(heapArr, arr, size * sizeof(T));
        

        // ���������� ���� (��������������� �������)
        for (int i = heapSize / 2 - 1; i >= 0; i--)
        {
            heapifyMax(i, heapSize);
        }
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
    T*GetHeapArray() const
    {
        return heapArr;
    }
    //������ � �������� �� �������
    T getElement(int index) const
    {
        if (index >= 0 && index < heapSize)
        {
            return heapArr[index];
        }
        else
        {
            // ��������� ������, ���� ������ ������� �� ������� �������
            throw std::invalid_argument("���e�� �� ��������� �������");
        }
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

            //// ����������� ������������ ��������� � ����� ���� ������
            //for (int i = 0; i < heapSize; i++)
            //{
            //    newHeapArr[i] = heapArr[i];
            //}
            memcpy(newHeapArr, heapArr, sizeof(T)*maxHeapSize);
            // ������������ ������� ����� ������
            delete[] heapArr;

            // ���������� ��������� �� ����� ���� ������ � ������������� ������� ����
            heapArr = newHeapArr;
            maxHeapSize = newMaxSize;
        
            // ���� ��� �����, ���������� �������� ������ ���������
            //throw invalid_argument("��������� ������������ ������ ����");
        }
       //���� ������ ����=0,���� �����
       else if (heapSize == 0)
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
                heapifyMax( i, heapSize);
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
            heapifyMax(j, heapSize);
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

    // ���������� ������� �� ����������� � �������������� ������������� ����������
    void heapSort()
    {  // ���������� ���� �� ��������� �������
        for (int i = heapSize / 2 - 1; i >= 0; i--)
        {//�������������� ������� � ����
            heapifyMax(i, heapSize);
        }

        // ���������� ��������� �� ���� �� ������ �� �����
        for (int i = heapSize - 1; i > 0; i--) {
            // ���������� ������� ������ � �����
           swap(&heapArr[0], &heapArr[i]);

            // �������� heapifyMax �� ����������� ����
            heapifyMax(0,i);
        }
    }
    //��������� ����������
    void turnamentSort() {

    
        // ������� ���� �� ���������� ������� ����������� ����� �������
        for (int i = heapSize - 1; i > 0; i--) {
            // ���������� ���� �� ����� ���������
            for (int j = 0; j < i; j += 2) {
                //winnerIdx ������ ������ ���������� ������� ���� ���������
                //���������� ��������������� � ������ ������� �������� ���� J
                int winnerIdx = j;

                // ������� ������ ���������� � ������� ���� ���������
                if (j + 1 < i && heapArr[j + 1] > heapArr[winnerIdx])
                    winnerIdx = j + 1;
                if (heapArr[i] > heapArr[winnerIdx])
                    winnerIdx = i;

                // ���� ���������� �� ����� �������� �������� ������� ��������,
                // ������ ���������� � ������� ������� ������ ������� �������
                if (winnerIdx != i) {
                    swap(&heapArr[i], &heapArr[winnerIdx]);
                }
            }
        }

    }
    
};


