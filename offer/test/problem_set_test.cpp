#include <gtest/gtest.h>
#include <vector>
#include <sstream>
#include <set>
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

TEST(P13_movingCount, WHEN_2x2_matrix_DO_count_THEN_equal) {
    EXPECT_EQ(movingCount(2, 2, 2), 4);
    EXPECT_EQ(movingCount(3, 2, 2), 4);
    EXPECT_EQ(movingCount(100, 2, 2), 4);
    EXPECT_EQ(movingCount(1, 2, 2), 3);
    EXPECT_EQ(movingCount(0, 2, 2), 1);
    EXPECT_EQ(movingCount(-1, 2, 2), 0);
}

TEST(P14_cutting, WHEN_dp_DO_cut_THEN_equal) {
    EXPECT_EQ(maxProductAfterCutting_dp(8), 18);
    EXPECT_EQ(maxProductAfterCutting_dp(0), 0);
    EXPECT_EQ(maxProductAfterCutting_dp(1), 0);
    EXPECT_EQ(maxProductAfterCutting_dp(2), 1);
    EXPECT_EQ(maxProductAfterCutting_dp(3), 2);
}

TEST(P14_cutting, WHEN_greedy_DO_cut_THEN_equal) {
    EXPECT_EQ(maxProductAfterCutting_greedy(8), 18);
    EXPECT_EQ(maxProductAfterCutting_greedy(0), 0);
    EXPECT_EQ(maxProductAfterCutting_greedy(1), 0);
    EXPECT_EQ(maxProductAfterCutting_greedy(2), 1);
    EXPECT_EQ(maxProductAfterCutting_greedy(3), 2);
}

TEST(P15_NumberOf1, WHEN_valid_DO_calc_THEN_equal) {
    EXPECT_EQ(NumberOf1(1), 1);
    EXPECT_EQ(NumberOf1(0x7fffffff), 31);
    EXPECT_EQ(NumberOf1(0x80000000), 1);
    EXPECT_EQ(NumberOf1(0xffffffff), 32);
    EXPECT_EQ(NumberOf1(0), 0);
}

TEST(P16_Power, WHEN_valid_DO_power_THEN_equal) {
    EXPECT_EQ(Power(2, 3), 8);
    EXPECT_EQ(Power(2, -3), 0.125);
}

TEST(P18_DeleteNode, WHEN_123_DO_Delete2_THEN_13) {
    ListNode* ln3 = new ListNode{3, nullptr};
    ListNode* ln2 = new ListNode{2, ln3};
    ListNode* ln1 = new ListNode{1, ln2};

    DeleteNode(&ln1, ln2);
    
    EXPECT_EQ(ln1->m_pNext->m_nKey, ln2->m_nKey);
    delete ln2;
    delete ln1;
}

TEST(P18_DeleteNode, WHEN_123_DO_Delete1_THEN_23) {
    ListNode* ln3 = new ListNode{3, nullptr};
    ListNode* ln2 = new ListNode{2, ln3};
    ListNode* ln1 = new ListNode{1, ln2};

    DeleteNode(&ln1, ln1);
 
    EXPECT_EQ(ln1->m_nKey, 2);
    delete ln3;
    delete ln1;
}

TEST(P18_DeleteNode, WHEN_OneNode_DO_Delete_THEN_null) {
    ListNode* ln = new ListNode{0, nullptr};

    DeleteNode(&ln, ln);

    EXPECT_TRUE(ln == nullptr);
}

TEST(P18_DeleteNode, WHEN_Invalid_DO_Delete_THEN_null) {
    ListNode* ln = new ListNode{999, nullptr};

    DeleteNode(&ln, nullptr);
    DeleteNode(nullptr, nullptr);

    EXPECT_EQ(ln->m_nKey, 999);

    delete ln;
}

TEST(P18_DeleteDuplication, WHEN_Valid_DO_Delete_THEN_succ) {
    ListNode* ln[7];
    ln[6] = new ListNode{5, nullptr};
    ln[5] = new ListNode{4, ln[6]};
    ln[4] = new ListNode{3, ln[5]};
    ln[3] = new ListNode{3, ln[4]};
    ln[2] = new ListNode{2, ln[3]};
    ln[1] = new ListNode{2, ln[2]};
    ln[0] = new ListNode{1, ln[1]};

    DeleteDuplication(&ln[0]);
    EXPECT_EQ(ln[0]->m_pNext, ln[5]);
    delete ln[0];
    delete ln[5];
    delete ln[6];
}

