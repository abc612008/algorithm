#include "gtest/gtest.h"
#include <cstdlib>
#include <unordered_map>
#include "../algorithm/InsertionSort.h"
#include "../algorithm/BubbleSort.h"
#include "../algorithm/LinkedList.h"
#include "../algorithm/SelectionSort.h"
#include "../algorithm/Stack.h"
#include "../algorithm/MergeSort.h"
#include "../algorithm/Quicksort.h"
#include "../algorithm/BinarySearch.h"
#include "../algorithm/BinarySearchTree.h"

bool sortCheck(SortType* arr, SortType* src, size_t len) {
    std::unordered_map<int, int> srcNumberCount;
    std::unordered_map<int, int> targetNumberCount;
    for (size_t i = 0; i < len; ++i)
        srcNumberCount[src[i]]++;

    targetNumberCount[arr[0]]++;
    for (size_t i = 1; i < len; ++i) {
        targetNumberCount[arr[i]]++;
        if (arr[i - 1]>arr[i]) return false;
    }

    for (auto n : srcNumberCount)
        if (targetNumberCount[n.first] != n.second) return false;

    return true;
}

TEST(Sort, SortChecker) {
    int arr1[] = { 1,3,5,9,12,17 };
    int arr1s1[] = { 1,3,5,9,12,12 };
    int arr1s2[] = { 1,12,5,3,9,17 };
    int arr2[] = { 3,3,5,9,12,12 };
    int arr2s1[] = { 12,3,3,5,9,3 };
    int arr2s2[] = { 5,3,12,3,9,12 };
    EXPECT_TRUE(sortCheck(arr1, arr1s2, sizeof(arr1) / sizeof(int)));
    EXPECT_TRUE(sortCheck(arr2, arr2s2, sizeof(arr2) / sizeof(int)));
    EXPECT_FALSE(sortCheck(arr1, arr1s1, sizeof(arr1) / sizeof(int)));
    EXPECT_FALSE(sortCheck(arr2, arr2s1, sizeof(arr2) / sizeof(int)));

    int arr3[] = { 1,3,2,9,12,17 };
    int arr4[] = { 5,3,3,9,12,17 };
    int arr5[] = { 1,3,5,9,12,11 };
    EXPECT_FALSE(sortCheck(arr3, arr3, sizeof(arr3) / sizeof(int)));
    EXPECT_FALSE(sortCheck(arr4, arr4, sizeof(arr4) / sizeof(int)));
    EXPECT_FALSE(sortCheck(arr5, arr5, sizeof(arr5) / sizeof(int)));
}

static void randomArray(SortType* arr, size_t len) {
    for (size_t i = 0; i < len; ++i) arr[i] = rand();
}

template<class T>
void sortTest() {
    {
        constexpr size_t len = 100;
        constexpr size_t test = 100;
        int arr[len];
        int src[len];
        for (size_t i = 0; i < test; ++i) {
            randomArray(arr, len);
            memcpy(src, arr, len*sizeof(int));
            T sort;
            sort(arr, len);
            EXPECT_TRUE(sortCheck(arr, src, len));
        }
    }
    {
        T sort2;
        int arr2[] = { 1 };
        int src2[] = { 1 };
        sort2(arr2, 1);
        EXPECT_TRUE(sortCheck(arr2, src2, 1));
    }
    {
        T sort3;
        int arr3[] = { 2,1 };
        int src3[] = { 2,1 };
        sort3(arr3, 1);
        EXPECT_TRUE(sortCheck(arr3, src3, 1));
    }
}

TEST(Sort, InsertionSort) {
    sortTest<InsertionSort>();
}

TEST(Sort, BubbleSort) {
    sortTest<BubbleSort>();
}

TEST(Sort, SelectionSort) {
    sortTest<SelectionSort>();
}

TEST(Sort, MergeSort) {
    sortTest<MergeSort>();
}

TEST(Sort, Quicksort) {
    sortTest<Quicksort<false>>();
}

