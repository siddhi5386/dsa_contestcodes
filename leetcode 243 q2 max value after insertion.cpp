class Solution {
public:
    string maxValue(string n, int x) {
        bool flag=0;
        bool fl=0;
        if(n[0]=='-') flag=1;
        string ans="";
        char xi=x+'0';
        int indx=0;
        if(flag==0){
            while(indx< n.size() && n[indx]>=xi){
                indx++;
            }
            
            ans=n.substr(0,indx)+xi+n.substr(indx,n.size()-indx);
        }
        else{
            indx=1;
            while(indx<n.size() && n[indx]<=xi ){
                indx++;
            }
            
            ans=n.substr(0,indx)+xi+n.substr(indx,n.size()-indx);
        }
        return ans;
    }
};