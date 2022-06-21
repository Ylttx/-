#include <gtest/gtest.h>
#include "problem_set.h"

TEST(P10_subarrySum, WHEN_k_2_DO_THEN_2) {
    vector<int> nums{1,1,1};

    EXPECT_EQ(subarrySum(nums, 2), 2);
}

TEST(P11_findMaxLength, WHEN_010_DO_THEN_2) {
    vector<int> nums{0,1,0};

    EXPECT_EQ(findMaxLength(nums), 2);
}

TEST(P11_findMaxLength, WHEN_001100_DO_THEN_4) {
    vector<int> nums{0,0,1,1,0,0};

    EXPECT_EQ(findMaxLength(nums), 4);
}

TEST(P12_pivotIndex, WHEN_173629_DO_THEN_3) {
    vector<int> nums{1,7,3,6,2,9};

    EXPECT_EQ(pivotIndex(nums), 3);
}

TEST(P12_pivotIndex, WHEN_173_DO_THEN_neg_1) {
    vector<int> nums{1,7,3};

    EXPECT_EQ(pivotIndex(nums), -1);
}

