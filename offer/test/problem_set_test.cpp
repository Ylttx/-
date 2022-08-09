#include <gtest/gtest.h>
#include <vector>
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

TEST(P4_find, WHEN_exist_DO_find_THEN_true) {
    int matrix[] = {
        1,2,8,9,
        2,4,9,12,
        4,7,10,13,
        6,8,11,15
    };

    EXPECT_TRUE(Find(matrix, 4, 4, 7));
    EXPECT_TRUE(Find(matrix, 4, 4, 15));
    EXPECT_TRUE(Find(matrix, 4, 4, 1));
}
TEST(P4_find, WHEN_not_exist_DO_find_THEN_false) {
    int matrix[] = {
        1,2,8,9,
        2,4,9,12,
        4,7,10,13,
        6,8,11,15
    };

    EXPECT_FALSE(Find(matrix, 4, 4, 3));
    EXPECT_FALSE(Find(matrix, 4, 4, 0));
    EXPECT_FALSE(Find(matrix, 4, 4, 16));
}

TEST(P4_find, WHEN_invalid_DO_find_THEN_false) {
    int *matrix = nullptr;
    EXPECT_FALSE(Find(matrix, 0, 0, 1));
}

TEST(P5_ReplaceBlank, WHEN_have_blank_DO_replace_THEN_equal) {
    char string[18] = "We are happy.";
    ReplaceBlank(string, 18);
    EXPECT_STREQ(string, "We%20are%20happy.");

    char string1[18] = " Weare happy.";
    ReplaceBlank(string1, 18);
    EXPECT_STREQ(string1, "%20Weare%20happy.");

    char string2[18] = "We arehappy. ";
    ReplaceBlank(string2, 18);
    EXPECT_STREQ(string2, "We%20arehappy.%20");

    char string3[18] = "Weare  happy.";
    ReplaceBlank(string3, 18);
    EXPECT_STREQ(string3, "Weare%20%20happy.");

    char string4[4] = " ";
    ReplaceBlank(string4, 4);
    EXPECT_STREQ(string4, "%20");

    char string5[10] = "   ";
    ReplaceBlank(string5, 10);
    EXPECT_STREQ(string5, "%20%20%20");
}

TEST(P5_ReplaceBlank, WHEN_no_blank_DO_replace_THEN_equal) {
    char string[18] = "Wearehappy.";
    ReplaceBlank(string, 18);
    EXPECT_STREQ(string, "Wearehappy.");
}

TEST(P5_ReplaceBlank, WHEN_invalid_DO_replace_THEN_equal) {
    char *string = nullptr;
    ReplaceBlank(string, 1);
    EXPECT_TRUE(string == nullptr);

    char string1[] = "";
    ReplaceBlank(string, sizeof(string1));
    EXPECT_EQ(string1[0], '\0');
}

TEST(P6_ConstructBinaryTree, WHEN_incomplte_DO_construct_THEN_equal) {
    int preorder[] = {1,2,4,7,3,5,6,8};
    int inorder[] = {4,7,2,1,5,3,8,6};
    const int length = (int) (sizeof(preorder) / sizeof(int));
 
    BinaryTreeNode *expect[length];
    for (int i = 1; i <= length; i++)
        expect[i - 1] = new BinaryTreeNode(i);
    expect[0]->m_pLeft = expect[1];
    expect[0]->m_pRight = expect[2];
    expect[1]->m_pLeft = expect[3];
    expect[3]->m_pRight = expect[6];
    expect[2]->m_pLeft = expect[4];
    expect[2]->m_pRight = expect[5];
    expect[5]->m_pLeft = expect[7];

    BinaryTreeNode *result = Construct(preorder, inorder, length);
    EXPECT_TRUE(BinaryTreeEqual(result, expect[0]));
}

