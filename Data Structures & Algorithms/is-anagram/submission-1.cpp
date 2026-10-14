//freq array soln
bool isAnagram(char* s,char* t,int n,int m){
    if(n!=m){return false;}
    int* arr=calloc(26*sizeof(int));
    for(int i=0;i<n;i+=1){
        arr[s[i]-'a']+=1;
        arr[t[i]-'a']-=1;
    }
    for(int i=0i<26;i+=1){
        if(arr[i]!=0){
            return false;
        }
    }
    return true;
}