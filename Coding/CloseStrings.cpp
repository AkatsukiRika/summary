#include <algorithm>
#include <cstdio>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) {
            return false;
        }
        if (word1 == word2) {
            return true;
        }
        unordered_map<char, int> mapWord1;
        unordered_set<char> charSet;
        for (int i = 0; i < word1.length(); i++) {
            char charAtI = word1[i];
            mapWord1[charAtI]++;
            charSet.insert(charAtI);
        }
        // logUnorderedMap(mapWord1);

        unordered_map<char, int> mapWord2;
        for (int i = 0; i < word2.length(); i++) {
            char charAtI = word2[i];
            mapWord2[charAtI]++;
            if (charSet.find(charAtI) == charSet.end()) {
                return false;
            }
        }
        // logUnorderedMap(mapWord2);

        vector<int> occurrencesWord1;
        for (auto it = mapWord1.begin(); it != mapWord1.end(); it++) {
            occurrencesWord1.emplace_back(it->second);
        }
        sort(occurrencesWord1.begin(), occurrencesWord1.end());
        // logVector(occurrencesWord1);

        vector<int> occurrencesWord2;
        for (auto it = mapWord2.begin(); it != mapWord2.end(); it++) {
            occurrencesWord2.emplace_back(it->second);
        }
        sort(occurrencesWord2.begin(), occurrencesWord2.end());
        // logVector(occurrencesWord2);

        if (occurrencesWord1.size() != occurrencesWord2.size()) {
            return false;
        }
        for (int i = 0; i < occurrencesWord1.size(); i++) {
            if (occurrencesWord1[i] != occurrencesWord2[i]) {
                return false;
            }
        }

        return true;
    }

    void logUnorderedMap(unordered_map<char, int>& map) {
        string log = "{";
        for (auto it = map.begin(); it != map.end(); it++) {
            log += "\"";
            log += it->first;
            log += "\": ";
            log += to_string(it->second);
            log += ", ";
        }
        log[log.length() - 2] = '}';
        log[log.length() - 1] = '\0';
        printf("logUnorderedMap: %s\n", log.c_str());
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
    auto solution = make_unique<Solution>();
    bool answer = solution->closeStrings("uau", "ssx");
    printf("answer=%d\n", answer);
}