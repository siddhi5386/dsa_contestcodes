class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]!=nums[i]){
                res=res+(nums.size()-i);
            }
        }
        return res;
    }
};