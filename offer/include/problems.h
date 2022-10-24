#ifndef PROBLEMS_H
#define PROBLEMS_H

#include <stack>
#include <iostream>
#include <vector>

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
    BinaryTreeNode(int value, BinaryTreeNode* pLeft, BinaryTreeNode *pRight):
        m_nValue(value), m_pLeft(pLeft), m_pRight(pRight), m_pParent(nullptr) {}
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
 
// 面试题10: 斐波那契数列
// 题目一：求斐波那契数列的第n项
long long Fibonacci_recursively(unsigned int n);
long long Fibonacci_iteratively(unsigned int n);
// 题目二：青蛙跳台阶问题 —— 就是斐波那契数列

// 面试题11: 旋转数组的最小数字
int Min(int *numbers, int length);

// 2.4.3 回溯法
// 面试题12: 矩阵中的路径
bool hasPath(char *matrix, int rows, int cols, const char *str);

// 面试题13: 机器人的运动范围
int movingCount(int threshold, int rows, int cols);

// 2.4.4 动态规划与贪婪算法
// 面试题14: 剪绳子
int maxProductAfterCutting_dp(int length);
int maxProductAfterCutting_greedy(int length);

// 2.4.5 位运算
// 面试题15: 二进制中1的个数
int NumberOf1(int n);

// 面试题16: 数值的整数次方
double Power(double base, int exponent);

// 面试题18: 删除链表的节点
// 题目一：在O(1)时间内删除链表节点。
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted);

// 题目二：删除链表中重复的节点
void DeleteDuplication(ListNode** pHead);

// 面试题19: 正则表达式匹配
bool match(const char* str, const char* pattern);

/**
 * @brief 面试题20: 表示数值的字符串
 * @param str 数字的字符串表示
 * @return true: 遵循模式 A[.[B]][e|E[C]]  .B[e|EC]
 */
bool isNumeric(const char* str);

/**
 * @brief 面试题21: 调整数组顺序使奇数位于偶数前面
 * 可扩展性：函数指针
 * @param pData
 * @param length
 */
void ReorderOddEven(int* pData, unsigned int length);

// 3.4 代码的鲁棒性
// 面试题22: 链表中倒数第k个节点
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);

// 面试题23: 链表中环的入口节点
ListNode* EntryNodeOfLoop(ListNode* pHead);

// 面试题24: 反转链表
ListNode* ReverseList(ListNode* pHead);

// 面试题25: 合并两个排序的链表
ListNode* Merge(ListNode* pHead1, ListNode* pHead2);

struct BinaryTreeNodeDouble {
    double m_dbValue;
    BinaryTreeNodeDouble* m_pLeft;
    BinaryTreeNodeDouble* m_pRight;
};

// 面试题26: 树的子结构
bool HasSubtree(BinaryTreeNodeDouble* pRoot1, BinaryTreeNodeDouble* pRoot2);

// 4.2 画图让抽象问题形象化
// 面试题27: 二叉树的镜像
void MirrorRecursively(BinaryTreeNode* pNode);

// 面试题28: 对称的二叉树
bool isSymmetrical(BinaryTreeNode* pRoot);

// 面试题29: 顺时针打印矩阵
extern int p29_numbers[20];
void PrintMatrixClockwisely(int** numbers, int columns, int rows);

// 4.3 举例让抽象问题具体化
// 面试题30: 包含min函数的栈
template<typename T>
class StackWithMin {
public:
    void push(const T& value) {
        m_data.push(value);
 
        if (m_min.empty() || value <= m_min.top())
            m_min.push(value);
        else
            m_min.push(m_min.top());
    }

    void pop() {
        assert(!m_data.empty() && !m_min.empty());

        m_data.pop();
        m_min.pop();
    }

    const T& min() const {
        assert(!m_data.empty() && !m_min.empty());

        return m_min.top();
    }

private:
    std::stack<T> m_data;
    std::stack<T> m_min;
};

// 面试题31: 栈的压入、弹出序列
bool IsPopOrder(const int* pPush, const int* pPop, int nLength);

// 面试题32: 从上到下打印二叉树
// 题目一：不分行从上到下打印二叉树
extern int p32_numbers[20];
void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot);

// 之字形打印二叉树
void Print(BinaryTreeNode* pRoot);

// 面试题33: 二叉树搜索树的后序遍历序列
bool VerifySequenceOfBST(int sequence[], int length);

// 面试题34: 二叉树中和为某一值的路径
std::vector<std::vector<int>> FindPath(BinaryTreeNode* pRoot, int expectedSum);

// 4.4 分解让复杂问题简单化
// 面试题35: 复杂链表的复制
// 面试题36: 二叉搜索树与双向链表
// 面试题37: 序列话二叉树
// 面试题38: 字符串的排列

#endif