class Solution {
public:
    string truncateSentence(string s, int k) {
        int count=0;
        int i=0;
        for(i=0;i<s.size();i++){
            if(s[i]==' '){
                count++;
            }
            if(count==k) break;
        }
        return s.substr(0,i);
    }
};