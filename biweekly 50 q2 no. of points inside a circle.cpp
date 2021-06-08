class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        int count=0;
        int r,x,y,m,n;
        for(int i=0;i<queries.size();i++){
            r=queries[i][2],x=queries[i][0],y=queries[i][1];
            count=0;
            for(int j=0;j<points.size();j++){
                m=points[j][0],n=points[j][1];
                if((((x-m)*(x-m))+((y-n)*(y-n))) <=(r*r)) count++;
            }
            ans[i]=count;
        }
        return ans;
    }
};