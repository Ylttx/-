#include <gtest/gtest.h>

extern "C" {
#include "sort.h"
}

TEST(sort, insertion_sort_1) {
    int A[] = {5,2,4,6,1,3};
    int B[] = {1,2,3,4,5,6};

    insertion_sort(A, 6);

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(A[i], B[i]);
}

TEST(sort, insertion_sort_2) {
    int A[] = {52,23,44,64,21,23};
    int B[] = {21,23,23,44,52,64};

    insertion_sort(A, 6);

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(A[i], B[i]);
}


TEST(sort, insertion_down_sort_1) {
    int A[] = {5,2,4,6,1,3};
    int B[] = {6,5,4,3,2,1};

    insertion_down_sort(A, 6);

    for (int i = 0; i < 6; i++)
        EXPECT_EQ(A[i], B[i]);
}
