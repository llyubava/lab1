#ifndef ARRAY_H
#define ARRAY_H

class Array {
public:
    Array(int size = 10, int step = 5);
    ~Array();

    void showElements() const;
    void expandArray(int size);
    int getSize() const;
    int getElemSize() const;
    void setValue(int val);
    void setArray(int *pArr, int size);

private:
    int initialSize;
    int expandStep;
    int *arrayPtr;
    int currentIdx;
};

#endif // ARRAY_H