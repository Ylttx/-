#include "problems.h"
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    char data[] = "hello world";
    CMyString str(data);
    cout << str.to_string() << endl;

    CMyString str1, str2, str3;
    str1 = str2 = str3 = str;
    cout << str1.to_string() << " " << str2.to_string() << " " << str3.to_string() << endl;

    vector<CMyString> strs;
    strs.push_back(str1);
    strs.push_back(str2);
    strs.push_back(str3);
    for (auto &s : strs) {
        cout << s.to_string() << " ";
    }
    cout << endl;
    return 0;
}