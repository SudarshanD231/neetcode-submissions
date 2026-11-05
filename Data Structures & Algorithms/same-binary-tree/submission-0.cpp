//this is dfs soln 
typedef struct treenode{
    int data;
    struct treenode* left;
    struct treenode* right;
}TreeNode;
bool isSame(TreeNode* a,TreeNode* b){
    if(!a && !b){
        return true;
    }
    if((!a && b) || (!b && a) ){
        return false;
    }
    if(a->data!=b->data){
        return false;
    }
    return (isSame(a->left,b->left)&& isSame(a->right,b->right));
}