#include <iostream>
#include "array.h"

Array::Array(int size, int step) {
    initialSize = size > 0 ? size : 10;
    expandStep = step > 0 ? step : 5;
    arrayPtr = new int[initialSize];
    currentIdx = 0;
}

Array::~Array() {
    delete[] arrayPtr;
}

void Array::showElements() const {
    for (int i = 0; i < currentIdx; i++) {
        std::cout << arrayPtr[i] << " ";
    }
    std::cout << std::endl;
}

void Array::expandArray(int size) {
    int newSize = initialSize + size;
    int *newArray = new int[newSize];

    for (int i = 0; i < currentIdx; i++) {
        newArray[i] = arrayPtr[i];
    }

    delete[] arrayPtr;
    arrayPtr = newArray;
    initialSize = newSize;
}

int Array::getSize() const {
    return initialSize;
}

int Array::getElemSize() const {
    return currentIdx;
}

void Array::setValue(int val) {
    if (currentIdx >= initialSize) {
        expandArray(expandStep);
    }

    arrayPtr[currentIdx++] = val;
}

void Array::setArray(int *pArr, int size) {
    for (int i = 0; i < size; i++) {
        setValue(pArr[i]);
    }
}