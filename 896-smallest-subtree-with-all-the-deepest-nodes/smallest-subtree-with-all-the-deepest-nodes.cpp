class Solution {
public:
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) return {0, nullptr};

        auto [ld, lnode] = dfs(node->left);
        auto [rd, rnode] = dfs(node->right);

        if (ld > rd) return {ld + 1, lnode};
        if (rd > ld) return {rd + 1, rnode};
        return {ld + 1, node};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
