#ifndef PROBLEMS_H
#define PROBLEMS_H

#include <stack>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <limits>

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
    ListNode() : m_nKey(0), m_pNext(nullptr) {}
    ListNode(int key, ListNode* next) : m_nKey(key), m_pNext(next) {}
 
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
struct ComplexListNode {
    int m_nValue;
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
 
    ComplexListNode() {}
    ComplexListNode(int value, ComplexListNode* pNext) :
        m_nValue(value), m_pNext(pNext), m_pSibling(nullptr) {}
};

ComplexListNode* Clone(ComplexListNode* pHead);

// 面试题36: 二叉搜索树与双向链表
BinaryTreeNode* Convert(BinaryTreeNode* pRoot);

// 面试题37: 序列化二叉树
void Serialize(BinaryTreeNode* pRoot, std::ostream& stream);
void Deserialize(BinaryTreeNode** pRoot, std::istream& stream);

// 面试题38: 字符串的排列
void Permutation(char* pStr, std::set<std::string>& result);

// 第5章 优化时间和空间效率
// 5.2 时间效率
// 面试题39: 数组中出现次数超过一半的数字
int MoreThanHalfNum(int* numbers, int length);
int MoreThanHalfNum2(int* numbers, int length);

// 面试题40: 最小的k个数
void GetLeastNumbers(int* input, int n, int* output, int k);
typedef std::priority_queue<int, std::vector<int>> PQInt;
void GetLeastNumbers(const std::vector<int>& data, PQInt& out, int k);

// 面试题41: 数据流中的中位数
template<typename T>
class DynamicArray {
public:
    void Insert(T num) {
        if (((min.size() + max.size()) & 1) == 0) {
            if (max.size() > 0 && max[0] > num) {
                max.push_back(num);
                push_heap(max.begin(), max.end(), std::less<T>());

                num = max[0];

                pop_heap(max.begin(), max.end(), std::less<T>());
                max.pop_back();
            }

            min.push_back(num);
            push_heap(min.begin(), min.end(), std::greater<T>());
        } else {
            if (min.size() > 0 && min[0] < num) {
                min.push_back(num);
                push_heap(min.begin(), min.end(), std::greater<T>());

                num = min[0];

                pop_heap(min.begin(), min.end(), std::greater<T>());
                min.pop_back();
            }

            max.push_back(num);
            push_heap(max.begin(), max.end(), std::less<T>());
        }
    }

    T GetMedian(void) {
        int size = min.size() + max.size();
        if (size == 0)
            throw "No numbers are available";
        
        return (size & 1) ? min[0] : (min[0] + max[0]) / 2;
    }

private:
    std::vector<T> min;
    std::vector<T> max;
};

// 面试题42: 连续子数组的最大和
extern bool g_bInvalidInput;
int FindGreatestSumOfSubArrays(int* pData, int iLength);

// 面试题43: 1～n整数中1出现的次数
int NumberOf1Between1AndN(int n);

// 面试题44: 数字序列中某一位的数字
int DigitAtIndex(int index);

// 面试题45: 把数组排成最小的数
const char* PrintMinNumber(int* numbers, int length);

// 面试题46: 把数字翻译成字符串
int GetTranslationCount(int number);

// 面试题47: 礼物的最大价值
int GetMaxValueS1(const int* values, int rows, int cols);
int GetMaxValueS2(const int* values, int rows, int cols);

// 面试题48: 最长不含重复字符的子字符串
int LongestSubstringNoRepeat(const std::string& str);

// 5.3 时间效率与空间效率第平衡
// 面试题49: 丑数
int GetUglyNumberS1(int index);
int GetUglyNumberS2(int index);

// 面试题50: 第一个只出现一次的字符
// 题目一：字符串中第一个只出现一次的字符
char FirstNotRepeatingChar(const char* pString);

// 题目二：字符流中第一个只出现一次的字符
class CharStatistics {
public:
    CharStatistics() : index(0) {
        for (int i = 0; i < 256; ++i)
            occurrence[i] = -1;
    }

