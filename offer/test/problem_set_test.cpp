#include <gtest/gtest.h>
#include "problems.h"

TEST(P1_CMyString, WHEN_helloworld_DO_assign_THEN_equal) {
    char data[] = "hello world";
    CMyString x(data);
    CMyString y = x;
    EXPECT_TRUE(strcmp(x.to_string(), y.to_string()) == 0);
    EXPECT_TRUE(strcmp(x.to_string(), "hello world") == 0);
}
