#pragma once
#include <cstdlib>
using SortType = int;
class Sort {
public:
    virtual ~Sort() {}
    virtual void operator()(SortType* arr, size_t len) = 0;
};
class SortChecker {
public:
    static void random(SortType* arr, size_t len) {
        for (size_t i = 0; i < len; ++i) arr[i] = rand();
    }
    static bool check(SortType* arr, size_t len) {
        for (size_t i = 1; i < len; ++i)
            if (arr[i - 1]>arr[i]) return false;
        return true;
    }
};
