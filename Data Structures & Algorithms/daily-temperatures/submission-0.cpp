//here we use a monotonic stack,its a stack where elements r ordered strictly in increasing or decreasing order,used to find nearest larger or smaller element

int* dailyTemperatures(int* dailyTemps,int size,int* returnSize){
    *returnSize=size;
    int return_arr=(int*)calloc(size,sizeof(int));
    int stck=malloc(size*sizeof(int));
    int top=-1
    for(int i=0;i<size;i+=1){
        
        while(top>=0 && temperatures[i]>temperature[stck[top]]){
            int previdx=stck[top];
            top-=1;
            return_arr[previdx]=i-previdx;
        }
        stck[++top]=i;
    }
    return return_arr;
}