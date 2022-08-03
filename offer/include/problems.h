#ifndef PROBLEMS_H
#define PROBLEMS_H

// 面试题1: 赋值运算符函数
class CMyString {
public:
    CMyString(char *pData = 0);
    CMyString(const CMyString &str);
    ~CMyString(void);

    CMyString &operator=(const CMyString &str);

    const char *to_string(void) { return m_pData; }

private:
    char *m_pData;
};

// 面试题3: 数组中重复的数字
// 题目一：找出数组中重复的数字
bool duplicate(int numbers[], int length, int *duplication);

// 题目二：不修改数组找到重复的数字
int getDuplication(const int *numbers, int length);

// 面试题4: 二维数组中的查找
bool Find(int *matrix, int rows, int columns, int number);

// 面试题5: 替换空格
void ReplaceBlank(char string[], int length);

// 面试题6: 从尾到头打印链表
struct ListNode {
    int m_nKey;
    ListNode *m_pNext;
};

void AddToTail(ListNode **pHead, int value);
void ClearNode(ListNode **pHead);

void PrintListReversingly_Iteratively(ListNode *pHead);
void PrintListReversingly_Recursively(ListNode *pHead);

// 面试题7: 重建二叉树
struct BinaryTreeNode {
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;

    BinaryTreeNode(int value): m_nValue(value), m_pLeft(nullptr), m_pRight(nullptr) {}
};

bool BinaryTreeEqual(BinaryTreeNode *bt1, BinaryTreeNode *bt2);

BinaryTreeNode *Construct(int *preorder, int *inorder, int length);

#endif