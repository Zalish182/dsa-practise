#include <iostream>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] > pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[low], arr[i - 1]);
    return i - 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[] = {18, 73, 39, 55, 16, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";

    quickSort(arr, 0, size - 1);

    cout << "Sorted array descending: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}