TEST(P6_ConstructBinaryTree, WHEN_complte_DO_construct_THEN_equal) {
    int preorder[] = {1,2,4,5,3,6,7};
    int inorder[] = {4,2,5,1,6,3,7};
    const int length = (int) (sizeof(preorder) / sizeof(int));
 
    BinaryTreeNode *expect[length];
    for (int i = 1; i <= length; i++)
        expect[i - 1] = new BinaryTreeNode(i);
    expect[0]->m_pLeft = expect[1];
    expect[0]->m_pRight = expect[2];
    expect[1]->m_pLeft = expect[3];
    expect[1]->m_pRight = expect[4];
    expect[2]->m_pLeft = expect[5];
    expect[2]->m_pRight = expect[6];
 
    try {
        BinaryTreeNode *result = Construct(preorder, inorder, length);
        EXPECT_TRUE(BinaryTreeEqual(result, expect[0]));
    } catch (const char *c) {
        std::cerr << c << std::endl;
        ASSERT_TRUE(false);
    }
}

TEST(P6_ConstructBinaryTree, WHEN_special_one_node_DO_construct_THEN_equal) {
    int preorder[] = {1024};
    int inorder[] = {1024};
    const int length = (int) (sizeof(preorder) / sizeof(int));
    BinaryTreeNode *expect = new BinaryTreeNode(1024);
 
    BinaryTreeNode *result = Construct(preorder, inorder, length);
 
    EXPECT_TRUE(BinaryTreeEqual(result, expect));
}

TEST(P6_ConstructBinaryTree, WHEN_special_only_left_DO_construct_THEN_equal) {
    int preorder[] = {1,2,3};
    int inorder[] = {3,2,1};
    const int length = (int) (sizeof(preorder) / sizeof(int));
    BinaryTreeNode *expect[length];
    for (int i = 1; i <= length; i++)
        expect[i - 1] = new BinaryTreeNode(i);
    expect[0]->m_pLeft = expect[1];
    expect[1]->m_pLeft = expect[2];

    BinaryTreeNode *result = Construct(preorder, inorder, length);
 
    EXPECT_TRUE(BinaryTreeEqual(result, expect[0]));
}

TEST(P6_ConstructBinaryTree, WHEN_special_only_right_DO_construct_THEN_equal) {
    int preorder[] = {1,2,3};
    int inorder[] = {1,2,3};
    const int length = (int) (sizeof(preorder) / sizeof(int));
    BinaryTreeNode *expect[length];
    for (int i = 1; i <= length; i++)
        expect[i - 1] = new BinaryTreeNode(i);
    expect[0]->m_pLeft = expect[1];
    expect[1]->m_pLeft = expect[2];

    BinaryTreeNode *result = Construct(preorder, inorder, length);
 
    EXPECT_TRUE(BinaryTreeEqual(result, expect[0]));
}

TEST(P6_ConstructBinaryTree, WHEN_invalid_DO_construct_THEN_throw) {
    int *preorder = nullptr;
    int inorder[] = {4,2,5,1,6,3,7};
    EXPECT_EQ(Construct(preorder, inorder, 7), nullptr);
    EXPECT_EQ(Construct(inorder, preorder, 7), nullptr);
    EXPECT_EQ(Construct(preorder, preorder, 1), nullptr);
    EXPECT_EQ(Construct(preorder, inorder, 0), nullptr);
 
    int invalid_preorder[] = {1,2,4,5,3,7,6};
    EXPECT_THROW(Construct(invalid_preorder, inorder, 7), const char *);
}

TEST(P7_GetNextBTNode, WHEN_incomplete_DO_getnext_THEN_equal) {
    const int length = 9;
    BinaryTreeNode *expect[length];
    for (int i = 1; i <= length; i++)
        expect[i - 1] = new BinaryTreeNode(i);
    expect[0]->m_pLeft = expect[1];
    expect[0]->m_pRight = expect[2];
    expect[1]->m_pLeft = expect[3];
    expect[1]->m_pRight = expect[4];
    expect[2]->m_pLeft = expect[5];
    expect[2]->m_pRight = expect[6];
    expect[4]->m_pLeft = expect[7];
    expect[4]->m_pRight = expect[8];

    expect[1]->m_pParent = expect[0];
    expect[2]->m_pParent = expect[0];
    expect[3]->m_pParent = expect[1];
    expect[4]->m_pParent = expect[1];
    expect[5]->m_pParent = expect[2];
    expect[6]->m_pParent = expect[2];
    expect[7]->m_pParent = expect[4];
    expect[8]->m_pParent = expect[4];

    EXPECT_EQ(GetNext(expect[0]), expect[5]);
    EXPECT_EQ(GetNext(expect[8]), expect[0]);
    EXPECT_EQ(GetNext(expect[6]), nullptr);
}

