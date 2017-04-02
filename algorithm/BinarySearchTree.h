#pragma once
#include "DataType.h"
#include <memory>

class BinarySearchTree {
public:
    BinarySearchTree(DataType val):mValue(val){}

    const DataType& getValue() const noexcept { return mValue; }

    BinarySearchTree* find(DataType target) noexcept {
        if (target == mValue) return this;
        auto& next = target > mValue ? mRight : mLeft;
        if (next) return next->find(target);
        else return nullptr;
    }

    bool exist(DataType target) noexcept {
        return find(target) != nullptr;
    }

    // Can only be used on the root!
    void insert(DataType target) {
        if (target == mValue) throw ElementAlreadyExist();
        auto& next = target > mValue ? mRight : mLeft;
        if (next) return next->insert(target);
        next = std::make_unique<BinarySearchTree>(target);
    }

    // Can only be used on the root!
    void remove(DataType target) {
        
    }

    struct ElementAlreadyExist {};
    struct ElementNotExist {};

private:
    DataType mValue;
    std::unique_ptr<BinarySearchTree> mLeft = nullptr;
    std::unique_ptr<BinarySearchTree> mRight = nullptr;
};

