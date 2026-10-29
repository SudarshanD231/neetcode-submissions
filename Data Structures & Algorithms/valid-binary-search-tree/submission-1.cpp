class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }

private:
    bool isValid(TreeNode* root, long long min, long long max) {
        if (root == nullptr) {
            return true;
        }

        if (root->val >= max || root->val <= min) {
            return false;
        }

        return isValid(root->left, min, root->val) &&
               isValid(root->right, root->val, max);
    }
};