class Solution {
public:
    int search(vector<int>& nums, int target) {
         
        int fst =0;
        int lst =nums.size()-1;
        while (fst<=lst){
            int m=(fst+lst)/2;
            if (nums[m]==target){
            return m;
            }
            else if (nums[m]<target){
              fst =m+1;
            }
            else {
            lst=m-1;}
        }

       return -1;
    }
};