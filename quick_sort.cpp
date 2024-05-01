#include <iostream>
#include <conio.h>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low]; // Choose the first element as pivot
        int i = low - 1;
        int j = high + 1;

        while (true) {
            do {
                i++;
            } while (arr[i] < pivot);

            do {
                j--;
            } while (arr[j] > pivot);

            if (i >= j)
                break;

            swap(arr[i], arr[j]);
        }

        quick_sort(arr, low, j);
        quick_sort(arr, j + 1, high);
    }
}

void display_arr(int arr[], int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

int main() {
    int arr[] = {10, 24, 21, 57, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, size - 1);

    display_arr(arr, size);

    getch();
    return 0;
}
