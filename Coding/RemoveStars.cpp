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

        char* result;
        int resultPtr = 0;
        int starCount = 0;

        while (!charStack.empty()) {
            char top = charStack.top();
            if (starCount == 0) {
                result[resultPtr++] = top;
            }
            charStack.pop();
        }
        return "";
    }
};

int main() {
    auto solution = std::unique_ptr<RemoveStars>();
    auto result = solution->removeStars("leet**cod*e");
    printf("result=%s\n", result.c_str());
    return 0;
}