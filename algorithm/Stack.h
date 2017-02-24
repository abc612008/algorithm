#pragma once
#include "DataType.h"

struct StackOverflow {};
struct StackUnderflow {};

template<size_t Size>
class Stack {
public:
    void push(DataType d) {
        if (mSize == Size) throw StackOverflow();
        mData[mSize++] = d;
    }
    void pop() {
        if (mSize == 0) throw StackUnderflow();
        mSize--;
    }
    DataType get() const {
        if (mSize == 0) throw StackUnderflow();
        return mData[mSize-1];
    }
    void clear() noexcept { mSize = 0; }
    size_t size() const noexcept { return mSize; }

private:
    DataType mData[Size] = { 0 };
    size_t mSize = 0;
};
