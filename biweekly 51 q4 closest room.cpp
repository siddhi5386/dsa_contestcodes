class Solution {
public:
    static bool mycmp(vector<int> a,vector<int> b){
        if(a[1]==b[1]){
            return a[0]<=b[0];
        }
        return a[1]<b[1];
    }
    
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        
        sort(queries.begin(),queries.end(),[](vector<int> &a,vector<int> &b){
           return a[1]>b[1]; 
        });
        
        sort(rooms.begin(),rooms.end(),[](vector<int> &a,vector<int> &b){
           return a[1]>b[1]; 
        });
        int j=0;
        set<int> s;
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            
            int pre=queries[i][0],minsize=queries[i][1],idx=queries[i][2];
            
            while(j<rooms.size() && rooms[j][1]>=minsize){
                s.insert(rooms[j][0]);
                j++;
            }
            
            if(s.size()==0){
                ans[idx]=-1;
            }
            else{
                auto it = s.upper_bound(pre);
                int res = it != s.end() ? abs(*it - pre) : INT_MAX;
                int resRoomId = it != s.end() ? *it : INT_MAX;
                if(it != s.begin()) {
                    --it;
                    if(abs(*it - pre) <= res)
                        resRoomId = *it;
                }
                ans[idx] = resRoomId;
            }
        }
        return ans;
    }
};