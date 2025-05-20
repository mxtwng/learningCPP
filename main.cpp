#include <bits/stdc++.h>
#include "searchingAlgorithms/sortedSearch.h"
#include "searchingAlgorithms/unsortedSearch.h"
#include "sortingAlgorithms/basicSorting.h"
#include "sortingAlgorithms/advancedSorting.h"

using namespace std;


int main() {
    int arr[] = {5, 2, 6, 3 ,13, 0, 1, 5, 8};
    mergeSort(arr, 0, 8);
    for (auto x: arr)
        cout << x << " ";
    return 0;
}
