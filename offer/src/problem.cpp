#include "problems.h"
#include <string.h>
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
