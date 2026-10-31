//queue ,push nodes ,get size of queue ,malloc tht size to tht levels array ,pop nodes ,put the value in the array and push its children to the queue.

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Tree;
typedef struct qnode{
    Tree* node;
    struct qnode* next;

}qnode;
typedef struct queue{
    qnode* front;
    qnode* rear;
    int size;
}Queue;
void initQ(Queue* q){
    q->rear=q->front=NULL;
    q->size=0;
}
void enqueue(Tree* node,Queue* q){
    qnode* new_node=(qnode*)malloc(sizeof(qnode));
    new_node->node=node;
    new_node->next=NULL;
    if(!q->rear){
        q->front=q->rear=new_node;
    }else{
        q->rear->next=new_node;
        q->rear=new_node;
    }
    q->size+=1;
}
Tree* dequeue(Queue* q){
    if(!q->front){return NULL;}
    Tree* temp=q->front->node;
    q->size-=1;
    qnode* tempqnode=q->front;
    q->front=q->front->next;
    if(!q->front){
        q->rear=NULL;
    }
    free(tempqnode);
    return temp;
}
bool isEmpty(Queue* q){
    return q->size==0;
}
int** levelOrderTraversal(Tree* root,int* returnSize,int** returnColumSize){
    *returnSize=0;
    if(!root){
        *returnSize=0;
        return NULL;
    }
    int maxLevel=2000;//max number of levels
    int* returnColSize=(int*)malloc(maxLevel*sizeof(int));//array returning the sizes of columns.
    int** result=(int**)malloc(maxLevel*sizeof(int*));//actual array result
    Queue q;
    initQ(&q);
    enqueue(root,&q);
    while(!isEmpty(&q)){
        int levelSize=q.size;//q.size returns the number of nodes in tht level .
        result[*returnSize]=malloc(levelSize*sizeof(int));
        *returnColumnSize[*returnSize]=levelSize;
        for(int i=0;i<levelSize;i+=1){
            Tree* node=dequeue(&q);
            result[*resultSize][i]=node->val;
            if(node->left){enqueue(&q,node->left);}
            if(node->right){enqueue(&q,node->right);}
        }
        (*returnSize)+=1;
    }
    result=(int**)realloc(result,(*returnSize)*sizeof(int**));
    *returnColumnSize=(int*)realloc(*returnColumnSize,(*returnSize)*sizeof(int));
    return result;
}