TEST(P19_match, WHEN_match_DO_match_THEN_true) {
    EXPECT_TRUE(match("aaa", "a.a"));
    EXPECT_TRUE(match("aaa", "ab*ac*a"));
}

TEST(P19_match, WHEN_not_match_DO_match_THEN_false) {
    EXPECT_FALSE(match("aaa", "aa.a"));
    EXPECT_FALSE(match("aaa", "ab*a"));
}

TEST(P20_isNumeric, WHEN_valid_DO_test_THEN_true) {
    EXPECT_TRUE(isNumeric("+100"));
    EXPECT_TRUE(isNumeric("5e2"));
    EXPECT_TRUE(isNumeric("-123"));
    EXPECT_TRUE(isNumeric("3.1416"));
    EXPECT_TRUE(isNumeric("-1E-16"));
}

TEST(P20_isNumeric, WHEN_invalid_DO_test_THEN_false) {
    EXPECT_FALSE(isNumeric("12e"));
    EXPECT_FALSE(isNumeric("1a3.14"));
    EXPECT_FALSE(isNumeric("1.2.3"));
    EXPECT_FALSE(isNumeric("+-5"));
    EXPECT_FALSE(isNumeric("12e+5.4"));
}

TEST(P21_ReorderOddEven, WHEN_12345_DO_reorder_THEN_15342) {
    int data[] = {1,2,3,4,5};
    int expect[] = {1,5,3,4,2};
    auto length = (unsigned int) (sizeof(data) / sizeof(int));
    ReorderOddEven(data, length);
    EXPECT_EQ(memcmp(data, expect, sizeof(data)), 0);
}

TEST(P22_FindKthToTail, WHEN_12345_DO_find_3_THEN_3) {
    ListNode ln5{5, nullptr};
    ListNode ln4{4, &ln5};
    ListNode ln3{3, &ln4};
    ListNode ln2{2, &ln3};
    ListNode ln1{1, &ln2};

    EXPECT_EQ(FindKthToTail(&ln1, 3), &ln3);
    EXPECT_EQ(FindKthToTail(&ln1, 6), nullptr);
    EXPECT_EQ(FindKthToTail(&ln1, 0), nullptr);
    EXPECT_EQ(FindKthToTail(nullptr, 1), nullptr);
}

TEST(P23_EntryNodeOfLoop, WHEN_exist_DO_find_THEN_3) {
    ListNode ln6{6, nullptr};
    ListNode ln5{5, &ln6};
    ListNode ln4{4, &ln5};
    ListNode ln3{3, &ln4};
    ListNode ln2{2, &ln3};
    ListNode ln1{1, &ln2};
    ln6.m_pNext = &ln3;

    EXPECT_EQ(EntryNodeOfLoop(&ln1), &ln3);
}

TEST(P23_EntryNodeOfLoop, WHEN_not_exist_DO_find_THEN_nullptr) {
    ListNode ln2{2, nullptr};
    ListNode ln1{1, &ln2};

    EXPECT_EQ(EntryNodeOfLoop(&ln1), nullptr);
    EXPECT_EQ(EntryNodeOfLoop(&ln2), nullptr);
    EXPECT_EQ(EntryNodeOfLoop(nullptr), nullptr);
}

TEST(P24_ReverseList, WHEN_abc_DO_reverse_THEN_cba) {
    ListNode lnc{'c', nullptr};
    ListNode lnb{'b', &lnc};
    ListNode lna{'a', &lnb};

    EXPECT_EQ(ReverseList(&lnc), &lnc);
    EXPECT_EQ(ReverseList(&lna), &lnc);
    EXPECT_EQ(ReverseList(nullptr), nullptr);
}

TEST(P25_Merge, WHEN_any_input_DO_merge_THEN_equal) {
    ListNode ln7{7, nullptr};
    ListNode ln5{5, &ln7};
    ListNode ln3{3, &ln5};
    ListNode ln1{1, &ln3};

    ListNode ln8{8, nullptr};
    ListNode ln6{6, &ln8};
    ListNode ln4{4, &ln6};
    ListNode ln2{2, &ln4};

    EXPECT_EQ(Merge(&ln1, &ln2), &ln1);
 
    int list[8] = {0}, expect[] = {1,2,3,4,5,6,7,8}, i = 0;
    ListNode* pNode = &ln1;
    while (pNode != nullptr) {
        list[i++] = pNode->m_nKey;
        pNode = pNode->m_pNext;
    }

    EXPECT_EQ(memcmp(list, expect, sizeof(list)), 0);
}

