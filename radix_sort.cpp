#include <iostream>
using namespace std;

void radixSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        int output[n], count[10] = {0};
        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (int i = n - 1; i >= 0; i--)
            output[--count[(arr[i] / exp) % 10]] = arr[i];
        for (int i = 0; i < n; i++)
            arr[i] = output[i];
    }
}

int main() {
    int arr[] = {90, 21, 0, 973, 998802};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
