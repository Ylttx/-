#include <gtest/gtest.h>
#include "problems.h"

TEST(P1_CMyString, WHEN_helloworld_DO_assign_THEN_equal) {
    char data[] = "hello world";
    CMyString x(data);
    CMyString y = x;
    EXPECT_TRUE(strcmp(x.to_string(), y.to_string()) == 0);
    EXPECT_TRUE(strcmp(x.to_string(), "hello world") == 0);
}

TEST(P3_duplicate, WHEN_2310253_DO_duplicate_THEN_true_2) {
    int numbers[] = {2,3,1,0,2,5,3};
    int duplication = 0;
    EXPECT_TRUE(duplicate(numbers, sizeof(numbers) / sizeof(int), &duplication));
    EXPECT_EQ(duplication, 2);
}

TEST(P3_duplicate, WHEN_no_duplication_DO_duplicate_THEN_false) {
    int numbers[] = {2,3,1,0,4,5,6};
    int duplication = 0;
    EXPECT_FALSE(duplicate(numbers, sizeof(numbers) / sizeof(int), &duplication));
    EXPECT_EQ(duplication, 0);
}

TEST(P3_duplicate, WHEN_invalid_numbers_DO_duplicate_THEN_false) {
    int numbers[] = {2,3,1,0,4,5,7};
    int duplication = 0;
    EXPECT_FALSE(duplicate(numbers, sizeof(numbers) / sizeof(int), &duplication));
    EXPECT_EQ(duplication, 0);

    int *null_numbers = nullptr;
    EXPECT_FALSE(duplicate(null_numbers, 1, &duplication));
    EXPECT_EQ(duplication, 0);

    int zero_numbers[] = {};
    EXPECT_FALSE(duplicate(zero_numbers, sizeof(zero_numbers) / sizeof(int), &duplication));
    EXPECT_EQ(duplication, 0);
}

TEST(P3_duplicate, WHEN_23543267_DO_getDuplicate_THEN_2_or_3) {
    int numbers[] = {2,3,5,4,3,2,6,7};
    int length = sizeof(numbers) / sizeof(int);
    int res = getDuplication(numbers, length);
    EXPECT_TRUE(res == 2 || res == 3);
}

TEST(P3_duplicate, WHEN_no_duplication_DO_getDuplicate_THEN_neg1) {
    int numbers[] = {2,3,5,4,1,6,7};
    int length = sizeof(numbers) / sizeof(int);
    EXPECT_EQ(getDuplication(numbers, length), -1);
}

TEST(P3_duplicate, WHEN_invalid_numbers_DO_getDuplicate_THEN_neg1) {
    int *null_numbers = nullptr;
    EXPECT_EQ(getDuplication(null_numbers, 0), -1);

    int zero_numbers[] = {};
    EXPECT_EQ(getDuplication(zero_numbers, sizeof(zero_numbers) / sizeof(int)), -1);

}