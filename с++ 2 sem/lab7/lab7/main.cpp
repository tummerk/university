#include <iostream>
#include <stdexcept>

using namespace std;

class VectorBool {
private:
    unsigned char* arr;
    size_t size_;
    size_t cap;
    void reallocate() {
        size_t new_cap = (cap == 0) ? 8 : cap * 2;
        size_t bytes = (new_cap + 7) / 8;
        unsigned char* new_arr = new unsigned char[bytes](); 

        if (arr) {
            for (size_t i = 0; i < (cap + 7) / 8; ++i) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
        }

        arr = new_arr;
        cap = new_cap;
    }

public:
    class Bit {
    private:
        unsigned char& block;
        unsigned int mask;

    public:
        Bit(unsigned char& block, size_t bit_pos)
            : block(block), mask(1 << bit_pos) {
        }

        operator bool() const { return (block & mask) != 0; }

        Bit& operator=(bool value) {
            if (value) block |= mask;
            else block &= ~mask;
            return *this;
        }
    };

    VectorBool() : arr(nullptr), size_(0), cap(0) {
        reallocate();
    }

    ~VectorBool() {
        delete[] arr;
    }

    void push_back(bool value) {
        if (size_ >= cap) reallocate();

        size_t chunk = size_ / 8;
        size_t bit_pos = size_ % 8;

        if (value) arr[chunk] |= (1 << bit_pos);
        else arr[chunk] &= ~(1 << bit_pos);

        size_++;
    }

    size_t size() const { return size_; }

    bool operator[](int key) const {
        size_t chunk = key / 8;
        size_t bit_pos = key % 8;
        return (arr[chunk] & (1 << bit_pos)) != 0;
    }

    Bit operator[](int key) {
        size_t chunk = key / 8;
        size_t bit_pos = key % 8;
        return Bit(arr[chunk], bit_pos);
    }

    void erase(size_t key) {
        size_t chunk = key / 8;
        size_t bit_pos = key % 8;
        unsigned char mask = 255 << (bit_pos+1);
        unsigned char reminder = arr[chunk] & mask;
        arr[chunk] &= ~(mask >> 1);
        arr[chunk] |= (reminder >> 1);

        size_t count_chunks = (size_ + 7) / 8;
        for (int i = chunk; i < count_chunks-1; i++) {
            if (arr[i + 1] % 2 == 1) {
                arr[i] |= 128;
            } else {
                arr[i] &= ~128;
            }
            arr[i + 1] >>= 1;

        }
        size_--;
    }

    void insert(size_t key, bool value) {
        size_++;
        if (size_ >= cap) {
            reallocate();
        }
        size_t chunk = key / 8;
        size_t bit_pos = key % 8;
        unsigned char mask = 255 << bit_pos;
        unsigned char reminder = arr[chunk] & mask;
        arr[chunk] &= ~mask;
        arr[chunk] |= reminder<<1;

        size_t count_chunks = (size_ + 8) / 8;
        unsigned char carry = reminder / 128;
        unsigned char next_carry;

        for (size_t i = chunk + 1; i < count_chunks - 1; ++i) {
            next_carry = (arr[i] / 128);
            arr[i] <<= 1;
            arr[i] += carry;
            carry = next_carry;
        }
        arr[count_chunks - 1] <<= 1;
        arr[count_chunks - 1] += carry;

        (*this)[key] = value;
    }

    void print() const {
        for (size_t i = 0; i < size_; ++i) {
            cout << ((*this)[i] ? '1' : '0');
            if ((i + 1) % 8 == 0) cout << " ";
        }
        cout << endl;
    }
};

int main() {
    VectorBool v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
   
    v.print();
    
    v.insert(0, 1);
    v.print();
    return 0;
}