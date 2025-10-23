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
    void dfs(TreeNode* node, int maxValue = 0) {
        printf("dfs current=%d, maxValue=%d\n", node->val, maxValue);
        if (node == nullptr) {
            return;
        }
        if (node->left != nullptr) {
            printf("dfs (%d, %d) go left\n", node->val, maxValue);
            dfs(node->left);
            printf("dfs (%d, %d) recovered from left\n", node->val, maxValue);
        }
        if (node->right != nullptr) {
            printf("dfs (%d, %d) go right\n", node->val, maxValue);
            dfs(node->right);
            printf("dfs (%d, %d) recovered from right\n", node->val, maxValue);
        }
    }

    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return 0;
    }
};

int main() {
    std::vector<TreeNode*> nodes = {
        new TreeNode(3),
        new TreeNode(1),
        new TreeNode(4),
        new TreeNode(3),
        new TreeNode(1),
        new TreeNode(5)
    };
    nodes[0]->left = nodes[1];
    nodes[0]->right = nodes[2];
    nodes[1]->left = nodes[3];
    nodes[2]->left = nodes[4];
    nodes[2]->right = nodes[5];

    auto solution = std::unique_ptr<GoodNodes>();
    int answer = solution->goodNodes(nodes[0]);
    printf("answer=%d\n", answer);

    return 0;
}