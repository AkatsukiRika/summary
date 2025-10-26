#include <cstdio>
#include <vector>
#include <memory>
using namespace std;

class Solution {
public:
    int peakIndex = 0;

    void binarySearch(vector<int>& nums, int begin, int end) {
        int mid = (begin + end) / 2;
        // printf("binarySearch begin=%d, end=%d, mid=%d\n", begin, end, mid);
        if (mid == 0 || mid == nums.size() - 1) {
            if (mid == 0 && nums[mid] > nums[mid+1]) {
                peakIndex = 0;
            } else if (mid == nums.size() - 1 && nums[mid] > nums[mid-1]) {
                peakIndex = nums.size() - 1;
            }
            // printf("peakIndex=%d, return\n", peakIndex);
            return;
        }
        if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
            peakIndex = mid;
            // printf("peakIndex=%d\n", peakIndex);
        } else if (begin < end) {
            binarySearch(nums, begin, mid);
            binarySearch(nums, mid + 1, end);
        }
    }

    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        if (nums.size() == 2) {
            if (nums[0] > nums[1]) {
                return 0;
            } else {
                return 1;
            }
        }
        binarySearch(nums, 0, nums.size() - 1);
        return peakIndex;
    }
};

int main() {
    auto solution = make_unique<Solution>();
    vector<int> nums = {3,4,3,2,1};
    int answer = solution->findPeakElement(nums);
    printf("answer=%d\n", answer);
}