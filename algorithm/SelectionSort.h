#pragma once
#include "sort.h"
#include <utility>

class SelectionSort : public Sort {
public:
    void operator()(SortType* arr, size_t len) override {
        for (size_t pos = 0; pos < len; ++pos) {
            size_t minPos = pos;
            SortType* min = &arr[pos];
            for (size_t i = pos+1; i < len; ++i) {
                if (arr[i] < *min) { min = &arr[i]; minPos = i; }
            }
            std::swap(arr[pos], arr[minPos]);
        }
    }
};
