class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n=logs.size();
        int maxy=0;
        int maxp=0;
        for(int i=0;i<n;i++){
            int year=logs[i][0];
            int temp=0;
            for(int j=0;j<n;j++){
                if(logs[j][0]<=year && logs[j][1]>year){
                    temp++;
                }
            }
            if(temp>maxp){
                maxp=temp;
                maxy=year;
            }
            else if(temp==maxp && maxy>year){
                maxy=year;
                maxp=temp;
            }
            year=logs[i][1];
            temp=0;
            for(int j=0;j<n;j++){
                if(logs[j][0]<=year && logs[j][1]>year){
                    temp++;
                }
            }
            if(temp>maxp){
                maxp=temp;
                maxy=year;
            }
            else if(temp==maxp && maxy>year){
                maxy=year;
                maxp=temp;
            }
            
        }
        return maxy;
    }
};