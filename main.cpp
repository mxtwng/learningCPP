#include <bits/stdc++.h>
#include "searchingAlgorithms/sortedSearch.h"
#include "searchingAlgorithms/unsortedSearch.h"
using namespace std;


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << iterativeTernarySearch(arr, 0, 10, 2) << endl;
    return 0;
}
