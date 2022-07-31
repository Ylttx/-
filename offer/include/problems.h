#ifndef PROBLEMS_H
#define PROBLEMS_H

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

#endif