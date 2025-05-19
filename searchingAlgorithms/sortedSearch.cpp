#include "sortedSearch.h"
#include <cmath>

// O(sqrt n)
int jumpSearch(int arr[], int n, int target) {
    int jump = (int) sqrt(n);
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

// O(logn)
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
        
        if (arr[mid] > target) right = mid - 1;
        else if (arr[mid] < target) left = mid + 1;
        else return mid;
    }
    return -1;
}

// O(2*log3n)
int recursiveTernarySearch(int arr[], int left, int right, int target) {
    int midLeft = (int) (left + (right - left)/3),
        midRight = (int) (right - (right - left)/3);
    
    if (arr[midLeft] == target) return midLeft;
    if (arr[midRight] == target) return midRight;

    if (target < arr[midLeft]) return recursiveTernarySearch(arr, left, midLeft - 1, target);
    else if (target > arr[midRight]) return recursiveTernarySearch(arr, midRight + 1, right, target);
    else return recursiveTernarySearch(arr, midLeft, midRight, target);

    return -1;
}

int iterativeTernarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int midLeft = (int) (left + (right - left)/3),
        midRight = (int) (right - (right - left)/3);
    
        if (arr[midLeft] == target) return midLeft;
        if (arr[midRight] == target) return midRight;

        if (target < arr[midLeft]) 
            right = midLeft - 1;
        else if (target > arr[midRight])
            left = midRight + 1;
        else 
            left, right = midLeft + 1, midRight - 1;
    }
    return -1;
}

// O(loglogn) Uniformly distributed, sorted arrays
int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        int pos = low + ((double)(high - low) /
                         (arr[high] - arr[low])) * (target - arr[low]);

        if (arr[pos] == target) return pos;
        if (arr[pos] < target) low = pos + 1;
        else high = pos - 1;
    }

    return -1;
}

// O(logn) Very large or infinite sorted arrays
int exponentialSearch(int arr[], int n, int target) {
    if (arr[0] == target) return 0;

    int i = 1;
    while (i < n && arr[i] <= target) i *= 2;

    return iterativeBinarySearch(arr, i / 2, (i < n - 1 ? i : n - 1), target);
}