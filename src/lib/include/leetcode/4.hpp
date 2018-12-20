#pragma once

#include <vector>

namespace leetcode {
namespace p4 {

class Solution {
public:
    double findMedianSortedArrays(const std::vector<int> &nums1, const std::vector<int> &nums2);

    double findMedianSortedArraysNaive(std::vector<int> v1, const std::vector<int> &v2);

private:
};

}
}
