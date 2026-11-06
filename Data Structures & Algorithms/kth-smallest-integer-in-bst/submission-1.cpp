class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while (cur != nullptr || !st.empty()) {
            // Go as left as possible
            while (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }

            // Process node
            cur = st.top();
            st.pop();
            
            k--;
            if (k == 0) {
                return cur->val;
            }

            // Move to right subtree
            cur = cur->right;
        }

        return -1; // should never reach here if k is valid
    }
};