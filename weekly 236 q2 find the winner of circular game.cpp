class Solution {
public:
    int findTheWinner(int n, int k) {
        int count=0;
        vector<int> vis(n+1,0);
        int i=0;
        int ans=-1;
        int l=1;
        while(count!=n-1){
            int j=0;
            while(j!=k){
                if(l<n){
                    if(vis[l]!=1){
                        l++;
                        j++;
                    }
                    else{
                        l++;
                    }
                }
                else if(l>=n){
                    l=0;
                }
            }
            vis[l-1]=1;
            // cout<<l;
            count++;
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                ans=i;
                break;
            }
        }
        return ans;
    }
};