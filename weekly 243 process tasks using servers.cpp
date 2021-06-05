class Compare1{
  public:
  bool operator()(pair<int,int>&a, pair<int,int>&b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
  }
};

class Compare2{
  public:
  bool operator()(pair<int,pair<int,int>>&a, pair<int,pair<int,int>>&b){
    return a.first > b.first;
  }
};

class Solution {
public:
    vector<int> assignTasks(vector<int>& s, vector<int>& t) {
      // { server_weight, server_index }
      priority_queue<pair<int,int>, vector<pair<int,int>>, Compare1> free_servers; 

      // { finish_time, { server_wt, server_id } }
      priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, Compare2> running;
      
      // all servers are free currently
      for(int i=0; i<s.size(); ++i){
        free_servers.push({s[i], i});
      }
      
      vector<int> ans(t.size(), 0);
      int time = 0;
      
      for(int j=0; j<ans.size(); ++j){
        // time can be max of time (may be we have incremented it when we popped it from running pq), or j
        time = max(time, j);
        
        // if free servers are not availbale pop from running and change the time when it would have been popped
        if(!free_servers.size()){
          auto fr = running.top(); running.pop();
          free_servers.push({fr.second.first, fr.second.second});
          time = max(time, fr.first);
        }
        
        // if we can still pop from from running using curr time, pop them
        while(running.size() && running.top().first <= time){
          auto fr = running.top(); running.pop();
          free_servers.push({fr.second.first, fr.second.second});
        }
        
        // in free_server pq at top we will have a server with min weight
        auto temp = free_servers.top(); 
        free_servers.pop();
        
        ans[j] = temp.second;
        
        // push it in running pq
        running.push({time + t[j], {temp.first, temp.second}});
      } 
      return ans;
    }
};