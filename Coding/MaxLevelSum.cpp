#include <vector>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class MaxLevelSum {
public:
    std::vector<int> levelSums;

    void bfs(TreeNode* node, int level) {
        // printf("bfs node=%d, level=%d\n", node->val, level);
        bool canGoLeft = false;
        bool canGoRight = false;
        int nextLevelSum = 0;
        if (node->left != nullptr) {
            // printf("left=%d\n", node->left->val);
            nextLevelSum += node->left->val;
            canGoLeft = true;
        }
        if (node->right != nullptr) {
            // printf("right=%d\n", node->right->val);
            nextLevelSum += node->right->val;
            canGoRight = true;
        }
        int nextLevel = level + 1;
        if (canGoLeft || canGoRight) {
            // printf("nextLevel=%d, nextLevelSum=%d\n", nextLevel, nextLevelSum);
            if (levelSums.size() < nextLevel + 1) {
                levelSums.emplace_back(nextLevelSum);
            } else {
                levelSums[nextLevel] += nextLevelSum;
            }
        }
        if (canGoLeft) {
            bfs(node->left, nextLevel);
        }
        if (canGoRight) {
            bfs(node->right, nextLevel);
        }
    }

    int maxLevelSum(TreeNode* root) {
        levelSums.emplace_back(root->val);
        bfs(root, 0);

        int maxSum = INT_MIN;
        int maxLevel = 1;
        for (int i = 0; i < levelSums.size(); i++) {
            printf("i=%d, levelSum=%d\n", i, levelSums[i]);
            if (levelSums[i] > maxSum) {
                maxSum = levelSums[i];
                maxLevel = i + 1;
            }
        }

        return maxLevel;
    }
};

int main() {
    // std::vector<TreeNode*> nodes = {
    //     new TreeNode(1),
    //     new TreeNode(7),
    //     new TreeNode(0),
    //     new TreeNode(7),
    //     new TreeNode(-8)
    // };
    // nodes[0]->left = nodes[1];
    // nodes[0]->right = nodes[2];
    // nodes[1]->left = nodes[3];
    // nodes[1]->right = nodes[4];

    // std::vector<TreeNode*> nodes = {
    //     new TreeNode(989),
    //     new TreeNode(10250),
    //     new TreeNode(98693),
    //     new TreeNode(-89388),
    //     new TreeNode(-32127)
    // };
    // nodes[0]->right = nodes[1];
    // nodes[1]->left = nodes[2];
    // nodes[1]->right = nodes[3];
    // nodes[3]->right = nodes[4];

    std::vector<TreeNode*> nodes = {
        new TreeNode(-100),
        new TreeNode(-200),
        new TreeNode(-300),
        new TreeNode(-20),
        new TreeNode(-5),
        new TreeNode(-10)
    };
    nodes[0]->left = nodes[1];
    nodes[0]->right = nodes[2];
    nodes[1]->left = nodes[3];
    nodes[1]->right = nodes[4];
    nodes[2]->left = nodes[5];

    auto solution = std::make_unique<MaxLevelSum>();
    int answer = solution->maxLevelSum(nodes[0]);
    printf("answer=%d\n", answer);

    return 0;
}