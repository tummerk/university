#include "MyVector.hpp"

    MyVector::MyVector() {
        m_size = 0;
        m_cap = 0;
        m_arr = nullptr;
    }
    MyVector::MyVector(size_t size) {
        m_arr = new int[size];
        m_cap = size;
        m_size = size;
    }
    MyVector::~MyVector() {
        if (m_arr != nullptr)
            delete[] m_arr;
    }

    void MyVector::push_back(int value) {
        if (m_size + 1 <= m_cap) {
            m_arr[m_size] = value;
            m_size++;
            return;
        }
        if (m_cap < 1024)
            m_cap = m_cap * 2 + 1;
        else
            m_cap = m_cap * 1.25;
        int* tmp = new int[m_cap];
        for (int i = 0; i < m_size; i++)
            tmp[i] = m_arr[i];
        tmp[m_size] = value;
        delete[] m_arr;
        m_arr = tmp;
        m_size++;
    }

    void MyVector::reserve(size_t cap) {
        if (m_size >= cap)
            return;
        m_cap = cap;
        int* tmp = new int[m_cap];
        for (int i = 0; i < m_size; i++)
            tmp[i] = m_arr[i];
        delete[] m_arr;
        m_arr = tmp;
    }

    void MyVector::shrink_to_fit() {
        m_cap = m_size;
        int* tmp = new int[m_cap];
        for (int i = 0; i < m_size; i++)
            tmp[i] = m_arr[i];
        delete[] m_arr;
        m_arr = tmp;
    }

    size_t MyVector::size() {
        return m_size;
    }

    size_t MyVector::capacity() {
        return m_cap;
    }

    int& MyVector::operator[](size_t index) {
        int def = 0;
        if (m_size-1 < index)
            return def;
        return m_arr[index];
    }

    int& MyVector::front()
    {
        return m_arr[0];
    }

    int& MyVector::back() {
        return m_arr[m_size - 1];
    }

    bool MyVector::empty()
    {
        if (m_size==0)
            return true;
        return false;
    }

    void MyVector::erase(size_t index)
    {
        if (index > m_size)
            return;
        for (int i = index; i < m_size-1; i++) {
            m_arr[i] = m_arr[i + 1];
        }
        m_size -= 1;
    }

    void MyVector::insert(size_t index, int value)
    {
        if (index == m_size){
            push_back(value);
            return;}
        if (index > m_size || index<0)
            return;
        int last = m_arr[m_size - 1];
        for (int i = m_size-1; i > index ; i--) {
            m_arr[i] = m_arr[i-1];
        }
        m_arr[index] = value;
        push_back(last);
    }

    MyVector::MyVector(const MyVector& vec)
    {
        m_arr = vec.m_arr;
        m_size = vec.m_size;
        m_cap = vec.m_cap;
    }

    MyVector& MyVector::operator=(const MyVector& vec)
    {
        m_arr = vec.m_arr;
        m_size = vec.m_size;
        m_cap = vec.m_cap;
        return *this;
    }

