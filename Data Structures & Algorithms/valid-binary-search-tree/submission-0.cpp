typedef struct node{
    int val;
    struct node* right;
    struct node* left;
}Tree;
bool isValidTree(Tree* root,long long min,long long max){
    if(!root){return true;}
    if(root->val>=max || root->val<=min){
        return false;
    }
    return (isValidTree(root->left,min,root->val) && isValidTree(root->right,root->val,max));
}