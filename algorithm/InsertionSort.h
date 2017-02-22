#pragma once
#include "sort.h"
#include <memory>

class InsertionSort : public Sort {
public:
    void operator()(SortType* arr, size_t len) override {
        SortType n = 0;
        for (size_t i = 1; i < len; ++i) {
            // pick the number
            n = arr[i];

            // find the position to insert
            for (size_t j = i - 1; ; --j) {
                if (arr[j] > n) arr[j + 1] = arr[j];
                else arr[j] = n;
                if (j == 0) break;
            }
        }
    }
};
