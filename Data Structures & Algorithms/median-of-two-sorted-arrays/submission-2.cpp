//brute force wld be to make a new arr,merge sort the arrys and find the mdian of tht new arr ,opitmized soln wld be to use 2 pointers and not exactly merge but simulate merging for (len1 + len2)/2 +1 iterations ,bcs tht wld take us to the middle ,and thn if len1+len2 is even,the median wld be median 1+ median 2 /2, or it wld just be median1 if its odd.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();int len2=nums2.size();
        int i=0;int j=0;
        int median1=0;int median2=0;
        for(int count=0;count<(len1 +len2)/2 +1;count+=1){
            median2=median1;//median 2 is previous median.
            if(i<len1 && j<len2){
                if(nums1[i]<nums2[j]){
                    median1=nums1[i];
                    i+=1;
                }else{
                    median1=nums2[j];
                    j+=1;
                }
            }else if(i<len1){
                median1=nums1[i];
                i+=1;
            }else{
                median1=nums2[j];
                j+=1;
            }
        }
        if((len1+len2)%2 ==1){
            return double(median1);
        }else{
            return (median1 +median2)/2.0;
        }
    }
};
