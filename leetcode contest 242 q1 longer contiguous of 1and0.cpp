class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones=0;
        int zeros=0;
        int maxo=0;
        int maxz=0;
        for(int i=0;i<s.size();){
            if(s[i]=='0'){
                while(s[i]=='0' && i<s.size()){
                    zeros++;
                    i++;
                }
                maxz=max(maxz,zeros);
                zeros=0;
            }
            else{
                while(s[i]=='1' && i<s.size()){
                    ones++;
                    i++;
                }
                maxo=max(maxo,ones);
                ones=0;
            }
        }
        if(maxo>maxz) return true;
        else return false;
    }
};