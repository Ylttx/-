#include <gtest/gtest.h>
#include "problem_set.h"

TEST(P10_subarrySum, WHEN_k_2_DO_THEN_2) {
    vector<int> nums{1,1,1};

    EXPECT_EQ(subarrySum(nums, 2), 2);
}
