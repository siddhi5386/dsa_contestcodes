class Solution {
public:
    int minSideJumps(vector<int>& o) {
        int curr=2;
        int lane1=1,lane2=3;
        int side=0;
        
        for(int i=0;i<o.size()-1;i++){
            if(o[i+1]==curr){
                auto x=find(o.begin()+i,o.end(),lane1);
                auto y=find(o.begin()+i,o.end(),lane2);
                
                if(x==o.end() || x==o.end()){
                    side++;
                    break;
                }
                
                else{
                    int x1=x-o.end(),y1=y-o.end();
                    if(x1>y1){
                        swap(curr,lane1);
                        side++;
                    }
                    else{
                        swap(curr,lane2);
                        side++;
                    }
                }
            }
        }
        return side;
    }
};

https://leetcode.com/problems/minimum-sideway-jumps/discuss/1152515/c-wo-dp-beats-100-with-comments