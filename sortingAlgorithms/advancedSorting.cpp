#include "advancedSorting.h"
#include <algorithm>

static int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) 
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

static void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1,
        n2 = high - mid;

    int* L = new int[n1];
    int* H = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[low + i];
    for (int i = 0; i < n2; i++) H[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (L[i] <= H[j]) arr[k++] = L[i++];
        else arr[k++] = H[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = H[j++];

    delete[] L;
    delete[] H;
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

static void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest == left;
    if (right < n && arr[right] > arr[largest]) largest == right;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}