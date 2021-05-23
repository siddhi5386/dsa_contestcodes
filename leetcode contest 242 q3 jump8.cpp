    bool canReach(string s, int minJump, int maxJump) {
        
        vector<bool> visited(s.size(), false);
        queue<int> q;
        q.push(0);
        

        int farthest = 0;
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            if(visited[t]) {
                continue;
            }
            visited[t] = true;

            for(int i = max(farthest, t + minJump); i <=  min(t + maxJump, (int)s.length() - 1) ; i++) {
                if(!visited[i] && s[i] == '0'){
                    q.push(i);
                }
            }
            
            farthest = max(farthest, t + maxJump+1);
        }
        
        return visited[s.size() - 1];
    }