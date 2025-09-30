#include <iostream>
using namespace std;

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // choose first element as pivot
    int left = low + 1;
    int right = high;

    while (true) {
        // Move left index while element <= pivot
        while (left <= right && arr[left] <= pivot) {
            left++;
        }

        // Move right index while element > pivot
        while (left <= right && arr[right] > pivot) {
            right--;
        }

        // If indices cross, break
        if (left > right) {
            break;
        }

        // Swap arr[left] and arr[right]
        swap(arr[left], arr[right]);
    }

    // Place pivot in its correct location
    swap(arr[low], arr[right]);

    return right; // new pivot position
}

// Recursive quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[] = {37, 2, 6, 4, 89, 8, 10, 12, 68, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
