typedef struct interval{
    int start;
    int end;
}Interval;
//qsort is sort function in c,eg:- qsort(nums,numsSize,sizeof(int),cmpr)
//here cmpr is a function ,the cmpr function shld be written in such a way tht it shld take two arguments and return a positive number if first argument shld come before 2nd ,negative if 2nd argument comes first and 0 if they r equal.
int cmpr(const void* a,const void* b){//const void bcs it shld be able to take any data type.
    Interval* x=(Interval*)a;
    Interval* y=(Interval*)b;
    return x->start - y->start;
}
bool canAttendMeetings(Interval** arr,int size){
    if(size<=1){return true;}
    qsort(arr,size,sizeof(Intervals*),cmpr);
    for(int i=1;i<size;i+=1){
        if(arr[i-1]->end > arr[i]->start){return false;}
    }
    return true;
}