TEST(P26_HasSubtree, WHEN_valid_DO_HasSubtree_THEN_true) {
    BinaryTreeNodeDouble bt4{4., nullptr, nullptr};
    BinaryTreeNodeDouble bt7{7., nullptr, nullptr};
    BinaryTreeNodeDouble bt9{9., nullptr, nullptr};
    BinaryTreeNodeDouble bt2{2., &bt4, &bt7};
    BinaryTreeNodeDouble bt8{8., &bt9, &bt2};
    BinaryTreeNodeDouble bt77{7., nullptr, nullptr};
    BinaryTreeNodeDouble bt1{8., &bt8, &bt77};

    BinaryTreeNodeDouble bt92{9., nullptr, nullptr};
    BinaryTreeNodeDouble bt22{2., nullptr, nullptr};
    BinaryTreeNodeDouble bt28{8., &bt92, &bt22};
 
    EXPECT_TRUE(HasSubtree(&bt1, &bt28));
}

TEST(P27_MirrorRecursively, WHEN_valid_DO_mirror_THEN_succ) {
    BinaryTreeNode pNode5(5);
    BinaryTreeNode pNode7(7);
    BinaryTreeNode pNode9(9);
    BinaryTreeNode pNode11(11);
    BinaryTreeNode pNode6(6, &pNode5, &pNode7);
    BinaryTreeNode pNode10(10, &pNode9, &pNode11);
    BinaryTreeNode pNode8(8, &pNode6, &pNode10);

    MirrorRecursively(&pNode8);

    BinaryTreeNode* pLeft = pNode8.m_pLeft;
    BinaryTreeNode* pRight = pNode8.m_pRight;
    EXPECT_EQ(pLeft->m_nValue, 10);
    EXPECT_EQ(pRight->m_nValue, 6);
    EXPECT_EQ(pLeft->m_pLeft->m_nValue, 11);
    EXPECT_EQ(pLeft->m_pRight->m_nValue, 9);
    EXPECT_EQ(pRight->m_pLeft->m_nValue, 7);
    EXPECT_EQ(pRight->m_pRight->m_nValue, 5);
}

TEST(P28_isSymmetrical, WHEN_valid_DO_isSymmetrical_THEN_true) {
    BinaryTreeNode *pNode[6];
    pNode[0] = new BinaryTreeNode(5);
    pNode[1] = new BinaryTreeNode(7);
    pNode[2] = new BinaryTreeNode(7);
    pNode[3] = new BinaryTreeNode(5);
    pNode[4] = new BinaryTreeNode(6, pNode[0], pNode[1]);
    pNode[5] = new BinaryTreeNode(6, pNode[2], pNode[3]);
    BinaryTreeNode pRoot(8, pNode[4], pNode[5]);

    EXPECT_TRUE(isSymmetrical(&pRoot));

    for (int i = 0; i < 6; i++) {
        delete pNode[i];
        pNode[i] = nullptr;
    }
}

TEST(P28_isSymmetrical, WHEN_notSymmetrical_DO_isSymmetrical_THEN_false) {
    BinaryTreeNode *pNode[6];
    pNode[0] = new BinaryTreeNode(5);
    pNode[1] = new BinaryTreeNode(7);
    pNode[2] = new BinaryTreeNode(7);
    pNode[3] = new BinaryTreeNode(5);
    pNode[4] = new BinaryTreeNode(6, pNode[0], pNode[1]);
    pNode[5] = new BinaryTreeNode(9, pNode[2], pNode[3]);
    BinaryTreeNode pRoot(8, pNode[4], pNode[5]);

    EXPECT_FALSE(isSymmetrical(&pRoot));
 
    for (int i = 0; i < 6; i++)
        pNode[i]->m_nValue = 7;
    delete pNode[3];
    pNode[3] = nullptr;

    EXPECT_FALSE(isSymmetrical(&pRoot));

    for (int i = 0; i < 6; i++) {
        if (i == 3)
            continue;

        delete pNode[i];
        pNode[i] = nullptr;
    }
}

