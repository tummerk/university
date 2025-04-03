// lab5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "MyVector.hpp"
using namespace std;

int main()
{
    MyVector arr(0);
    arr.push_back(23);
    arr.push_back(45);
    arr.push_back(52);
    arr.insert(0, 228);
    for (int i=0;i<arr.size();i++)
        cout << arr[i]<<" ";
}
