#pragma once
#define MYVECTOR_HPP

class MyVector
{
private:
    int* m_arr;
    size_t m_size;
    size_t m_cap;
public:
    MyVector();
    MyVector(size_t size);
    ~MyVector();

    void push_back(int value);

    void reserve(size_t cap);

    void shrink_to_fit();

    size_t size();

    size_t capacity();

    int& operator[](size_t index);

    int& front();
    int& back();

    bool empty();
    void erase(size_t index);
    void insert(size_t index, int value);

    MyVector(const MyVector&);
    MyVector& operator=(const MyVector& vec);
};


