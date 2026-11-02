//hv 2 pointers,one at the start of the substring and once which moves thru the substring,hash each new character and increase len ,and if we encounter a repeated character ,move left pointer to the last seen index of repeateed character+1 which moves the window forward,we use 256 instead of 26 to avoid issues with capital letters and such.

int lengthOfLongestSubstring(char* s){
    int left=0;
    int maxLen=0;
    int lastSeen[256]={};
    for (int right=0;s[right]!='\0';right+=1){
        if(lastSeen[c]>=left){
            left=lastSeen[c]+1;
        }
        lastSeen[c]=right;
        int len =right-left+1;
        if(len>maxLen){
            maxLen=len;
        }
    }
    return maxLen;
}