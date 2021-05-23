class Solution {
public:
//     bool canJump(vector<int>& nums) {
//         queue<int> q;
//         q.push(0);
//         int n=nums.size();
//         vector<bool> visited(n,0);
//         visited[0]=1;
//         int farthest=0;
        
//         while(!q.empty()){
//             int i=q.front();
//             q.pop();
//             for(int j=max(i+1,farthest);j<=min(i+nums[i],n-1);j++){
//                 if(visited[j]!=1){
//                     visited[j]=1;
//                     q.push(j);
//                 }
//             }
//             if(visited[n-1]==true) return 1;
//             farthest=max(farthest, i+nums[i]+1);
//         }
//         return visited[n-1];
//     }
    
    bool canJump(vector<int> &n){
        int i=0;
        int nl=n.size();
        int maxj=n[0];
        while(i<=maxj){
            if(i==nl-1){
                return true;
            }
            maxj=max(maxj,i+n[i]);
            i++;
        }
        return false;
    }
};