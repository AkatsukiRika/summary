#include <cstdio>
#include <memory>
#include <stack>
#include <string>
using namespace std;

class RemoveStars {
public:
    string removeStars(string s) {
        stack<char> charStack;
        for (int i = 0; i < s.length(); i++) {
            charStack.push(s[i]);
        }

        int starCount = 0;
        vector<char> result;

        while (!charStack.empty()) {
            char top = charStack.top();
            if (top == '*') {
                starCount++;
                charStack.pop();
                continue;
            }
            if (starCount == 0) {
                result.emplace_back(top);
            } else {
                starCount--;
            }
            charStack.pop();
        }

        reverse(result.begin(), result.end());
        auto resultString = string(result.begin(), result.end());
        return resultString;
    }
};

int main() {
    auto solution = std::unique_ptr<RemoveStars>();
    auto result = solution->removeStars("erase*****");
    printf("result=%s\n", result.c_str());
    return 0;
}