TEST(P9_CQueue, WHEN_12345_DO_push_THEN_12345) {
    CQueue<int> cq;
    std::vector<int> result;
    std::vector<int> expect = {1,2,3,4,5};
 
    for (int i = 1; i <= 5; ++i) {
        cq.appendTail(i);
    }

    for (int i = 1; i <= 5; ++i) {
        result.push_back(cq.deleteHead());
    }

    EXPECT_EQ(result, expect);
}

TEST(P10_Fibonacci, WHEN_valid_DO_compare_THEN_equal) {
    EXPECT_EQ(Fibonacci_iteratively(10), Fibonacci_recursively(10));
    EXPECT_EQ(Fibonacci_iteratively(0), Fibonacci_recursively(0));
    EXPECT_EQ(Fibonacci_iteratively(1), Fibonacci_recursively(1));
    EXPECT_EQ(Fibonacci_iteratively(2), Fibonacci_recursively(2));
}

TEST(P11_Min, WHEN_any_12345_DO_find_min_THEN_equal_1) {
    int numbers[] = {3,4,5,1,2};
    EXPECT_EQ(Min(numbers, 5), 1);

    int numbers1[] = {1,2,3,4,5};
    EXPECT_EQ(Min(numbers1, 5), 1);
}

TEST(P11_Min, WHEN_invalid_DO_find_min_THEN_throw) {
    int numbers[] = {5,4,3,2,1};
    EXPECT_THROW(Min(numbers, 5), const char *);

    int *numbers1 = nullptr;
    EXPECT_THROW(Min(numbers1, 0), const char *);
}

TEST(P12_hasPath, WHEN_exist_DO_hasPath_THEN_true) {
    char matrix[] = {
        'a', 'b', 't', 'g',
        'c', 'f', 'c', 's',
        'j', 'd', 'e', 'h'
    };

    EXPECT_TRUE(hasPath(matrix, 3, 4, "bfce"));
}

TEST(P12_hasPath, WHEN_not_exist_DO_hasPath_THEN_false) {
    char matrix[] = {
        'a', 'b', 't', 'g',
        'c', 'f', 'c', 's',
        'j', 'd', 'e', 'h'
    };

    EXPECT_FALSE(hasPath(matrix, 3, 4, "abfb"));
}

TEST(P12_hasPath, WHEN_borde_matrix_DO_hasPath_THEN_true) {
    char matrix[] = {'a', 'b', 't', 'g'};

    EXPECT_TRUE(hasPath(matrix, 1, 4, "bt"));
    EXPECT_TRUE(hasPath(matrix, 4, 1, "gt"));

    char same_matrix[] = {
        'a', 'a', 'a', 'a',
        'a', 'a', 'a', 'a'
    };

    EXPECT_TRUE(hasPath(same_matrix, 2, 4, "aaaaaa"));
}

TEST(P12_hasPath, WHEN_null_matrix_DO_hasPath_THEN_false) {
    char *matrix = nullptr;
    EXPECT_FALSE(hasPath(matrix, 0, 0, "0"));
}

TEST(P12_movingCount, WHEN_2x2_matrix_DO_count_THEN_equal) {
    EXPECT_EQ(movingCount(2, 2, 2), 4);
    EXPECT_EQ(movingCount(3, 2, 2), 4);
    EXPECT_EQ(movingCount(100, 2, 2), 4);
    EXPECT_EQ(movingCount(1, 2, 2), 3);
    EXPECT_EQ(movingCount(0, 2, 2), 1);
    EXPECT_EQ(movingCount(-1, 2, 2), 0);
}