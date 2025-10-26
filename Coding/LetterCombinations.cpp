#include <cstdio>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
using namespace std;

void logVector(vector<string>& vec) {
    string message = "[";
    for (int i = 0; i < vec.size(); i++) {
        message += "\"" + vec[i] + "\"";
        if (i != vec.size() - 1) {
            message += ",";
        }
    }
    message += "]";
    printf("logVector: %s\n", message.c_str());
}

class Solution {
public:
    vector<string> result;
    
    string getCombinationsByDigit(char digit) {
        unordered_map<char, string> digitMap;
        digitMap['2'] = "abc";
        digitMap['3'] = "def";
        digitMap['4'] = "ghi";
        digitMap['5'] = "jkl";
        digitMap['6'] = "mno";
        digitMap['7'] = "pqrs";
        digitMap['8'] = "tuv";
        digitMap['9'] = "wxyz";
        return digitMap[digit];
    }

    void traverse(string curString, string digits) {
        // printf("traverse curString=%s, digits=%s\n", curString.c_str(), digits.c_str());
        string combinations = getCombinationsByDigit(digits[curString.length()]);
        // printf("combinations=%s\n", combinations.c_str());
        for (int i = 0; i < combinations.length(); i++) {
            string newString = curString + combinations[i];
            if (newString.length() < digits.length()) {
                traverse(newString, digits);
            } else {
                result.emplace_back(newString);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        traverse("", digits);
        return result;
    }
};

int main() {
    auto solution = make_unique<Solution>();
    auto result = solution->letterCombinations("234");
    logVector(result);
}