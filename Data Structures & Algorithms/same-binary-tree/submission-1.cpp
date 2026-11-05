//queue+bfs soln .
typedef struct tree{
    int val;
    struct tree* right;
    struct tree* left;
}TreeNode;

bool isSame(TreeNode* a,TreeNode* b){
    TreeNode** q1=malloc(100*sizeof(TreeNode*));
    TreeNode** q2=malloc(100*sizeof(TreeNode));
    int frontA=0;
    int frontB=0;
    int rearA=0;
    int rearB=0;
    q1[rearA++]=a;
    q2[rearB++]=b;
    while(frontA<rearA && frontB<rearB){
        TreeNode* x=q1[frontA++];
        TreeNode* y=q2[frontB++];
        if(!x && !y){
            continue;
        }
        if(!x || !y){
            return false;

        }
        if(x->val !=y->val){
            return false;
        }
        q1[rearA++]=x->left;
        q1[rearA++]=x->right;
        q2[rearB++]=y->left;
        q2[rearB++]=y->right;
    }
    return frontA==rearA && frontB==rearB;
}