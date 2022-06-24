#ifndef PROBLEM_SET_H
#define PROBLEM_SET_H

#include <vector>
#include <string>
using namespace std;

// P10: 和为k的子数组
int subarrySum(const vector<int> &nums, int k);

// P11: 0和1个数相同的子数组
int findMaxLength(const vector<int> &nums);

// P12: 左右两边子数组的和相等
int pivotIndex(const vector<int> &nums);

// P13: 二维子矩阵的数字之和
class NumMatrix {
public:
    NumMatrix(const vector<vector<int>> &matrix);
    int sumRegion(int row1, int col1, int row2, int col2);

private:
    vector<vector<int>> sums;
};

// P14: 字符串中的变位词
bool checkInclusion(const string &s1, const string &s2);

// P15: 字符串中的所有变位词
vector<int> findAnagrams(const string &s1, const string &s2);

#endif