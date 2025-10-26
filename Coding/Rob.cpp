#include <algorithm>
#include <cstdio>
#include <vector>
#include <memory>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[200];
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (i < 2) {
                dp[i] = max(dp[i-1], nums[i]);
            } else {
                dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            }
        }
        return dp[nums.size() - 1];
    }
};

int main() {
    auto solution = make_unique<Solution>();
    vector<int> nums = {1};
    int answer = solution->rob(nums);
    printf("answer=%d\n", answer);
}