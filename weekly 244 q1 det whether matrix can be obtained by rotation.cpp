class Solution {
public:
    vector<vector<int>> rotate90(vector<vector<int>>& mat,int n){
        vector<vector<int>> m(n,vector<int> (n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m[j][n-i-1]=mat[i][j];
            }
        }
        return m;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int co1=0,co2=0;
        int n=mat.size();
        if(mat==target) return 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1) co1++;
                if(target[i][j]==1) co2++;
            }
        }
        if(co1!=co2) return false;
        vector<vector<int>> m;
        int ti=4;
        while(ti--){
            m=rotate90(mat,n);
            if(mat==target) return 1;
            mat=m;
        }
        return 0;
    }
};