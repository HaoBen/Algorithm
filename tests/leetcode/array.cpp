#include "catch2/catch.hpp"
#include <iostream>
#include <numeric>

using std::vector;
using std::max;
using std::min;
using std::numeric_limits;

class Solution {
public:
    /*
     * 查找两个排序数组的中位数
     */
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

            nums1Left = (i == 0) ? numeric_limits<int>::min() : nums1[i - 1];
            nums1Right = (i == m) ? numeric_limits<int>::max() : nums1[i];
            nums2Left = (j == 0) ? numeric_limits<int>::min() : nums2[j - 1];
            nums2Right = (j == n) ? numeric_limits<int>::max() : nums2[j];

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

    /*
    * 原地删除某个值的元素
    */
    int removeElement(vector<int> &v, int ele) {
        int i = 0;
        int j = 0;
        while (j < v.size()) {
            if (v[j] != ele) {
                v[i] = v[j];
                ++i;++j;
            }
            else {
                ++j;
            }
        }
        return i;
    }

    /*
     * 题目209.长度最小的子数组
     * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
     * 示例：
     * 输入：s = 7, nums = [2,3,1,2,4,3]
     * 输出：2
     * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
     */
    int findShortestSubsArray(int s, const vector<int> &v) {
        int i = 0;
        int j = 0;
        int ans = numeric_limits<int>::max();

        int tmp = 0;
        while (i < v.size() && j < v.size()) {
            tmp += v[j];
            if (tmp >= s) {
                ans = j-i+1 < ans ? j-i+1 : ans;
                tmp -= v[i];
                tmp -= v[j];
                ++i;
            } else {
                ++j;
            }
        }
        return ans == numeric_limits<int>::max() ? 0 : ans;
    }

    /*
     * 题目59
     */
    vector<int> generateMatrix(int n) {
                
    }
};

TEST_CASE("find no. k number", "[leetcode.array]") {
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

TEST_CASE("remove element in suit", "[leetcode.array]") {
    Solution s;
    SECTION("case 1") {
        std::vector<int> vec = {1,2,3,4,5,6,7};
        REQUIRE(s.removeElement(vec, 8) == 7);
    }
    SECTION("case 2") {
        std::vector<int> vec = {1,2,2,3,4,5,2};
        REQUIRE(s.removeElement(vec, 2) == 4);
    }
}

TEST_CASE("leetcode 209", "[leetcode.array]") {
    Solution s;
    SECTION("case 1") {
        std::vector<int> vec = {2, 3, 1, 2, 4, 3};
        REQUIRE(s.findShortestSubsArray(7, vec) == 2);
    }
    SECTION("case 2") {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6};
        REQUIRE(s.findShortestSubsArray(21, vec) == 6);
    }
}
