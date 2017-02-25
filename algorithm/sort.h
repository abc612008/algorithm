#pragma once
using SortType = int;
class Sort {
public:
    virtual ~Sort() {}
    virtual void operator()(SortType* arr, size_t len) = 0;
};
