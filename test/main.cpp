#include "gtest/gtest.h"
#include "../algorithm/InsertionSort.h"
#include "../algorithm/BubbleSort.h"
#include "../algorithm/LinkedList.h"

TEST(Sort, SortChecker) {
    int arr1[] = { 1,3,5,9,12,17 };
    int arr2[] = { 3,3,5,9,12,12 };
    EXPECT_TRUE(SortChecker::check(arr1, sizeof(arr1) / sizeof(int)));
    EXPECT_TRUE(SortChecker::check(arr2, sizeof(arr2) / sizeof(int)));
    int arr3[] = { 1,3,2,9,12,17 };
    int arr4[] = { 5,3,3,9,12,17 };
    int arr5[] = { 1,3,5,9,12,11 };
    EXPECT_FALSE(SortChecker::check(arr3, sizeof(arr3) / sizeof(int)));
    EXPECT_FALSE(SortChecker::check(arr4, sizeof(arr4) / sizeof(int)));
    EXPECT_FALSE(SortChecker::check(arr5, sizeof(arr5) / sizeof(int)));
}

template<class T>
void sortTest() {
    {
        constexpr size_t len = 100;
        constexpr size_t test = 100;
        int arr[len];
        for (size_t i = 0; i < test; ++i) {
            SortChecker::random(arr, len);
            T sort;
            sort(arr, len);
            EXPECT_TRUE(SortChecker::check(arr, len));
        }
    }
    {
        T sort2;
        int arr2[] = { 1 };
        sort2(arr2, 1);
        EXPECT_TRUE(SortChecker::check(arr2, 1));
    }
    {
        T sort3;
        int arr3[] = { 2,1 };
        sort3(arr3, 1);
        EXPECT_TRUE(SortChecker::check(arr3, 1));
    }
}

TEST(Sort, InsertionSort) {
    sortTest<InsertionSort>();
}

TEST(Sort, BubbleSort) {
    sortTest<BubbleSort>();
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

int main(int argc, char* argv[]) {
    srand(static_cast<unsigned int>(time(nullptr)));
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
