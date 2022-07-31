#include "problems.h"
#include <string.h>
#include <stack>
#include <iostream>
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

void ReplaceBland(char string[], int length) {
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