TEST(P29_PrintMatrixClockwisely, WHEN_valid_matrix_DO_Print_THEN_eq) {
    int** numbers = new int*[3];
    int k = 1;
    for (int i = 0; i < 3; i++) {
        numbers[i] = new int[2];
        for (int j = 0; j < 2; j++) {
            numbers[i][j] = k++;
        }
    }

    int expect[] = {1, 2, 4, 6, 5, 3};
    PrintMatrixClockwisely(numbers, 2, 3);
    EXPECT_EQ(memcmp(expect, p29_numbers, sizeof(expect)), 0);

    int expect22[] = {1, 2, 4, 3};
    PrintMatrixClockwisely(numbers, 2, 2);
    EXPECT_EQ(memcmp(expect22, p29_numbers, sizeof(expect22)), 0);

    for (int i = 0; i < 3; i++) {
        delete[] numbers[i];
    }
    delete[] numbers;
}

TEST(P30_StackWithMin, WHEN_valid_DO_op_THEN_eq) {
    StackWithMin<int> swm;
 
    swm.push(3);
    EXPECT_EQ(swm.min(), 3);
    swm.push(4);
    EXPECT_EQ(swm.min(), 3);
    swm.push(2);
    EXPECT_EQ(swm.min(), 2);
    swm.push(1);
    EXPECT_EQ(swm.min(), 1);
    swm.pop();
    EXPECT_EQ(swm.min(), 2);
    swm.pop();
    EXPECT_EQ(swm.min(), 3);
    swm.push(0);
    EXPECT_EQ(swm.min(), 0);
}

TEST(P31_IsPopOrder, WHEN_is_DO_IsPopOrder_THEN_true) {
    int push[] = {1,2,3,4,5};
    int pop[] = {4,5,3,2,1};

    EXPECT_TRUE(IsPopOrder(push, pop, 5));
}

TEST(P31_IsPopOrder, WHEN_isnot_DO_IsPopOrder_THEN_false) {
    int push[] = {1,2,3,4,5};
    int pop[] = {4,3,5,1,2};

    EXPECT_FALSE(IsPopOrder(push, pop, 5));
}

TEST(P32_PrintFromTopToBottom, WHEN_bt_DO_print_THEN_eq) {
    BinaryTreeNode *pNode[6];
    pNode[0] = new BinaryTreeNode(5);
    pNode[1] = new BinaryTreeNode(7);
    pNode[2] = new BinaryTreeNode(9);
    pNode[3] = new BinaryTreeNode(11);
    pNode[4] = new BinaryTreeNode(6, pNode[0], pNode[1]);
    pNode[5] = new BinaryTreeNode(10, pNode[2], pNode[3]);
    BinaryTreeNode pRoot(8, pNode[4], pNode[5]);

    PrintFromTopToBottom(&pRoot);
    const int expect[] = {8,6,10,5,7,9,11};
    EXPECT_EQ(memcmp(p32_numbers, expect, sizeof(expect)), 0);

    for (int i = 0; i < 6; i++) {
        delete pNode[i];
        pNode[i] = nullptr;
    }
}

TEST(P32_Print, WHEN_bt_DO_print_THEN_eq) {
    BinaryTreeNode *pNode[16];
    for (int i = 0; i < 16; i++)
        pNode[i] = new BinaryTreeNode(i);
 
    for (int i = 1; i <= 7; i++) {
        pNode[i]->m_pLeft = pNode[i * 2];
        pNode[i]->m_pRight= pNode[i * 2 + 1];
    }

    Print(pNode[1]);
    const int expect[] = {1,3,2,4,5,6,7,15,14,13,12,11,10,9,8};
    EXPECT_EQ(memcmp(p32_numbers, expect, sizeof(expect)), 0);

    for (int i = 0; i < 16; i++) {
        delete pNode[i];
        pNode[i] = nullptr;
    }
}

TEST(P33_VerifySequenceOfBST, WHEN_valid_bst_DO_verify_THEN_true) {
    int input[] = {5,7,6,9,11,10,8};
    EXPECT_TRUE(VerifySequenceOfBST(input, 7));
}

TEST(P33_VerifySequenceOfBST, WHEN_invalid_bst_DO_verify_THEN_false) {
    int input[] = {7,4,6,5};
    EXPECT_FALSE(VerifySequenceOfBST(input, 4));
    EXPECT_FALSE(VerifySequenceOfBST(input, 0));
    EXPECT_FALSE(VerifySequenceOfBST(nullptr, 4));
}

