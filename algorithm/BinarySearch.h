#pragma once
using SearchType = int;

// Input: a sorted array, the length of the array, the target
// Output: the index of the target in the array.
//         If the target does not exist in the array, size will be returned.
inline size_t binarySearch(SearchType* sortedArray, size_t size, SearchType target) {
    size_t l = 0, r = size - 1;
    while (l<=r) {
        auto m = (l + r) / 2;
        if (target < sortedArray[m]) r = m - 1;
        else if (target > sortedArray[m]) l = m + 1;
        else return m;
    }
    return size; // not found
}
