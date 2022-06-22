#include "problem_set.h"
#include <map>
#include <iostream>
#include <numeric>

int subarrySum(const vector<int> &nums, int k) {
    int count = 0;
    int sum = 0;
    map<int, int> sum2index = {{0, 1}};

    for (int num : nums) {
        sum += num;
        auto it = sum2index.find(sum - k);
        count += it != sum2index.end() ? it->second : 0;
        sum2index[sum] = sum2index.find(sum) != sum2index.end() ? sum2index[sum] + 1 : 1;
    }

    return count;
}

int findMaxLength(const vector<int> &nums) {
    int length = 0;
    int sum = 0;
    map<int, int> sum2index = {{0, -1}};

    for (int i = 0; i < nums.size(); i++) {
        sum += 0 == nums[i] ? -1 : 1;
        if (sum2index.find(sum) != sum2index.end()) {
            length = std::max(length, i - sum2index[sum]);
        } else {
            sum2index[sum] = i;
        }
    }

    return length;
}

int pivotIndex(const vector<int> &nums) {
    int allsum = std::accumulate(nums.begin(), nums.end(), 0);
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum - nums[i] == allsum - sum) {
            return i;
        }
    }
    return -1;
}

NumMatrix::NumMatrix(const vector<vector<int>> &matrix) {
    sums.resize(matrix.size() + 1);
    for (int i = 0; i < sums.size(); i++) {
        sums[i].resize(matrix[0].size());
    }
 
    for (int i = 1; i <= matrix.size(); i++) {
        int sum = 0;
        for (int j = 1; j <= matrix[0].size(); j++) {
            sum += matrix[i - 1][j - 1];
            sums[i][j] = sum + sums[i - 1][j];
        }
    }
}

int NumMatrix::sumRegion(int row1, int col1, int row2, int col2) {
    return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1];
}