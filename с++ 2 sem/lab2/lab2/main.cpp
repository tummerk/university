#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime> 

using namespace std;
string vowels = "aoiuey";
const int N_max = 1000;

int quantityVowels(string str,int num){
	char letter = str[num];
	int isVow = 0;
	for (int i = 0; i < 6; i++) {
		if (letter == vowels[i])
			isVow++;
	}
	if (str.length() <= num++)
		return isVow;
	return isVow + quantityVowels(str, num++);
}

void QuickSort(int a, int b, int* arr) {
    if (a >= b)
        return;
    int k = (rand() * rand()) % (b - a + 1) + a;
    int m = arr[k];
    int l = a - 1;
    int r = b + 1;
    while (true) {
        do l++; while (arr[l] < m);
        do r--; while (arr[r] > m);
        if (l >= r)
            break;
        std::swap(arr[l], arr[r]);
    }
    l = r;
    r++;
    QuickSort(a, l, arr);
    QuickSort(r, b, arr);
}

int main() {
    double start = clock();
    const int n = 10000;
    int arr[n] = { 1, 2, 1, 2, 4 };
    QuickSort(0, n - 1, arr);
    double end = clock();
    double t = (end - start)/CLOCKS_PER_SEC;
    cout << t<<"  ";
    for (int i = n - 5; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}