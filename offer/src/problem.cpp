#include "problems.h"
#include <string.h>
#include <queue>
#include <exception>
#include <cmath>
using namespace std;

CMyString::CMyString(char *pData) : m_pData(nullptr) {
    if (pData) {
        m_pData = new char[strlen(pData) + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString &str) : m_pData(nullptr) {
    // 成员变量一定要初始化为空，不然abort
    if (str.m_pData) {
        m_pData = new char[strlen(str.m_pData) + 1];
        strcpy(m_pData, str.m_pData);
    }
}

CMyString::~CMyString(void) {
    if (m_pData) {
        delete []m_pData;
    }
}

CMyString& CMyString::operator=(const CMyString &str) {
    if (this != &str) {
        CMyString tmp(str);

        char *pData = tmp.m_pData;
        tmp.m_pData = m_pData;
        m_pData = pData;
    }
    
    return *this;
}

bool duplicate(int numbers[], int length, int *duplication) {
    if (nullptr == numbers || length <= 0) {
        return false;
    }

    for (int i = 0; i < length; ++i) {
        if (numbers[i] < 0 || numbers[i] >= length) {
            return false;
        }
    }

    for (int i = 0; i < length; ++i) {
        while (numbers[i] != i) {
            int temp = numbers[i];
            if (temp == numbers[temp]) {
                *duplication = numbers[i];
                return true;
            }
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return false;
}

static int countNumbers(const int *numbers, int length, int start, int end) {
    int res = 0;
    for (int i = 0; i < length; i++) {
        if (numbers[i] >= start && numbers[i] <= end) {
            res++;
        }
    }
    return res;
}

int getDuplication(const int *numbers, int length) {
    if (nullptr == numbers || length < 2) {
        return -1;
    }

    int start = 1, end = length - 1;
    while (start <= end) {
        int middle = ((end - start) >> 1) + start;
        int count = countNumbers(numbers, length, start, middle);
        if (count > middle - start + 1) {
            if (start == end) {
                return start;
            }
            end = middle;
        } else {
            start = middle + 1;
        }
    }

    return -1;
}

bool Find(int *matrix, int rows, int columns, int number) {
    if (nullptr == matrix || rows < 1 || columns < 1) {
        return false;
    }
    
    int r = 0, c = columns - 1;
    while (r < rows && c >= 0) {
        int x = matrix[r * columns + c];
        if (x == number) {
            return true;
        } else if (x < number) {
            ++r;
        } else {
            --c;
        }
    }

    return false;
}

void ReplaceBlank(char string[], int length) {
    if (nullptr == string || length < 3) {
        return;
    }

    int i = 0, size = 0, blank = 0;
    while (string[i] != '\0') {
        if (string[i] == ' ') {
            ++blank;
        }
        ++size;
        ++i;
    }

    int p1 = size - 1;
    int p2 = p1 + 2 * blank;
    if (p2 >= length) {
        return;
    }

    while (p1 < p2) {
        if (string[p1] != ' ') {
            string[p2] = string[p1];
            --p2;
        } else {
            p2 -= 3;
            strncpy(string + p2 + 1, "%20", 3);
        }
        --p1;
    }
}

void AddToTail(ListNode **pHead, int value) {
    ListNode *pNew = new ListNode();
    pNew->m_nKey = value;
    pNew->m_pNext = nullptr;

    if (*pHead == nullptr) {
        *pHead = pNew;
    } else {
        ListNode *pNode = *pHead;
        while (pNode->m_pNext) {
            pNode = pNode->m_pNext;
        }

        pNode->m_pNext = pNew;
    }
}

void ClearNode(ListNode **pHead) {
    if (nullptr == pHead || nullptr == *pHead) {
        return;
    }

    ListNode *pNode = *pHead;
    while (pNode != nullptr) {
        ListNode *pToDelete = pNode;
        pNode = pNode->m_pNext;
        delete pToDelete;
        pToDelete = nullptr;
    }
}

void PrintListReversingly_Iteratively(ListNode *pHead) {
    stack<int> st;

    ListNode *pNode = pHead;
    while (pNode != nullptr) {
        st.push(pNode->m_nKey);
        pNode = pNode->m_pNext;
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void PrintListReversingly_Recursively(ListNode *pHead) {
    if (pHead) {
        if (pHead->m_pNext) {
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
        cout << pHead->m_nKey << " ";
    }
}

bool BinaryTreeEqual(BinaryTreeNode *bt1, BinaryTreeNode *bt2) {
    if (nullptr == bt1 || nullptr == bt2) {
        return bt1 == bt2;
    }

    queue<BinaryTreeNode *> qbt1, qbt2;
    qbt1.push(bt1);
    qbt2.push(bt2);

    while (!qbt1.empty() && !qbt2.empty()) {
        auto size = qbt1.size();
        if (size != qbt2.size())
            break;

        for (decltype(size) i = 0; i < size; i++) {
            auto x = qbt1.front(), y = qbt2.front();
            if (x->m_nValue != y->m_nValue) {
                return false;
            }
            if (x->m_pLeft) qbt1.push(x->m_pLeft);
            if (x->m_pRight) qbt1.push(x->m_pRight);
            if (y->m_pLeft) qbt2.push(y->m_pLeft);
            if (y->m_pRight) qbt2.push(y->m_pRight);
            qbt1.pop();
            qbt2.pop();
        }
    }

    return qbt1.empty() && qbt2.empty();
}

static BinaryTreeNode *ConstructCore(int *startPreorder, int *endPreorder, int *startInorder, int *endInorder) {
    int rootValue = startPreorder[0];
    BinaryTreeNode *root = new BinaryTreeNode(rootValue);

    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startPreorder == *startInorder) {
            return root;
        } else {
            throw "preordoer != inorder";
        }
    }

    // 在中序遍历序列找到根结点的值
    int *rootInorder = startInorder;
    while (rootInorder < endInorder && *rootInorder != rootValue) {
        rootInorder++;
    }

    if (rootInorder == endInorder && *rootInorder != rootValue) {
        throw "can't find rootInorder";
    }

    int leftLength = rootInorder - startInorder;
    int *leftPreorderEnd = startPreorder + leftLength;
    if (leftLength > 0) {
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    if (leftLength < endPreorder - startPreorder) {
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }

    return root;
}

BinaryTreeNode *Construct(int *preorder, int *inorder, int length) {
    if (nullptr == preorder || nullptr == inorder || length < 1) {
        return nullptr;
    }

    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode *GetNext(BinaryTreeNode *pNode) {
    if (nullptr == pNode)
        return nullptr;

    BinaryTreeNode *pNext = nullptr;

    if (pNode->m_pRight != nullptr) {
        BinaryTreeNode *pRight = pNode->m_pRight;
        while (pRight->m_pLeft != nullptr) {
            pRight = pRight->m_pLeft;
        }
        pNext = pRight;
    } else if (pNode->m_pParent != nullptr) {
        BinaryTreeNode *pCurrent = pNode;
        BinaryTreeNode *pParent = pNode->m_pParent;
        while (pParent != nullptr && pParent->m_pRight == pCurrent) {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }
        pNext = pParent;
    }

    return pNext;
}

// 模版类方法定义：必须在类名指定模版参数，否则报错 error: 'CQueue' is not a class, namespace, or enumeration
// template <typename T>
// void CQueue<T>::appendTail(const T &node) {
//     cout << "test" << node << endl;
// }

long long Fibonacci_recursively(unsigned int n) {
    return n <= 1 ? n : (Fibonacci_recursively(n - 1) + Fibonacci_recursively(n - 2));
}

long long Fibonacci_iteratively(unsigned int n) {
    int x = 0, y = 1, z = n;

    for (unsigned int i = 2; i <= n; ++i) {
        z = x + y;
        x = y;
        y = z;
    }

    return z;
}

static int MinInOrder(int *numbers, int left, int right) {
    int min = numbers[left];

    for (int i = left + 1; i <= right; ++i) {
        min = std::min(numbers[i], min);
    }

    return min;
}

int Min(int *numbers, int length) {
    if (nullptr == numbers || length < 1) {
        throw "Invalid Parameters";
    }

    int left = 0, right = length - 1;
    int mid = left;

    while (numbers[left] >= numbers[right]) {
        if (right - left == 1) {
            mid = right;
            break;
        }
 
        mid = (right - left) / 2 + left;
        if (numbers[mid] == numbers[left] && numbers[mid] == numbers[right]) {
            return MinInOrder(numbers, left, right);
        }
        
        if (numbers[mid] >= numbers[left]) {
            left = mid;
        } else if (numbers[mid] <= numbers[right]) {
            right = mid;
        } else {
            throw "Invalid Sequence";
        }
    }

    return numbers[mid];
}

static bool hasPathCore(char *matrix, int rows, int cols, const char *str, int row, int col, int &length, bool *visited) {
    if (str[length] == '\0') {
        return true;
    }

    bool result = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols &&
        matrix[row * cols + col] == str[length] && !visited[row * cols + col]) {
        ++length;
        visited[row * cols + col] = true;
        result = hasPathCore(matrix, rows, cols, str, row + 1, col, length, visited)
                || hasPathCore(matrix, rows, cols, str, row, col + 1, length, visited)
                || hasPathCore(matrix, rows, cols, str, row - 1, col, length, visited)
                || hasPathCore(matrix, rows, cols, str, row, col - 1, length, visited);

        if (!result) {
            --length;
            visited[row * cols + col] = false;
        }
    }
    
    return result;
}

bool hasPath(char *matrix, int rows, int cols, const char *str) {
    if (nullptr == matrix || rows < 1 || cols < 1 || nullptr == str) {
        return false;
    }

    bool *visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);
    int length = 0;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (hasPathCore(matrix, rows, cols, str, row, col, length, visited)) {
                delete[] visited;
                return true;
            }
        }
    }

    delete[] visited;
    return false;
}

static int getDigitSum(int digit) {
    int sum = 0;
    while (digit) {
        sum += digit % 10;
        digit /= 10;
    }
    return sum;
}

static bool check(int threshold, int rows, int cols, int row, int col, bool *visited) {
    return (row >= 0 && row < rows && col >= 0 && col < cols
            && !visited[row * cols + col] && getDigitSum(row) + getDigitSum(col) <= threshold);
}

static int movingCountCore(int threshold, int rows, int cols, int row, int col, bool *visited) {
    int count = 0;

    if (check(threshold, rows, cols, row, col, visited)) {
        visited[row * cols + col] = true;

        count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
                + movingCountCore(threshold, rows, cols, row + 1, col, visited)
                + movingCountCore(threshold, rows, cols, row, col - 1, visited)
                + movingCountCore(threshold, rows, cols, row, col + 1, visited);
    }

    return count;
}

int movingCount(int threshold, int rows, int cols) {
    if (threshold < 0 || rows < 1 || cols < 1) {
        return 0;
    }

    bool *visited = new bool[rows * cols];
    memset(visited, 0, rows * cols);

    int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

    delete []visited;
    return count;
}

int maxProductAfterCutting_dp(int length) {
    if (length < 2) return 0;
    if (length == 2) return 1;
    if (length == 3) return 2;

    int *products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;
    for (int i = 4; i <= length; ++i) {
        max = 0;
        for (int j = 1; j <= i / 2; ++j) {
            max = std::max(max, products[j] * products[i - j]);
        }
        products[i] = max;
    }

    max = products[length];
    delete []products;
    return max;
}

int maxProductAfterCutting_greedy(int length) {
    if (length < 2) return 0;
    if (length == 2) return 1;
    if (length == 3) return 2;

    int timesOf3 = length / 3;
    if (length - timesOf3 * 3 == 1) {
        --timesOf3;
    }

    int timesOf2 = (length - timesOf3 * 3) / 2;

    return std::pow(3, timesOf3) * std::pow(2, timesOf2);
}

int NumberOf1(int n) {
    int count = 0;

    while (n) {
        ++count;
        n &= n - 1;
    }

    return count;
}

double Power(double base, int exponent) {
    if (0 == base)
        return 0;
    if (0 == exponent)
        return 1;
 
    double ret = 1;
    bool positive = exponent > 0;
    exponent = std::abs(exponent);
    while (exponent--)
    {
        ret *= base;
    }

    return positive ? ret : 1.0 / ret;
}

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
    if (!pListHead || !pToBeDeleted)
        return;
    
    if (pToBeDeleted->m_pNext) {
        ListNode* pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nKey = pNext->m_nKey;
        pToBeDeleted->m_pNext = pNext->m_pNext;

        delete pNext;
        pNext = nullptr;
    } else if (pToBeDeleted == *pListHead) {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    } else {
        ListNode* pNode = *pListHead;
        while (pNode->m_pNext != pToBeDeleted)
            pNode = pNode->m_pNext;
        pNode->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

void DeleteDuplication(ListNode** pHead) {
    if (!pHead || !(*pHead))
        return;
    
    ListNode* pPrev = nullptr;
    ListNode* pNode = *pHead;

    while (pNode) {
        bool needDelete = false;
        ListNode* pNext = pNode->m_pNext;
        if (pNext && pNext->m_nKey == pNode->m_nKey)
            needDelete = true;
        
        if (!needDelete) {
            pPrev = pNode;
            pNode = pNext;
        } else {
            int value = pNode->m_nKey;
            ListNode* pToBeDel = pNode;
            while (pToBeDel && pToBeDel->m_nKey == value) {
                pNext = pToBeDel->m_pNext;
                delete pToBeDel;
                pToBeDel = pNext;
            }

            if (!pPrev)
                *pHead = pNode;
            else
                pPrev->m_pNext = pNext;
            pNode = pNext;
        }
    }
}

static bool matchCore(const char* str, const char* pattern) {
    if (*str == '\0' && *pattern == '\0')
        return true;
    
    if (*str != '\0' && *pattern == '\0')
        return false;

    if (*(pattern + 1) == '*') {
        if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
            return matchCore(str + 1, pattern + 2) ||
                    matchCore(str + 1, pattern) ||
                    matchCore(str, pattern + 2);
        } else {
            return matchCore(str, pattern + 2);
        }
    }

    if (*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchCore(str + 1, pattern + 1);
 
    return false;
}

bool match(const char* str, const char* pattern) {
    if (!str || !pattern)
        return false;
    
    return matchCore(str, pattern);
}

static bool scanUnsignedInteger(const char** str) {
    const char* before = *str;

    while (**str != '\0' && **str >= '0' && **str <= '9')
        ++(*str);

    return *str > before;
}

static bool scanInteger(const char** str) {
    if (**str == '+' || **str == '-')
        ++(*str);
    return scanUnsignedInteger(str);
}

bool isNumeric(const char* str) {
    if (str == nullptr)
        return false;

    bool numeric = scanInteger(&str);

    if (*str == '.') {
        ++str;
        numeric = scanUnsignedInteger(&str) || numeric;
    }

    if (*str == 'e' || *str == 'E') {
        ++str;
        numeric = numeric && scanInteger(&str);
    }

    return numeric && *str == '\0';
}

void ReorderOddEven(int* pData, unsigned int length) {
    if (!pData || !length)
        return;
    
    int* pBegin = pData;
    int* pEnd = pData + length - 1;

    while (pBegin < pEnd)
    {
        while (pBegin < pEnd && (*pBegin & 1) != 0)
            pBegin++;
        
        while (pBegin < pEnd && (*pEnd & 1) == 0)
            pEnd--;
        
        if (pBegin < pEnd) {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if (!pListHead || !k)
        return nullptr;
    
    ListNode* pFast = pListHead;

    // 快指针先走k-1步伐
    while (--k && pFast != nullptr)
        pFast = pFast->m_pNext;
    
    if (!pFast)
        return nullptr;
    
    ListNode* pSlow = pListHead;
    while (pFast->m_pNext) {
        pFast = pFast->m_pNext;
        pSlow = pSlow->m_pNext;
    }
    
    return pSlow;
}

ListNode* MeetingNode(ListNode* pHead) {
    if (!pHead)
        return nullptr;
    
    ListNode* pSlow = pHead->m_pNext;
    if (!pSlow)
        return nullptr;
    
    ListNode* pFast = pSlow->m_pNext;
    while (pFast && pFast != pSlow) {
        pSlow = pSlow->m_pNext;
        pFast = pFast->m_pNext;
        if (pFast)
            pFast = pFast->m_pNext;
    }

    return pFast;
}

ListNode* EntryNodeOfLoop(ListNode* pHead) {
    ListNode* pMeeting = MeetingNode(pHead);
    if (!pMeeting)
        return nullptr;

    ListNode* pSlow = pHead;
    while (pSlow != pMeeting) {
        pSlow = pSlow->m_pNext;
        pMeeting = pMeeting->m_pNext;
    }

    return pSlow;
}

ListNode* ReverseList(ListNode* pHead) {
    ListNode* pPrev = nullptr;
    ListNode* pCur = pHead;
    ListNode* pNext;

    while (pCur != nullptr) {
        pNext = pCur->m_pNext;
        pCur->m_pNext = pPrev;
        pPrev = pCur;
        pCur = pNext;
    }

    return pPrev;
}

ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    if (!pHead1)
        return pHead2;
    if (!pHead2)
        return pHead1;
    
    ListNode* pRet = nullptr;

    if (pHead1->m_nKey < pHead2->m_nKey) {
        pRet = pHead1;
        pRet->m_pNext = Merge(pHead1->m_pNext, pHead2);
    }
    else {
        pRet = pHead2;
        pRet->m_pNext = Merge(pHead1, pHead2->m_pNext);
    }

    return pRet;
}

static bool Equal(double num1, double num2) {
    return (num1 - num2 > -0.0000001 && num1 - num2 < 0.0000001);
}

static bool DoseTree1HaveTree2(BinaryTreeNodeDouble* pRoot1, BinaryTreeNodeDouble* pRoot2) {
    if (!pRoot2)
        return true;
    if (!pRoot1)
        return false;
    
    if (!Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
        return false;
    
    return DoseTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) &&
        DoseTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

bool HasSubtree(BinaryTreeNodeDouble* pRoot1, BinaryTreeNodeDouble* pRoot2) {
    bool bRet = false;

    if (pRoot1 && pRoot2) {
        if (Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
            bRet = DoseTree1HaveTree2(pRoot1, pRoot2);
        if (!bRet)
            bRet = HasSubtree(pRoot1->m_pLeft, pRoot2);
        if (!bRet)
            bRet = HasSubtree(pRoot1->m_pRight, pRoot2);
    }

    return bRet;
}

void MirrorRecursively(BinaryTreeNode* pNode) {
    if (!pNode || (!pNode->m_pLeft && !pNode->m_pRight))
        return;
    
    BinaryTreeNode* pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;

    MirrorRecursively(pNode->m_pLeft);
    MirrorRecursively(pNode->m_pRight);
}

static bool isSymmetricalRecursively(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2) {
    if (!pRoot1 && !pRoot2)
        return true;
    if (!pRoot1 || !pRoot2)
        return false;
    if (pRoot1->m_nValue != pRoot2->m_nValue)
        return false;
    
    return isSymmetricalRecursively(pRoot1->m_pLeft, pRoot2->m_pRight) &&
            isSymmetricalRecursively(pRoot1->m_pRight, pRoot2->m_pLeft);
}

bool isSymmetrical(BinaryTreeNode* pRoot) {
    return isSymmetricalRecursively(pRoot, pRoot);
}

// For test
int p29_numbers[20] = {0};
int p29_ptr = 0;

static void printNumber(int number) {
    cout << number << " ";
    p29_numbers[p29_ptr++] = number;
}

static void PrintMatrixInCircle(int** numbers, int columns, int rows, int start) {
    int endX = columns - 1 - start;
    int endY = rows - 1 - start;

    // 从左到右
    for (int i = 0; i <= endX; i++)
        printNumber(numbers[start][i]);
    
    // 从上到下
    if (endY > start)
        for (int i = start + 1; i <= endY; i++)
            printNumber(numbers[i][endX]);

    // 从右到左
    if (endX > start && endY > start)
        for (int i = endX - 1; i >= start; i--)
            printNumber(numbers[endY][i]);
        
    // 从下到上
    if (endX > start && endY - 1> start)
        for (int i = endY - 1; i >= start + 1; i--)
            printNumber(numbers[i][start]);
}

void PrintMatrixClockwisely(int** numbers, int columns, int rows) {
    if (!numbers || columns <= 0 || rows <= 0)
        return;
 
    p29_ptr = 0;
    int start = 0;
    while (columns > start * 2 && rows > start * 2) {
        PrintMatrixInCircle(numbers, columns, rows, start);
        start++;
    }
    cout << endl;
}

bool IsPopOrder(const int* pPush, const int* pPop, int nLength) {
    if (!pPush || !pPop || nLength <= 0)
        return false;

    int p1 = 0;
    while (p1 < nLength && pPush[p1] != pPop[0])
        p1++;
    
    if (p1 == nLength)
        return false;
    
    int p2 = p1 + 1;
    for (int i = 0; i < nLength; i++) {
        if (p1 >= 0 && pPop[i] == pPush[p1])
            p1--;
        else if (p2 < nLength && pPop[i] == pPush[p2])
            p2++;
        else
            return false;
    }

    return true;
}

// For test
int p32_numbers[20] = {0};
int p32_ptr = 0;

static void printNumber32(int number) {
    cout << number << " ";
    p32_numbers[p32_ptr++] = number;
}

void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot) {
    p32_ptr = 0;
    if (!pTreeRoot)
        return;
    
    queue<BinaryTreeNode*> qTreeNode;
    qTreeNode.push(pTreeRoot);

    while (!qTreeNode.empty()) {
        int size = (int) qTreeNode.size();
        for (int i = 0; i < size; i++) {
            auto pNode = qTreeNode.front();
            qTreeNode.pop();

            printNumber32(pNode->m_nValue);
            if (pNode->m_pLeft)
                qTreeNode.push(pNode->m_pLeft);
            if (pNode->m_pRight)
                qTreeNode.push(pNode->m_pRight);
        }
    }

    cout << endl;
}

void Print(BinaryTreeNode* pRoot) {
    p32_ptr = 0;
    if (!pRoot)
        return;
    
    stack<BinaryTreeNode*> level[2];
    int current = 0;
    int next = 1;

    level[current].push(pRoot);
    while (!level[0].empty() || !level[1].empty()) {
        auto pNode = level[current].top();
        level[current].pop();

        printNumber32(pNode->m_nValue);

        if (current == 0) {
            if (pNode->m_pLeft) level[next].push(pNode->m_pLeft);
            if (pNode->m_pRight) level[next].push(pNode->m_pRight);
        } else {
            if (pNode->m_pRight) level[next].push(pNode->m_pRight);
            if (pNode->m_pLeft) level[next].push(pNode->m_pLeft);
        }

        if (level[current].empty()) {
            current = 1 - current;
            next = 1 - next;
        }
    }
}

bool VerifySequenceOfBST(int sequence[], int length) {
    if (nullptr == sequence || length <= 0)
        return false;
 
    int root = sequence[length - 1];
    int i = 0;
    for (; i < length - 1; i++)
        if (sequence[i] > root)
            break;

    int j = i;
    for (; j < length - 1; j++)
        if (sequence[j] < root)
            return false;

    bool left = true;
    if (i > 0)
        left = VerifySequenceOfBST(sequence, i);

    bool right = true;
    if (i < length - 1)
        right = VerifySequenceOfBST(sequence + i, length - i - 1);

    return (left && right);
}

static void FindPath(BinaryTreeNode* pRoot, int expectedSum, int currentSum, vector<int>& path, vector<vector<int>>& res) {
    if (!pRoot)
        return;
    
    currentSum += pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);
    if (!pRoot->m_pLeft && !pRoot->m_pRight) {
        if (expectedSum == currentSum) {
            res.push_back(path);
        }
    }

    if (pRoot->m_pLeft)
        FindPath(pRoot->m_pLeft, expectedSum, currentSum, path, res);

    if (pRoot->m_pRight)
        FindPath(pRoot->m_pRight, expectedSum, currentSum, path, res);

    path.pop_back();
}

std::vector<std::vector<int>> FindPath(BinaryTreeNode* pRoot, int expectedSum) {
    std::vector<std::vector<int>> res;

    if (pRoot) {
        std::vector<int> path;
        FindPath(pRoot, expectedSum, 0, path, res);
    }
    
    return res;
}

static void CloneNodes(ComplexListNode* pHead) {
    ComplexListNode* pNode = pHead;

    while (pNode) {
        ComplexListNode* pClone = new ComplexListNode(pNode->m_nValue, pNode->m_pNext);
        pNode->m_pNext = pClone;
        pNode = pClone->m_pNext;
    }
}

static void ConnectSiblingNodes(ComplexListNode* pHead) {
    ComplexListNode* pNode = pHead;

    while (pNode) {
        ComplexListNode* pClone = pNode->m_pNext;
        if (pNode->m_pSibling)
            pClone->m_pSibling = pNode->m_pSibling->m_pNext;
        pNode = pClone->m_pNext; 
    }
}

static ComplexListNode* ReconnectNodes(ComplexListNode* pHead) {
    ComplexListNode* pCloneHead, *pCloneNode;
    ComplexListNode* pNode = pHead;

    pCloneHead = pCloneNode = pNode->m_pNext;
    pNode->m_pNext = pCloneNode->m_pNext;
    pNode = pNode->m_pNext;

    while (pNode) {
        pCloneNode->m_pNext = pNode->m_pNext;
        pCloneNode = pCloneNode->m_pNext;
        pNode->m_pNext = pCloneNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    return pCloneHead;
}

ComplexListNode* Clone(ComplexListNode* pHead) {
    if (!pHead)
        return nullptr;
 
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}

#if 0
static void dfs(BinaryTreeNode* pRoot, vector<BinaryTreeNode*>& vbt) {
    if (!pRoot)
        return;
    
    vbt.push_back(pRoot);
    dfs(pRoot->m_pLeft, vbt);
    dfs(pRoot->m_pRight, vbt);
}

BinaryTreeNode* Convert(BinaryTreeNode* pRoot) {
    vector<BinaryTreeNode*> vbt;

    dfs(pRoot, vbt);

    std::sort(vbt.begin(), vbt.end(), [](BinaryTreeNode* x, BinaryTreeNode* y) {
        return x->m_nValue <= y->m_nValue;
    });

    for (int i = 0; i < vbt.size(); i++) {
        if (i == 0)
            vbt[i]->m_pRight = vbt[i + 1];
        else if (i == vbt.size() - 1)
            vbt[i]->m_pLeft = vbt[i - 1];
        else if (i > 0 && i < vbt.size() - 1) {
            vbt[i]->m_pRight = vbt[i + 1];
            vbt[i]->m_pLeft = vbt[i - 1];
        }
    }

    return vbt[0];
}
#else
static void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList){
    if (!pNode)
        return;
    
    BinaryTreeNode* pCurrent = pNode;
    if (pCurrent->m_pLeft)
        ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
    
    pCurrent->m_pLeft = *pLastNodeInList;
    if (*pLastNodeInList)
        (*pLastNodeInList)->m_pRight = pCurrent;

    *pLastNodeInList = pCurrent;

    if (pCurrent->m_pRight)
        ConvertNode(pCurrent->m_pRight, pLastNodeInList);
}

BinaryTreeNode* Convert(BinaryTreeNode* pRoot) {
    BinaryTreeNode* pLastNodeInList = nullptr;
    ConvertNode(pRoot, &pLastNodeInList);

    BinaryTreeNode* pHeadOfList = pLastNodeInList;
    while (pHeadOfList && pHeadOfList->m_pLeft)
        pHeadOfList = pHeadOfList->m_pLeft;

    return pHeadOfList;
}
#endif

void Serialize(BinaryTreeNode* pRoot, std::ostream& stream) {
    if (!pRoot) {
        stream << "$,";
        return;
    }
 
    stream << pRoot->m_nValue << ",";
    Serialize(pRoot->m_pLeft, stream);
    Serialize(pRoot->m_pRight, stream);
}

static bool ReadStream(std::istream& stream, int& number) {
    stream >> number;
    return true;
}

void Deserialize(BinaryTreeNode** pRoot, std::istream& stream) {
    int number;
    if (ReadStream(stream, number)) {
        *pRoot = new BinaryTreeNode(number);
 
        Deserialize(&((*pRoot)->m_pLeft), stream);
        Deserialize(&((*pRoot)->m_pRight), stream);
    }
}

static void Permutation(char* pStr, char* pBegin, std::set<std::string>& result) {
    if (*pBegin == '\0') {
        result.insert(std::string(pStr, pBegin - pStr));
        return;
    }

    for (char* pCh = pBegin; *pCh != '\0'; ++pCh) {
        char temp = *pCh;
        *pCh = *pBegin;
        *pBegin = temp;

        Permutation(pStr, pBegin + 1, result);

        temp = *pCh;
        *pCh = *pBegin;
        *pBegin = temp;
    }
}

void Permutation(char* pStr, std::set<std::string>& result) {
    if (!pStr)
        return;
    
    Permutation(pStr, pStr, result);
}