TEST(P34_FindPath, WHEN_two_valid_DO_find_THEN_eq) {
    BinaryTreeNode pNode4(4);
    BinaryTreeNode pNode7(7);
    BinaryTreeNode pNode5(5, &pNode4, &pNode7);
    BinaryTreeNode pNode12(12);
    BinaryTreeNode pNode10(10, &pNode5, &pNode12);

    std::vector<std::vector<int>> expect{{10, 5, 7}, {10, 12}};
 
    EXPECT_EQ(FindPath(&pNode10, 22), expect);
}

TEST(P35_Clone, WHEN_valid_DO_clone_THEN_eq) {
    ComplexListNode E('E', nullptr);
    ComplexListNode D('D', &E);
    ComplexListNode C('C', &D);
    ComplexListNode B('B', &C);
    ComplexListNode A('A', &B);

    A.m_pSibling = &C;
    B.m_pSibling = &E;
    D.m_pSibling = &B;

    ComplexListNode* pResult = Clone(&A);
    EXPECT_NE(pResult, &A);

    std::vector<std::vector<int>> expect;
    ComplexListNode* pNode = pResult;
    while (pNode != nullptr) {
        std::vector<int> temp;
        temp.push_back(pNode->m_nValue);

        ComplexListNode* pNext = pNode->m_pNext;
        if (pNext)
            temp.push_back(pNext->m_nValue);
        if (pNode->m_pSibling)
            temp.push_back(pNode->m_pSibling->m_nValue);
        
        expect.push_back(temp);
 
        pNode = pNext;
    }
    std::vector<std::vector<int>> vvi{{'A','B','C'}, {'B','C','E'}, {'C','D'}, {'D','E','B'}, {'E'}};
    EXPECT_EQ(expect, vvi);

    pNode = pResult;
    while (pNode) {
        ComplexListNode* pNext = pNode->m_pNext;
        delete pNode;
        pNode = pNext;
    }
}

TEST(P36_Convert, WHEN_valid_DO_Convert_THEN_eq) {
    BinaryTreeNode bt4(4);
    BinaryTreeNode bt8(8);
    BinaryTreeNode bt12(12);
    BinaryTreeNode bt16(16);
    BinaryTreeNode bt6(6, &bt4, &bt8);
    BinaryTreeNode bt14(14, &bt12, &bt16);
    BinaryTreeNode bt10(10, &bt6, &bt14);

    BinaryTreeNode* pDoubleList = Convert(&bt10);

    std::vector<int> vi;
    BinaryTreeNode* pNode = pDoubleList;
    bool right = true;
    do {
        vi.push_back(pNode->m_nValue);
        if (right && pNode->m_pRight)
            pNode = pNode->m_pRight;
        else {
            right = false;
            pNode = pNode->m_pLeft;
        }
    } while (pNode && pNode != pDoubleList);
    vi.push_back(pNode->m_nValue);

    std::vector<int> expect{4,6,8,10,12,14,16,14,12,10,8,6,4};

    EXPECT_EQ(vi, expect);
}

TEST(P37_Serialize, WHEN_valid_DO_Serialize_THEN_eq) {
    BinaryTreeNode bt4(4);
    BinaryTreeNode bt5(5);
    BinaryTreeNode bt6(6);
    BinaryTreeNode bt2(2, &bt4, nullptr);
    BinaryTreeNode bt3(3, &bt5, &bt6);
    BinaryTreeNode bt1(1, &bt2, &bt3);

    std::ostringstream oss;
    Serialize(&bt1, oss);
 
    EXPECT_EQ(oss.str(), "1,2,4,$,$,$,3,5,$,$,6,$,$,");
}

TEST(P38_Permutation, WHEN_abc_DO_Permutation_THEN_eq) {
    std::set<std::string> result;
    char cs[] = "abc";

    Permutation(cs, result);

    std::set<std::string> expect{"abc", "acb", "bac", "bca", "cab", "cba"};
    EXPECT_EQ(result, expect);
}

TEST(P39_MoreThanHalfNum, WHEN_valid_DO_MoreThanHalfNum_THEN_eq2) {
    int numbers[] = {1,2,3,2,2,2,5,4,2};

    EXPECT_EQ(MoreThanHalfNum(numbers, 9), 2);
}

