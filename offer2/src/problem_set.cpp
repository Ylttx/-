#include "problem_set.h"
#include <map>
#include <iostream>

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