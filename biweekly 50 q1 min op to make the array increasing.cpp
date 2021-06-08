class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        if(nums.size()==1) return count;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<=nums[i]){
                count=count+nums[i]-nums[i+1]+1;
                nums[i+1]=nums[i]+1;
            }
        }
        return count;
    }
};