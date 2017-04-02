#pragma once
#include "sort.h"

class MergeSort : public Sort {
public:
    void operator()(SortType* arr, size_t len) override {
        auto buffer = new SortType[len];
        merge(arr, buffer, 0, len - 1);
        delete[] buffer;
    }
private:
    static void merge(SortType* arr, SortType* buffer, size_t start, size_t end) {
        if (start >= end) return;
        auto mid = start + (end - start) / 2;
        merge(arr, buffer, start, mid);
        merge(arr, buffer, mid + 1, end);

        // Now arr[start...mid] and arr[mid+1...end] should be sorted.
        // Merge the two sorted array into the buffer.
        size_t i = start, j = mid + 1, p = start;

        // For each loop, choose the smaller one into the buffer,
        // until one of the arrays are running out of numbers.
        while (i <= mid&&j <= end)
            buffer[p++] = arr[i] < arr[j] ? arr[i++] : arr[j++];

        // These two lines should copy the remaining number into the buffer.
        // Only one (or neither) of the two lines will take effect.
        while (i <= mid) buffer[p++] = arr[i++];
        while (j <= end) buffer[p++] = arr[j++];

        // Copy the buffer into the target array.
        for (size_t l = start; l <= end; ++l)
            arr[l] = buffer[l];
    }
};
