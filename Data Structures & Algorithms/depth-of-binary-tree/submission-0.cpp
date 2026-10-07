/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//here we iteratively add to stack ,pop off the last item from the stack if there r no further branches and also keep track of the depth until tht node.
//so the depth array keeps track of the depth till tht node,index will increase as stack grows,corresponding stack top =depth of tht element which is in the top.
typedef struct TreeNode NODE;
class Solution {
public:
    int maxDepth(NODE* root){
    if(!root){return 0;}
    NODE* s[100];
    int depth[100];
    int top=-1;
    int max=0;
    s[++top]=root;
    depth[top]=1;
    while(top>=0){
        NODE* cur=s[top];
        int curdepth=depth[top];
        top--;
        if(curdepth>max){
            max=curdepth;
        }
        if(cur->right){
            s[++top]=cur->right;
            depth[top]=curdepth+1;
        }
        if(cur->left){
            s[++top]=cur->left;
            depth[top]=curdepth+1;
        }
    }
    return max;
}
};
