class Solution {
public:
    long long totalSum = 0;
    long long best = 0;
    long long mod = 1000000007;

    long long getSum(TreeNode* root) {
        if (root == NULL) return 0;
        return root->val + getSum(root->left) + getSum(root->right);
    }

    long long dfs(TreeNode* root) {
        if (root == NULL) return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long currentSum = root->val + leftSum + rightSum;
        long long product = currentSum * (totalSum - currentSum);

        if (product > best) best = product;

        return currentSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getSum(root);
        dfs(root);
        return best % mod;
    }
};
