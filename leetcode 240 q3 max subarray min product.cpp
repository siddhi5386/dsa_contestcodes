class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<long> prefix(n+1,0);
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        stack<int> a;
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        for(int i=0;i<n;i++){
            while(a.empty()!=true && nums[i]<=nums[a.top()]){
                a.pop();
            }
            if(a.empty()==true){
                left[i]=-1;
            }
            else{
                left[i]=a.top();
            }
            a.push(i);
        }
        
        while(a.empty()!=true){
            a.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            while(a.empty()!=true && nums[i]<=nums[a.top()]){
                a.pop();
            }
            if(a.empty()==true){
                right[i]=n;
            }
            else{
                right[i]=a.top();
            }
            a.push(i);
        }
        
        long maxi=0;
        
        for(int i=0;i<n;i++){
            int l=left[i];
            int r=right[i];
            long sum=prefix[r]-prefix[l+1];
            long prod=sum*nums[i];
            maxi=max(maxi,prod);
        }
        maxi=maxi%1000000007;
        return (int)(maxi);
    }
};