#pragma once
#include "sort.h"
#include <cstring>

template<bool InPlace>
class Quicksort : public Sort {
public:
    void operator()(SortType* arr, size_t len) override {
        if (!InPlace) qsort(arr, len);
    }
private:
    static void qsort(SortType* arr, size_t len) {
        if (len == 1) return;
        auto small = new SortType[len];
        size_t smallLen = 0;
        auto big = new SortType[len];
        size_t bigLen = 0;
        auto base = arr[0];
        for (size_t i = 0; i < len; ++i) {
            if (arr[i] > base) big[bigLen++] = arr[i];
            else small[smallLen++] = arr[i];
        }
        qsort(small, smallLen);
        qsort(big, bigLen);
        memcpy(arr, small, smallLen*sizeof(SortType));
        arr[smallLen] = base;
        memcpy(arr + smallLen + 1, big, bigLen*sizeof(SortType));
        delete[] small;
        delete[] big;
    }
};
