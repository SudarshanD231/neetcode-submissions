//flatten the array and search .

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROW=matrix.size();
        int COLS=matrix[0].size();
        int l=0;int r=ROW*COLS -1;
        while(l<=r){
            int m=l+(r-l)/2;
            int row=m/COLS,col=m%COLS;
            if(matrix[row][col]==target){
                return true;
            } 
            if(matrix[row][col]>target){
                r=m-1;
            }if(matrix[row][col]<target){
                l=m+1;
            }
            
        }
        return false;
    }
};
