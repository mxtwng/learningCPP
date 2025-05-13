#include "sortedSearch.h"
#include <cmath>

int jumpSearch(int arr[], int n, int target) {
    int jump = (int) pow(n, 0.5);
    int i = 0, j = i + jump;
    while (j < n && arr[j] < target) {
        j = j + jump;
        i = i + jump;
    }
    if (j >= n)
        j = n - 1;
    while (arr[i] < target) {
        i++;
        if (i >= n || i > j)
            return -1;
    }
    if (arr[i] == target)
        return i;
    return -1;
}

int recursiveBinarySearch(int arr[], int left, int right, int target) {
    if (left > right) return -1;
    int mid = (int) (left + (right - left) / 2);
    if (arr[mid] > target) return recursiveBinarySearch(arr, left, mid - 1, target);
    if (arr[mid] < target) return recursiveBinarySearch(arr, mid + 1, right, target);
    return mid;
}

int iterativeBinarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = (int) (left + (right - left) / 2);
        
    }
}