    void Insert(char ch) {
        if (occurrence[(unsigned char) ch] == -1)
            occurrence[(unsigned char) ch] = index;
        else if (occurrence[(unsigned char) ch] >= 0)
            occurrence[(unsigned char) ch] = -2;

        ++index;
    }

    char FirstAppearingOnce(void) {
        char ch = '\0';
        int minIndex = std::numeric_limits<int>::max();

        for (int i = 0; i < 256; ++i) {
            if (occurrence[i] >= 0 && occurrence[i] < minIndex) {
                ch = (char) i;
                minIndex = occurrence[i];
            }
        }

        return ch;
    }

private:
    int index;
    int occurrence[256];
};

// 面试题51: 数组中的逆序对
int InversePairs(int* data, int length);

// 面试题52: 两个链表的第一个公共节点
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2);

// 6.3 知识迁移能力
// 面试题53: 在排序数组中查找数字
// 题目一：数字在排序数组中出现的次数
int GetNumberOfK(int* data, int length, int k);

// 题目二：0~n-1中缺失的数字
int GetMissingNumber(const int* numbers, int length);

// 题目三：数组中数值和下标相等的元素
int GetNumberSameAsIndex(const int* numbers, int length);

// 面试题54: 二叉搜索树的第k大节点
BinaryTreeNode* KthNode(BinaryTreeNode* pRoot, unsigned int k);

// 面试题55: 二叉树的深度
// 题目一：二叉树的深度
int TreeDepth(BinaryTreeNode* pRoot);

// 题目二：平衡二叉树
bool IsBalanced(BinaryTreeNode* pRoot);

// 面试题56: 数组中数字出现的次数
// 题目一: 数组中只出现一次的两个数字
void FindNumsAppearOnce(int data[], int length, int* num1, int *num2);

// 题目二: 数组中唯一只出现一次的数字
int FindNumberAppearingOnce(int numbers[], int length);

// 面试题57: 和为s的数字
// 题目一：和为s的两个数字
bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int* num2);

// 题目二：和为s的连续正数序列
std::vector<std::vector<int>> FindContinuesSequence(int sum);

// 面试题58：翻转字符串
// 题目一：翻转单词顺序
char* ReverseSentence(char* pData);

// 题目二：左旋转字符串
char* LeftRotateString(char* pStr, int n);

// 面试题59：队列的最大值
// 题目一：滑动窗口的最大值
std::vector<int> maxInWindows(const std::vector<int>& num, unsigned int size);

// 题目二：队列的最大值
template <typename T>
class QueueWithMax {
public:
    QueueWithMax() : currentIndex(0) {}

    void push_back(T number) {
        while (!maximums.empty() && number >= maximums.back().number)
            maximums.pop_back();
        
        InternalData internalData = { number, currentIndex };
        data.push_back(internalData);
        maximums.push_back(internalData);
        currentIndex++;
    }

    void pop_front() {
        if (maximums.empty())
            throw "queue is empty";

        if (maximums.front().index == data.front().index)
            maximums.pop_back();
 
        data.pop_back();
    }

    T max() const {
        if (maximums.empty())
            throw "queue is empty";
        
        return maximums.front().number;
    }

private:
    struct InternalData { T number; int index;};
    std::deque<InternalData> data;
    std::deque<InternalData> maximums;
    int currentIndex;
};

// 6.4 抽象建模能力
// 面试题60: n个骰子的点数
std::vector<double> PrintProbability(int n);
std::vector<double> PrintProbabilityIteratively(int n);

// 面试题61: 扑克牌中的顺子
bool IsContinuous(int* numbers, int length);

// 面试题62: 圆圈中最后剩下的数字
int LastRemaining(unsigned n, unsigned m);

// 面试题63: 股票的最大利润
int MaxDiff(const int* numbers, unsigned length);

#endif