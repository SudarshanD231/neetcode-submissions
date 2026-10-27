bool isValid(char* str){
    char s[1000];
    int top=-1;
    for(int i=0;str[i]!='\0';i+=1){
        if(str[i]=='(' || str[i]== '[' || str[i]== '{'){
            s[++top]=str[i];
        }else if(top!=-1 &&
        ((s[top] == '(' && str[i] == ')') ||
          (s[top] == '{' && str[i] == '}') ||
          (s[top] == '[' && str[i] == ']'))){
            top-=1;
          }else{
            return false;
          }
        
    }
    return top=-1;
}