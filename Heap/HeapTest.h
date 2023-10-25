#pragma once
//@author Maltseva K.V.
#include<cassert>
#include"Heap.h"

Heap<int> CreateHeapTest() {
    Heap<int> heap(5);

    heap.Insert(5); 
    heap.Insert(3);
    heap.Insert(7);
    heap.Insert(2);
    heap.Insert(4);

    return heap;
}

void TestInsert() {
    Heap<int> heap=CreateHeapTest();

    assert(heap.Size() == 5);
    assert(!heap.IsEmpty());

    cout << "Вставка тест пройден" <<endl;
}

void TestSize() {
    Heap<int> heap(6);

    assert(heap.Size() == 0);

    Heap<int> heap1 = CreateHeapTest();
    assert(heap1.Size() == 5);

    cout << "Размер кучи тест пройден" << endl;
}

void TestIsEmpty() {
    Heap<int> heap(5);

    assert(heap.IsEmpty());

    Heap<int> heap1 = CreateHeapTest();

    assert(!heap1.IsEmpty());

    cout << "Пустота кучи тест пройден" << endl;
}
