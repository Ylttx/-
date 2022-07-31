#include "problems.h"
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    char data[] = "hello world";
    CMyString str(data);
    CMyString str1, str2, str3;
    str1 = str2 = str3 = str;
    cout << str1.to_string() << " " << str2.to_string() << " " << str3.to_string() << endl;

    ListNode *pHead = nullptr;
    AddToTail(&pHead, 1);
    AddToTail(&pHead, 2);
    AddToTail(&pHead, 3);
    AddToTail(&pHead, 4);
    AddToTail(&pHead, 5);
    PrintListReversingly_Iteratively(pHead);
    PrintListReversingly_Recursively(pHead);
    ClearNode(&pHead);

    return 0;
}