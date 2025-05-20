#include "basicSorting.h"
#include <algorithm>
#include "../searchingAlgorithms/sortedSearch.h"

//bubbleSort updated with swapped mechanic to stop early if finished sorting
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 1; j < n; j++)
        if (arr[j] < arr[j - 1]) {
            std::swap(arr[j], arr[j - 1]);
            swapped = true;
        }
        if (!swapped) return;
    }
}

//selectionSort with check minVal changing thing, avoid unneccessary swaps 
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minVal = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] > arr[minVal]) minVal = j;
        
        if (minVal != i) std::swap(arr[minVal], arr[i]);
    }
}

//insertionSort updated with binarySearch to increase speed
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++){
        int x = arr[i];
        int loc = iterativeBinarySearch(arr, x, 0, i - 1);

        for (int j = i - 1; j >= loc; j--)
            arr[j + 1] = arr[j];
        
        arr[loc] = x;
    }
}

//a better insertionSort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
}
