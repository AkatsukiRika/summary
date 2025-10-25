#include <climits>
#include <cstdio>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class IncreasingTriplet {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        int first = nums[0];
        int second = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > second) {
                return true;
            } else if (nums[i] > first) {
                second = nums[i];
            } else {
                first = nums[i];
            }
        }
        return false;
    }

    void logVector(vector<int>& nums) {
        string log = "[";
        for (int i = 0; i < nums.size(); i++) {
            log += to_string(nums[i]);
            if (i < nums.size() - 1) {
                log += ",";
            }
        }
        log += "]";
        printf("logVector: %s\n", log.c_str());
    }
};

int main() {
    auto solution = make_unique<IncreasingTriplet>();
    vector<int> nums = {1,6,2,5,1};
    bool answer = solution->increasingTriplet(nums);
    printf("answer=%d\n", answer);
    return 0;
}