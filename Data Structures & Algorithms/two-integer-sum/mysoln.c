typedef struct list{
    int key;
    int used;
    int index;
}NODE;
int* twoSum(int* nums,int target){
    int sz=nums.size();
    int size=2*sz +1;
    NODE* table=(NODE*)calloc((2*sz)+1,sizeof(NODE));
    int* return_arr=(int*)malloc(2*sizeof(int));
    for(int i=0;i<sz;i+=1){
        int comp=target - nums[i];
        int lookup=(comp)%size;
        if(lookup<0){lookup+=size;}
        while(table[lookup].used){
            if(table[lookup].key==comp){
                return_arr[0]=table[lookup].index;
                return_arr[1]=i;
                return return_arr;
            }
            lookup=(lookup +1)%size;
        }
        int h=(nums[i]) %size;
        if(h<0){h+=size;}
        while(table[h].used){
            h=(h+1)%size;
        }
        table[h].key=nums[i];
        table[h].used=1;
        table[h].index=i;
    }
    free(table);
    free(return_arr);
    return NULL;

}
