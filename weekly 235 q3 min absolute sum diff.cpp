class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long orig=0,maxdecrement=0;
        set<int> s(nums1.begin(),nums1.end());
        
        for(int i=0;i<nums2.size();i++){
            long currdif=abs(nums1[i]-nums2[i]);
            orig=orig+currdif;
            if(maxdecrement<currdif){
            auto it=s.lower_bound(nums2[i]);
            if(it!=s.end()) maxdecrement=max(maxdecrement,currdif-abs(*it-nums2[i]));
            if(it!=s.begin()) maxdecrement=max(maxdecrement,currdif-abs(*prev(it)-nums2[i]));
            }
        }
        
        return (orig-maxdecrement)% 1000000007;
        
        
// greedy solution wont workk!!!!!
        // try 9 30 28 and 1 28 28
        
//         if(nums1==nums2) return 0;
//         int sum=0;
//         int maxi=-1;
//         int index=0;
//         for(int i=0;i<nums1.size();i++){
//             if(abs(nums1[i]-nums2[i])>maxi){
//                 maxi=abs(nums1[i]-nums2[i]);
//                 index=i;
//             }
//         }
//         int compe=0;
//         for(int i=0;i<nums1.size();i++){
//             if(abs(nums2[index]-nums1[i])<maxi){
//                 maxi=abs(nums2[index]-nums1[i]);
//                 compe=i;
//             }
//         }
//         nums1[index]=nums1[compe];
        
//         for(int i=0;i<nums1.size();i++){
//             sum=sum+abs(nums1[i]-nums2[i]);
//             sum=sum % 1000000007;
//         }
//         return sum % 1000000007;
        
    }
};