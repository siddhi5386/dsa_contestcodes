class Solution {
public:
    char shift(char sh,int a){
        return sh+a;
    }
    string replaceDigits(string s) {
        string ans="";
        int n=s.size();
        ans=s[0];
        for(int i=1;i<n;i++){
            if(i%2!=0){
                int si=s[i]-'0';
                char so=shift(s[i-1],si);
                ans=ans+so;
            }
            else{
                ans=ans+s[i];
            }
        }
        return ans;
    }
};