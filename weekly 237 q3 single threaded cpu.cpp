class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        if(tasks.size()==0) return ans;
        for(int i=0;i<tasks.size();i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]){
                if(a[1]==b[1]){
                    return a[2]<b[2];
                }
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });
        
        int i=0;
        long long timee=1;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;     

        
        while(i<tasks.size() || !pq.empty()){
             int fl1=0,fl2=0;
             while(i<tasks.size() && (long long)tasks[i][0]<=timee){
                int pro=tasks[i][1];
                int ind=tasks[i][2];
                int tim=tasks[i][0];
                pq.push({pro,ind,tim});
                fl2=1;
                i++;
            }

            if(!pq.empty()){
                vector<int> t=pq.top();
                pq.pop();
                timee=timee+(long long)t[0];
                ans.push_back(t[1]);
                fl1=1;
            }
            if(fl1==0 && fl2==0) timee=tasks[i][0];
        }
        return ans;
    }
};

https://leetcode.com/problems/single-threaded-cpu/discuss/1197841/c%2B%2B-priority_queue-and-sort-or-O(n*log(n))-time-O(n)-space