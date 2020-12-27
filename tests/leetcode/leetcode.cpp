#include "catch2/catch.hpp"
#include <iostream>
using std::vector;
using std::max;
using std::min;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();
        int left_cnt = (m+n+1)/2;

        int left = 0, right = m;

        int nums1Left = 0;
        int nums1Right = 0;
        int nums2Left = 0;
        int nums2Right = 0;

        while (left <= right) {
            int i = (left+right)/2;
            int j = left_cnt - i;

            nums1Left = (i == 0) ? INT_MIN : nums1[i - 1];
            nums1Right = (i == m) ? INT_MAX : nums1[i];
            nums2Left = (j == 0) ? INT_MIN : nums2[j - 1];
            nums2Right = (j == n) ? INT_MAX : nums2[j];

            if (nums1Left > nums2Right) {
                right = i-1;
            } else if (nums1Right < nums2Left) {
                left = i+1;
            } else {
                break;
            }
        }
    
        if ((m+n) % 2 == 0) {
            return (std::max(nums1Left, nums2Left)+std::min(nums1Right, nums2Right))/2.0;
        } else {
            return std::max(nums1Left, nums2Left);
        }
    }
};

TEST_CASE("find no. k number", "[leetcode]") {
    Solution s;
    SECTION("case 1") {
        std::vector<int> vec1 = {1, 3, 5, 7};
        std::vector<int> vec2 = {2, 4, 6};

        REQUIRE(s.findMedianSortedArrays(vec1, vec2) == 4);
    }
    SECTION("case 2") {
        std::vector<int> vec1 = {};
        std::vector<int> vec2 = {1,2,3,4,5,6,7};

        REQUIRE(s.findMedianSortedArrays(vec1, vec2) == 4);
    }
    SECTION("case 3") {
        std::vector<int> vec1 = {1,2,3,4};
        std::vector<int> vec2 = {5,6,7,8};

        REQUIRE(s.findMedianSortedArrays(vec1, vec2) == 4.5);
    }
    SECTION("case 4") {
        std::vector<int> vec1 = {1};
        std::vector<int> vec2 = {2,3,4,5,6};

        REQUIRE(s.findMedianSortedArrays(vec1, vec2) == 3.5);
    }
}