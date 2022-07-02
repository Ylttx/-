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

TEST(P13_NumMatrix, WHEN_5x5_DO_21_43_THEN_8) {
    vector<vector<int>> nums = {
        {3,0,1,4,2},
        {5,6,3,2,1},
        {1,2,0,1,5},
        {4,1,0,1,7},
        {1,0,3,0,5}
    };
    NumMatrix nm(nums);

    EXPECT_EQ(nm.sumRegion(2, 1, 4, 3), 8);
}

TEST(P14_checkInclusion, WHEN_ac_dgcaf_DO_check_THEN_true) {
    string s1 = "ac", s2 = "dgcaf";

    EXPECT_TRUE(checkInclusion(s1, s2));
}

TEST(P14_checkInclusion, WHEN_ab_dgcaf_DO_check_THEN_false) {
    string s1 = "ab", s2 = "dgcaf";

    EXPECT_FALSE(checkInclusion(s1, s2));
}

TEST(P15_findAnagrams, WHEN_cbadabacg_abc_DO_find_THEN_05) {
    string s1 = "cbadabacg", s2 = "abc";
    vector<int> res = {0, 5};
 
    EXPECT_EQ(findAnagrams(s1, s2), res);
}

TEST(P15_findAnagrams, WHEN_s1_less_s2_DO_find_THEN_empty) {
    string s1 = "cb", s2 = "abc";
    vector<int> res;
 
    EXPECT_EQ(findAnagrams(s1, s2), res);
}

TEST(P16_lengthOfLongestSubstring, WHEN_babcca_DO_find_THEN_eq_3) {
    string s = "babcca";
 
    EXPECT_EQ(lengthOfLongestSubstring(s), 3);
}

TEST(P16_lengthOfLongestSubstring, WHEN_dfdgapfuy_DO_find_THEN_eq_7) {
    string s = "dfdgapfuy";
 
    EXPECT_EQ(lengthOfLongestSubstring(s), 7);
}

TEST(P17_minWindow, WHEN_ADDBANCAD_ABC_DO_minWindow_THEN_eq_BANC) {
    string s = "ADDBANCAD", t = "ABC";
 
    EXPECT_EQ(minWindow(s, t), "BANC");
}

TEST(P17_minWindow, WHEN_s_shorter_than_t_DO_minWindow_THEN_empty) {
    string s = "AD", t = "ABC";
 
    EXPECT_EQ(minWindow(s, t), "");
}

TEST(P18_isPalindrome, WHEN_DO_isPalindrome_THEN) {
    EXPECT_TRUE(isPalindrome("Was it a cat I saw?"));
    EXPECT_FALSE(isPalindrome("race a car"));
}

TEST(P19_validPalindrome, WHEN_DO_validPalindrome_THEN) {
    EXPECT_TRUE(validPalindrome("abca"));
    EXPECT_TRUE(validPalindrome("race a car"));
    EXPECT_FALSE(validPalindrome("race ba car"));
}

TEST(P20_countSubstrings, WHEN_string_DO_countSubstrings_THEN_equal) {
    EXPECT_EQ(countSubstrings("abc"), 3);
    EXPECT_EQ(countSubstrings("aaa"), 6);
    EXPECT_EQ(countSubstrings("zhyhz"), 7);
    EXPECT_EQ(countSubstrings(""), 0);
}