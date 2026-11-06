    //iterative dfs uses stack for inorder traversal ,we go as deep as possible in the left branch ,if we cant go any further ,pop tht node and go right and repeat loop .

    typedef struct tree{
        int data;
        struct tree* left;
        struct tree* right;
    }TreeNode;
    int dfs(TreeNode* root,int k){
    TreeNode** stck=(TreeNode**)malloc(10000*sizeof(TreeNode*));
    int top=-1;
    TreeNode* cur=root;
    
    while(top>=0 || cur!=NULL){
        while(cur!=NULL){
            stck[++top]=cur;
            cur=cur->left;
        }
        cur=stck[top--];
        k-=1;
        if(k==0){return cur->data;}
        cur=cur->right;
    }
    return -1;

    }
    int kthSmallest(TreeNode* root,int k){
        return dfs(root,k);
    }