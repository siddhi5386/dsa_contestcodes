class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans=0;
        int i,j;
        sort(nums.begin(),nums.end());
        for(i=0,j=nums.size()-1;i<nums.size()/2;i++,j--){
            int t=nums[i]+nums[j];
            ans=max(ans,t);
        }
        return ans;
    }
};