#include <iostream>

using namespace std;


class VectorBool {
private:
    unsigned char* arr;
    size_t size;
    size_t cap;
    void reallocate() {
        size_t new_cap = (cap == 0) ? 8 : cap * 2;
        unsigned char* new_arr = new unsigned char[new_cap / 8]();

        for (size_t i = 0; i < (cap / 8); ++i) {
            new_arr[i] = arr[i];
        }

        delete[] arr;
        arr = new_arr;
        cap = new_cap;
    }
public:
    VectorBool() : arr(nullptr), size(0), cap(0) {
        reallocate();
    }

    VectorBool(size_t size) {
        int sizeArr = size / 8 + 1;
        arr = new unsigned char[sizeArr];
        this->size = size;
        cap = sizeArr * 8;
    };

    ~VectorBool() {
        delete[] arr;
    };

    void push_back(bool value) {
        if (size >= cap)
            reallocate();

        if (value) {
            arr[size / 8] |= (1 << 7 - size % 8);
        }
        else {
            arr[size / 8] &= ~(1 << 7 - size % 8);
        }
        size++;
    };

    size_t size() {
        return this->size;
    }

    bool operator[] (int key) {
        key++;
        int chunk = key / 8 - (key % 8 == 0 ? 1 : 0);
        if (key > size-1) 
            return false;
        bool value;
        value = ((arr[chunk] >> (8 - key % 8)) & 1);
        return value;
    }

    void erase(size_t index) {
        size_t chank_index = index / 8;
        
    }


    void print() const {
        for (size_t i = 0; i < (size + 7) / 8; ++i) {
            for (int j = 7; j >=8- (size%8); --j) {
                cout << ((arr[i] & (1 << j)) ? '1' : '0');
            }
            cout << " ";
        }
        cout << endl;
    }

};

void main() {
    VectorBool v;
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    v.print();
    cout << v[2];
}