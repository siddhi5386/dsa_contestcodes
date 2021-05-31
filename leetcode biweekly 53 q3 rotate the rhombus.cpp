class Solution {
public:

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        priority_queue<int> pq;
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pq.push(grid[i][j]);
                int side=1;
                while(true){
                    if(j-side<0 || j+side>=n || i+2*side>=m) break;
                    int k=-1;
                    int sum=0;
                    
                    while(++k<side){
                        sum+=grid[i+side-k][j-side+k]; //left to top movemnet (upward)
                        sum+=grid[i+k][j+k]; //top included and then moving right (downward)
                        sum+=grid[i+side+k][j+side-k]; //right to bottom (downward)
                        sum+=grid[i+2*side -k][j-k]; //bottom inlcude and moving bottom to left
                    }
                    
                    pq.push(sum);
                    // cout<<l<<" ";
                    ++side;
                }
            }
        }
        vector<int> ans;
        int te=pq.top();
        pq.pop();
        ans.push_back(te);
        int count=1;
        while(!pq.empty()){
            if(te!=pq.top()){
                te=pq.top();
                count++;
                ans.push_back(te);
            }
            pq.pop();
            if(count==3) break;
        }
        
        return ans;
    }
};