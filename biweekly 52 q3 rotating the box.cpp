class Solution {
public:
    void transpose(vector<vector<char>> A,vector<vector<char>> &B)
    {
        int i, j;
        int M=A.size();
        int N=A[0].size();
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++)
                B[i][M-1-j] = A[j][i];
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int spaces=0;
        int m=box.size();
        int n=box[0].size();
        for(int i=0;i<m;i++){
            deque<int> s;
            spaces=0;
            for(int j=n-1;j>=0;j--){
                if(box[i][j]=='.'){
                    s.push_back(j);
                    // cout<<s.front();
                    spaces++;
                    // cout<<spaces;
                }
                else if(box[i][j]=='*'){
                    s.clear();
                    spaces=0;
                }
                else if(box[i][j]=='#'){
                    if(spaces>0){
                        int ind=s.front();
                        // cout<<ind;
                        swap(box[i][j],box[i][ind]);
                        s.erase(s.begin());
                        s.push_back(j);
                    }
                    else continue;
                }
            }
        }
        
        vector<vector<char>> ans(n,vector<char> (m,'0'));
        transpose(box,ans);
        return ans;
    }
};