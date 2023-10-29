#pragma once
//@author Maltseva K.V.
#include<cassert>
#include"Heap.h"
//�������� ���� ��� ������������
Heap<int> CreateHeapTest() {
    Heap<int> heap(5);

    heap.Insert(5); 
    heap.Insert(3);
    heap.Insert(7);
    heap.Insert(2);
    heap.Insert(4);

          //     7
         //    / \
         //  4     5
         // / \
         //2   3
     
    return heap;
}
Heap<int> CreateHeap1Test() {

   /*       9
           / \
        7       6
       / \      / \
      5   4    3   2
     /
    1*/
    Heap<int> heap(10);

    heap.Insert(9);
    heap.Insert(7);
    heap.Insert(6);
    heap.Insert(5);
    heap.Insert(4);
    heap.Insert(3);
    heap.Insert(2);
    heap.Insert(1);
    return heap;
}
Heap<int> CreateHeapOneTest() {
    Heap<int> heap(1);

    heap.Insert(8);
    return heap;
}

//������������ ������������
void TestConstructor() {
    // ���� � ���������� ���� �������� ����
    int maxsize = 10;
    Heap<int> heap1(maxsize);
    assert(heap1.GetMaxHeapSize() == maxsize);
    assert(heap1.Size() == 0);

    //���� � ������������ ��������� ���� �������
    int invalidmaxsize = -5;
 
    try{ 
        Heap<int> heap1(invalidmaxsize);
    }
    catch (const invalid_argument& e) {
        // ��������� ���������� invalid_argument
        cout << "������: " << e.what() << endl;
    }
    cout << "����������� ���� �������" << endl;
}
//������������ ������� ������ ��������
void TestInsert() {
    Heap<int> heap=CreateHeapTest();

    assert(heap.Size() == 5);
    assert(!heap.IsEmpty());


    Heap<int> heap1 = CreateHeapOneTest();
    assert(heap1.Size() == 1);
    assert(!heap1.IsEmpty());

    Heap<int> heap2(6);
    assert(heap2.Size() == 0);
    assert(heap2.IsEmpty());
    cout << "������� ���� �������" <<endl;
}
//������������ ������� ����
void TestSize() {
    Heap<int> heap(6);

    assert(heap.Size() == 0);

    Heap<int> heap1 = CreateHeapTest();
    assert(heap1.Size() == 5);

    Heap<int> heap2 = CreateHeapOneTest();
    assert(heap2.Size() == 1);
    cout << "������ ���� ���� �������" << endl;
}
//������������ �� �������
void TestIsEmpty() {
    Heap<int> heap(5);

    assert(heap.IsEmpty());

    Heap<int> heap1 = CreateHeapTest();

    assert(!heap1.IsEmpty());

    Heap<int> heap2 = CreateHeapOneTest();

    assert(!heap2.IsEmpty());

    cout << "������� ���� ���� �������" << endl;
}
//������������ ����� ��������
void TestFind() {
    Heap<int> heap = CreateHeapTest();
    // ���� ������������� ��������
    int index1 = heap.Find(7);
    assert(index1 == 0);

    int index2 = heap.Find(4);
    assert(index2 == 1);

    int index3 = heap.Find(5);
    assert(index3 == 2);
   
    // ���� ��������������� ��������
    int index4 = heap.Find(30);
    assert(index4 == -1);

    Heap<int> heap1 = CreateHeap1Test();
    // ���� ������������� ��������
    int index5 = heap1.Find(3);
    assert(index5 == 5);

    int index6 = heap1.Find(9);
    assert(index6 == 0);

    int index7 = heap1.Find(5);
    assert(index7 == 3);
    int index8 = heap1.Find(1);
    assert(index8 == 7);

    // ���� ��������������� ��������
    int index9 = heap1.Find(26);
    assert(index9 == -1);


    Heap<int> heap2(5);
    int index10 = heap2.Find(3);
    assert(index10 == -1);


    Heap<int> heap3 = CreateHeapOneTest();
    int index11 = heap3.Find(4);
    assert(index11 == -1);
    int index12 = heap3.Find(8);
    assert(index12 == 0);
    cout << "����� �������� ���� �������" << endl;
}

void TestDelete() {
    int elements[] = { 5, 3, 7, 2, 4 };
    int numElements = sizeof(elements) / sizeof(elements[0]);

    Heap<int> heap(numElements);
    for (int i = 0; i < numElements; i++) {
        heap.Insert(elements[i]);
    }

    heap.deleteNode(7);
    // �������� ������� ���� ����� ��������
    assert(heap.Size() == 3);
}