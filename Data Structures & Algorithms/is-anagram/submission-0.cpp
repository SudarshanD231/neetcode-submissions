//dont technically need hashmap ,can be done with frequency array,this was first idea.
typedef struct hashmap{
    char c;
    int count;
}NODE;

bool isAnagram(char* s,char* t,int n,int m){
    if(n!=m){return false;}//not same size,not anagram

    NODE** hmap=(NODE**)calloc(26,sizeof(NODE*));
    for(int i=0;i<n;i+=1){
        int idx=s[i]-'a';//ascii values
        if(!hmap[idx]){
            NODE* new_node=malloc(sizeof(NODE));
            new_node->c=s[i];
            new_node->count=1;
            hmap[idx]=new_node;
        }else{
            hmap[idx]->count+=1;
        }
    }
    for(int i=0;i<m;i+=1){
        int idx=t[i]-'a';
        if(!hmap[idx] || hmap[idx]->count==0){return false;}//node doesnt exist or count in 2nd string of particular character is already matched.
        hmap[idx]-=1;//reduce count .
    }
    return true;
}