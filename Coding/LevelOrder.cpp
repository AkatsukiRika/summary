#include <vector>
#include <memory>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> result = {};

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return result;
        }
        vector<TreeNode*> levelNodes = {root};
        while (!levelNodes.empty()) {
            vector<int> level;
            vector<TreeNode*> nextLevelNodes = {};
            for (int i = 0; i < levelNodes.size(); i++) {
                level.emplace_back(levelNodes[i]->val);
                if (levelNodes[i]->left != nullptr) {
                    nextLevelNodes.emplace_back(levelNodes[i]->left);
                }
                if (levelNodes[i]->right != nullptr) {
                    nextLevelNodes.emplace_back(levelNodes[i]->right);
                }
            }
            result.emplace_back(level);
            levelNodes.clear();
            levelNodes.insert(levelNodes.end(), nextLevelNodes.begin(), nextLevelNodes.end());
        }
        return result;
    }
};

void logVector(vector<int>& nums) {
    string log = "[";
    for (int i = 0; i < nums.size(); i++) {
        log += to_string(nums[i]);
        if (i < nums.size() - 1) {
            log += ",";
        }
    }
    log += "]";
    printf("%s\n", log.c_str());
}

void log2DVector(vector<vector<int>>& vec) {
    printf("log2DVector START\n");
    for (int i = 0; i < vec.size(); i++) {
        logVector(vec[i]);
    }
    printf("log2DVector END\n");
}

int main() {
    auto solution = make_unique<Solution>();

    // vector<TreeNode*> nodes = {
    //     new TreeNode(3),
    //     new TreeNode(9),
    //     new TreeNode(20),
    //     new TreeNode(15),
    //     new TreeNode(7)
    // };
    // nodes[0]->left = nodes[1];
    // nodes[0]->right = nodes[2];
    // nodes[2]->left = nodes[3];
    // nodes[2]->right = nodes[4];

    vector<TreeNode*> nodes = {new TreeNode(1)};
    
    auto answer = solution->levelOrder(nullptr);
    log2DVector(answer);
}