TEST(Search, BinarySearch) {
    constexpr size_t arraySize = 100;
    auto testCount = 100;
    while(testCount-->0) {
        SearchType arr[arraySize];
        arr[0] = 0;
        for(size_t i=1;i<arraySize;++i) {
            arr[i] = arr[i - 1] + rand();
        }
        size_t index = rand() % arraySize;
        EXPECT_EQ(index, binarySearch(arr, arraySize, arr[index]));
        size_t target_not_found = 0;
        bool success = false;
        while(!success) {
            target_not_found = rand();
            success = true;
            for (size_t i = 0; i<arraySize; ++i) {
                if (arr[i] == target_not_found) success = false;
            }
        }
        EXPECT_EQ(arraySize, binarySearch(arr, arraySize, target_not_found));
    }
}

TEST(Structures, LinkedList) {
    LinkedList list; //[]
    EXPECT_EQ(list.size(), 0);
    list.insertHead(0); //[0]
    list.insert(list.getHead(), 1); //[0, 1]
    list.insert(list.getHead(), 2); //[0, 2, 1]
    list.insert(1, 5); //[0, 2, 5, 1]
    list.insertHead(8); //[8, 0, 2, 5, 1]
    EXPECT_EQ(list.size(), 5);
    EXPECT_EQ(list.get(0), 8);
    EXPECT_EQ(list.get(1), 0);
    EXPECT_EQ(list.get(2), 2);
    EXPECT_EQ(list.get(3), 5);
    EXPECT_EQ(list.get(4), 1);
    list.set(3, 7); //[8, 0, 2, 7, 1]
    EXPECT_EQ(list.get(3), 7);
    list.removeAfter(list.getNode(1)->getNext()); //[8, 0, 2, 1]
    list.remove(0); //[0, 2, 1]
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.get(0), 0);
    EXPECT_EQ(list.get(1), 2);
    EXPECT_EQ(list.get(2), 1);
    list.remove(1); //[0, 1]
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.get(0), 0);
    EXPECT_EQ(list.get(1), 1);
    list.clear(); //[]
    EXPECT_EQ(list.size(), 0);
}

TEST(Structures, Stack) {
    Stack<3> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_EQ(stack.get(), 3);
    EXPECT_EQ(stack.size(), 3);
    stack.pop();
    EXPECT_EQ(stack.get(), 2);
    EXPECT_EQ(stack.size(), 2);
    stack.clear();
    EXPECT_EQ(stack.size(), 0);
    try {
        stack.get();
        FAIL() << "Expected StackUnderflow";
    } catch (StackUnderflow&) {} catch (...) {
        FAIL() << "Expected StackUnderflow";
    }
    stack.push(1);
    stack.pop();
    try {
        stack.pop();
        FAIL() << "Expected StackUnderflow";
    } catch (StackUnderflow&) {}
    catch (...) {
        FAIL() << "Expected StackUnderflow";
    }
    stack.push(1);
    stack.push(2);
    stack.push(3);
    try {
        stack.push(4);
        FAIL() << "Expected StackOverflow";
    } catch (StackOverflow&) {}
    catch (...) {
        FAIL() << "Expected StackOverflow";
    }
}

TEST(Structures, BinarySearchTree) {
    BinarySearchTree bst(0);
    auto insertTest = [&bst](int value)
    {
        EXPECT_FALSE(bst.exist(value));
        bst.insert(value);
        EXPECT_TRUE(bst.exist(value));
    };
    insertTest(2);
    insertTest(1);
    insertTest(7);
    insertTest(9);
    insertTest(-10);
    insertTest(-12);
    insertTest(12);
    insertTest(233);
    insertTest(-8);
    insertTest(-9);
    insertTest(8);
    try {
        bst.insert(2);
        FAIL() << "Expected ElementAlreadyExist";
    }
    catch (BinarySearchTree::ElementAlreadyExist&) {}
    catch (...) {
        FAIL() << "Expected ElementAlreadyExist";
    }
    auto removeTest = [&bst](int value) {
        EXPECT_TRUE(bst.exist(value));
        bst.remove(value);
        EXPECT_FALSE(bst.exist(value));
    };
    removeTest(2);
    insertTest(2);
    removeTest(233);
    try {
        bst.remove(250);
        FAIL() << "Expected ElementAlreadyExist";
    }
    catch (BinarySearchTree::ElementAlreadyExist&) {}
    catch (...) {
        FAIL() << "Expected ElementAlreadyExist";
    }
}

int main(int argc, char* argv[]) {
    srand(static_cast<unsigned int>(time(nullptr)));
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
