#pragma once
#include "sort.h"
#include <utility>

class BubbleSort : public Sort {
public:
    void operator()(SortType* arr, size_t len) override {
        bool flag = true;
        while(flag) {
            flag = false;
            for (size_t i = 0; i < len - 1; ++i) {
                if (arr[i]>arr[i + 1]) {
                    std::swap(arr[i], arr[i + 1]);
                    flag = true;
                }
            }
        }
    }
};
