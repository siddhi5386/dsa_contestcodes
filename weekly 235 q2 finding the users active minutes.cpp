class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k,0);
        set<vector<int>> s;
        for(int i=0;i<logs.size();i++){
            s.insert(logs[i]);
        }
        unordered_map<int,int> m;
        for(auto it=s.begin();it!=s.end();it++){
            vector<int> temp=*it;
            m[temp[0]]++;
        }
        for(auto i:m){
            ans[i.second-1]++;
        }
        return ans;
    }
};