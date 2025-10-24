#include <cstdio>
#include <memory>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class GoodNodes {
public:
    int goodNodesCount = 0;

    void dfs(TreeNode* node, int maxValue) {
        // printf("dfs current=%d, maxValue=%d\n", node->val, maxValue);
        if (node->val >= maxValue) {
            goodNodesCount++;
            // printf("goodNodesCount=%d\n", goodNodesCount);
        }
        if (node == nullptr) {
            return;
        }
        if (node->left != nullptr) {
            // printf("dfs (%d, %d) go left\n", node->val, maxValue);
            if (node->val >= maxValue) {
                dfs(node->left, node->val);
            } else {
                dfs(node->left, maxValue);
            }
            // printf("dfs (%d, %d) recovered from left\n", node->val, maxValue);
        }
        if (node->right != nullptr) {
            // printf("dfs (%d, %d) go right\n", node->val, maxValue);
            if (node->val >= maxValue) {
                dfs(node->right, node->val);
            } else {
                dfs(node->right, maxValue);
            }
            // printf("dfs (%d, %d) recovered from right\n", node->val, maxValue);
        }
    }

    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return goodNodesCount;
    }
};

int main() {
    // std::vector<TreeNode*> nodes = {
    //     new TreeNode(3),
    //     new TreeNode(1),
    //     new TreeNode(4),
    //     new TreeNode(3),
    //     new TreeNode(1),
    //     new TreeNode(5)
    // };
    // nodes[0]->left = nodes[1];
    // nodes[0]->right = nodes[2];
    // nodes[1]->left = nodes[3];
    // nodes[2]->left = nodes[4];
    // nodes[2]->right = nodes[5];

    std::vector<TreeNode*> nodes = {
        new TreeNode(3),
        new TreeNode(3),
        new TreeNode(4),
        new TreeNode(2)
    };
    nodes[0]->left = nodes[1];
    nodes[1]->left = nodes[2];
    nodes[1]->right = nodes[3];

    auto solution = std::make_unique<GoodNodes>();
    int answer = solution->goodNodes(nodes[0]);
    printf("answer=%d\n", answer);

    return 0;
}