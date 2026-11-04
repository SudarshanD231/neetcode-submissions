//u can make a new string with only alphanumeric characters which takes O(n) space or use two pointers which uses constant space.

class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<r){
            while(l<r && !isalphanum(s[l])){
                l+=1;
            }
            while(l<r && !isalphanum(s[r])){//l<r to make sure no crossing over.
                r-=1;
            }
            if(tolower(s[l])!=tolower(s[r])){
                return false;
            }
            l+=1;
            r-=1;
        }
        return true;
    }
    bool isalphanum(char c){
         return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9'); 
    }
};
