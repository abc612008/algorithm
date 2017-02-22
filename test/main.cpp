#include "gtest/gtest.h"
#include "../algorithm/InsertionSort.h"
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
TEST(Sort, InsertionSort) {
    constexpr size_t len = 100;
    constexpr size_t test = 100;
    int arr[len];
    for (int i = 0; i < test; ++i) {
        SortChecker::random(arr, len);
        InsertionSort sort;
        sort(arr, len);
        EXPECT_TRUE(SortChecker::check(arr, len));
    }
    InsertionSort sort;
    int arr2[] = { 1 };
    sort(arr2, 1);
    EXPECT_TRUE(SortChecker::check(arr2, 1));

    int arr3[] = { 2,1 };
    sort(arr3, 1);
    EXPECT_TRUE(SortChecker::check(arr3, 1));
}
int main(int argc, char* argv[]) {
    srand(static_cast<unsigned int>(time(nullptr)));
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