TEST(P39_MoreThanHalfNum, WHEN_valid_DO_MoreThanHalfNum2_THEN_eq2) {
    int numbers[] = {1,2,3,2,2,2,5,4,2};

    EXPECT_EQ(MoreThanHalfNum2(numbers, 9), 2);
}

TEST(P40_GetLeastNumbers, WHEN_valid_DO_GetLeastNumbers_THEN_eq) {
    int input[] = {4,5,1,6,2,7,3,8};
    int output[4] = {0};
    int expect[4] = {1,2,3,4};

    GetLeastNumbers(input, 8, output, 4);

    EXPECT_EQ(memcmp(output, expect, sizeof(output)), 0);
}

TEST(P40_GetLeastNumbers, WHEN_valid_DO_GetLeastNumbersQueue_THEN_eq) {
    std::vector<int> data{4,5,1,6,2,7,3,8};
    PQInt out;
    std::vector<int> outdata;
    std::vector<int> expect{4,3,2,1};

    GetLeastNumbers(data, out, 4);
    while (!out.empty()) {
        outdata.push_back(out.top());
        out.pop();
    }
 
    EXPECT_EQ(outdata, expect);
}

TEST(P41_DynamicArray, WHEN_valid_DO_DynamicArray_THEN_eq) {
    DynamicArray<int> da;

    da.Insert(2);
    da.Insert(5);
    da.Insert(8);
    da.Insert(3);
    da.Insert(1);

    EXPECT_EQ(da.GetMedian(), 3);

    da.Insert(6);
    EXPECT_EQ(da.GetMedian(), 4);
}

TEST(P42_FindGreatestSumOfSubArrays, WHEN_valid_DO_find_THEN_eq) {
    int data[] = {1,-2,3,10,-4,7,2,-5};
    int iLength = (int) (sizeof(data) / sizeof(int));

    EXPECT_EQ(FindGreatestSumOfSubArrays(data, iLength), 18);
    EXPECT_FALSE(g_bInvalidInput);
}

TEST(P42_FindGreatestSumOfSubArrays, WHEN_invalid_DO_find_THEN_invalid) {
    FindGreatestSumOfSubArrays(nullptr, 0);
 
    EXPECT_TRUE(g_bInvalidInput);
}

TEST(P43_NumberOf1Between1AndN, WHEN_valid_DO_get_num_THEN_eq) {
    EXPECT_EQ(NumberOf1Between1AndN(12), 5);
}

TEST(P44_DigitAtIndex, WHEN_valid_DO_get_digit_THEN_eq) {
    EXPECT_EQ(DigitAtIndex(5), 5);
    EXPECT_EQ(DigitAtIndex(13), 1);
    EXPECT_EQ(DigitAtIndex(19), 4);
    EXPECT_EQ(DigitAtIndex(1001), 7);
}

TEST(P45_PrintMinNumber, WHEN_PrintMinNumber_DO_print_THEN_eq) {
    int numbers[] = {3, 32, 321};
    
    EXPECT_EQ(strcmp(PrintMinNumber(numbers, 3), "321323"), 0);
}

TEST(P46_GetTranslationCount, WHEN_valid_DO_GetTranslationCount_THEN_eq) {
    EXPECT_EQ(GetTranslationCount(12258), 5);
    EXPECT_EQ(GetTranslationCount(9), 1);
}

TEST(P46_GetTranslationCount, WHEN_special_DO_GetTranslationCount_THEN_eq) {
    EXPECT_EQ(GetTranslationCount(0), 1);
    EXPECT_EQ(GetTranslationCount(-1), 0);
    EXPECT_EQ(GetTranslationCount(25), 2);
    EXPECT_EQ(GetTranslationCount(26), 1);
}

TEST(P47_GetMaxValue, WHEN_valid_DO_GetMaxValue_THEN_eq) {
    int values[] = {
        1,10,3,8,
        12,2,9,6,
        5,7,4,11,
        3,7,16,5
    };
 
    EXPECT_EQ(GetMaxValueS1(values, 4, 4), 53);
    EXPECT_EQ(GetMaxValueS2(values, 4, 4), 53);
}

TEST(P48_LongestSubstringNoRepeat, WHEN_arabcacfr_DO_Get_THEN_eq) {
    EXPECT_EQ(LongestSubstringNoRepeat("arabcacfr"), 4);
}