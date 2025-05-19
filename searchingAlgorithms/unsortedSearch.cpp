#include "unsortedSearch.h"
#include <cmath>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

int sentinalSearch(int arr[], int n, int target) {
    int i = 0;
    while (arr[i] != target && i < n)
        i++;
    if (i < n) return i;
    return -1;
}


