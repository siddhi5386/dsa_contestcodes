class Solution {
public:
    int jump(vector<int>& nums) {
        int count=0;
        queue<int> q;
        q.push(0);
        int n=nums.size();
        vector<int> visited(n,0);
        visited[0]=1;
        int far=0;
        if(n==1) return 0;
        
        while(!q.empty()){
            count++;
            int size=q.size();
            while(size--){
                int i=q.front();
                q.pop();
                
                for(int j=max(i+1,far);j<=min(n-1,i+nums[i]);j++){
                if(visited[j]==false){
                    q.push(j);
                    visited[j]=1;
                    }
                }
            
                if(visited[n-1]==true) return count;
                far=max(far,i+nums[i]);
            }
            
        }
        return count;
    }
};