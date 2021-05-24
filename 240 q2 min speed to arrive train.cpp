class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {

        int n=dist.size();
        
        if(hour < (double)(n-1)){
          return -1;  
        } 
        
        int l=1;
        int h=1e7;
        
        int m=0;
        int ans=-1;
        while(l<=h){
            m=(l+h)/2;

            double t=0;
            for(int i=0;i<n-1;i++){
                t=t+ceil((double)dist[i]/(double)m);
            }
            
            t=t+(double)((double)dist[n-1]/(double)m);
            
            if(t<=hour){
                ans=m;
                h=m-1;
            }
            else if(t>hour){
                l=m+1;
            }
        }
        return ans;
    }
};