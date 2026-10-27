//the only problem with this code was tht it fails when top becomes -1 inside the loop in which case s[top] accesses an invalid index.,eg:- ()() ,()) and so on.
bool isValid(char* str){
    char s[1000];
    int top=-1
    s[++top]=str[0];
    for(int i=1;str[i]!='\n';i+=1){
        if((s[top]=='(' && str[i]==')') || (s[top]=='{'  && str[i]=='}') || (s[top]=='[' && str[i]==']')){
            top--;
        }else{
            s[++top]=str[i];
        }
    }
    if(top==-1){return true;}
    return false;
}
