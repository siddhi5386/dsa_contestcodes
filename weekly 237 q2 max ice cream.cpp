class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int count=0;
        if(costs[0]>coins) return count;
        
        for(int i=0;i<costs.size();i++){
            if(costs[i]<=coins){
                count++;
                coins=coins-costs[i];
            }
            else{
                break;
            }
        }
        
        return count;
    }
};