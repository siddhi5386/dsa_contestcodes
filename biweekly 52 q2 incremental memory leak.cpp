class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int maxele=-1;
        int m1=memory1;
        int m2=memory2;
        int time=1;
        while(true){
            if(m1>=m2){
                if(m1>=time){
                    m1=m1-time;
                }
                else{
                    break;
                }
            }
            else if(m2>m1){
                if(m2>=time){
                    m2=m2-time;
                }
                else{
                    break;
                }
            }
            time++;
        }
        
        vector<int> ans;
        ans.push_back(time);
        ans.push_back(m1);
        ans.push_back(m2);
        
        return ans;
    }
};