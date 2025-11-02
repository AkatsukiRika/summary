#include <vector>
#include <memory>
#include <cstdio>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        printf("prices size=%d\n", prices.size());
        if (prices.size() == 1) {
            return 0;
        }
        vector<vector<int>> dp(prices.size(), vector<int>(prices.size(), 0));
        int step = 1;
        while (step < prices.size()) {
            for (int i = 0; i < prices.size(); i++) {
                int endIndex = i + step;
                if (endIndex >= prices.size()) {
                    break;
                }
                if (step == 1) {
                    dp[i][endIndex] = max(0, prices[endIndex] - prices[i] - fee);
                } else {
                    int tmp1 = max(0, dp[i][endIndex-1] + dp[endIndex-1][endIndex]);
                    int tmp2 = max(0, prices[endIndex] - prices[i] - fee);
                    dp[i][endIndex] = max(tmp1, tmp2);
                }
                // printf("dp[%d, %d] = %d\n", i, endIndex, dp[i][endIndex]);
            }
            step++;
            // printf("\n");
        }
        return dp[0][prices.size() - 1];
    }
};

int main() {
    auto solution = make_unique<Solution>();
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    int answer = solution->maxProfit(prices, fee);
    printf("answer = %d\n", answer);
    return 0;
}