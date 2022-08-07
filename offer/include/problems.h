#ifndef PROBLEMS_H
#define PROBLEMS_H

#include <stack>
#include <iostream>

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
    BinaryTreeNode *m_pParent;

    BinaryTreeNode(int value): m_nValue(value), m_pLeft(nullptr), m_pRight(nullptr), m_pParent(nullptr) {}
};

bool BinaryTreeEqual(BinaryTreeNode *bt1, BinaryTreeNode *bt2);

BinaryTreeNode *Construct(int *preorder, int *inorder, int length);

// 面试题8: 二叉树的下一个节点
BinaryTreeNode *GetNext(BinaryTreeNode *pNode);

// 面试题9: 用两个栈实现队列
template <typename T>
class CQueue {
public:
    CQueue(void) {}
    ~CQueue(void) {}

    // 模版类的方法定义需要放在头文件中，否则link错误
    // https://stackoverflow.com/questions/1639797/template-issue-causes-linker-error-c
    void appendTail(const T &node) {
        stack1.push(node);
    }

    T deleteHead(void) {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        T res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    std::stack<T> stack1;
    std::stack<T> stack2;
};
 
#endif