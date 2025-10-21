#include <cstdio>
#include <memory>
#include <vector>
#include <algorithm>
#include <chrono>
#include <map>
using namespace std;

class MaxOperations {
public:
    int maxOperations(vector<int>& nums, int k) {
        int length = nums.size();
        if (length <= 1) {
            return 0;
        }
        if (length == 2) {
            if (nums[0] + nums[1] == k) {
                return 1;
            } else {
                return 0;
            }
        }

        sort(nums.begin(), nums.end());
        map<int, int> occurrences;
        for (int i = 0; i < length; i++) {
            int value = nums[i];
            occurrences[value] = occurrences[value] + 1;
        }

        int result = 0;
        for (auto it = occurrences.begin(); it != occurrences.end(); it++) {
            int num = it->first;
            int count = it->second;
            // printf("num=%d, count=%d\n", num, count);

            int coupleNum = k - num;
            int coupleNumCount = occurrences[coupleNum];
            // printf("coupleNum=%d, coupleNumCount=%d\n", coupleNum, coupleNumCount);
            if (coupleNum < num || coupleNumCount < 1) {
                continue;
            }

            if (coupleNum == num) {
                result += coupleNumCount / 2;
                occurrences[coupleNum] -= coupleNumCount / 2;
            } else {
                int minCount = min(count, coupleNumCount);
                result += minCount;
                occurrences[num] -= minCount;
                occurrences[coupleNum] -= minCount;
            }
        }

        return result;
    }

    int maxOperationsFail(vector<int>& nums, int k) {
        int length = nums.size();
        if (length <= 1) {
            return 0;
        }
        if (length == 2) {
            if (nums[0] + nums[1] == k) {
                return 1;
            } else {
                return 0;
            }
        }

        sort(nums.begin(), nums.end());
        vector<int> flags(length, 0);
        int result = 0;
        int frontPtr = 0;
        int rearPtr = 1;
        while (frontPtr < rearPtr && frontPtr < length && rearPtr < length) {
            int frontVal = nums[frontPtr];
            int rearVal = nums[rearPtr];
            // printf("frontPtr=%d, rearPtr=%d, frontVal=%d, rearVal=%d\n", frontPtr, rearPtr, frontVal, rearVal);

            if (frontVal + rearVal == k && !flags[frontPtr] && !flags[rearPtr]) {
                flags[frontPtr] = 1;
                flags[rearPtr] = 1;
                result++;

                int frontPtrAdd;
                for (frontPtrAdd = 1; frontPtrAdd < length - frontPtr; frontPtrAdd++) {
                    int newFrontPtr = frontPtr + frontPtrAdd;
                    // printf("frontPtrAdd=%d, newFrontPtr=%d, flag=%d\n", frontPtrAdd, newFrontPtr, flags[newFrontPtr]);
                    if (!flags[newFrontPtr]) {
                        break;
                    }
                }
                // printf("frontPtrAdd=%d\n", frontPtrAdd);
                frontPtr += frontPtrAdd;
                rearPtr = frontPtr + 1;
                continue;
            }

            if (rearPtr + 1 < length) {
                rearPtr++;
            } else {
                frontPtr++;
                rearPtr = frontPtr + 1;
            }
        }

        return result;
    }
};

int main() {
    auto solution = std::unique_ptr<MaxOperations>();
    vector<int> nums = {1,2,3,4};
    int k = 5;
    auto start = chrono::high_resolution_clock::now();
    auto result = solution->maxOperations(nums, k);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    printf("result=%d, time=%lld ms\n", result, duration.count());
    return 0;
}